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
void operator>>(std::istream& console, Date& myDate) {
	std::cout << "Day: ";
	console >> myDate.day;
	std::cout << "Month: ";
	console >> myDate.month;
	std::cout << "Year: ";
	console >> myDate.year;
}

void operator<<(std::ostream& console, const Date& myDate) {
	console << (myDate.day < 10 ? "0" : "") << myDate.day << "/";
	console << (myDate.month < 10 ? "0" : "") << myDate.month << "/";
	console << myDate.year;
}