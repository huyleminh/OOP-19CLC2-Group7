#include "Information.h"

Information::Information()
{
	this->_name = "Null";
	this->_sex = "Null";
	this->_birthday = "dd/mm/yyyy";
}

Information::Information(const Information& info)
{
	this->_name = info._name;
	this->_sex = info._sex;
	this->_birthday = info._birthday;
}

Information& Information::operator=(const Information& info)
{
	this->_name = info._name;
	this->_sex = info._sex;
	this->_birthday = info._birthday;
	return *this;
}

ifstream& operator>>(ifstream& ifs, Information& info)
{
	string temp="";

	getline(ifs, temp, '\n');

	getline(ifs, temp, '\n');
	if (temp == "")
		return ifs;
	info._name = temp;

	getline(ifs, temp, '\n');
	info._sex = temp;

	getline(ifs, temp, '\n');
	info._birthday = temp;

	return ifs;
}

ofstream& operator<<(ofstream& ofs, const Information& info)
{
	ofs << endl;
	ofs << info._name << endl;
	ofs << info._sex << endl;
	ofs << info._birthday << endl;

	return ofs;
}

istream& operator>>(istream& is, Information& info)
{
	cout << "Enter name: ";
	getline(is, info._name, '\n');

	cout << "Enter sex (MALE/FEMALE): ";
	getline(is, info._sex, '\n');

	cout << "Enter birthday follow this format dd/mm/yyyy: ";
	getline(is, info._birthday, '\n');

	return is;
}

ostream& operator<<(ostream& os, const Information& info)
{
	cout << "Name: " << info._name << endl;
	cout << "Sex: " << info._sex << endl;
	cout << "Birthday: " << info._birthday << endl;

	return os;
}
