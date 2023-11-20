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

	friend void operator>>(std::istream& console, Time& myTime);
};