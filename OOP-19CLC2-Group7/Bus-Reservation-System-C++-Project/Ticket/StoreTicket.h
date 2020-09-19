#ifndef _STORE_TICKET_H_
#define _STORE_TICKET_H_

#include "Ticket.h"

class StoreTicket
{
private:
	vector<Ticket*> _tickets;
	
public:
	StoreTicket();

	//Type: 
	enum {
		PLAYS = 1,
		MONTHLY = 2,
	};
	
	~StoreTicket();

	//Create new ticket
	bool createNewTicket(const int& type, const string& passType, const string& busID, const string& username);

	void viewTicket(const string& username);
};

#endif