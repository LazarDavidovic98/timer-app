#define _CRT_SECURE_NO_WARNINGS  // Ako želiš da ignorišeš warning (opciono)
#include "AlarmModel.h"
#include <chrono>
#include <iomanip>
#include <sstream>
#include <ctime>

AlarmModel::AlarmModel() : hours(0), minutes(0), seconds(0), enabled(false) {}

void AlarmModel::setAlarmTime(const std::string& time) {
    if (time.length() != 8 || time[2] != ':' || time[5] != ':') return;

    hours = std::stoi(time.substr(0, 2));
    minutes = std::stoi(time.substr(3, 2));
    seconds = std::stoi(time.substr(6, 2));
}

std::string AlarmModel::getAlarmTime() const {
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << hours << ":"
        << std::setw(2) << std::setfill('0') << minutes << ":"
        << std::setw(2) << std::setfill('0') << seconds;
    return oss.str();
}

std::string AlarmModel::getTime() const {
    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::tm localTime;
    localtime_s(&localTime, &now);  // sigurna verzija

    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << localTime.tm_hour << ":"
        << std::setw(2) << std::setfill('0') << localTime.tm_min << ":"
        << std::setw(2) << std::setfill('0') << localTime.tm_sec;
    return oss.str();
}

bool AlarmModel::isTimeUp() const {
    if (!enabled) return false;

    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::tm localTime;
    localtime_s(&localTime, &now);  // sigurna verzija

    return hours == localTime.tm_hour &&
        minutes == localTime.tm_min &&
        seconds == localTime.tm_sec;
}

void AlarmModel::enable() {
    enabled = true;
}

void AlarmModel::disable() {
    enabled = false;
}
