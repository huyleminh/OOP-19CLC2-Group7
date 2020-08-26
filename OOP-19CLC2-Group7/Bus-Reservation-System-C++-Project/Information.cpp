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
	cout << "Enter name: ";
	while (getchar() != '\n');
	getline(is, info._name, '\n');

	cout << "1. Male.\n";
	cout << "2. Female.\n";
	cout << "3. Others.\n";
	cout << "Choose gender: ";

	int option = 0;
	is >> option;

	if (option < 1 || option > 3)
		info._sex = "Others";
	
	info._sex = ((option == 1) ? "Male" : (option == 2) ? "Female" : "Others");

	is.ignore(1);
	cout << "Enter birthday follow this format dd/mm/yyyy: ";
	getline(is, info._birthday, '\n');

	cout << "If any informations above is wrong, you can change it.\n";
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
	const string regEx = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM ";
	for (int i = 0; i < name.length(); i++)
		//If a character is not include in regEx(valid) return false mean == npos
		if (regEx.rfind(name[i]) == string::npos)
			return false;
	

	vector<string> tmpStr = Tokenizer::split(name, " ");
	for (int i = 0; i < tmpStr.size(); i++)
		tmpStr[i][0] = tolower(tmpStr[i][0]);

	this->_name = Tokenizer::join(tmpStr, " ");
	return true;
}

void Information::changeSex(const string& sex)
{
	this->_sex = sex;
}

bool Information::changeBirthday(const string& birthday)
{
	vector<string> date = Tokenizer::split(birthday, "/");
	if (date.size() != 3)
		return false;

	for (int i = 0; i < date.size(); i++)
		if (stoi(date[i]) <= 0)
			return false;

		switch (stoi(date[1]))
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		if (stoi(date[0]) > 31)
			return false;
		else
			break;
	case 4: case 6: case 9: case 11:
		if (stoi(date[0]) > 30)
			return false;
		else
			break;
	case 2:
		if (stoi(date[2]) % 400 != 0 && !(stoi(date[2]) % 4 == 0 && stoi(date[2]) % 100 != 0)) {
			if (stoi(date[0]) > 28)
				return false;
		}
		else 
			if (stoi(date[0]) > 29)
				return false;
	}

	this->_birthday = birthday;
	return true;
}