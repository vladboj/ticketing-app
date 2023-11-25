#include "TicketManager.h"
#include "Event.h"
#include "Ticket.h"
#include <iostream>

void TicketManager::startApp() {
	int choice;
	do {
		this->displayMenu();
		std::cout << "\nEnter your choice: ";
		std::cin >> choice;
		if (choice > 4) {
			std::cout << "\nINVALID OPTION!\n";
		}

		switch (choice) {
		case 1:
			this->addEvent();
			break;
		case 2:
			this->generateTicket();
			break;
		case 3:
			this->validateTicket();
			break;
		}
	} while (choice != 4);
}

void TicketManager::displayMenu() {
	std::cout << std::endl;
	std::cout << "|--------------------|\n";
	std::cout << "|      Main menu     |\n";
	std::cout << "|                    |\n";
	std::cout << "| 1. Add Event       |\n";
	std::cout << "| 2. Generate Ticket |\n";
	std::cout << "| 3. Validate Ticket |\n";
	std::cout << "| 4. EXIT            |\n";
	std::cout << "|                    |\n";
	std::cout << "|--------------------|\n";
}

void TicketManager::addEvent() {
	Event newEvent;
	std::cin >> newEvent;
	Event::addEvent(newEvent);

	Event::printEvents();
}

void TicketManager::generateTicket() {
	Ticket newTicket;
	std::cout << "\nTicket Details:\n";
	std::cin >> newTicket;
	Ticket::addTicket(newTicket);

	Ticket::printTickets();
}

void TicketManager::validateTicket() {
	int isValid = false;
	int givenTicketId;
	std::cout << "\nEnter ticket ID:\n";
	std::cin >> givenTicketId;
	int noTickets = Ticket::getNoTickets();
	Ticket* tickets = Ticket::getTickets();
	for (int i = 0; i < noTickets; i++) {
		if (tickets[i].getId() == givenTicketId) {
			isValid = true;
			break;
		}
	}
	if (isValid) {
		std::cout << "\nTicket is valid\n";
	}
	else {
		std::cout << "\nTicket is invalid\n";
	}
}

// if maxSeats is not divisible by noZones, it is not good