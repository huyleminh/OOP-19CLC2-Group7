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
	time_t current = time(NULL);

	char tmp[26];
	ctime_s(tmp, 26, &current);

	string timer = "";
	for (int i = 0; i < 24; i++)
		timer += tmp[i];
	vector<string> now = Tokenizer::split(timer, " ");

	string purchaseDate = "";
	purchaseDate += now[2] + "/";

	if (now[1] == "Jan")	purchaseDate += "1";
	else if (now[1] == "Feb")	purchaseDate += "2";
	else if (now[1] == "Mar")	purchaseDate += "3";
	else if (now[1] == "Apr")	purchaseDate += "4";
	else if (now[1] == "May")	purchaseDate += "5";
	else if (now[1] == "Jun")	purchaseDate += "6";
	else if (now[1] == "Jul")	purchaseDate += "7";
	else if (now[1] == "Aug")	purchaseDate += "8";
	else if (now[1] == "Sep")	purchaseDate += "9";
	else if (now[1] == "Oct")	purchaseDate += "10";
	else if (now[1] == "Nov")	purchaseDate += "11";
	else    
		purchaseDate += "12";

	purchaseDate += "/" + now[4];
	this->_purchaseDate = purchaseDate;
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

MonthlyTicket::MonthlyTicket(const string& type, const string& busID, const string& username)
{
	if (type == "Student")
		this->_price = STUDENT_MONTHLY;
	else
		this->_price = NORMAL_MONTHLY;

	this->_busID = busID;
	this->_username = username;

	//Initialize time 
	time_t current = time(NULL);

	char tmp[26];
	ctime_s(tmp, 26, &current);

	string timer = "";
	for (int i = 0; i < 24; i++)
		timer += tmp[i];
	vector<string> now = Tokenizer::split(timer, " ");

	string purchaseDate = "";
	purchaseDate += now[2] + "/";

	if (now[1] == "Jan")	purchaseDate += "1";
	else if (now[1] == "Feb")	purchaseDate += "2";
	else if (now[1] == "Mar")	purchaseDate += "3";
	else if (now[1] == "Apr")	purchaseDate += "4";
	else if (now[1] == "May")	purchaseDate += "5";
	else if (now[1] == "Jun")	purchaseDate += "6";
	else if (now[1] == "Jul")	purchaseDate += "7";
	else if (now[1] == "Aug")	purchaseDate += "8";
	else if (now[1] == "Sep")	purchaseDate += "9";
	else if (now[1] == "Oct")	purchaseDate += "10";
	else if (now[1] == "Nov")	purchaseDate += "11";
	else    
		purchaseDate += "12";

	purchaseDate += "/" + now[4];
	this->_purchaseDate = purchaseDate;
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
