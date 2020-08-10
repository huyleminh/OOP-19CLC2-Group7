#ifndef _ADMIN_H_
#define _ADMIN_H_

#include "Information.h"
#include "User.h"

class Admin : public Information
{
private:
	User user;
public:
	//Constructor
	Admin();
	Admin(const Admin& ad);

	//Operator assignment
	Admin& operator= (const Admin& ad);

	//Operator input output(console and form file)
	friend istream& operator >> (istream& is, Admin& ad);
	friend ostream& operator << (ostream& os, const Admin& ad);
	friend ifstream& operator >> (ifstream& ifs, Admin& ad);
	friend ofstream& operator << (ofstream& ofs, const Admin& ad);

	////Methods
	//void editInfo(string acc, string pass);
};

#endif