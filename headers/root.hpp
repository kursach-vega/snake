#ifndef ROOT_HPP
#define ROOT_HPP

#include "snake.hpp"
#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class root; }
QT_END_NAMESPACE

class root : public QMainWindow {
    Q_OBJECT
public:
    root(QWidget* parent = nullptr);
    ~root();

private slots:
    void on_button_exit_clicked();

private:
    Ui::root* _ui;
    Snake* _game;
    QTimer* _timer;
};

#endif
