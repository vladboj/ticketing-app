#include "EventLocation.h"
#include <iostream>
#include <string>
#include <exception>

// STATIC ATTRIBUTES INITIALIZATIONS
const int EventLocation::MIN_NAME_LENGTH = 3;
const int EventLocation::MAX_NAME_LENGTH = 50;

const int EventLocation::MIN_ADDRESS_LENGTH = 10;
const int EventLocation::MAX_ADDRESS_LENGTH = 200;

// DEFAULT CONSTRUCTOR
EventLocation::EventLocation() : name(nullptr), address(nullptr), noZones(0), availableSeats(0), availableSeatsPerZone(nullptr) {}

// CONSTRUCTOR WITH ARGUMENTS
EventLocation::EventLocation(const char* newName, const char* newAddress, int newNoZones, int newAvailableSeats) {
	this->setName(newName);
	this->setAddress(newAddress);
	this->setNoZones(newNoZones);
	this->setAvailableSeats(newAvailableSeats);
}

// COPY CONSTRUCTOR
EventLocation::EventLocation(const EventLocation& toBeCopied) {
	this->name = new char[strlen(toBeCopied.name) + 1];
	strcpy_s(this->name, strlen(toBeCopied.name) + 1, toBeCopied.name);
	this->address = new char[strlen(toBeCopied.address) + 1];
	strcpy_s(this->address, strlen(toBeCopied.address) + 1, toBeCopied.address);
	this->setNoZones(toBeCopied.noZones);
	this->setAvailableSeats(toBeCopied.availableSeats);

	// available seats
	int* temp = new int[this->noZones];
	for (int i = 0; i < this->noZones; i++) {
		temp[i] = toBeCopied.availableSeatsPerZone[i];
	}
	if (this->availableSeatsPerZone != nullptr) {
		delete[] this->availableSeatsPerZone;
	}
	this->availableSeatsPerZone = temp;
}

// DESTRUCTOR
EventLocation::~EventLocation() {
	if (this->name != nullptr) {
		delete[] this->name;
	}
	if (this->address != nullptr) {
		delete[] this->address;
	}
	if (this->availableSeatsPerZone != nullptr) {
		delete[] this->availableSeatsPerZone;
	}
}

// SETTERS
void EventLocation::setName(const char* newName) {
	if (strlen(newName) < EventLocation::MIN_NAME_LENGTH || strlen(newName) > EventLocation::MAX_NAME_LENGTH) {
		throw std::exception("Invalid name length");
	}
	char* temp = new char[strlen(newName) + 1];
	strcpy_s(temp, strlen(newName) + 1, newName);
	if (this->name != nullptr) {
		delete[] this->name;
	}
	this->name = temp;
}

void EventLocation::setAddress(const char* newAddress) {
	if (strlen(newAddress) < EventLocation::MIN_ADDRESS_LENGTH || strlen(newAddress) > EventLocation::MAX_ADDRESS_LENGTH) {
		throw std::exception("Invalid address length");
	}
	char* temp = new char[strlen(newAddress) + 1];
	strcpy_s(temp, strlen(newAddress) + 1, newAddress);
	if (this->address != nullptr) {
		delete[] this->address;
	}
	this->address = temp;
}

void EventLocation::setNoZones(int newNoZones) {
	this->noZones = newNoZones;
}

void EventLocation::setAvailableSeats(int newMaxSeats) {
	this->availableSeats = newMaxSeats;

	// available seats
	this->availableSeatsPerZone = new int[this->noZones];
	for (int i = 0; i < this->noZones; i++) {
		this->availableSeatsPerZone[i] = this->availableSeats / this->noZones;
	}
}

// GETTERS
std::string EventLocation::getName() {
	return std::string(this->name);
}
std::string EventLocation::getAddress() {
	return std::string(this->address);
}

int EventLocation::getNoZones() {
	return this->noZones;
}

int EventLocation::getAvailableSeats() {
	return this->availableSeats;
}

// OPERATORS OVERLOADING
void EventLocation::operator=(const EventLocation& toBeCopied) {
	if (this == &toBeCopied) {
		return;
	}
	this->setName(toBeCopied.name);
	this->setAddress(toBeCopied.address);
	this->setNoZones(toBeCopied.noZones);
	this->setAvailableSeats(toBeCopied.availableSeats);

	// available seats
	int* temp = new int[this->noZones];
	for (int i = 0; i < this->noZones; i++) {
		temp[i] = toBeCopied.availableSeatsPerZone[i];
	}
	if (this->availableSeatsPerZone != nullptr) {
		delete[] this->availableSeatsPerZone;
	}
	this->availableSeatsPerZone = temp;
}

char EventLocation::operator[](int index) {
	return this->name[index];
}

int EventLocation::operator+(EventLocation rightEventLocation) {
	return this->availableSeats + rightEventLocation.availableSeats;
}

EventLocation EventLocation::operator--(int) {
	EventLocation copy = *this;
	this->availableSeats--;
	return copy;
}

EventLocation EventLocation::operator--() {
	this->availableSeats--;
	return *this;
}

bool EventLocation::operator==(const EventLocation& rightEventLocation) {
	if (strcmp(this->name, rightEventLocation.name) != 0) return false;
	if (strcmp(this->address, rightEventLocation.address) != 0) return false;
	if (this->noZones != rightEventLocation.noZones) return false;
	if (this->availableSeats != rightEventLocation.availableSeats) return false;
	return true;
}

void operator>>(std::istream& console, EventLocation& myEventLocation) {
	// name
	std::cout << "Name: ";
	char buffer1[EventLocation::MAX_NAME_LENGTH + 1];
	console.getline(buffer1, EventLocation::MAX_NAME_LENGTH + 1);
	myEventLocation.setName(buffer1);

	// address
	std::cout << "Address: ";
	char buffer2[EventLocation::MAX_ADDRESS_LENGTH + 1];
	console.getline(buffer2, EventLocation::MAX_ADDRESS_LENGTH);
	myEventLocation.setAddress(buffer2);

	// number of zones
	std::cout << "Number of zones: ";
	console >> myEventLocation.noZones;
	
	// max number of seats
	std::cout << "Number of total available seats: ";
	console >> myEventLocation.availableSeats;
	myEventLocation.availableSeatsPerZone = new int[myEventLocation.noZones];
	for (int i = 0; i < myEventLocation.noZones; i++) {
		myEventLocation.availableSeatsPerZone[i] = myEventLocation.availableSeats / myEventLocation.noZones;
	}
}

void operator<<(std::ostream& console, const EventLocation& myEventLocation) {
	console << "\nName: " << myEventLocation.name;
	console << "\nAddress: " << myEventLocation.address;
	console << "\nNumber of zones: " << myEventLocation.noZones;
	console << "\nNumber of total available seats: " << myEventLocation.availableSeats;
	for (int i = 0; i < myEventLocation.noZones; i++) {
		console << "\nNumber of available seats for zone " << i + 1 << ": " << myEventLocation.availableSeatsPerZone[i];
	}
}