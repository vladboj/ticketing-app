#include "EventLocation.h"
#include <iostream>
#include <string>
#include <exception>

// STATIC ATTRIBUTES INITIALIZATIONS
const int EventLocation::MIN_NAME_LENGTH = 3;
const int EventLocation::MAX_NAME_LENGTH = 50;

const int EventLocation::MIN_ADDRESS_LENGTH = 5;
const int EventLocation::MAX_ADDRESS_LENGTH = 200;

// DEFAULT CONSTRUCTOR
EventLocation::EventLocation() : name(nullptr), address(nullptr) {}

// CONSTRUCTOR WITH ARGUMENTS
EventLocation::EventLocation(const char* newName, const char* newAddress) {
	this->setName(newName);
	this->setAddress(newAddress);
}

// COPY CONSTRUCTOR
EventLocation::EventLocation(const EventLocation& toBeCopied) {
	this->name = new char[strlen(toBeCopied.name) + 1];
	strcpy_s(this->name, strlen(toBeCopied.name) + 1, toBeCopied.name);
	this->address = new char[strlen(toBeCopied.address) + 1];
	strcpy_s(this->address, strlen(toBeCopied.address) + 1, toBeCopied.address);
}

// DESTRUCTOR
EventLocation::~EventLocation() {
	if (this->name != nullptr) {
		delete[] this->name;
	}
	if (this->address != nullptr) {
		delete[] this->address;
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

// GETTERS
std::string EventLocation::getName() {
	return std::string(this->name);
}
std::string EventLocation::getAddress() {
	return std::string(this->address);
}

// OPERATORS OVERLOADING
void EventLocation::operator=(const EventLocation& toBeCopied) {
	if (this == &toBeCopied) {
		return;
	}
	this->setName(toBeCopied.name);
	this->setAddress(toBeCopied.address);
}

char EventLocation::operator[](int index) {
	return this->name[index];
}

bool EventLocation::operator==(const EventLocation& rightEventLocation) {
	if (strcmp(this->name, rightEventLocation.name) != 0) return false;
	if (strcmp(this->address, rightEventLocation.address) != 0) return false;
	return true;
}

void operator>>(std::istream& console, EventLocation& myEventLocation) {
	while (true) {
		try {
			std::cout << "Name: ";
			char buffer1[EventLocation::MAX_NAME_LENGTH + 1];
			console.getline(buffer1, EventLocation::MAX_NAME_LENGTH + 1);
			myEventLocation.setName(buffer1);
			break;
		}
		catch (const std::exception& e) {
			std::cout << "!!! " << e.what() << " !!!\n";
		}
	}

	while (true) {
		try {
			std::cout << "Address: ";
			char buffer2[EventLocation::MAX_ADDRESS_LENGTH + 1];
			console.getline(buffer2, EventLocation::MAX_ADDRESS_LENGTH);
			myEventLocation.setAddress(buffer2);
			break;
		}
		catch (const std::exception& e) {
			std::cout << "!!! " << e.what() << " !!!\n";
		}
	}
}

void operator<<(std::ostream& console, const EventLocation& myEventLocation) {
	console << "\nName: " << myEventLocation.name;
	console << "\nAddress: " << myEventLocation.address;
}