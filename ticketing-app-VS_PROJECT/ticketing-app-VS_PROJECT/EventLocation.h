#pragma once
#include <iostream>
#include <string>

class EventLocation {
	// NORMAL ATTRIBUTES
	char* name;
	char* address;
	int noZones;
	int availableSeats;
	int* availableSeatsPerZone;
	
	// STATIC ATTRIBUTES
	static const int MIN_NAME_LENGTH;
	static const int MAX_NAME_LENGTH;

	static const int MIN_ADDRESS_LENGTH;
	static const int MAX_ADDRESS_LENGTH;
public:
	// CONSTRUCTORS
	EventLocation();
	EventLocation(const char* newName, const char* newAddress, int newNoZones, int newAvailableSeats);
	EventLocation(const EventLocation& toBeCopied);

	// DESTRUCTOR
	~EventLocation();

	// SETTERS
	void setName(const char* newName);
	void setAddress(const char* newAddress);
	void setNoZones(int newNoZones);
	void setAvailableSeats(int newAvailableSeats);

	// GETTERS
	std::string getName();
	std::string getAddress();
	int getNoZones();
	int getAvailableSeats();
	//int* getAvailableSeatsPerZone();

	//OPERATORS OVERLOADING
	void operator=(const EventLocation& toBeCopied);
	char operator[](int index);	// return first letter of name
	int operator+(EventLocation rightEventLocation);	// return total number of available seats

	friend void operator>>(std::istream& console, EventLocation& myEventLocation);
	friend void operator<<(std::ostream& console, const EventLocation& myEventLocation);
};