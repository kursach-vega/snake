#ifndef TAB_GAME_HPP
#define TAB_GAME_HPP

#include <QWidget>

class Tab_game : public QWidget {
    Q_OBJECT
public:
    explicit Tab_game(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *) override;
};

#endif
