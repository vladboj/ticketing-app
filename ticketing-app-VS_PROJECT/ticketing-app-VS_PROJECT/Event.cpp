#include "Event.h"

int Event::MIN_NAME_LENGTH = 3;
int Event::MAX_NAME_LENGTH = 40;

Event::Event() : name(""), location(EventLocation()), date(Date()), time(Time()) {}
Event::Event(std::string newName, EventLocation newLocation, Date newDate, Time newTime) {
	this->setName(newName);
	this->setLocation(newLocation);
	this->setDate(newDate);
	this->setTime(newTime);
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