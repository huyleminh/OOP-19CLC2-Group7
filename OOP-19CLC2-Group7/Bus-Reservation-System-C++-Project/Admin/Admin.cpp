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

void Admin::addDriver()
{
	List<Driver> d;

	d.loadListDataFromFile("../Data\\Driver.txt");
	cout << "!!!!Driver List!!!!" << endl;
	for (int i = 0; i < d.size(); i++)
	{
		cout << "Driver " << i + 1 << endl;
		cout << d[i] << endl;
	}

	Driver tmp;
	cout << "Input new driver you want to ADD" << endl;
	cin >> tmp;

	// Tu tao username bang ho va ten
	vector<string> user = Tokenizer::split(tmp._name, " ");
	string username = Tokenizer::join(user, "");
	tmp.updateUsername(username);

	if (d.includes(tmp) == true)
	{
		cout << "The driver you want to ADD already have in data" << endl;
		system("pause");
		return;
	}

	d.push_back(tmp);
	//Save to file Driver.txt
	d.saveListDataToFile("../Data\\Driver.txt");

	//Save to User.txt
	List<User> u;
	u.loadListDataFromFile("../Data\\Users.txt");
	User driver;

	driver._username = tmp._username;
	driver._password = "1";
	driver._role = "Driver";

	u.push_back(driver);

	u.saveListDataToFile("../Data\\Users.txt");
}

void Admin::deleteDriver()
{
	List<Driver> d;
	//Erase in driver.txt

	d.loadListDataFromFile("../Data\\Driver.txt");
	cout << "!!!!Driver List!!!!" << endl;
	for (int i = 0; i < d.size(); i++)
	{
		cout << "Driver " << i + 1 << endl;
		cout << d[i] << endl;
	}

	Driver tmp;
	cout << "Input username of driver you want to delete: " << endl;
	while (getchar() != '\n');
	getline(cin, tmp._username, '\n');

	//Check xem co nguoi do co trong list hay khong
	if (d.includes(tmp)==false)
	{
		cout << "Error: That username is not exist in data" << endl;
		system("pause");
		return;
	}

	for (int i = 0; i < d.size(); i++)
	{
		if (d.getItemInData(i)._username == tmp._username)
		{
			d.erase(i);
			i--;
		}
	}
	d.saveListDataToFile("../Data\\Driver.txt");

	//Erase in User.txt
	List<User> u;
	u.loadListDataFromFile("../Data\\Users.txt");
	
	for (int i = 0; i < u.size(); i++)
	{
		if (u.getItemInData(i)._username == tmp._username)
		{
			u.erase(i);
			i--;
		}
	}

	u.saveListDataToFile("../Data\\Users.txt");
	cout << "Delete success fully!!!" << endl;
	system("pause");
}

void Admin::editDriver()
{
	List<Driver> d;
	

	d.loadListDataFromFile("../Data\\Driver.txt");
	//hien ra list driver
	cout << "!!!!Driver List!!!!" << endl;
	for (int i = 0; i < d.size(); i++)
	{
		cout << "Driver " << i + 1 << endl;
		cout << d[i] << endl;
	}

	Driver tmp;
	cout << "Input username of driver you want to edit: " << endl;
	while (getchar() != '\n');
	getline(cin, tmp._username, '\n');

	//Check xem co nguoi do co trong list hay khong
	if (d.includes(tmp) == false)
	{
		cout << "Error: That username is not exist in data" << endl;
		system("pause");
		return;
	}

	for (int i = 0; i < d.size(); i++)
	{
		if (d.getItemInData(i)._username == tmp._username)
		{
			User s;//bien tam de dung ham changeinformation.

			d.getItemInData(i).changeInformation(s);
		}
	}
	d.saveListDataToFile("../Data\\Driver.txt");

	//Ko can edit trong user.txt
}

void Admin::addBus()
{
	List<Bus> b;
	b.loadListDataFromFile("../Data\\Buses.txt");
	
	cout << "~~~~~BUS LIST~~~~~" << endl;
	for (int i = 0; i < b.size(); i++)
	{
		cout << "Bus " << i + 1 << endl;
		cout << b.getItemInData(i) << endl;
	}

	Bus n;
	cout << "Input data for new Bus" << endl;
	cin >> n;

	if (b.includes(n) == true)
	{
		cout << "That ID bus has existed in bus data" << endl;
		system("pause");
		return;
	}

	b.push_back(n);

	b.saveListDataToFile("../Data\\Buses.txt");
	cout << "Add successfully!!!!" << endl;
	system("pause");
}

