#pragma once
#include "Event.h"

class Ticket {
	const int ticketId;
	Event associatedEvent;
	char row;
	int seat;
	bool vipStatus;
	bool validationStatus;

	static int MIN_TICKET_ID;
	static char MIN_ROW;
	static int MIN_SEAT;
public:
	Ticket();
	Ticket(int newTicketId, Event newAssociatedEvent, char newRow, int newSeat, bool newVipStatus, bool newValidationStatus);
	Ticket(const Ticket& toBeCopied);

	void setAssociatedEvent(Event newAssociatedEvent);
	void setRow(char newRow);
	void setSeat(int newSeat);
	void setVipStatus(bool newVipStatus);
	void setValidationStatus(bool newValidationStatus);

	int getTicketId();
	Event getAssociatedEvent();
	char getRow();
	int getSeat();
	bool isVip();
	bool isValidated();

private:
	int validateTicketId(int newTicketId);
};