#include "Driver.h"

//Constructor 
Driver::Driver() :Information() {}

//Copy constructor
Driver::Driver(const Driver& driver) : Information(driver) {
	this->_user = driver._user;
}

//Assignment operator
Driver& Driver::operator =(const Driver& driver) {
	Information::operator=(driver);
	this->_user = driver._user;

	return *this;
}

//File and console operators
ifstream& operator >>(ifstream& in, Driver& driver) {
	in >> (Information&)(driver);
	return in;
}

ofstream& operator <<(ofstream& out, const Driver& driver) {
	out << (Information const&)driver;
	return out;
}

istream& operator >>(istream& in, Driver& driver) {
	in >> (Information&)driver;
	return in;
}

ostream& operator <<(ostream& out, const Driver& driver) {
	out << (Information const&)driver;
	return out;
}

//Methods change information