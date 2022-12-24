#include "../headers/tab_game.hpp"
#include <QPainter>
#include <QKeyEvent>

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
    : QWidget(parent), _SECUND_TIMER(200), _game(new Snake(20, 20)), _timer_signal(new QTimer(this)),
    _new_value(_game->get_step()), _m_seconds(0), _seconds(0) {

    auto lamda_signal = [this](){
        this->_step();
        return ;
    };
    this->connect(this->_timer_signal, &QTimer::timeout, lamda_signal);
    return ;
}

Tab_game::~Tab_game() {
    this->exit();
    return ;
}

void Tab_game::start(std::function<void ()> &completion_game,
                     std::function<void ()> &increasing_counters) {
    this->_completion_game = completion_game;
    this->_increasing_counters = increasing_counters;
    this->_timer_signal->start(this->_SECUND_TIMER);
    return ;
}

void Tab_game::pause() {
    this->_timer_signal->stop();
    this->_new_value = this->_game->get_step();
    return ;
}

void Tab_game::exit() {
    delete this->_timer_signal;
    delete this->_game;
    return ;
}

void Tab_game::renewals() {
    this->_timer_signal->start(this->_SECUND_TIMER);
    this->repaint();
    return ;
}

void Tab_game::restart(std::function<void ()> &completion_game,
                       std::function<void ()> &increasing_counters) {

    this->_timer_signal->stop();
    delete this->_game;
    this->_new_value = STEP_SNAKE::RIGHT;
    this->_m_seconds = 0;
    this->_seconds = 0;
    this->_completion_game = completion_game;
    this->_increasing_counters = increasing_counters;
    this->_game = new Snake(20, 20);
    this->_new_value = this->_game->get_step();
    this->_timer_signal->start(this->_SECUND_TIMER);
    this->repaint();
    return ;
}

void Tab_game::keyboard(QKeyEvent *event) {
    switch ( event->key() ) {
        case  Qt::Key_Up :
            this->_new_value = STEP_SNAKE::UP;
            break;
        case  Qt::Key_Down:
            this->_new_value = STEP_SNAKE::DOWN;
            break;
        case Qt::Key_Right:
            this->_new_value = STEP_SNAKE::RIGHT;
            break;
        case Qt::Key_Left:
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

void Tab_game::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPixmap myPixmap(":/resource_img/images/field.png");
    Q_ASSERT(!myPixmap.isNull());
    QPainter canvas(this);
    canvas.drawPixmap(100, 100, myPixmap);
    QPixmap myPixmap1(":/resource_img/images/apple.png");
    canvas.drawPixmap(100, 100, myPixmap1);



    //canvas.drawRect(74, 55, 600, 600);
    return ;
}
