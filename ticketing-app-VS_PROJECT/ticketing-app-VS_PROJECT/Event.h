#pragma once
#include "EventLocation.h"
#include "Date.h"
#include "Time.h"
#include <string>
#include <iostream>

class Event {
	int id;
	std::string name;
	EventLocation location;
	Date date;
	Time time;

	static Event* events;
	static int noEvents;

	static int NEXT_EVENT_ID;

	static int MIN_NAME_LENGTH;
	static int MAX_NAME_LENGTH;
public:
	static void printEvents();
	static void addEvent(const Event& newEvent);

	Event();
	Event(std::string newName, EventLocation newLocation, Date newDate, Time newTime);
	Event(const Event& toBeCopied);

	void setName(std::string newName);
	void setLocation(EventLocation newLocation);
	void setDate(Date newDate);
	void setTime(Time newTime);

	int getEventId();
	std::string getName();
	EventLocation getLocation();
	Date getDate();
	Time getTime();

	void operator=(const Event& toBeCopied);

	friend void operator>>(std::istream& console, Event& myEvent);
	friend void operator<<(std::ostream& console, const Event& myEvent);
};