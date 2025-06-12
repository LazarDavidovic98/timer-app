#include "TimerModel.h"
#include <fstream>
#include <sstream>
#include <iomanip> 
#include "AlarmModel.h"

TimerModel::TimerModel() {
	restartTimer();
}

void TimerModel::restartTimer()
{
	setTime(loadTimeValue());
}

void TimerModel::setTime(const std::string& time)
{
	if (time.length() != 8 || time[2] != ':' || time[5] != ':')	return;

	hours = std::stoi(time.substr(0, 2));
	minutes = std::stoi(time.substr(3, 2));
	seconds = std::stoi(time.substr(6, 2));

	storeTimeValue(time);
}

std::string TimerModel::getTime() const {
	std::ostringstream oss;
	oss << std::setw(2) << std::setfill('0') << hours << ":"
		<< std::setw(2) << std::setfill('0') << minutes << ":"
		<< std::setw(2) << std::setfill('0') << seconds;
	return oss.str();
}


bool TimerModel::isTimeUp() const {
	return hours == 0 && minutes == 0 && seconds == 0;
}

void TimerModel::timeTick() {
	if (!isTimeUp()) {
		if (seconds > 0) {
			--seconds;
		}
		else if (minutes > 0) {
			--minutes;
			seconds = 59;
		}
		else {
			--hours;
			minutes = 59;
			seconds = 59;
		}
	}
}

void TimerModel::storeTimeValue(const std::string& time) {
	std::ofstream file("resources/properties.txt");
	if (file.is_open()) {
		file << time << std::endl;
		file.close();
	}
}

std::string TimerModel::loadTimeValue() {
	std::ifstream file("resources/properties.txt");
	std::string line = "00:00:00";
	if (file.is_open()) {
		std::getline(file, line);
		file.close();
	}
	return line;
}
