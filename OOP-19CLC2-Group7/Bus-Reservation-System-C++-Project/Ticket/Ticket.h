#ifndef _TICKET_H_
#define _TICKET_H_

#include "../Header.h"

#define STUDENT_PLAYS 3000
#define STUDENT_MONTHLY 50000
#define NORMAL_PLAYS 5000
#define NORMAL_MONTHLY 100000

class Ticket
{
protected:
	int _price;
	string _busID;
	string _purchaseDate;
	string _username;
public:
	//Print ticket
	virtual void render() = 0;
	// virtual bool validTicket() = 0;
	virtual void saveToFile() = 0;
	void updatePurchaseDate(const string& purchase) {
		this->_purchaseDate = purchase;
	}
	//Check overdue ticket
	virtual bool isOverdue() = 0;

	//Check match with an Passenger by username
	bool matchUser(const string& username) {
		return this->_username == username;
	}

	//operator ==
	bool operator ==(Ticket* ticket) {
		if (this->_busID != ticket->_busID)
			return false;
		if (this->_price != ticket->_price)
			return false;
		if (this->_purchaseDate != ticket->_purchaseDate)
			return false;
		if (this->_username != ticket->_username)
			return false;
		return true;
	}
};

class PlaysTicket : public Ticket { 
public:
	PlaysTicket(const string& type, const string& busID, const string& username);
	void render();
	// bool validTicket();
	void saveToFile() {
		ofstream out;
		out.open("../Data/Tickets.txt", ios::app);

		out << endl;
		out << this->_username << endl;
		out << ((this->_price == STUDENT_PLAYS) ? "Student" : "Normal") << endl;
		out << this->_busID << endl;
		out << this->_purchaseDate << endl;
		out << "Plays" << endl;
		out.close();
	}

	bool isOverdue();
};

class MonthlyTicket : public Ticket {
public:
	MonthlyTicket(const string& type, const string& busID, const string& username);
	void render();
	// bool validTicket();
	void saveToFile() {
		ofstream out;
		out.open("../Data/Tickets.txt", ios::app);

		out << endl;
		out << this->_username << endl;
		out << ((this->_price == STUDENT_MONTHLY) ? "Student" : "Normal") << endl;
		out << this->_busID << endl;
		out << this->_purchaseDate << endl;
		out << "Monthly" << endl;
		out.close();
	}

	bool isOverdue();
};

#endif