#include "TicketManager.h";

int main() {
	TicketManager& ticketManager = TicketManager::getInstance();

	ticketManager.startApp();
}