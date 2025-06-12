// StopWatchModel.cpp
#include "StopWatchModel.h"
#include <iomanip>
#include <sstream>

StopWatchModel::StopWatchModel() {
    restartStopWatch();
}

void StopWatchModel::restartStopWatch() {
    minutes = 0;
    seconds = 0;
    milliseconds = 0;
}

std::string StopWatchModel::getTime() const {
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << minutes << ":"
        << std::setw(2) << std::setfill('0') << seconds << ":"
        << std::setw(2) << std::setfill('0') << milliseconds;
    return oss.str();
}

void StopWatchModel::timeTick() {
    if (milliseconds < 99) {
        milliseconds++;
    }
    else if (seconds < 59) {
        seconds++;
        milliseconds = 0;
    }
    else if (minutes < 59) {
        minutes++;
        seconds = 0;
        milliseconds = 0;
    }
    else {
        minutes = 0;
        seconds = 0;
        milliseconds = 0;
    }
}
