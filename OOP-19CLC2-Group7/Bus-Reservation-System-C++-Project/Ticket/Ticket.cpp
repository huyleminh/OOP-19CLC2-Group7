#include "Ticket.h"
#include "StoreTicket.h"

//Plays Ticket 
PlaysTicket::PlaysTicket(const string& type, const string& busID, const string& busName, const string& username) {
	if (type == "Student")
		this->_price = STUDENT_PLAYS;
	else
		this->_price = NORMAL_PLAYS;

	this->_busID = busID;
	this->_busName = busName;
	this->_username = username;
	this->_lifeCycle = 1;


}

void PlaysTicket::render()
{
	cout << "##############################################################################" << endl;
	cout << "#                                                                            #" << endl;
	cout << setw(25) << left << "# *Bus Id " << ": " << setw(50) << left << this->_busID << "#" << endl;
	cout << setw(25) << left << "# *Bus name " << ": " << setw(50) << left << this->_busName << "#" << endl;
	cout << setw(25) << left << "# *Price " << ": " << setw(50) << left << this->_price << "#" << endl;
	cout << setw(25) << left << "# *Expriry date " << ": " << setw(50) << left << this->_lifeCycle << "#" << endl;
	cout << "#                                                                            #" << endl;
	cout << "##############################################################################" << endl;
}

MonthlyTicket::MonthlyTicket(const string& type, const string& busID, const string& busName, const string& username)
{
	if (type == "Student")
		this->_price = STUDENT_MONTHLY;
	else
		this->_price = NORMAL_MONTHLY;

	this->_busID = busID;
	this->_busName = busName;
	this->_username = username;
	this->_lifeCycle = 1;
}

void MonthlyTicket::render()
{
	cout << "##############################################################################" << endl;
	cout << "#                                                                            #" << endl;
	cout << setw(25) << left << "# *Bus Id " << ": " << setw(50) << left << this->_busID << "#" << endl;
	cout << setw(25) << left << "# *Bus name " << ": " << setw(50) << left << this->_busName << "#" << endl;
	cout << setw(25) << left << "# *Price " << ": " << setw(50) << left << this->_price << "#" << endl;
	cout << setw(25) << left << "# *Expriry date " << ": " << setw(50) << left << this->_lifeCycle << "#" << endl;
	cout << "#                                                                            #" << endl;
	cout << "##############################################################################" << endl;
}
