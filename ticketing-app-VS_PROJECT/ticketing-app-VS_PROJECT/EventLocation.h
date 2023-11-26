#pragma once
#include <iostream>
#include <string>

class EventLocation {
	// NORMAL ATTRIBUTES
	char* name;
	char* address;
	int noZones;
	int maxSeats;
	int* availableSeats;	// number of available seats for each zone
public:
	// CONSTRUCTORS
	EventLocation();
	EventLocation(const char* newName, const char* newAddress, int newNoZones, int newMaxSeats);
	EventLocation(const EventLocation& toBeCopied);

	// DESTRUCTOR
	~EventLocation();

	// SETTERS
	void setName(const char* newName);
	void setAddress(const char* newAddress);
	void setNoZones(int newNoZones);
	void setMaxSeats(int newMaxSeats);

	// GETTERS
	std::string getName();
	std::string getAddress();
	int getNoZones();
	int getMaxSeats();
	//int* getAvailableSeats();

	//OPERATORS OVERLOADING
	void operator=(const EventLocation& toBeCopied);
	char operator[](int index);	// return first letter of name

	friend void operator>>(std::istream& console, EventLocation& myEventLocation);
	friend void operator<<(std::ostream& console, const EventLocation& myEventLocation);
};