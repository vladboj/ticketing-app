#pragma once
#include "Event.h"
#include "Ticket.h"

class TicketManager {
	Event* events;
	Ticket* tickets;
public:
	void startApp();
	void displayMenu();
	void addEvent();
	void generateTicket();
	void validateTicket();
};