#ifndef ROOT_HPP
#define ROOT_HPP

#include "snake.hpp"
#include <QMainWindow>
#include <QStack>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
    class root;
}
QT_END_NAMESPACE

class root : public QMainWindow {
    Q_OBJECT
public:
    root(QWidget* parent = nullptr);
    ~root();

private slots:
    void on_transition_game_clicked();
    void on_transition_cystom_clicked();
    void on_transition_about_game_clicked();
    void on_exit_button_clicked();


    void on_customization_back_clicked();

    void on_about_game_back_clicked();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    enum class WINDOW_TYPES {
        MENU = 0,
        GAME = 1,
        CUSTOMIZATION = 2,
        ABOUT_THE_GAME = 3,
    };
    enum class GAME_TYPES {
        NOT_GAME,
        GAME,
        PAUSE,
        END_GAME,
    };

    void _push_window(WINDOW_TYPES other);
    void _pop_window();
    void _enabling_pause();
    void _ending_pause();
    void _game_step();

    Ui::root* _ui;
    QTimer* _timer_game;
    Snake* _snake_game;

    QStack<WINDOW_TYPES> _stack_windows;
    GAME_TYPES _state_game;
    unsigned short _secund_timer;


};

#endif
