#pragma once
#include "Event.h"

class Ticket {
	// NORMAL ATTRIBUTES
	int id;
	Event associatedEvent;
	bool vipStatus;

	// STATIC ATTRIBUTES
	static Ticket* tickets;
	static int noTickets;

	static int NEXT_TICKET_ID;

	static char MIN_ROW;
	static int MIN_SEAT;
public:
	// STATIC METHODS
	static void printTickets();
	static void addTicket(const Ticket& newTicket);
	static int getNoTickets();
	static Ticket* getTickets();

	// CONSTRUCTORS
	Ticket();
	Ticket(Event newAssociatedEvent, bool newVipStatus);
	Ticket(const Ticket& toBeCopied);

	// SETTERS
	void setAssociatedEvent(Event newAssociatedEvent);
	void setVipStatus(bool newVipStatus);

	// GETTERS
	int getId();
	Event getAssociatedEvent();
	bool isVip();
	
	// OPERATORS OVERLOADING
	void operator=(const Ticket& toBeCopied);

	friend void operator>>(std::istream& console, Ticket& myTicket);
	friend void operator<<(std::ostream& console, const Ticket& myTicket);
};