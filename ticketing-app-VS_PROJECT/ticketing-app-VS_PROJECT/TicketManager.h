#pragma once
#include "Event.h"
#include "Ticket.h"

class TicketManager {
	Event* events;
	Ticket* tickets;

	int noEvents;
public:
	TicketManager();

	void startApp();
	void displayMenu();
	void addEvent();
	void printEvents();
	void generateTicket();
	void validateTicket();
};