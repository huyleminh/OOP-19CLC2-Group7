#ifndef _PASSENGER_H_
#define _PASSENGER_H_

#include "Header.h"
#include "Information.h"

class Passenger : public Information
{
private:	
	//Attributes
	//User _user;
	string _type;

public:
	//Constructor
	Passenger();
	Passenger(const Passenger&);

	//Assignment operator
	Passenger& operator =(const Passenger&);

	//File and console operators
	friend ifstream& operator >>(ifstream& in, Passenger&);
	friend ofstream& operator <<(ofstream& out, const Passenger&);
	friend istream& operator >>(istream& in, Passenger&);
	friend ostream& operator <<(ostream& out, const Passenger&);

	//Methods change information
	void changeInformation(User& user); //Render change information interface

private:
	bool changeName(const string& name);
	void changeSex(const string& sex);
	bool changeBirthday(const string& dob);
};

#endif

