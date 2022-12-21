#include "../headers/tab_game.hpp"
#include <QPainter>
#include <iostream>

Tab_game::Tab_game(QWidget *parent)
    : QWidget(parent) {

}

void Tab_game::paintEvent(QPaintEvent *event) {
     std::cout << "Cart" << std::endl;
     QPainter x(this);
     x.setBrush(QBrush(Qt::black, Qt::SolidPattern));
     x.drawRect(74, 55, 600, 600);
     return ;
}

void Tab_game::mouseMoveEvent(QMouseEvent *) {
    std::cout << "Cart1"  << std::endl;
}
