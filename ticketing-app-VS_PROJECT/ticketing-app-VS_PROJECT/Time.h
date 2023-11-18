#pragma once

class Time {
	int hour;
	int minute;
public:
	Time();
	Time(int newHour, int newMinute);

	void setHour(int newHour);
	void setMinute(int newMinute);

	int getHour();
	int getMinute();
};