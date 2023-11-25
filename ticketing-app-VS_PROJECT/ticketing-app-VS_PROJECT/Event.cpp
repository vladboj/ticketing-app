#include "Event.h"
#include "EventLocation.h"
#include "Date.h"
#include "Time.h"
#include <iostream>
#include <string>
#include <exception>

// STATIC ATTRIBUTES INITIALIZATIONS
Event* Event::events = nullptr;
int Event::noEvents = 0;

int Event::NEXT_EVENT_ID = 1;

int Event::MIN_NAME_LENGTH = 3;
int Event::MAX_NAME_LENGTH = 40;

// STATIC METHODS
void Event::printEvents() {
	std::cout << "\n__________________________________PRINTING ALL EVENTS +++START+++\n";
	for (int i = 0; i < Event::noEvents; i++) {
		std::cout << events[i];
	}
	std::cout << "\n__________________________________PRINTING ALL EVENTS +++END+++\n";
}

void Event::addEvent(const Event& newEvent) {
	Event::noEvents++;
	Event* temp = new Event[noEvents];
	for (int i = 0; i < Event::noEvents - 1; i++) {
		temp[i] = Event::events[i];
	}
	temp[Event::noEvents - 1] = newEvent;
	if (Event::events != nullptr) {
		delete[] Event::events;
	}
	Event::events = temp;
	Event::NEXT_EVENT_ID++;
}

Event Event::getEvent(int id) {
	return Event::events[id - 1];
}

// DEFAULT CONSTRUCTOR
Event::Event() : id(Event::NEXT_EVENT_ID), name(""), location(EventLocation::EventLocation()),
date(Date::Date()), time(Time::Time()) {}

// CONSTRUCTOR WITH ARGUMENTS
Event::Event(std::string newName, EventLocation newLocation, Date newDate, Time newTime) : id(Event::NEXT_EVENT_ID) {
	this->setName(newName);
	this->setLocation(newLocation);
	this->setDate(newDate);
	this->setTime(newTime);
}

// COPY CONSTRUCTOR
Event::Event(const Event& toBeCopied) {
	this->id = toBeCopied.id;
	this->name = toBeCopied.name;
	this->location = toBeCopied.location;
	this->date = toBeCopied.date;
	this->time = toBeCopied.time;
}

// SETTERS
void Event::setName(std::string newName) {
	if (newName.length() < Event::MIN_NAME_LENGTH || newName.length() > Event::MAX_NAME_LENGTH) {
		throw std::exception("Invalid name length");
	}
	this->name = newName;
}
void Event::setLocation(EventLocation newLocation) {
	this->location = newLocation;
}
void Event::setDate(Date newDate) {
	this->date = newDate;
}
void Event::setTime(Time newTime) {
	this->time = newTime;
}

// GETTERS
int Event::getEventId() {
	return this->id;
}

std::string Event::getName() {
	return this->name;
}
EventLocation Event::getLocation() {
	return this->location;
}
Date Event::getDate() {
	return this->date;
}
Time Event::getTime() {
	return this->time;
}

// OPERATORS OVERLOADING
void Event::operator=(const Event& toBeCopied) {
	this->id = toBeCopied.id;
	this->name = toBeCopied.name;
	this->location = toBeCopied.location;
	this->date = toBeCopied.date;
	this->time = toBeCopied.time;
}

void operator>>(std::istream& console, Event& myEvent) {
	std::cout << "\n------------------ INPUT EVENT " << myEvent.id << " ------------------\n";
	std::cout << "Name: ";
	console.ignore();
	std::getline(console, myEvent.name);
	std::cout << "\nLocation\n";
	console >> myEvent.location;
	std::cout << "\nDate\n";
	console >> myEvent.date;
	std::cout << "\nTime\n";
	console >> myEvent.time;
	std::cout << "---------------------------------------------------\n";
}

void operator<<(std::ostream& console, const Event& myEvent) {
	console << "\n------------------ EVENT " << myEvent.id << " ------------------\n";
	console << "Name: " << myEvent.name;
	console << "\n\nLocation" << myEvent.location;
	console << "\n\nDate: " << myEvent.date;
	console << "\n\nTime: " << myEvent.time;
	console << "\n---------------------------------------------\n";
}