#pragma once
#include <string>
#include <iostream>

enum LocationType {NONE, theater, stadium, standingVenue};

class EventLocation {
	std::string name;
	std::string address;
	LocationType type;
public:
	EventLocation();
	EventLocation(std::string newName, std::string newAddress, LocationType newType);
	EventLocation(const EventLocation& toBeCopied);

	void setName(std::string newName);
	void setAddress(std::string newAddress);
	void setType(LocationType newType);

	std::string getName();
	std::string getAddress();
	LocationType getType();

	void operator=(const EventLocation& toBeCopied);

	friend void operator>>(std::istream& console, EventLocation& myEventLocation);
	friend void operator<<(std::ostream& console, const EventLocation& myEventLocation);
};