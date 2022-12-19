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
    void on_button_game_clicked();
    void on_button_customization_clicked();
    void on_button_abaut_game_clicked();
    void on_button_exit_clicked();

    void on_game_back_clicked();
    void on_pause_window_exit_clicked();

    void on_about_game_back_clicked();

    void on_cusrimizatio_back_clicked();

private:
    enum class WINDOW_TYPES {
        MENU = 0,
        GAME = 1,
        CUSTOMIZATION = 2,
        ABOUT_THE_GAME = 3,
    };
    enum class GAME_TYPES {
        NOT_RUN,
        RUN,
        PAUSE,
        END_GAME,
    };

    void _switching_window(WINDOW_TYPES other);
    void paintEvent(QPaintEvent *event);
    Ui::root* _ui;
    Snake* _game;
    QTimer* _timer;
    WINDOW_TYPES _parent_window;
    WINDOW_TYPES _current_window;
    GAME_TYPES _state_game;
};

#endif
