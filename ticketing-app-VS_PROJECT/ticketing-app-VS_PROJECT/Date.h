#pragma once
#include <iostream>

class Date {
	// NORMAL ATTRIBUTES
	int day;
	int month;
	int year;
public:
	// CONSTRUCTORS
	Date();
	Date(int newDay, int newMonth, int newYear);
	Date(const Date& toBeCopied);

	// SETTERS
	void setDay(int newDay);
	void setMonth(int newMonth);
	void setYear(int newYear);

	// GETTERS
	int getDay();
	int getMonth();
	int getYear();

	// OPERATORS OVERLOADING
	void operator=(const Date& toBeCopied);

	friend void operator>>(std::istream& console, Date& myDate);
	friend void operator<<(std::ostream& console, const Date& myDate);
};