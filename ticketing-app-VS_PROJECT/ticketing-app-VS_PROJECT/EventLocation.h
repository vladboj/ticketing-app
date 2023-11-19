#pragma once
#include <string>

enum LocationType {NONE, theater, stadium, standingVenue};

class EventLocation {
	std::string name;
	std::string address;
	LocationType type;
public:
	EventLocation();
	EventLocation(std::string newName, std::string newAddress, LocationType newType);

	void setName(std::string newName);
	void setAddress(std::string newAddress);
	void setType(LocationType newType);

	std::string getName();
	std::string getAddress();
	LocationType getType();
};