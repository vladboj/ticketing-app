#pragma once
#include <iostream>

class Time {
	// NORMAL ATTRIBUTES
	int hour;
	int minute;
public:
	// CONSTRUCTORS
	Time();
	Time(int newHour, int newMinute);
	Time(const Time& toBeCopied);

	// SETTERS
	void setHour(int newHour);
	void setMinute(int newMinute);

	// GETTERS
	int getHour();
	int getMinute();

	// OPERATORS OVERLOADING
	void operator=(const Time& toBeCopied);

	friend void operator>>(std::istream& console, Time& myTime);
	friend void operator<<(std::ostream& console, const Time& myTime);
};