#include "Ticket.h"
#include "Event.h"







// STATIC ATTRIBUTES INITIALIZATIONS
Ticket* Ticket::tickets = nullptr;
int Ticket::noTickets = 0;

int Ticket::NEXT_TICKET_ID = 1;







// STATIC METHODS
void Ticket::printTickets() {
	for (int i = 0; i < Ticket::noTickets; i++) {
		std::cout << Ticket::tickets[i];
		std::cout << std::endl;
	}
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
	Ticket::NEXT_TICKET_ID++;
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
Ticket::Ticket() : id(NEXT_TICKET_ID), associatedEvent(Event()), vipStatus(false) {}

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
	std::cout << "\nEnter ID of the associated event!\n";
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
	// ticked id
	console << "\nTicket ID: " << myTicket.id;

	// associated event
	console << "\nAssociated Event: " << myTicket.associatedEvent;
	
	// vip status
	console << "\nVIP Status: " << myTicket.vipStatus;
}