#include "Ticket.h"
#include "StoreTicket.h"

//Plays Ticket 
PlaysTicket::PlaysTicket(const string& type, const string& busID, const string& username) {
	if (type == "Student")
		this->_price = STUDENT_PLAYS;
	else
		this->_price = NORMAL_PLAYS;

	this->_busID = busID;
	this->_username = username;

	//Initialize time 
	Date purchaseDate;
	this->_purchaseDate = purchaseDate.toString();
}

void PlaysTicket::render()
{
	cout << "##############################################################################" << endl;
	cout << "#                                                                            #" << endl;
	cout << setw(25) << left << "# *Bus Id " << ": " << setw(50) << left << this->_busID << "#" << endl;
	cout << setw(25) << left << "# *Price " << ": " << setw(50) << left << this->_price << "#" << endl;
	cout << setw(25) << left << "# *Expriry date " << ": " << setw(50) << left << this->_purchaseDate << "#" << endl;
	cout << "#                                                                            #" << endl;
	cout << "##############################################################################" << endl;
}

bool PlaysTicket::isOverdue()
{
	Date tmp(this->_purchaseDate);
	Date current;
	if ((tmp - current) > 1)
		return true;
	else 
		return false;
}

MonthlyTicket::MonthlyTicket(const string& type, const string& busID, const string& username)
{
	if (type == "Student")
		this->_price = STUDENT_MONTHLY;
	else
		this->_price = NORMAL_MONTHLY;

	this->_busID = busID;
	this->_username = username;

	//Initialize time 
	Date purchaseDate;
	this->_purchaseDate = purchaseDate.toString();
}

void MonthlyTicket::render()
{
	cout << "##############################################################################" << endl;
	cout << "#                                                                            #" << endl;
	cout << setw(25) << left << "# *Bus Id " << ": " << setw(50) << left << this->_busID << "#" << endl;
	cout << setw(25) << left << "# *Price " << ": " << setw(50) << left << this->_price << "#" << endl;
	cout << setw(25) << left << "# *Expriry date " << ": " << setw(50) << left << this->_purchaseDate << "#" << endl;
	cout << "#                                                                            #" << endl;
	cout << "##############################################################################" << endl;
}

bool MonthlyTicket::isOverdue()
{
	Date tmp(this->_purchaseDate);
	Date current;
	if ((tmp - current) > 30)
		return true;
	else 
		return false;
}