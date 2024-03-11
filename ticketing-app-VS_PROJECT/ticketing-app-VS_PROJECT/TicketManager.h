#pragma once

class TicketManager {
private:
	static TicketManager instance;
	TicketManager();
	~TicketManager();
public:
	TicketManager(const TicketManager&) = delete;
	TicketManager& operator=(const TicketManager&) = delete;

	static TicketManager& getInstance();

	void startApp();
	void displayMenu();
	void addEvent();
	void generateTicket();
	void validateTicket();
	void testCode();
};