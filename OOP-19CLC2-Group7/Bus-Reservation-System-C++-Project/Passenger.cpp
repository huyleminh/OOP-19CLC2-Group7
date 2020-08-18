#include "Passenger.h"

//Constructor
Passenger::Passenger() : Information() {
	this->_type = "Normal";
}

Passenger::Passenger(const Passenger& p) : Information(p) {
	this->_user = p._user;
	this->_type = p._type;
}

//Operator
Passenger& Passenger::operator =(const Passenger& p) {
	Information::operator =(p);
	this->_user = p._user;
	this->_type = p._type;
	return *this;
}

void Passenger::changeInformation(User& user)
{
	vector<Information> passenger;// tính đọc từ file rồi lưu vào vector
	vector<string> role;
	int pos = -1; // position
	ifstream fin;
	int option;
	string newName;
	string newGender;
	string newDob;
	int stop = 1;
	fin.open(".\\Data\\Passenger.txt");

	if (!fin.is_open())
	{
		cout << "Can not open file";
	}

	else
	{
		Information infotemp;
		string roletemp = "";
		while (!fin.eof())
		{
			fin >> infotemp;
			passenger.push_back(infotemp);

		}

		for (int i = 0; i < passenger.size(); i++)
		{

			if (this->_user == user)
			{
				pos = i;
			}
		}

		do {

			cout << "1.Name" << endl;
			cout << "2.Sex" << endl;
			cout << "3.Date of birth" << endl;

			cout << "Choose the option you want to edit(1-3):";

			do {
				cin >> option;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore(32767, '\n');
				}

				if (option < 1 || option > 3)
				{
					cout << "Invaild choice!!! Choose again: ";
				}
			} while (option < 1 || option > 3);

			if (option == 1)
			{
				cout << "Enter new name: ";
				getline(cin, newName);
				changeName(newName);
			}

			if (option == 2)
			{
				cout << "Input your new gender: ";
				getline(cin, newGender);
				changeSex(newGender);
			}

			if (option == 3)
			{

				cout << "Input example: 01/01/2001" << endl;
				cout << "Enter your new Dob: " << endl;
				getline(cin, newDob);
				changeBirthday(newDob);
			}

			cout << "Do you want to continue edit: ";
			cout << "1.Yes" << endl;
			cout << "0.No" << endl;
			cin >> stop;
		} while (stop == 1);
	}

	fin.close();
}

bool Passenger::changeName(const string& name)
{
	if(Information::changeName(name) == 1)
		return true;
	return false;
}

void Passenger::changeSex(const string& sex)
{
	Information::changeSex(sex);
}

bool Passenger::changeBirthday(const string& dob)
{
	if (Information::changeBirthday(dob) == 1)
	{
		return true;
	}
	return false;
}


ifstream& operator >>(ifstream& in, Passenger& p) {
	in >> (Information&)(p);

	string line = "";
	getline(in, p._type, '\n');

	return in;
}

ofstream& operator <<(ofstream& out, const Passenger& p) {
	out << (Information const&)(p);
	out << p._type << endl;
	return out;
}

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