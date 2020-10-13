#include "BuyTicketWorkflow.h"
#include "../../Ticket/StoreTicket.h"

bool BuyTicketWorkflow::validateBuyTicketRequest(const int& type, const string& passType, const string& busID, const string& busName, const string& username) {
    //Validate ticket type
    if (type != StoreTicket::PLAYS || type != StoreTicket::MONTHLY)
        return false;

    //Validate user who buy ticket
    //Validate exist ticket
    Ticket* check = NULL;

    switch (type)
	{
	case StoreTicket::PLAYS:
		check = new PlaysTicket(passType, busID, busName, username);
		break;
	case StoreTicket::MONTHLY:
		check = new MonthlyTicket(passType, busID, busName, username);
		break;
	default:
		break;
	}
}