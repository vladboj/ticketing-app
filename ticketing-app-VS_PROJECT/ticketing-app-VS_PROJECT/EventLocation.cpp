#include "EventLocation.h"

EventLocation::EventLocation() : name(""), address(""), type(NONE) {}
EventLocation::EventLocation(std::string newName, std::string newAddress, LocationType newType) {
	this->setName(newName);
	this->setAddress(newAddress);
	this->setType(newType);
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
void EventLocation::setType(LocationType newType) {
	if (newType == NONE) {
		throw std::exception("Invalid location type");
	}
	this->type = newType;
}

std::string EventLocation::getName() {
	return this->name;
}
std::string EventLocation::getAddress() {
	return this->address;
}
LocationType EventLocation::getType() {
	return this->type;
}