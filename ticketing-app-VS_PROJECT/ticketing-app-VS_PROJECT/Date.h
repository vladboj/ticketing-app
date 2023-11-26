#pragma once
#include <iostream>

class Date {
	int day;
	int month;
	int year;
public:
	// CONSTRUCTORS
	Date();
	Date(int newDay, int newMonth, int newYear);

	// SETTERS
	void setDay(int newDay);
	void setMonth(int newMonth);
	void setYear(int newYear);

	// GETTERS
	int getDay();
	int getMonth();
	int getYear();

	// OPERATORS OVERLOADING
	bool operator==(const Date& rightDate);
	
	friend void operator>>(std::istream& console, Date& myDate);
	friend void operator<<(std::ostream& console, const Date& myDate);
};