#pragma once
#include <iostream>

class Date {
	int day;
	int month;
	int year;
public:
	Date();
	Date(int newDay, int newMonth, int newYear);
	Date(const Date& toBeCopied);

	void setDay(int newDay);
	void setMonth(int newMonth);
	void setYear(int newYear);

	int getDay();
	int getMonth();
	int getYear();

	friend void operator>>(std::istream& console, Date& myDate);
};