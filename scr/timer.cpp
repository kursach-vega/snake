#include "../headers/timer.hpp"
#include <QObject>

Timer::Timer(const unsigned short MAX_SECONDS,
             const std::function<void ()> END_SECOND) :
    _MAX_SECONDS(MAX_SECONDS), _END_SECOND(END_SECOND),
    _seconds(0), _timer(nullptr) {
}

Timer::~Timer() {
    delete _timer;
    return ;
}

void Timer::start(){
    this->_timer = new QTimer();
    auto increase_timer = [this](){
        this->_seconds += 1;
        if ( this->_MAX_SECONDS == this->_seconds ) {
            this->_timer->stop();
            this->_END_SECOND();
        }
        return ;
    };
    this->connect(this->_timer, &QTimer::timeout, increase_timer);
    return ;
}
