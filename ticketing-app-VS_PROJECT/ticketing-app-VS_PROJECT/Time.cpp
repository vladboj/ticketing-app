#include "Time.h"
#include <iostream>

// DEFAULT CONSTRUCTOR
Time::Time() : hour(0), minute(0) {}

// CONSTRUCTOR WITH ARGUMENTS
Time::Time(int newHour, int newMinute) {
	this->setHour(newHour);
	this->setMinute(newMinute);
}

// SETTERS
void Time::setHour(int newHour) {
	if (newHour < 0 || newHour > 23) {
		throw std::exception("Invalid minute value");
	}
	this->hour = newHour;
}

void Time::setMinute(int newMinute) {
	if (newMinute < 0 || newMinute > 59) {
		throw std::exception("Invalid minute value");
	}
	this->minute = newMinute;
}

// GETTERS
int Time::getHour() {
	return this->hour;
}

int Time::getMinute() {
	return this->minute;
}

// OPERATORS OVERLOADING
void operator>>(std::istream& console, Time& myTime) {
	std::cout << "\nHour: ";
	console >> myTime.hour;
	std::cout << "\nMinute: ";
	console >> myTime.minute;
}

void operator<<(std::ostream& console, const Time& myTime) {
	console << myTime.hour << ":" << myTime.minute;
}