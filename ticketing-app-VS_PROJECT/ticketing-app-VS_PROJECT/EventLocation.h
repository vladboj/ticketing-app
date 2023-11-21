#pragma once
#include <string>
#include <iostream>

class EventLocation {
	std::string name;
	std::string address;
public:
	EventLocation();
	EventLocation(std::string newName, std::string newAddress);
	EventLocation(const EventLocation& toBeCopied);

	void setName(std::string newName);
	void setAddress(std::string newAddress);

	std::string getName();
	std::string getAddress();

	void operator=(const EventLocation& toBeCopied);

	friend void operator>>(std::istream& console, EventLocation& myEventLocation);
	friend void operator<<(std::ostream& console, const EventLocation& myEventLocation);
};