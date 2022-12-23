#include "../headers/tab_game.hpp"
#include <QPainter>
#include <iostream>
#include <QKeyEvent>


Tab_game::Tab_game(QWidget *parent)
    : QWidget(parent) {

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
