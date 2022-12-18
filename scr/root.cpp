#include "../headers/root.hpp"
#include "ui_root.h"
#include <QTabBar>
#include <QStandardItemModel>
#include <QMediaPlayer>
#include <QMediaPlaylist>

void root::_switching_window(WINDOW_TYPES other) {
    this->_parent_window = this->_current_window;
    this->_current_window = other;
    int index_window = static_cast<int>(other);
    this->_ui->tab_game->setCurrentIndex(index_window);
    return ;
}

root::root(QWidget* parent) : QMainWindow(parent),
    _ui(new Ui::root), _game(nullptr), _timer(nullptr),
    _current_window(WINDOW_TYPES::MENU) {

    this->_ui->setupUi(this);
    this->_ui->tab_game->tabBar()->hide();
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("/home/pbalykov/вега/3_семестр/МИСП/Курсовая/snake/x.mp3"));
    player->setVolume(50);
    player->play();

    this->_switching_window(WINDOW_TYPES::MENU);
    return ;
}

root::~root() {
    delete this->_timer;
    delete this->_game;
    delete this->_ui;
    return ;
}

void root::on_button_game_clicked() {
    this->_switching_window(WINDOW_TYPES::GAME);
    return ;
}

void root::on_button_customization_clicked() {
    this->_switching_window(WINDOW_TYPES::CUSTOMIZATION);
    return ;
}

void root::on_button_abaut_game_clicked() {
    this->_switching_window(WINDOW_TYPES::ABOUT_THE_GAME);
    return ;
}

void root::on_button_exit_clicked() {
    this->close();
    return ;
}

void root::on_game_back_clicked() {
    this->_switching_window(this->_parent_window);
    return ;
}

void root::on_about_game_back_clicked() {
    this->_switching_window(this->_parent_window);
    return ;
}

void root::on_cusrimizatio_back_clicked() {
    this->_switching_window(this->_parent_window);
}

