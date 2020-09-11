#include "StoreTicket.h"

StoreTicket::StoreTicket() {
	ifstream in("../Data/Tickets.txt");
	if (!in.is_open()) {
		cout << "Can not open Tickets.txt to load." << endl;
		this->_tickets.resize(0);
	}
	else {
		return;
	}
}

StoreTicket::~StoreTicket() {
	for (int i = 0; i < this->_tickets.size(); i++)
		delete this->_tickets[i];
}

void StoreTicket::createNewTicket(const int& type, const string& passType, const string& busID, const string& busName, const string& username) {
	switch (type)
	{
	case PLAYS:
		this->_tickets.push_back(new PlaysTicket(passType, busID, busName, username));
		break;
	case MONTHLY:
		this->_tickets.push_back(new MonthlyTicket(passType, busID, busName, username));
		break;
	default:
		break;
	}
}