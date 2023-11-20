#include "Time.h"
#include <iostream>

Time::Time() : hour(0), minute(0) {}
Time::Time(int newHour, int newMinute) {
	this->setHour(newHour);
	this->setMinute(newMinute);
}
Time::Time(const Time& toBeCopied) {
	this->hour = toBeCopied.hour;
	this->minute = toBeCopied.minute;
}

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

int Time::getHour() {
	return this->hour;
}

int Time::getMinute() {
	return this->minute;
}

void operator>>(std::istream& console, Time& myTime) {
	std::cout << "Hour: ";
	console >> myTime.hour;
	std::cout << "Minute: ";
	console >> myTime.minute;
}