#ifndef _STORE_TICKET_H_
#define _STORE_TICKET_H_

#include "Ticket.h"

class StoreTicket
{
private:
	vector<Ticket*> _tickets;
private:
	StoreTicket();
public:
	//Type: 
	enum {
		PLAYS = 1,
		MONTHLY = 2,
	};
	
	~StoreTicket();

	void createNewTicket(const int& type, const string& passType, const string& busID, const string& busName, const string& username);
};

#endif