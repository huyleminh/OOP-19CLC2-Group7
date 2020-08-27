#ifndef _DRIVER_H_
#define _DRIVER_H_

#include "Header.h"
#include "Information.h"
#include "User.h"

class Driver : public Information
{
private:
public:
	//Constructor 
	Driver();
	Driver(const Driver& driver);

	//Assignment operator
	Driver& operator =(const Driver&);
	bool operator==(const Driver& info);

	//File and console operators
	friend ifstream& operator >>(ifstream& in, Driver&);
	friend ofstream& operator <<(ofstream& out, const Driver&);
	friend istream& operator >>(istream& in, Driver&);
	friend ostream& operator <<(ostream& out, const Driver&);

	//Methods change information
	void changeInformation(User & user); //Render change information interface

	friend class Admin;//De admin co the truy xuat duoc tai khoan nay no
private:
	bool changeName(const string& name);
	void changeSex(const string& sex);
	bool changeBirthday(const string& dob);
};

#endif
