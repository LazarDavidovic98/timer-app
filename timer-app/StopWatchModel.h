// StopWatchModel.h
#ifndef STOPWATCHMODEL_H
#define STOPWATCHMODEL_H

#include <string>

class StopWatchModel {
private:
    int minutes;
    int seconds;
    int milliseconds;

public:
    StopWatchModel();

    void restartStopWatch();
    std::string getTime() const;
    void timeTick();
};

#endif 
