#include "EventLocation.h"
#include "Date.h"
#include "Time.h"
#include "Event.h"
#include <string>
#include <iostream>

int Event::MIN_NAME_LENGTH = 3;
int Event::MAX_NAME_LENGTH = 40;

Event::Event() : name(""), location(EventLocation()), date(Date()), time(Time()) {}
Event::Event(std::string newName, EventLocation newLocation, Date newDate, Time newTime) {
	this->setName(newName);
	this->setLocation(newLocation);
	this->setDate(newDate);
	this->setTime(newTime);
}
Event::Event(const Event& toBeCopied) {
	this->name = toBeCopied.name;
	this->location = toBeCopied.location;
	this->date = toBeCopied.date;
	this->time = toBeCopied.time;
}

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

void Event::operator=(const Event& toBeCopied) {
	this->name = toBeCopied.name;
	this->location = toBeCopied.location;
	this->date = toBeCopied.date;
	this->time = toBeCopied.time;
}

void operator>>(std::istream& console, Event& myEvent) {
	std::cout << "\nName: ";
	console.ignore();
	std::getline(console, myEvent.name);
	std::cout << "\nLocation:";
	console >> myEvent.location;
	std::cout << "\nDate: ";
	console >> myEvent.date;
	std::cout << "\nTime: ";
	console >> myEvent.time;
}

void operator<<(std::ostream& console, const Event& myEvent) {
	console << "\nName: " << myEvent.name;
	console << "\nLocation:" << myEvent.location;
	console << "\nDate: " << myEvent.date;
	console << "\nTime: " << myEvent.time;
}