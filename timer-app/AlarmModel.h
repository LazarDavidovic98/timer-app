#ifndef ALARMMODEL_H
#define ALARMMODEL_H

#include <string>

class AlarmModel {
private:
	int hours;
	int minutes;
	int seconds;
	bool enabled;

public:
	AlarmModel();

	void setAlarmTime(const std::string& time);
	std::string getAlarmTime() const;
	std::string getTime() const;
	bool isTimeUp() const;

	void enable();
	void disable();
};

#endif