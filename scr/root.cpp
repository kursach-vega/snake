#include "../headers/root.hpp"
#include "ui_root.h"
#include <QTabBar>
#include <QKeyEvent>

void root::_push_window(WINDOW_TYPES other) {
    int index_window = static_cast<int>(other);
    this->_stack_windows.push(other);
    this->_ui->tabl_snake->setCurrentIndex(index_window);
    return ;
}

void root::_pop_window() {
    this->_stack_windows.pop();
    int index_window = static_cast<int>(this->_stack_windows.top());
    this->_ui->tabl_snake->setCurrentIndex(index_window);
    return ;
}

void root::_enabling_pause() {
    this->_ui->game->pause();
    this->_state_game = GAME_TYPES::PAUSE;
    this->_ui->pause_window->show();
}

void root::_ending_pause() {
    this->_state_game = GAME_TYPES::GAME;
    this->_ui->pause_window->hide();
    this->_ui->game->renewals();
}

void root::_game_step() {

    return ;
}

void root::keyPressEvent(QKeyEvent* event) {
    if (this->_stack_windows.top() != WINDOW_TYPES::GAME) {
        return ;
    }
    int key = event->key();
    switch (key) {
        case Qt::Key_Escape:
            if ( this->_state_game == GAME_TYPES::GAME) {
                this->_enabling_pause();
            }
            else if (this->_state_game == GAME_TYPES::PAUSE ) {
                this->_ending_pause();
            }
    }

}

root::root(QWidget* parent) : QMainWindow(parent),
    _ui(new Ui::root), _timer_game(nullptr), _snake_game(nullptr),
    _state_game(GAME_TYPES::GAME), _secund_timer(200) {

    this->_ui->setupUi(this);
    this->_ui->tabl_snake->tabBar()->hide();
    this->_push_window(WINDOW_TYPES::MENU);

    this->_ui->end_game_window->hide();
    this->_ui->pause_window->hide();

    return ;
}

root::~root() {
    delete this->_ui;
    delete this->_timer_game;
    delete this->_snake_game;
    return ;
}

void root::on_transition_game_clicked() {
    auto end_game_tab_lada = [this](){
        return ;
    };
    auto increasing_counters = [this](){
        int score = this->_ui->game->get_score();
        int timer = this->_ui->game->get_time();
        this->_ui->timer_game_widget->display(timer);
        this->_ui->score_apple_widget->display(score);
        return ;
    };
    this->_ui->game->start(end_game_tab_lada, increasing_counters);
    this->_push_window(WINDOW_TYPES::GAME);
    return ;
}

void root::on_transition_cystom_clicked() {
    this->_push_window(WINDOW_TYPES::CUSTOMIZATION);
    return ;
}

void root::on_transition_about_game_clicked() {
    this->_push_window(WINDOW_TYPES::ABOUT_THE_GAME);
    return ;
}

void root::on_exit_button_clicked() {
    this->close();
    return ;
}

void root::on_customization_back_clicked() {
    this->_pop_window();
    return ;
}


void root::on_about_game_back_clicked() {
    this->_pop_window();
    return ;
}

