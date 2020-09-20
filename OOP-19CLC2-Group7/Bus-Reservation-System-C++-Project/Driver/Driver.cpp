#include "Driver.h"
#include "../Workflow/ValidateInput/ValidateInputWorkflow.h"

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
	string day_off, Reason;
DATE_INPUT:
	cout << "Enter the date you want to take leave (dd/mm/yyyy): \n";
	getline(cin, day_off, '\n');

	if (!Date::isValidDate(day_off))
		goto DATE_INPUT;

	Date current;
	Date check(day_off);
	if (Date::calcDays(check) < Date::calcDays(current))
		goto DATE_INPUT;

	cout << "The reason for your leave: ";
	getline(cin, Reason, '\n');

	ofstream f("../Data/DayOff.txt", ios::app);
	if (!f.is_open()) {
		cout << "Can not open DayOff.txt" << endl;
		return;
	}
	f << this->_username << " " << day_off << ":" << Reason << endl;
	f.close();

	cout << "Request for day-off successfully." << endl;
	system("pause");
}

int Driver::countDayOffHistory()
{
	ifstream f("../Data/DayOff.txt");

	if (!f.is_open())
	{
		cout << "Cannot open DayOff.txt" << endl;
		return -1;
	}
	vector<string> temp;
	vector<string> v_date;
	int num = 0;

	Date date;
	Tokenizer a;
	vector<string> m_date = a.split(date.toString(), "/");

	while (!f.eof())
	{
		string id;
		getline(f, id, ' ');

		string day;
		getline(f, day, ':');

		string reason;
		getline(f, reason, '\n');

		temp.push_back(id);
		v_date.push_back(day);
	}

	for (int i = 0; i < temp.size(); i++)
		if (temp[i] == this->_username)
		{
			Tokenizer b;
			vector<string> temp_date = b.split(v_date[i], "/");

			if (stoi(m_date[1]) == stoi(temp_date[1]) && stoi(m_date[2]) == stoi(v_date[2]))
			{
				num++;
			}
		}

	f.close();
	return num;
}

int Driver::salary()
{
	int salary = 0;
	int dayoff = this->countDayOffHistory();
	if (dayoff == -1)
		return -1;
	salary = BASE_SALARY / 30 * (30 - dayoff);
	return salary;
}

void Driver::viewDayoff()
{
	ifstream f("../Data/DayOff.txt");

	if (!f.is_open())
	{
		cout << "Cannot open DayOff.txt" << endl;
		return;
	}

	vector<string> t_id;
	vector<string> t_dayandreason;

	while (!f.eof())
	{
		string id;
		getline(f, id, ' ');

		string dayandreason;
		getline(f, dayandreason, '\n');

		t_id.push_back(id);
		t_dayandreason.push_back(dayandreason);
	}

	for(int i = 0; i < t_id.size(); i++)
	{
		if(t_id[i] == this->_username)
		{
			cout << this->_username << t_dayandreason[i];
		}
	}

	f.close();
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