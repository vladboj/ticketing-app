#pragma once
#include "Event.h"
#include <iostream>
#include <string>

class Ticket {
	// NORMAL ATTRIBUTES
	int id;
	char* ownerName;
	Event associatedEvent;
	bool vipStatus;

	// STATIC ATTRIBUTES
	static Ticket* tickets;
	static int noTickets;

	static int NEXT_TICKET_ID;

	static const int MIN_NAME_LENGTH;
	static const int MAX_NAME_LENGTH;
public:
	// STATIC METHODS
	static void printTickets();
	static void addTicket(const Ticket& newTicket);
	static int getNoTickets();
	static Ticket* getTickets();
	static Ticket getTicket(int index);

	// CONSTRUCTORS
	Ticket();
	Ticket(const char* newOwnerName, Event newAssociatedEvent, bool newVipStatus);
	Ticket(const Ticket& toBeCopied);

	// DESTRUCTOR
	~Ticket();

	// SETTERS
	void setOwnerName(const char* newOwnerName);
	void setAssociatedEvent(Event newAssociatedEvent);
	void setVipStatus(bool newVipStatus);

	// GETTERS
	int getId();
	std::string getOwnerName();
	Event getAssociatedEvent();
	bool isVip();
	
	// OPERATORS OVERLOADING
	void operator=(const Ticket& toBeCopied);
	char operator[](int index);	// return the index+1th letter of the owner's name
	std::string operator+(Ticket rightTicket);	// return the names of the owners
	Ticket operator++(int);	// change vip status to true
	Ticket operator++();
	bool operator==(const Ticket& rightTicket);

	friend void operator>>(std::istream& console, Ticket& myTicket);
	friend void operator<<(std::ostream& console, const Ticket& myTicket);
};