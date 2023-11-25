#pragma once
#include <iostream>

class Time {
	int hour;
	int minute;
public:
	// CONSTRUCTORS
	Time();
	Time(int newHour, int newMinute);

	// SETTERS
	void setHour(int newHour);
	void setMinute(int newMinute);

	// GETTERS
	int getHour();
	int getMinute();

	// OPERATORS OVERLOADING
	friend void operator>>(std::istream& console, Time& myTime);
	friend void operator<<(std::ostream& console, const Time& myTime);
};