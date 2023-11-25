#pragma once
#include "EventLocation.h"
#include "Date.h"
#include "Time.h"
#include <iostream>
#include <string>

class Event {
	// NORMAL ATTRIBUTES
	int id;
	std::string name;
	EventLocation location;
	Date date;
	Time time;

	// STATIC ATTRIBUTES
	static Event* events;
	static int noEvents;

	static int NEXT_EVENT_ID;

	static int MIN_NAME_LENGTH;
	static int MAX_NAME_LENGTH;
public:
	// STATIC METHODS
	static void printEvents();
	static void addEvent(const Event& newEvent);
	static Event getEvent(int id);

	// CONSTRUCTORS
	Event();
	Event(std::string newName, EventLocation newLocation, Date newDate, Time newTime);
	Event(const Event& toBeCopied);

	// SETTERS
	void setName(std::string newName);
	void setLocation(EventLocation newLocation);
	void setDate(Date newDate);
	void setTime(Time newTime);

	// GETTERS
	int getEventId();
	std::string getName();
	EventLocation getLocation();
	Date getDate();
	Time getTime();

	// OPERATORS OVERLOADING
	void operator=(const Event& toBeCopied);

	friend void operator>>(std::istream& console, Event& myEvent);
	friend void operator<<(std::ostream& console, const Event& myEvent);
};