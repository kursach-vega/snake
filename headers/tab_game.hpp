#ifndef TAB_GAME_HPP
#define TAB_GAME_HPP

#include <QWidget>
#include <QPixmap>

class Tab_game : public QWidget {
    Q_OBJECT
public:
    explicit Tab_game(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

};

#endif
