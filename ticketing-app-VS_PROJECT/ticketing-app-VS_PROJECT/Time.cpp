#include "Time.h"
#include <iostream>

Time::Time() : hour(0), minute(0) {}

Time::Time(int newHour, int newMinute) {
	this->setHour(newHour);
	this->setMinute(newMinute);
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