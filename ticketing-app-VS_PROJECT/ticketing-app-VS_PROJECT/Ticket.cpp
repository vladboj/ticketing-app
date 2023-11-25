#include "Ticket.h"
#include "Event.h"
#include <iostream>

// local implementation of rand function to avoid using external libraries :D
// i might have stolen it :D but now i understand how a Linear Congruential Generator works
namespace my_rand {
	unsigned __int64 next = 1;

	int rand() // RAND_MAX assumed to be 32767
	{
		next = next * 1103515245 + 12345;
		return (unsigned __int64)(next / 65536) % 32768;
	}

	void srand(unsigned __int64 seed)
	{
		next = seed;
	}
}

// STATIC ATTRIBUTES INITIALIZATIONS
Ticket* Ticket::tickets = nullptr;
int Ticket::noTickets = 0;

int Ticket::NEXT_TICKET_ID = my_rand::rand();

// STATIC METHODS
void Ticket::printTickets() {
	std::cout << "\n__________________________________PRINTING ALL TICKETS +++START+++\n";
	for (int i = 0; i < Ticket::noTickets; i++) {
		std::cout << Ticket::tickets[i];
	}
	std::cout << "\n__________________________________PRINTING ALL TICKETS +++END+++\n";
}

void Ticket::addTicket(const Ticket& newTicket) {
	Ticket::noTickets++;
	Ticket* temp = new Ticket[Ticket::noTickets];
	for (int i = 0; i < Ticket::noTickets - 1; i++) {
		temp[i] = Ticket::tickets[i];
	}
	temp[Ticket::noTickets - 1] = newTicket;
	if (Ticket::tickets != nullptr) {
		delete[] Ticket::tickets;
	}
	Ticket::tickets = temp;

	Ticket::NEXT_TICKET_ID += my_rand::rand();
}

int Ticket::getNoTickets() {
	return Ticket::noTickets;
}

Ticket* Ticket::getTickets() {
	Ticket* newTickets = new Ticket[Ticket::noTickets];
	for (int i = 0; i < Ticket::noTickets; i++) {
		newTickets[i] = Ticket::tickets[i];
	}
	return newTickets;
}

// DEFAULT CONSTRUCTOR
Ticket::Ticket() : id(NEXT_TICKET_ID), associatedEvent(Event::Event()), vipStatus(false) {}

// CONSTRUCTOR WITH ARGUMENTS
Ticket::Ticket(Event newAssociatedEvent, bool newVipStatus) : id(Ticket::NEXT_TICKET_ID) {
	this->setAssociatedEvent(newAssociatedEvent);
	this->setVipStatus(newVipStatus);
}

// COPY CONSTRUCTOR
Ticket::Ticket(const Ticket& toBeCopied) {
	this->id = toBeCopied.id;
	this->associatedEvent = toBeCopied.associatedEvent;
	this->vipStatus = toBeCopied.vipStatus;
}

// SETTERS
void Ticket::setAssociatedEvent(Event newAssociatedEvent) {
	this->associatedEvent = newAssociatedEvent;
}

void Ticket::setVipStatus(bool newVip) {
	this->vipStatus = newVip;
}

// GETTERS
int Ticket::getId() {
	return this->id;
}

Event Ticket::getAssociatedEvent() {
	return this->associatedEvent;
}

bool Ticket::isVip() {
	return this->vipStatus;
}

// OPERATORS OVERLOADING
void Ticket::operator=(const Ticket& toBeCopied) {
	this -> id = toBeCopied.id;
	this->associatedEvent = toBeCopied.associatedEvent;
	this->vipStatus = toBeCopied.vipStatus;
}

void operator>>(std::istream& console, Ticket& myTicket) {
	// associated event
	Event::printEvents();
	std::cout << "\nEnter ID of the event you want!\n";
	int chosenEventId;
	std::cin >> chosenEventId;
	myTicket.associatedEvent = Event::getEvent(chosenEventId);
	
	// vip status
	std::cout << "\nDo you want to be a VIP? (1 for YES --- 2 for NO)\n";
	int chosenVipStatus;
	while(true) {
		console >> chosenVipStatus;
		if (chosenVipStatus == 1 || chosenVipStatus == 2) {
			break;
		}
		else {
			std::cout << "\n!!!choose either 1 or 2!!!\n";
		}
	}
	myTicket.vipStatus = (chosenVipStatus == 1) ? true : false;
}

void operator<<(std::ostream& console, const Ticket& myTicket) {
	console << "\n================== TICKET #" << myTicket.id << " ==================";
	console << "\nAssociated Event" << myTicket.associatedEvent;
	console << "\nVIP Status: " << myTicket.vipStatus;
	console << "\n===================================================\n";
}