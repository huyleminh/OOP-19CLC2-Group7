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
	string _busName;
	string _purchaseDate;
	string _lifeCycle;
	string _username;
public:
	//Print ticket
	virtual void render() = 0;
};

class PlaysTicket : public Ticket { 
public:
	PlaysTicket(const string& type, const string& busID, const string& busName, const string& username);
	void render();
};

class MonthlyTicket : public Ticket {
public:
	MonthlyTicket(const string& type, const string& busID, const string& busName, const string& username);
	void render();
};

#endif