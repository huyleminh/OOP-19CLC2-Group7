#ifndef _BUY_TICKET_WORKFLOW_H_
#define _BUY_TICKET_WORKFLOW_H_

#include "../Header.h"

class BuyTicketWorkflow {
public:
    static bool validateBuyTicketRequest(const int& type, const string& passType, const string& busID, const string& busName, const string& username);
};

#endif