void Admin::deleteBus()
{
	List<Bus> b;
	b.loadListDataFromFile("../Data\\Buses.txt");

	cout << "~~~~~BUS LIST~~~~~" << endl;
	for (int i = 0; i < b.size(); i++)
	{
		cout << "Bus " << i + 1 << endl;
		cout << b.getItemInData(i) << endl;
	}

	Bus n;
	cout << "Input Id bus you want to delete: " << endl;
	cin >> n._ID;

	if (b.includes(n) == false)
	{
		cout << "Error: That id bus is not exist in Bus data" << endl;
		system("pause");
		return;
	}

	for (int i = 0; i < b.size(); i++)
	{
		if (b.getItemInData(i)._ID == n._ID)
			b.erase(i);
	}

	b.saveListDataToFile("../Data\\Buses.txt");
	cout << "Delete successfully!!!" << endl;
	system("pause");
}

void Admin::editBus()
{
	List<Bus> b;
	b.loadListDataFromFile("../Data\\Buses.txt");

	cout << "~~~~~BUS LIST~~~~~" << endl;
	for (int i = 0; i < b.size(); i++)
	{
		cout << "Bus " << i + 1 << endl;
		cout << b.getItemInData(i) << endl;
	}

	Bus n;
	cout << "Input Id bus you want to edit: " << endl;
	cin >> n._ID;

	if (b.includes(n) == false)
	{
		cout << "Error: That id bus is not exist in Bus data" << endl;
		system("pause");
		return;
	}

	for (int i = 0; i < b.size(); i++)
	{
		if (b.getItemInData(i)._ID == n._ID)
		{
			b.getItemInData(i).change(n._ID);
		}
	}


}

void Admin::editAnnounce(Announcement &a)
{
	int index;
	cout << "Input the order of announcement you want to edit" << endl;
	cin >> index;
	if (index - 1 > a.title.size() || index - 1 < 0)
	{
		cout << "There is no announcement like your index" << endl;
		return;
	}
	for (int i = 0; i < a.title.size(); i++)
	{
		if (index - 1 == i)
		{
		MENU:
			string choice;
			cout << "What do you want to edit?" << endl;
			cout << "1:Title" << endl;
			cout << "2:Content" << endl;
			cin >> choice;

			if (!ValidateInputWorkflow::validateMenuOption(1, 2, choice))
				goto MENU;

			if (choice == "1")
			{
				string ti;
				cout << "Old title: " << a.title[i] << endl;
				cout << "Your new title: ";
				while (getchar() != '\n');
				getline(cin, ti,'\n');
				a.title[i] = "\t" + ti;

				string t = " .Chinh sua vao luc  ";
				time_t info = std::time(NULL);
				tm* now = localtime(&info);
				t = t + to_string(now->tm_hour) + ":" + to_string(now->tm_min) + ":" + to_string(now->tm_sec) + " ngay " + to_string(now->tm_mday) + "/" + to_string(now->tm_mon + 1) + "/" + to_string(now->tm_year + 1900);
				a.time[i] = a.time[i] + t;
			}

			else
			{
				string c;
				cout << "Old Content: " << a.content[i] << endl;
				cout << "Your new content: ";
				while (getchar() != '\n');
				getline(cin, c,'\n');
				a.content[i] = c;

				string t = " .Chinh sua vao luc  ";
				time_t info = std::time(NULL);
				tm* now = localtime(&info);
				t = t + to_string(now->tm_hour) + ":" + to_string(now->tm_min) + ":" + to_string(now->tm_sec) + " ngay " + to_string(now->tm_mday) + "/" + to_string(now->tm_mon + 1) + "/" + to_string(now->tm_year + 1900);
				a.time[i] = a.time[i] + t;
			}
		}
	}
	cout << "Edit successfully!!!" << endl;
}

void Admin::addAnnounce(Announcement& a)
{
	string t1 = "\t";
	string tmp;
	cout << "Your Title: ";
	getline(cin, tmp);
	t1 = t1 + tmp;
	a.title.push_back(t1);

	cout << "Content: " << endl;
	getline(cin, tmp);
	a.content.push_back(tmp);

	string t = "Duoc dang vao ";
	time_t info = std::time(NULL);
	tm* now = localtime(&info);
	t = t + to_string(now->tm_hour) + ":" + to_string(now->tm_min) + ":" + to_string(now->tm_sec) + " ngay " + to_string(now->tm_mday) + "/" + to_string(now->tm_mon + 1) + "/" + to_string(now->tm_year + 1900);
	a.time.push_back(t);

}

void Admin::deleteAnnounce(Announcement &a)
{
	int index;
	cout << "Input the order of announcement you want to delete" << endl;
	cin >> index;
	if (index - 1 > a.title.size() || index - 1 < 0)
	{
		cout << "There is no announcement like your index" << endl;
		return;
	}
	for (int i = 0; i < a.title.size(); i++)
	{
		if (i == index - 1)
		{
			a.title.erase(a.title.begin() + i);
			a.content.erase(a.content.begin() + i);
			a.time.erase(a.time.begin() + i);
		}
	}
	cout << "Delete successfully!!!" << endl;
}
