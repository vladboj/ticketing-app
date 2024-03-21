#include "Date.h"
#include <iostream>
#include <exception>

// DEFAULT CONSTRUCTOR
Date::Date() : day(1), month(1), year(1970) {}

// CONSTRUCTOR WITH ARGUMENTS
Date::Date(int newDay, int newMonth, int newYear) {
	this->setDay(newDay);
	this->setMonth(newMonth);
	this->setYear(newYear);
}

// SETTERS
void Date::setDay(int newDay) {
	if (newDay < 1 || newDay > 31) {
		throw std::exception("Invalid day value");
	}
	this->day = newDay;
}

void Date::setMonth(int newMonth) {
	if (newMonth < 1 || newMonth > 12) {
		throw std::exception("Invalid month value");
	}
	this->month = newMonth;
}

void Date::setYear(int newYear) {
	if (newYear < 2023 || newYear > 2025) {
		throw std::exception("Invalid year value");
	}
	this->year = newYear;
}

// GETTERS
int Date::getDay() {
	return this->day;
}

int Date::getMonth() {
	return this->month;
}

int Date::getYear() {
	return this->year;
}

// OPERATORS OVERLOADING
bool Date::operator==(const Date& rightDate) {
	if (this->day != rightDate.day) return false;
	if (this->month != rightDate.month) return false;
	if (this->year != rightDate.year) return false;
	return true;
}

void operator>>(std::istream& console, Date& myDate) {
	while (true) {
		try {
			std::cout << "Day: ";
			int day;
			console >> day;
			myDate.setDay(day);
			break;
		}
		catch (const std::exception& e) {
			std::cout << "!!! " << e.what() << " !!!\n";
		}
	}
	while (true) {
		try {
			std::cout << "Month: ";
			int month;
			console >> month;
			myDate.setMonth(month);
			break;
		}
		catch (const std::exception& e) {
			std::cout << "!!! " << e.what() << " !!!\n";
		}
	}
	while (true) {
		try {
			int year;
			std::cout << "Year: ";
			console >> year;
			myDate.setYear(year);
			break;
		}
		catch (const std::exception& e) {
			std::cout << "!!! " << e.what() << " !!!\n";
		}
	}
}

void operator<<(std::ostream& console, const Date& myDate) {
	console << (myDate.day < 10 ? "0" : "") << myDate.day << "/";
	console << (myDate.month < 10 ? "0" : "") << myDate.month << "/";
	console << myDate.year;
}