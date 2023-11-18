#pragma once
#include <iostream>

class Date {
	int day;
	int month;
	int year;
public:
	Date();
	Date(int newDay, int newMonth, int newYear);

	void setDay(int newDay);
	void setMonth(int newMonth);
	void setYear(int newYear);

	int getDay();
	int getMonth();
	int getYear();
};