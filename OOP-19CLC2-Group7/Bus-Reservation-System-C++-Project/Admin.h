#ifndef _ADMIN_H_
#define _ADMIN_H_

#include "Information.h"
#include "User.h"

class Admin : public Information
{
protected:
	User user;
public:
	//Constructor
	Admin();
	Admin(const Admin& ad);

	//Operator assignment
	Admin& operator= (Admin& ad);

	//Operator input output(console and form file)
	friend istream& operator >> (istream& is, Admin& ad);
	friend ostream& operator << (ostream& os, Admin& ad);
	friend ifstream& operator >> (ifstream& ifs, Admin& ad);
	friend ofstream& operator << (ofstream& ofs, Admin& ad);

	//Methods
	void editInfo(string acc, string pass);
};

#endif