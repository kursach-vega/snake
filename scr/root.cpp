#include "../headers/root.hpp"
#include "ui_root.h"
#include <QTabBar>
#include <QKeyEvent>
#include <iostream>

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

void root::keyPressEvent(QKeyEvent* event) {
    quint32 x = event->nativeVirtualKey();
    std::cout << x << std::endl;

}

root::root(QWidget* parent) : QMainWindow(parent),
    _ui(new Ui::root), _timer(nullptr), _state_game(GAME_TYPES::NOT_RUN) {

    this->_ui->setupUi(this);
    this->_ui->tabl_snake->tabBar()->hide();
    this->_push_window(WINDOW_TYPES::MENU);

    this->_ui->end_game_window->hide();
    this->_ui->pause_window->hide();

    return ;
}

root::~root() {
    delete this->_ui;
    delete this->_timer;
    return ;
}

void root::on_transition_game_clicked() {
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

