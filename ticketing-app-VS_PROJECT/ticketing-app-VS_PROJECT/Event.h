#pragma once
#include "EventLocation.h"
#include "Date.h"
#include "Time.h"
#include <string>

class Event {
	std::string name;
	EventLocation location;
	Date date;
	Time time;

	static int MIN_NAME_LENGTH;
	static int MAX_NAME_LENGTH;
public:
	Event();
	Event(std::string newName, EventLocation newLocation, Date newDate, Time newTime);

	void setName(std::string newName);
	void setLocation(EventLocation newLocation);
	void setDate(Date newDate);
	void setTime(Time newTime);

	std::string getName();
	EventLocation getLocation();
	Date getDate();
	Time getTime();
};