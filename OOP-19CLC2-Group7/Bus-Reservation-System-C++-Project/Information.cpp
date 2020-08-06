#include "Information.h"

Information::Information()
{
	this->name = "No name";
	this->sex = "male";
	this->birthday = "01/01/1990";
	this->CMNN = "xxxxxxxxx";
	this->phone = "0000000000";
}

Information::Information(const Information& info)
{
	*this = info;
}

Information& Information::operator=(const Information& info)
{
	*this = info;
	return *this;
}

ifstream& operator>>(ifstream& ifs, Information& info)
{
	string temp="";

	getline(ifs, temp, '\n');

	getline(ifs, temp, '\n');
	info.name = temp;

	getline(ifs, info.sex, '\n');
	info.sex = temp;

	getline(ifs, temp, '\n');
	info.birthday = temp;

	getline(ifs, temp, '\n');
	info.CMNN = temp;

	getline(ifs, temp, '\n');
	info.phone = temp;

	return ifs;
}

ofstream& operator<<(ofstream& ofs, const Information& info)
{
	ofs << info.name << endl;
	ofs << info.sex << endl;
	ofs << info.birthday << endl;
	ofs << info.CMNN << endl;
	ofs << info.phone << endl;
	ofs << endl;

	return ofs;
}

istream& operator>>(istream& is, Information& info)
{
	cout << "enter name: ";
	getline(is, info.name, '\n');

	cout << "enter sex (MALE/FEMALE): ";
	getline(is, info.sex, '\n');

	cout << "enter birthday(dd/mm/yy): ";
	getline(is, info.birthday, '\n');

	cout << "enter CMNN: ";
	getline(is, info.CMNN, '\n');

	cout << "enter phone: ";
	getline(is, info.phone, '\n');

	return is;
}

ostream& operator<<(ostream& os, const Information& info)
{
	cout << "Name: " << info.name << endl;
	cout << "Sex: " << info.sex << endl;
	cout << "Birthday: " << info.birthday << endl;
	cout << "CMNN: " << info.CMNN << endl;
	cout << "Phone: " << info.phone << endl;

	return os;
}
