#include "EventLocation.h"
#include <iostream>
#include <string>
#include <exception>

// DEFAULT CONSTRUCTOR
EventLocation::EventLocation() : name(""), address(""), noZones(0), maxSeats(0), availableSeats(nullptr) {}

// CONSTRUCTOR WITH ARGUMENTS
EventLocation::EventLocation(std::string newName, std::string newAddress, int newNoZones, int newMaxSeats) {
	this->setName(newName);
	this->setAddress(newAddress);
	this->setNoZones(newNoZones);
	this->setMaxSeats(newMaxSeats);
}

// COPY CONSTRUCTOR
EventLocation::EventLocation(const EventLocation& toBeCopied) {
	this->name = toBeCopied.name;
	this->address = toBeCopied.address;
	this->noZones = toBeCopied.noZones;
	this->maxSeats = toBeCopied.maxSeats;
	
	// available seats
	int* temp = new int[this->noZones];
	for (int i = 0; i < this->noZones; i++) {
		temp[i] = toBeCopied.availableSeats[i];
	}
	if (this->availableSeats != nullptr) {
		delete[] this->availableSeats;
	}
	this->availableSeats = temp;
}

// SETTERS
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

void EventLocation::setNoZones(int newNoZones) {
	this->noZones = newNoZones;
}

void EventLocation::setMaxSeats(int newMaxSeats) {
	this->maxSeats = newMaxSeats;

	// available seats
	this->availableSeats = new int[this->noZones];
	for (int i = 0; i < this->noZones; i++) {
		this->availableSeats[i] = this->maxSeats / this->noZones;
	}
}

// GETTERS
std::string EventLocation::getName() {
	return this->name;
}
std::string EventLocation::getAddress() {
	return this->address;
}

int EventLocation::getNoZones() {
	return this->noZones;
}

int EventLocation::getMaxSeats() {
	return this->maxSeats;
}

// OPERATORS OVERLOADING
void EventLocation::operator=(const EventLocation& toBeCopied) {
	this->name = toBeCopied.name;
	this->address = toBeCopied.address;
	this->noZones = toBeCopied.noZones;
	this->maxSeats = toBeCopied.maxSeats;

	// available seats
	int* temp = new int[this->noZones];
	for (int i = 0; i < this->noZones; i++) {
		temp[i] = toBeCopied.availableSeats[i];
	}
	if (this->availableSeats != nullptr) {
		delete[] this->availableSeats;
	}
	this->availableSeats = temp;
}

void operator>>(std::istream& console, EventLocation& myEventLocation) {
	std::cout << "Name: ";
	std::getline(console, myEventLocation.name);
	std::cout << "Address: ";
	std::getline(console, myEventLocation.address);
	std::cout << "Number of zones: ";
	console >> myEventLocation.noZones;
	std::cout << "Number of total available seats: ";
	console >> myEventLocation.maxSeats;
	myEventLocation.availableSeats = new int[myEventLocation.noZones];
	for (int i = 0; i < myEventLocation.noZones; i++) {
		myEventLocation.availableSeats[i] = myEventLocation.maxSeats / myEventLocation.noZones;
	}
}

void operator<<(std::ostream& console, const EventLocation& myEventLocation) {
	console << "\nName: " << myEventLocation.name;
	console << "\nAddress: " << myEventLocation.address;
	console << "\nNumber of zones: " << myEventLocation.noZones;
	console << "\nNumber of total available seats: " << myEventLocation.maxSeats;
	for (int i = 0; i < myEventLocation.noZones; i++) {
		console << "\nNumber of available seats for zone " << i + 1 << ": " << myEventLocation.availableSeats[i];
	}
}