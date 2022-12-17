#include "../headers/root.hpp"
#include "ui_root.h"
#include <QTabBar>

root::root(QWidget* parent) : QMainWindow(parent),
    _ui(new Ui::root), _game(nullptr), _timer(nullptr) {

    this->_ui->setupUi(this);
    this->_ui->tab_game->tabBar()->hide();
   // this->_ui->tab_game->setCurrentIndex(0);
}

root::~root() {
    delete this->_timer;
    delete this->_game;
    delete this->_ui;
    return ;
}


void root::on_button_exit_clicked() {
    this->close();
    return ;
}

