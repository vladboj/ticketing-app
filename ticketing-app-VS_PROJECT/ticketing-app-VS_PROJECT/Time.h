#pragma once
#include <iostream>

class Time {
	int hour;
	int minute;
public:
	Time();
	Time(int newHour, int newMinute);
	Time(const Time& toBeCopied);

	void setHour(int newHour);
	void setMinute(int newMinute);

	int getHour();
	int getMinute();

	void operator=(const Time& toBeCopied);

	friend void operator>>(std::istream& console, Time& myTime);
	friend void operator<<(std::ostream& console, const Time& myTime);
};