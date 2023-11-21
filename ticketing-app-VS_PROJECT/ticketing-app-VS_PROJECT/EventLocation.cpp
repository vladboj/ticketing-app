#include "EventLocation.h"
#include <string>
#include <iostream>

EventLocation::EventLocation() : name(""), address("") {}
EventLocation::EventLocation(std::string newName, std::string newAddress) {
	this->setName(newName);
	this->setAddress(newAddress);
}
EventLocation::EventLocation(const EventLocation& toBeCopied) {
	this->name = toBeCopied.name;
	this->address = toBeCopied.address;
}

void EventLocation::setName(std::string newName) {
	if (newName.empty() || newName.length() > 50) {
		throw std::exception("Invalid name length");
	}
	this->name = newName;
}
void EventLocation::setAddress(std::string newAddress) {
	if (newAddress.empty() || newAddress.length() > 50) {
		throw std::exception("Invalid address length");
	}
	this->address = newAddress;
}

std::string EventLocation::getName() {
	return this->name;
}
std::string EventLocation::getAddress() {
	return this->address;
}

void EventLocation::operator=(const EventLocation& toBeCopied) {
	this->name = toBeCopied.name;
	this->address = toBeCopied.address;
}

void operator>>(std::istream& console, EventLocation& myEventLocation) {
	std::cout << "\nName: ";
	std::getline(console, myEventLocation.name);
	std::cout << "\nAddress: ";
	std::getline(console, myEventLocation.address);
}

void operator<<(std::ostream& console, const EventLocation& myEventLocation) {
	console << "\nName: " << myEventLocation.name;
	console << "\nAddress: " << myEventLocation.address;
}