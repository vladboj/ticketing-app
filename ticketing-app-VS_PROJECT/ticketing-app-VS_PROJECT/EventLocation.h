#pragma once
#include <string>
#include <iostream>

class EventLocation {
	// NORMAL ATTRIBUTES
	std::string name;
	std::string address;
	int noZones;
	int maxSeats;
	int* availableSeats;	// number of available seats for each zone
public:
	// CONSTRUCTORS
	EventLocation();
	EventLocation(std::string newName, std::string newAddress, int newNoZones, int newMaxSeats);
	EventLocation(const EventLocation& toBeCopied);

	// SETTERS
	void setName(std::string newName);
	void setAddress(std::string newAddress);
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

	friend void operator>>(std::istream& console, EventLocation& myEventLocation);
	friend void operator<<(std::ostream& console, const EventLocation& myEventLocation);
};