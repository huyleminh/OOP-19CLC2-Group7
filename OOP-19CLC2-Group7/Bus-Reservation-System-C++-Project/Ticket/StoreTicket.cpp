#include "StoreTicket.h"

StoreTicket::StoreTicket() {
	ifstream in("../Data/Tickets.txt");
	if (!in.is_open()) {
		cout << "Can not open Tickets.txt to load." << endl;
		this->_tickets.resize(0);
	}
	else {
		string ignore = "";

		string username = "";
		string type = "";
		string id = "";
		string purchase = "";

		while (!in.eof()) {
			//Read empty line
			getline(in, ignore, '\n');

			getline(in, username, '\n');
			if (username == "")
				break;
			
			getline(in, type, '\n');
			getline(in, id, '\n');
			getline(in, purchase, '\n');

			getline(in, ignore, '\n');

			if (ignore == "Plays") {
				this->_tickets.push_back(new PlaysTicket(type, id, username));
				this->_tickets[this->_tickets.size() - 1]->updatePurchaseDate(purchase);
			}
			else if (ignore == "Monthly") {
				this->_tickets.push_back(new MonthlyTicket(type, id, username));
				this->_tickets[this->_tickets.size() - 1]->updatePurchaseDate(purchase);
			}
		}
		in.close();
	}
}

StoreTicket::~StoreTicket() {
	for (int i = 0; i < this->_tickets.size(); i++)
		delete this->_tickets[i];
}

bool StoreTicket::createNewTicket(const int& type, const string& passType, const string& busID, const string& username) {
	Ticket* check;
	switch (type)
	{
	case PLAYS:
		check = new PlaysTicket(passType, busID, username);
		this->_tickets.push_back(check);
		break;
	case MONTHLY:
		check = new MonthlyTicket(passType, busID, username);
		this->_tickets.push_back(check);
		break;
	default:
		return false;
	}

	for (int i = 0; i < this->_tickets.size() - 1; i++) {
		if (check == this->_tickets[i]) {
			this->_tickets.pop_back();
			return false;
		}
	}

	//Save to file new ticket 
	check->saveToFile();
	return true;
}