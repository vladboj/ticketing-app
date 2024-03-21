 #pragma once
#include <iostream>
#include <string>

class EventLocation {
	// NORMAL ATTRIBUTES
	char* name;
	char* address;
	
	// STATIC ATTRIBUTES
	static const int MIN_NAME_LENGTH;
	static const int MAX_NAME_LENGTH;

	static const int MIN_ADDRESS_LENGTH;
	static const int MAX_ADDRESS_LENGTH;
public:
	// CONSTRUCTORS
	EventLocation();
	EventLocation(const char* newName, const char* newAddress);
	EventLocation(const EventLocation& toBeCopied);

	// DESTRUCTOR
	~EventLocation();

	// SETTERS
	void setName(const char* newName);
	void setAddress(const char* newAddress);

	// GETTERS
	std::string getName();
	std::string getAddress();

	//OPERATORS OVERLOADING
	void operator=(const EventLocation& toBeCopied);
	char operator[](int index);	// return first letter of name
	bool operator==(const EventLocation& rightEventLocation);

	friend void operator>>(std::istream& console, EventLocation& myEventLocation);
	friend void operator<<(std::ostream& console, const EventLocation& myEventLocation);
};