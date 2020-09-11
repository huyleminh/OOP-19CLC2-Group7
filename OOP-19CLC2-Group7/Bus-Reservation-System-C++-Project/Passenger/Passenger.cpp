#include "Passenger.h"

//Constructor
Passenger::Passenger() : Information() {
	this->_type = "Normal";
}

Passenger::Passenger(const Passenger& p) : Information(p) {
	this->_type = p._type;
}

//Operator
Passenger& Passenger::operator =(const Passenger& p) {
	Information::operator =(p);
	this->_type = p._type;
	return *this;
}

ifstream& operator >>(ifstream& in, Passenger& p) {
	in >> (Information&)(p);

	getline(in, p._type, '\n');

	return in;
}

ofstream& operator <<(ofstream& out, const Passenger& p) {
	out << (Information const&)(p);
	out << p._type << endl;
	return out;
}

//Need to fix 
istream& operator >>(istream& in, Passenger& p) {
	in >> (Information&)(p);
	cout << "Choose your type: " << endl;
	cout << "1. Student.\n";
	cout << "2. Normal.\n";

	string option;
	getline(cin, option, '\n');
	if (option == "1")
		p._type = "Student";
	else
		p._type = "Normal";

	return in;
}

ostream& operator <<(ostream& out, const Passenger& p) {
	out << (Information const&)(p);
	out << "Type: " << p._type << endl;
	return out;
}


//Methods change information
void Passenger::changeInformation(User& user)
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
		cin.ignore(32767, '\n');
		goto OPTION;
	}

	if (option > 4 || option < 1)  {
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
			cout << "Fail to change day of birth.\n";
		Sleep(1000);
		break;
	case 4:
		break;
	}
}

bool Passenger::changeName(const string& name)
{
	if (Information::changeName(name) == 1)
		return true;
	return false;
}

void Passenger::changeSex(const string& sex)
{
	this->_sex = sex;
}

bool Passenger::changeBirthday(const string& dob) {
	if (Information::changeBirthday(dob) == 1)
		return true;
	return false;
}