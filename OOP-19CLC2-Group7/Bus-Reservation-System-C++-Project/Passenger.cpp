#include "Passenger.h"

//Constructor
Passenger::Passenger() : Information() {
	this->_type = "Normal";
}

Passenger::Passenger(const Passenger& p) : Information(p) {
	this->_user = p._user;
	this->_type = p._type;
}

//Operator
Passenger& Passenger::operator =(const Passenger& p) {
	Information::operator =(p);
	this->_user = p._user;
	this->_type = p._type;
	return *this;
}

ifstream& operator >>(ifstream& in, Passenger& p) {
	in >> (Information&)(p);

	string line = "";
	getline(in, p._type, '\n');

	return in;
}

ofstream& operator <<(ofstream& out, const Passenger& p) {
	out << (Information const&)(p);
	out << p._type << endl;
	return out;
}

istream& operator >>(istream& in, Passenger& p) {
	in >> (Information&)(p);
	cout << "Choose your type: " << endl;
	cout << "1. Student.\n";
	cout << "2. Normal.\n";

	string option;
	getline(cin, option, '\n');
	if (option == "1")
		p._type = "Student";
	else
		p._type = "Normal";

	return in;
}

ostream& operator <<(ostream& out, const Passenger& p) {
	out << (Information const&)(p);
	out << "Type: " << p._type << endl;
	return out;
}