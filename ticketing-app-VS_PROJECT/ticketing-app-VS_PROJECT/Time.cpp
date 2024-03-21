#include "Time.h"
#include <iostream>
#include <exception>

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
		throw std::exception("Invalid hour value");
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
bool Time::operator==(const Time& rightTime) {
	if (this->hour != rightTime.hour) return false;
	if (this->minute != rightTime.minute) return false;
	return true;
}

void operator>>(std::istream& console, Time& myTime) {
	std::cout << "(24-hour clock format)\n";
	while (true) {
		try {
			int hour;
			std::cout << "Hour: ";
			console >> hour;
			myTime.setHour(hour);
			break;
		}
		catch (const std::exception& e) {
			std::cout << "!!! " << e.what() << " !!!\n";
		}
	}
	while (true) {
		try {
			int minute;
			std::cout << "Minute: ";
			console >> minute;
			myTime.setMinute(minute);
			break;
		}
		catch (const std::exception& e) {
			std::cout << "!!! " << e.what() << " !!!\n";
		}
	}
}

void operator<<(std::ostream& console, const Time& myTime) {
	console << (myTime.hour < 10 ? "0" : "") << myTime.hour << ":";
	console << (myTime.minute < 10 ? "0" : "") << myTime.minute;
}