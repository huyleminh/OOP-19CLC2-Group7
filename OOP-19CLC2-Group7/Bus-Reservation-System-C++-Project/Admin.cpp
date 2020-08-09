#include "Admin.h"

Admin::Admin()
{
	this->_name = "Empty";
	this->_birthday = "Empty";
	this->_sex = "dd/mm/yyyy";
}

Admin::Admin(const Admin& ad)
{
	this->_name = ad._name;
	this->_birthday = ad._birthday;
	this->_sex = ad._sex;
}

Admin& Admin::operator=(Admin& ad)
{
	Information::operator=(ad);
	this->user = ad.user;

	return *this;
}

istream& operator>>(istream& is, Admin& ad)
{
	cout << "Enter name: ";
	getline(is, ad._name, '\n');

	cout << "Enter sex (MALE/FEMALE): ";
	getline(is, ad._sex, '\n');

	cout << "Enter birthday follow this format dd/mm/yyyy: ";
	getline(is, ad._birthday, '\n');

	return is;
	
	return is;
}

ostream& operator << (ostream& os, Admin& ad)
{
	cout << "Name: " << ad._name << endl;
	cout << "Sex: " << ad._sex << endl;
	cout << "Birthday: " << ad._birthday << endl;

	return os;
}
ifstream& operator >> (ifstream& ifs, Admin& ad)
{
	ifs >> (Information&)(ad);

	return ifs;
}

ofstream& operator << (ofstream& ofs, Admin& ad)
{
	ofs << (Information&)(ad);

	return ofs;       
}

void editInfoAdmin(string acc, int pos) //position in the file txt
{
	string newName;
	string newSex;
	string newBirthday;
	string newPassword;
	string newRole;


}