#include "Date.h"
#include <iostream>

Date::Date() : day(1), month(1), year(1970) {}
Date::Date(int newDay, int newMonth, int newYear) {
	this->setDay(newDay);
	this->setMonth(newMonth);
	this->setYear(newYear);
}
Date::Date(const Date& toBeCopied) {
	this->day = toBeCopied.day;
	this->month = toBeCopied.month;
	this->year = toBeCopied.year;
}

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

int Date::getDay() {
	return this->day;
}

int Date::getMonth() {
	return this->month;
}

int Date::getYear() {
	return this->year;
}

void operator>>(std::istream& console, Date& myDate) {
	std::cout << "Day: ";
	console >> myDate.day;
	std::cout << "Month: ";
	console >> myDate.month;
	std::cout << "Year: ";
	console >> myDate.year;
}