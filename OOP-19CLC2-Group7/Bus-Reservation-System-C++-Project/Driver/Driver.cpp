#include "Driver.h"

//Constructor 
Driver::Driver() :Information() {}

//Copy constructor
Driver::Driver(const Driver& driver) : Information(driver) {}

//Assignment operator
Driver& Driver::operator =(const Driver& driver) {
	Information::operator=(driver);

	return *this;
}

bool Driver::operator==(const Driver& driver)
{
	if (this->_username == driver._username)
		return 1;
	return 0;
}
//File and console operators
ifstream& operator >>(ifstream& in, Driver& driver) {
	in >> (Information&)(driver);
	return in;
}

ofstream& operator <<(ofstream& out, const Driver& driver) {
	out << (Information const&)driver;
	return out;
}

istream& operator >>(istream& in, Driver& driver) {
	in >> (Information&)driver;
	return in;
}

ostream& operator <<(ostream& out, const Driver& driver) {
	out << (Information const&)driver;
	return out;
}


//Methods change information
void Driver::changeInformation(User& user)
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
	{
		cout << "Enter new name you want to change: ";
		getline(cin, inputStr, '\n');

		//Try to change name
		if (this->changeName(inputStr))
			cout << "Change name successfully.\n";
		else
			cout << "Fail to change name, you inputted name might be unvalid name.\n";

		Sleep(1000);
		break;
	}

	case 2:
	{
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
	}

	case 3:
	{
		cout << "Enter your day of birth: ";
		getline(cin, inputStr, '\n');

		if (this->changeBirthday(inputStr))
			cout << "Change birthday successfully.\n";
		else
			cout << "Fail to change day of birth.\n";
		Sleep(1000);
		break;
	}
	
	case 4:
		break;
	}
}

void Driver::Dayoff()
{
	ofstream f("C:\\Users\Bot\Documents\GitHub\OOP-19CLC2-Group7\OOP-19CLC2-Group7\Data\Day-off.txt", ios::app);

	string day_off, Reason;
	cout << "Number of days off remaining: " << this->day_off;

	cout << "Enter the date you want to take leave (dd/mm/yyyy): \n";
	getline(cin, day_off, '\n');

	cout << "The reason for your leave: ";
	getline(cin, Reason, '\n');

	f << this->_name << " " << day_off << " " << Reason << endl;

}

bool Driver::changeName(const string& name)
{
	if (Information::changeName(name) == 1)
		return true;
	return false;
}

void Driver::changeSex(const string& sex)
{
	this->_sex = sex;
}

bool Driver::changeBirthday(const string& dob)
{
	if (Information::changeBirthday(dob) == 1)
		return true;
	return false;
}