#ifndef TAB_GAME_HPP
#define TAB_GAME_HPP

#include "snake.hpp"
#include <QWidget>
#include <QPixmap>
#include <QTimer>

class Tab_game : public QWidget {
    Q_OBJECT
public:
    explicit Tab_game(QWidget *parent = nullptr);

    void start(std::function<void()>& completion_game,
               std::function<void()>& increasing_counters);
    void pause();
    void stop();
    void renewals();
    void restart(std::function<void()>& completion_game,
                 std::function<void()>& increasing_counters);
    void keyboard(QKeyEvent* event);
    size_t get_score() const;
    size_t get_time() const;

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
};

#endif
