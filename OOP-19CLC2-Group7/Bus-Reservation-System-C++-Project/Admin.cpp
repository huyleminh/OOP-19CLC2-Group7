#include "Admin.h"

Admin::Admin() : Information() {}

Admin::Admin(const Admin& ad) : Information(ad) {}

Admin& Admin::operator =(const Admin& ad)
{
	Information::operator=(ad);

	return *this;
}

istream& operator >>(istream& is, Admin& ad)
{
	is >> (Information&)ad;

	return is;
}

ostream& operator << (ostream& os, const Admin& ad)
{
	os << (Information const&)ad;

	return os;
}
ifstream& operator >> (ifstream& ifs, Admin& ad)
{
	ifs >> (Information&)(ad);

	return ifs;
}

ofstream& operator << (ofstream& ofs, const Admin& ad)
{
	ofs << (Information const&)(ad);

	return ofs;
}


//Methods change information
void Admin::changeInformation(User& user) 
{
	system("cls");
	cout << "************************************************\n";
	cout << "*            CHANGE INFORMATION                *\n";
	cout << "*  1. Name.                                    *\n";
	cout << "*  2. Gender.                                  *\n";
	cout << "*  3. Day of birth.                            *\n";
	cout << "*  4. Back to menu.                            *\n";
	cout << "*                                              *\n";
	cout << "************************************************\n";

OPTION:
	cout << "Choose your option: ";

	int option;
	cin >> option;

	if (cin.fail()) {
		cin.clear();
		cout << "Invalid option, please choose aganin.\n";
		cin.ignore(32767, '\n');
		goto OPTION;
	}

	if (option > 4 || option < 1) {
		cout << "Invalid option, please choose aganin.\n";

		Sleep(1000);
		goto OPTION;
	}

	cin.ignore(1);

	string inputStr = "";

	switch (option)
	{
	case 1:
		cout << "Enter new name you want to change: ";
		getline(cin, inputStr, '\n');

		//Try to change name
		if (this->changeName(inputStr))
			cout << "Change name successfully.\n";
		else
			cout << "Fail to change name, you inputted name might be unvalid name.\n";

		Sleep(1000);
		break;

	case 2:
		cout << "Choose gender: " << endl;
		cout << "1. Male" << endl;
		cout << "2. Female" << endl;
		cout << "3. Others" << endl;
	GENDER:
		cout << "Choose one: ";
		cin >> option;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			goto GENDER;
		}

		if (option > 3 || option < 1) {
			cout << "Invalid option, please choose aganin.\n";
			goto GENDER;
		}

		if (option == 1)
			this->changeSex("Male");
		else if (option == 2)
			this->changeSex("Female");
		else
			this->changeSex("Others");
		cout << "Change gender successfully.\n";
		Sleep(1000);
		break;

	case 3:
		cout << "Enter your day of birth: ";
		getline(cin, inputStr, '\n');

		if (this->changeBirthday(inputStr))
			cout << "Change birthday successfully.\n";
		else
			cout << "Fail to change day of birth, your inputted is might be unvalud form.\n";
		Sleep(1000);
		break;
	case 4:
		break;
	}
}

bool Admin::changeName(const string& name)
{
	if (Information::changeName(name) == false)
		return false;
	return true;
}

void Admin::changeSex(const string& sex)
{
	this->_sex = sex;
}

bool Admin::changeBirthday(const string& dob)
{
	if (Information::changeBirthday(dob) == false)
		return false;
	return true;
}