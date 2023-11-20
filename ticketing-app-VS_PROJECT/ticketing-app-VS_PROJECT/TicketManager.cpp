#include "TicketManager.h"
#include <iostream>

void TicketManager::startApp() {
	this->noEvents = 0;
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
	this->noEvents++;
	Event* temp = new Event[noEvents];

	std::cout << "Event Details:\n";
	
}
void TicketManager::generateTicket() {

}
void TicketManager::validateTicket() {

}