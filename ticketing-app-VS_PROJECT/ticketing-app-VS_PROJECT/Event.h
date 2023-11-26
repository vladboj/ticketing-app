#pragma once
#include "EventLocation.h"
#include "Date.h"
#include "Time.h"
#include <iostream>
#include <string>

class Event {
	// NORMAL ATTRIBUTES
	int id;
	char* name;
	EventLocation location;
	Date date;
	Time time;

	// STATIC ATTRIBUTES
	static Event* events;
	static int noEvents;

	static int NEXT_EVENT_ID;

	static const int MIN_NAME_LENGTH;
	static const int MAX_NAME_LENGTH;
public:
	// STATIC METHODS
	static void printEvents();
	static void addEvent(const Event& newEvent);
	static Event getEvent(int id);

	// CONSTRUCTORS
	Event();
	Event(const char* newName, EventLocation newLocation, Date newDate, Time newTime);
	Event(const Event& toBeCopied);

	// DESTRUCTOR
	~Event();

	// SETTERS
	void setName(const char* newName);
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
	char operator[](int index);	// return first letter of name
	int operator-(Event rightEvent);	// return how many hours are between the events
	Time operator++(int);	// return and post-increment time by 1 hour
	Time operator++();	// return and pre-increment time by 1 hour
	explicit operator int();	// return number of seconds of the time since midnight

	friend void operator>>(std::istream& console, Event& myEvent);
	friend void operator<<(std::ostream& console, const Event& myEvent);
};