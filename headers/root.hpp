#ifndef ROOT_HPP
#define ROOT_HPP

#include "snake.hpp"
#include "music.hpp"
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
    void on_button_music_clicked();
    void on_music_volume_valueChanged(int value);

    void on_button_sound_clicked();
    void on_sound_volume_valueChanged(int value);

    void on_about_game_back_clicked();

    void on_continue_pause_clicked();
    void on_continut_settings_clicked();
    void on_return_menu_pause_clicked();

    void on_end_game_customization_clicked();
    void on_return_menu_end_clicked();
    void on_start_over_clicked();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    void _start_music();

    enum class VIEW_TYPES {
        MENU = 0,
        GAME = 1,
        CUSTOMIZATION = 2,
        ABOUT_THE_GAME = 3,
    };
    enum class GAME_TYPES {
        NOT_GAME,
        GAME,
        PAUSE,
    };

    void _push_window(VIEW_TYPES other);
    void _pop_window();
    void _jamp_menu();
    void _enabling_pause();
    void _ending_pause();
    void _removing_focus_button_pause();
    void _removing_focus_button_end_game();

    Ui::root* _ui;

    QStack<VIEW_TYPES> _stack_windows;
    GAME_TYPES _state_game;
    Music _music;
    Music _sound;
    int _music_volume;
    int _sound_volume;
};

#endif
