#include "Ticket.h"

int Ticket::MIN_TICKET_ID = 1;
char Ticket::MIN_ROW = 'A';
int Ticket::MIN_SEAT = 1;

Ticket::Ticket() : ticketId(0), associatedEvent(Event()), row(0), seat(0), vipStatus(false), validationStatus(false) {}
Ticket::Ticket(int newTicketId, Event newAssociatedEvent, char newRow, int newSeat, bool newVipStatus, bool newValidationStatus) {
	this->setTicketId(newTicketId);
	this->setAssociatedEvent(newAssociatedEvent);
	this->setRow(newRow);
	this->setSeat(newSeat);
	this->setVipStatus(newVipStatus);
	this->setValidationStatus(newValidationStatus);
}

void Ticket::setTicketId(int newTicketId) {
	if (newTicketId < Ticket::MIN_TICKET_ID) {
		throw std::exception("Invalid ticket ID value");
	}
	this->ticketId = newTicketId;
}
void Ticket::setAssociatedEvent(Event newAssociatedEvent) {
	this->associatedEvent = newAssociatedEvent;
}
void Ticket::setRow(char newRow) {
	if (newRow < Ticket::MIN_ROW) {
		throw std::exception("Invalid row value");
	}
	this->row = newRow;
}
void Ticket::setSeat(int newSeat) {
	if (newSeat < MIN_SEAT) {
		throw std::exception("Invalid seat value");
	}
	this->seat = newSeat;
}
void Ticket::setVipStatus(bool newVip) {
	this->vipStatus = newVip;
}
void Ticket::setValidationStatus(bool newValidationStatus) {
	this->validationStatus = newValidationStatus;
}

int Ticket::getTicketId() {
	return this->ticketId;
}
Event Ticket::getAssociatedEvent() {
	return this->associatedEvent;
}
char Ticket::getRow() {
	return this->row;
}
int Ticket::getSeat() {
	return this->seat;
}
bool Ticket::isVip() {
	return this->vipStatus;
}
bool Ticket::isValidated() {
	return this->validationStatus;
}