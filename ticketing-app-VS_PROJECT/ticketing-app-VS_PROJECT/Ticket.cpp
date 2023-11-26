#include "Ticket.h"
#include "Event.h"
#include <iostream>
#include <string>

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

const int Ticket::MIN_NAME_LENGTH = 3;
const int Ticket::MAX_NAME_LENGTH = 50;

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

Ticket Ticket::getTicket(int index) {
	return Ticket::tickets[index];
}

// DEFAULT CONSTRUCTOR
Ticket::Ticket() : id(NEXT_TICKET_ID), ownerName(nullptr), associatedEvent(Event::Event()), vipStatus(false) {}

// CONSTRUCTOR WITH ARGUMENTS
Ticket::Ticket(const char* newOwnerName, Event newAssociatedEvent, bool newVipStatus) : id(Ticket::NEXT_TICKET_ID) {
	this->setAssociatedEvent(newAssociatedEvent);
	this->setVipStatus(newVipStatus);
}

// COPY CONSTRUCTOR
Ticket::Ticket(const Ticket& toBeCopied) {
	this->id = toBeCopied.id;
	this->ownerName = new char[strlen(toBeCopied.ownerName) + 1];
	strcpy_s(this->ownerName, strlen(toBeCopied.ownerName) + 1, toBeCopied.ownerName);
	this->associatedEvent = toBeCopied.associatedEvent;
	this->vipStatus = toBeCopied.vipStatus;
}

// DESTRUCTOR
Ticket::~Ticket() {
	if (this->ownerName != nullptr) {
		delete[] this->ownerName;
	}
}

// SETTERS
void Ticket::setOwnerName(const char* newOwnerName) {
	if (strlen(newOwnerName) < Ticket::MIN_NAME_LENGTH || strlen(newOwnerName) > Ticket::MAX_NAME_LENGTH) {
		throw std::exception("Invalid name length");
	}
	char* temp = new char[strlen(newOwnerName) + 1];
	strcpy_s(temp, strlen(newOwnerName) + 1, newOwnerName);
	if (this->ownerName != nullptr) {
		delete[] this->ownerName;
	}
	this->ownerName = temp;
}

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

std::string Ticket::getOwnerName() {
	return std::string(this->ownerName);
}

Event Ticket::getAssociatedEvent() {
	return this->associatedEvent;
}

bool Ticket::isVip() {
	return this->vipStatus;
}

// OPERATORS OVERLOADING
void Ticket::operator=(const Ticket& toBeCopied) {
	if (this == &toBeCopied) {
		return;
	}
	this->id = toBeCopied.id;
	this->setOwnerName(toBeCopied.ownerName);
	this->associatedEvent = toBeCopied.associatedEvent;
	this->vipStatus = toBeCopied.vipStatus;
}

char Ticket::operator[](int index) {
	return this->ownerName[index];
}

std::string Ticket::operator+(Ticket rightTicket) {
	return std::string(this->ownerName) + " and " + std::string(rightTicket.ownerName);
}

Ticket Ticket::operator++(int) {
	Ticket copy = *this;
	this->vipStatus = true;
	return copy;
}

Ticket Ticket::operator++() {
	this->vipStatus = true;
	return *this;
}

bool Ticket::operator==(const Ticket& rightTicket) {
	if (this->id != rightTicket.id) return false;
	if (strcmp(this->ownerName, rightTicket.ownerName) != 0) return false;
	if (!(this->associatedEvent == rightTicket.associatedEvent)) return false;
	if (this->vipStatus != rightTicket.vipStatus) return false;
	return true;
}

void operator>>(std::istream& console, Ticket& myTicket) {
	std::cout << "Enter your name: ";
	char buffer[Ticket::MAX_NAME_LENGTH + 1];
	console.ignore();
	console.getline(buffer, Ticket::MAX_NAME_LENGTH + 1);
	myTicket.setOwnerName(buffer);

	// associated event
	Event::printEvents();
	std::cout << "\nEnter ID of the event you want!\n";
	int chosenEventId;
	console >> chosenEventId;
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

	// printing the ticket id
	std::cout << "\nYour ticket ID is " << myTicket.id << std::endl;
}

void operator<<(std::ostream& console, const Ticket& myTicket) {
	console << "\n================== TICKET #" << myTicket.id << " ==================";
	console << "\nOwner Name: " << myTicket.ownerName;
	console << "\nAssociated Event" << myTicket.associatedEvent;
	console << "\nVIP Status: " << myTicket.vipStatus;
	console << "\n===================================================\n";
}