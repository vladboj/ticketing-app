#include "TicketManager.h"
#include <iostream>

TicketManager::TicketManager() : events(nullptr), tickets(nullptr), noEvents(0) {}

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
			this->printEvents();
			break;
		case 3:
			this->generateTicket();
			break;
		case 4:
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
	std::cout << "| 2. Show Events     |\n";
	std::cout << "| 3. Generate Ticket |\n";
	std::cout << "| 4. Validate Ticket |\n";
	std::cout << "| 5. EXIT            |\n";
	std::cout << "|                    |\n";
	std::cout << "|--------------------|\n";
}

void TicketManager::addEvent() {
	this->noEvents++;
	Event* temp = new Event[noEvents];
	int i;
	for (i = 0; i < this->noEvents - 1; i++) {
		temp[i] = events[i];
	}
	Event newEvent;
	std::cout << "\nEvent Details:\n";
	std::cin >> newEvent;
	temp[i] = newEvent;
	if(this->events)
	delete[] this->events;
	this->events = temp;

	std::cout << newEvent;
	std::cout << std::endl;
}

void TicketManager::printEvents() {
	for (int i = 0; i < this->noEvents; i++) {
		std::cout << this->events[i];
		std::cout << std::endl;
	}
}

void TicketManager::generateTicket() {

}

void TicketManager::validateTicket() {

}