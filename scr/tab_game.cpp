#include "../headers/tab_game.hpp"
#include <QPainter>
#include <QKeyEvent>

namespace {
    ROTATE translation_in_radius(STEP_SNAKE value) {
        switch (value) {
            case  STEP_SNAKE::UP :
                return ROTATE::UP;
            case  STEP_SNAKE::LEFT :
                return ROTATE::LEFT;
            case STEP_SNAKE::RIGHT :
                return ROTATE::RIGHT;
            case STEP_SNAKE::DOWN :
                return ROTATE::DOWN;
            default :
                return ROTATE::NONE;
        }
        return ROTATE::NONE;
    }
}

void Tab_game::_step() {
    this->_m_seconds += _SECUND_TIMER;
    if (this->_m_seconds >= 1000 ) {
        this->_seconds += 1;
        this->_m_seconds = 0;
    }
    if ( this->_seconds == 99999 ) {
        this->_timer_signal->stop();
        this->_increasing_counters();
        this->_completion_game();
        return ;
    }
    this->_game->set_step(_new_value);
    this->_game->step();
    this->_increasing_counters();
    if ( this->_game->end_game() ) {
        this->_timer_signal->stop();
        this->_completion_game();
        return ;
    }
    this->repaint();
    return ;
}


Tab_game::Tab_game(QWidget *parent)
    : QWidget(parent), _SECUND_TIMER(200), _game(nullptr),
      _timer_signal(new QTimer(this)),
      _image_apple(":/resource_img/images/apple.png"),
      _image_field(":/resource_img/images/field.png"),
      _image_snake_head(":/resource_img/images/snake_head.png"),
      _image_snake_tail(":/resource_img/images/snake_tail.png"),
      _image_snake_body(":/resource_img/images/snake_body.png"){

    auto lamda_signal = [this](){
        this->_step();
        return ;
    };
    this->connect(this->_timer_signal, &QTimer::timeout, lamda_signal);
    return ;
}

Tab_game::~Tab_game() {
    delete this->_game;
    delete this->_timer_signal;
    this->_game = nullptr;
    this->_timer_signal = nullptr;
    return ;
}

void Tab_game::start(std::function<void ()> completion_game,
                     std::function<void ()> increasing_counters) {
    this->exit();
    this->_completion_game = completion_game;
    this->_increasing_counters = increasing_counters;
    this->_game = new Snake(20, 20);
    this->_new_value = this->_game->get_step();
    this->_timer_signal->start(this->_SECUND_TIMER);
    return ;
}

void Tab_game::pause() {
    if (this->_timer_signal->isActive()) {
            this->_timer_signal->stop();
    }
    this->_new_value = this->_game->get_step();
    return ;
}

void Tab_game::exit() {
    if (this->_timer_signal->isActive()) {
            this->_timer_signal->stop();
    }
    this->_m_seconds = 0;
    this->_seconds = 0;
    delete this->_game;
    this->_game = nullptr;
    return ;
}

void Tab_game::renewals() {
    if (!this->_timer_signal->isActive()) {
        this->_timer_signal->start(this->_SECUND_TIMER);
        this->repaint();
    }
    return ;
}

void Tab_game::restart() {
    this->exit();
    this->_game = new Snake(20, 20);
    this->_new_value = this->_game->get_step();
    this->_timer_signal->start(this->_SECUND_TIMER);
    this->repaint();
    return ;
}

void Tab_game::keyboard(QKeyEvent* event) {
    switch ( event->key() ) {
        case  Qt::Key_Up :
            this->_new_value = STEP_SNAKE::UP;
            break;
        case  Qt::Key_Down:
            this->_new_value = STEP_SNAKE::DOWN;
            break;
        case Qt::Key_Right :
            this->_new_value = STEP_SNAKE::RIGHT;
            break;
        case Qt::Key_Left :
            this->_new_value = STEP_SNAKE::LEFT;
            break;
        default:
            return;
    }
    return ;

}

size_t Tab_game::get_score() const {
    return this->_game->get_gray_apples() * 100;
}

size_t Tab_game::get_time() const {
    return this->_seconds;
}

Tab_game::TYPES_END_GAME Tab_game::end_game() const {
    if (this->_game->wing_game() ) {
        return TYPES_END_GAME::WING;
    }
    if ( this->_game->end_game() ) {
        return TYPES_END_GAME::LOSS;
    }
    return TYPES_END_GAME::DRAW;
}

void Tab_game::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    if ( !this->_game ) {
        return ;
    }
    QPainter canvas(this);
    int x_begin = this->width() / 2 - this->_image_field.width() / 2;
    int y_begin = this->height() / 2 - this->_image_field.height() / 2 + 22;
    this->_image_field.draw(canvas, x_begin, y_begin);
    const Field_Object& apple = this->_game->get_apple();
    this->_image_apple.draw(canvas, apple.x * this->_image_apple.width() + x_begin,
                                    apple.y * this->_image_apple.height() + y_begin);
    const auto snake = this->_game->get_snake();
    const auto turns = this->_game->get_turns();
    int snake_height = this->_image_snake_body.height();
    int snake_width = this->_image_snake_body.width();
    for (long long i = 1; i < qMax<long long>(snake.size() - 1, 0); i++) {
        this->_image_snake_body.draw(canvas, snake_width * snake[i].x + x_begin,
                                     snake_height * snake[i].y + y_begin,
                                     translation_in_radius(turns[i]));
    }
    if (snake.size() != 1) {
        this->_image_snake_tail.draw(canvas, snake_width * snake[0].x + x_begin,
                                     snake_height * snake[0].y + y_begin,
                                     translation_in_radius(turns[1]));
    }
    this->_image_snake_head.draw(canvas,snake_width * snake[snake.size() - 1].x + x_begin,
                                 snake_height * snake[snake.size() - 1].y + y_begin,
                                 translation_in_radius(turns[snake.size() - 1]));
    return ;
}
