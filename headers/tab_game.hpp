#ifndef TAB_GAME_HPP
#define TAB_GAME_HPP

#include "snake.hpp"
#include "draw_image.hpp"
#include <QWidget>
#include <QTimer>

class Tab_game : public QWidget {
    Q_OBJECT
public:
    enum class TYPES_END_GAME {
        WING,
        DRAW,
        LOSS,
    };

    explicit Tab_game(QWidget *parent = nullptr);
    ~Tab_game();

    void start(std::function<void()> completion_game,
               std::function<void()> increasing_counters);
    void pause();
    void exit();
    void renewals();
    void restart();
    void keyboard(QKeyEvent* event);
    size_t get_score() const;
    size_t get_time() const;
    TYPES_END_GAME end_game() const;

protected:
    void paintEvent(QPaintEvent* event) override;

public:
    void _step();

    const unsigned short _SECUND_TIMER;
    Snake* _game;
    QTimer* _timer_signal;
    std::function<void()> _completion_game;
    std::function<void()> _increasing_counters;
    STEP_SNAKE _new_value;
    size_t _m_seconds;
    size_t _seconds;

    Draw_image _image_apple;
    Draw_image _image_field;
    Draw_image _image_snake_head;
    Draw_image _image_snake_tail;
    Draw_image _image_snake_body;

};

#endif
