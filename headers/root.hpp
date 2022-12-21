#ifndef ROOT_HPP
#define ROOT_HPP

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
        NOT_RUN,
        RUN,
        PAUSE,
        END_GAME,
    };

    void _push_window(WINDOW_TYPES other);
    void _pop_window();

    Ui::root* _ui;
    QTimer* _timer;
    QStack<WINDOW_TYPES> _stack_windows;
    GAME_TYPES _state_game;
};

#endif
