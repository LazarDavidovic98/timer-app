#ifndef TIMERMODEL_H
#define TIMERMODEL_H 

#include <string>

class TimerModel {
private:

	int hours;
	int minutes;
	int seconds;

	void storeTimeValue(const std::string& time);
	std::string loadTimeValue();

public:

	TimerModel();

	void restartTimer();
	void setTime(const std::string& time);
	std::string getTime() const;
	bool isTimeUp() const;
	void timeTick();

};

#endif
