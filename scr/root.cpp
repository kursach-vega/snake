#include "../headers/root.hpp"
#include "ui_root.h"
#include <QTabBar>
#include <QKeyEvent>
#include <iostream>


void root::_push_window(VIEW_TYPES other) {
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

void root::_jamp_menu() {
    this->_ui->game->exit();
    this->_stack_windows.clear();
    this->_push_window(VIEW_TYPES::MENU);
    if ( this->_state_game == GAME_TYPES::PAUSE ) {
        this->_ui->pause_window->hide();
    }
    else {
        this->_ui->end_game_window->hide();
    }
    this->_state_game = GAME_TYPES::NOT_GAME;
    return ;
}

void root::_enabling_pause() {
    this->_ui->game->pause();
    this->_state_game = GAME_TYPES::PAUSE;
    this->_ui->pause_window->show();
    return ;
}

void root::_ending_pause() {
    this->_state_game = GAME_TYPES::GAME;
    this->_ui->pause_window->hide();
    this->_ui->game->resume();
    return ;
}

void root::_removing_focus_button_pause() {
    this->_ui->continue_pause->setFocusPolicy(Qt::NoFocus);
    this->_ui->return_menu_pause->setFocusPolicy(Qt::NoFocus);
    return ;
}

void root::_removing_focus_button_end_game() {
    this->_ui->start_over->setFocusPolicy(Qt::NoFocus);
    this->_ui->return_menu_end->setFocusPolicy(Qt::NoFocus);
    return ;
}

void root::keyPressEvent(QKeyEvent* event) {
    if (this->_stack_windows.top() != VIEW_TYPES::GAME) {
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
            break;
        default:
            if ( this->_state_game == GAME_TYPES::GAME) {
                this->_ui->game->keyboard(event);
            }
    }
    return ;
}

root::root(QWidget* parent) : QMainWindow(parent),
    _ui(new Ui::root), _state_game(GAME_TYPES::NOT_GAME) {
     
    this->_ui->setupUi(this);
    this->_ui->tabl_snake->tabBar()->hide();
    this->_push_window(VIEW_TYPES::MENU);

    this->_ui->end_game_window->hide();
    this->_ui->pause_window->hide();
    this->_removing_focus_button_pause();
    this->_removing_focus_button_end_game();

    return ;
}

root::~root() {
    delete this->_ui;
    return ;
}

void root::on_transition_game_clicked() {
    auto end_game = [this](){
        int score = this->_ui->game->get_score();
        int timer = this->_ui->game->get_time();
        this->_ui->time_end_game->display(timer);
        this->_ui->score_apple_end_game->display(score);
        this->_state_game = GAME_TYPES::NOT_GAME;
        this->_ui->end_game_window->show();
        Tab_game::TYPES_END_GAME ans = this->_ui->game->end_game();
        switch ( ans ) {
            case Tab_game::TYPES_END_GAME::DRAW :
                this->_ui->end_win_text->setText("??????????!");
                break;
            case Tab_game::TYPES_END_GAME::LOSS :
                this->_ui->end_win_text->setText("??????????????????!");
                break;
            case Tab_game::TYPES_END_GAME::WING :
                this->_ui->end_win_text->setText("????????????!");
                break;
            default:
                return ;
        }
        return ;
    };
    auto increasing_counters = [this]() {
        int score = this->_ui->game->get_score();
        int timer = this->_ui->game->get_time();
        this->_ui->timer_game_widget->display(timer);
        this->_ui->score_apple_widget->display(score);
        return ;
    };
    this->_ui->game->start(end_game, increasing_counters);
    this->_push_window(VIEW_TYPES::GAME);
    this->_state_game = GAME_TYPES::GAME;
    return ;
}

void root::on_transition_about_game_clicked() {
    this->_push_window(VIEW_TYPES::ABOUT_THE_GAME);
    return ;
}

void root::on_exit_button_clicked() {
    this->close();
    return ;
}

void root::on_about_game_back_clicked() {
    this->_pop_window();
    return ;
}

void root::on_continue_pause_clicked() {
    this->_ending_pause();
    return ;
}

void root::on_return_menu_pause_clicked() {
    this->_jamp_menu();
    return ;
}

void root::on_return_menu_end_clicked() {
    this->_jamp_menu();
    return ;
}

void root::on_start_over_clicked() {
    this->_ui->end_game_window->hide();
    this->_state_game = GAME_TYPES::GAME;
    this->_ui->game->restart();
    return ;
}

