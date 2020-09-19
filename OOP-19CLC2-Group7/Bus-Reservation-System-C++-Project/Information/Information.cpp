#include "Information.h"

Information::Information()
{
	this->_name = "Null";
	this->_sex = "Null";
	this->_birthday = "dd/mm/yyyy";
	this->_username = "Null";
}

void Information::updateUsername(const string& username) {
	this->_username = username;
}

Information::Information(const Information& info)
{
	this->_name = info._name;
	this->_sex = info._sex;
	this->_birthday = info._birthday;
	this->_username = info._username;
}

//Operator
Information& Information::operator=(const Information& info)
{
	this->_name = info._name;
	this->_sex = info._sex;
	this->_birthday = info._birthday;
	this->_username = info._username;
	return *this;
}

ifstream& operator>>(ifstream& ifs, Information& info)
{
	string temp = "";

	getline(ifs, temp, '\n');

	getline(ifs, temp, '\n');
	if (temp == "")
		return ifs;
	info._name = temp;

	getline(ifs, temp, '\n');
	info._sex = temp;

	getline(ifs, temp, '\n');
	info._birthday = temp;

	getline(ifs, temp, '\n');
	info._username = temp;

	return ifs;
}

ofstream& operator<<(ofstream& ofs, const Information& info)
{
	ofs << endl;
	ofs << info._name << endl;
	ofs << info._sex << endl;
	ofs << info._birthday << endl;
	ofs << info._username << endl;
	return ofs;
}

//Need to fix 
istream& operator>>(istream& is, Information& info)
{
	string tmp = "";
	cout << "Enter name: ";

	getline(is, tmp, '\n');
	if (StdFormat::stdName(tmp))
		info._name = tmp;
	else 
		info._name = "Null";

	cout << "1. Male.\n";
	cout << "2. Female.\n";
	cout << "3. Others.\n";
	cout << "Choose gender: ";

	int option = 0;
	is >> option;

	if (option < 1 || option > 3)
		info._sex = "Null";
	
	info._sex = ((option == 1) ? "Male" : (option == 2) ? "Female" : "Others");

	is.ignore(1);
DATE:
	cout << "Enter birthday follow this format dd/mm/yyyy: ";
	
	getline(is, tmp, '\n');
	if (!Date::isValidDate(tmp))
		goto DATE;
	info._birthday = tmp;
	Sleep(1000);
	return is;
}

ostream& operator<<(ostream& os, const Information& info)
{
	cout << "Name: " << info._name << endl;
	cout << "Sex: " << info._sex << endl;
	cout << "Birthday: " << info._birthday << endl;
	cout << "Username: " << info._username << endl;

	return os;
}

bool Information::includeUsername(const User& user) {
	return (this->_username == user.getUsername());
}

//Change and check success or not 
bool Information::changeName(const string& name)
{
	string tmp = name;
	if (StdFormat::stdName(tmp)) {
		this->_name = tmp;
		return true;
	}
	else 
		return false;
}

void Information::changeSex(const string& sex)
{
	this->_sex = sex;
}

bool Information::changeBirthday(const string& birthday)
{
	string tmp = birthday;
	if (StdFormat::stdDate(tmp)) {
		this->_birthday = tmp;
		return true;
	}
	else 
		return false;
}