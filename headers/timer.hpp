#ifndef TIMER_HPP
#define TIMER_HPP

#include <QTimer>

class Timer {
public:
    Timer(const unsigned short MAX_SECONDS,
          const std::function<void()> end_second);
    ~Timer();
    void start();
	void stop();
	void pause();
    void continue_timer();
	void restart();
	unsigned short get_seconds() const;
private:
    const std::function<void ()> _END_SECOND;
	const unsigned short _MAX_SECONDS;
	unsigned short _seconds;
	QTimer* _timer;
};


#endif
