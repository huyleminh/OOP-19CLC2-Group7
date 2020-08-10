#include "Admin.h"

Admin::Admin() : Information() {}

Admin::Admin(const Admin& ad) : Information(ad) {
	this->user = ad.user;
}

Admin& Admin::operator =(const Admin& ad)
{
	Information::operator=(ad);
	this->user = ad.user;

	return *this;
}

istream& operator >>(istream& is, Admin& ad)
{
	cout << "Enter name: ";
	getline(is, ad._name, '\n');

	cout << "Enter sex (MALE/FEMALE): ";
	getline(is, ad._sex, '\n');

	cout << "Enter birthday follow this format dd/mm/yyyy: ";
	getline(is, ad._birthday, '\n');

	return is;
}

ostream& operator << (ostream& os, const Admin& ad)
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

ofstream& operator << (ofstream& ofs, const Admin& ad)
{
	ofs << (Information&)(ad);

	return ofs;       
}
//
//void editInfoAdmin(string acc, int pos) //position in the file txt
//{
//	string newName;
//	string newSex;
//	string newBirthday;
//	string newPassword;
//	string newRole;
//
//
//}