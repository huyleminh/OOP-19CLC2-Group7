#include "Bus.h"
#include"../Library/Tokenizer.h"

//construct for stations
void Bus::createStations() {
	this->_stations = Tokenizer::split(this->_routeStart, " - ");
	vector<string> tmp = Tokenizer::split(this->_routeEnd, " - ");
	vector<string>::iterator iter;

	for (int i = 0; i < tmp.size(); i++) {
		//Check if a station in end route is include in start route or not, if not then push it back to stations
		iter = std::find(this->_stations.begin(), this->_stations.end(), tmp[i]);

		if (iter == this->_stations.end())
			this->_stations.push_back(tmp[i]);
	}
}

//Default constructor
Bus::Bus() {
	this->_ID = "000";
	this->_start = "Null";
	this->_end = "Null";
	this->_routeStart = "Null";
	this->_routeEnd = "Null";
	this->_spacing = "Minute";

	//Fixed price
	this->_normalPrice = "6000";
	this->_studentPrice = "3000";

	//Row
	this->_rows = 14;

	//Colum
	this->_cols = 4;

	//Empty seat
	this->_seat.resize(_rows);
	for (int i = 0; i < this->_rows; i++)
	{
		this->_seat[i].resize(_cols);
		for (int j = 0; j < this->_cols; j++)
			this->_seat[i][j] = ("Empty");
	}
	//Default time
	this->_Starttime = "00:00";
	this->_Endtime = "00:00";
	this->_IsActive = false;
}

//Operator
ifstream& operator >>(ifstream& ifs, Bus& bus) {
	string line = "";
	//ignore line
	getline(ifs, line, '\n');

	getline(ifs, line, '\n');
	bus._ID = line;

	getline(ifs, line, '\n');
	bus._start = line;

	getline(ifs, line, '\n');
	bus._end = line;

	getline(ifs, line, '\n');
	bus._routeStart = line;

	getline(ifs, line, '\n');
	bus._routeEnd = line;

	getline(ifs, line, '\n');
	bus._spacing = line;

	getline(ifs, line, '\n');
	bus._normalPrice = line;

	getline(ifs, line, '\n');
	bus._studentPrice = line;
	if (ifs.eof())
		return ifs;
	getline(ifs, line, ' ');
	bus._rows = stoi(line);
	getline(ifs, line, '\n');
	bus._cols = stoi(line);

	bus._seat.resize(bus._rows);
	for (int i = 0; i < bus._rows; i++)
	{
		bus._seat[i].resize(bus._cols);
		for (int j = 0; j < bus._cols; j++)
		{
			if (j == bus._cols - 1)
			{
				getline(ifs, bus._seat[i][j], '\n');
			}
			else
				getline(ifs, bus._seat[i][j], ' ');
		}
	}

	getline(ifs, line, '-');
	bus._Starttime = line;

	getline(ifs, line, '\n');
	bus._Endtime = line;

	ifs >> bus._IsActive;
	getline(ifs, line, '\n');

	//Create list of station that this bus run across from start route and end route
	bus.createStations();
	return ifs;
}

ofstream& operator <<(ofstream& ofs, const Bus& bus) {
	ofs << endl;
	ofs << bus._ID << endl;
	ofs << bus._start << endl;
	ofs << bus._end << endl;
	ofs << bus._routeStart << endl;
	ofs << bus._routeEnd << endl;
	ofs << bus._spacing << endl;
	ofs << bus._normalPrice << endl;
	ofs << bus._studentPrice << endl;
	ofs << bus._rows << " ";
	ofs << bus._cols << endl;

	for (int i = 0; i < bus._rows; i++)
	{
		for (int j = 0; j < bus._cols; j++)
			ofs << bus._seat[i][j] << " ";
		ofs << endl;
	}

	ofs << bus._Starttime << "-" << bus._Endtime << endl;
	ofs << ((bus._IsActive == true) ? 1 : 0) << endl;

	return ofs;
}


void Bus::show(string id)
{
	if (this->_ID == id)
	{
		system("cls");
		int i;
		cout << "What information you want to see?" << endl;
		cout << "1. Name and worktime" << endl;
		cout << "2. Route" << endl;
		cout << "3. Price" << endl;
		cout << "4. Seat" << endl;
		cout << "5. Back to menu" << endl;
OPTION:
		cout << "Choose your option: ";
		cin >> i;

		if (cin.fail()) {
			cout << "Wrong option, please try again." << endl;
			goto OPTION;
		}

		switch (i)
		{
		case 1:
		{
			system("cls");
			cout << "Number: " << this->_ID << endl;
			cout << "Name: " << this->_start << "-" << this->_end << endl;
			cout << "Work time: " << this->_Starttime << " - " << this->_Endtime << endl;
			cout << "This bus is: ";
			if (this->_IsActive == 0)
				cout << "Inactive" << endl;
			else
				cout << "Active" << endl;
			system("pause");
			break;
		}
		case 2:
		{
			system("cls");
			cout << "****Route from " << this->_start << " to " << this->_end << ": " << endl;
			cout << this->_routeStart << endl;
			cout << "****Route from " << this->_end << " to " << this->_start << ": " << endl;
			cout << this->_routeEnd << endl;
			cout << "****Spacing time: " << this->_spacing << endl;
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			cout << "$$$$Price$$$$" << endl;
			cout << "Normal price: " << this->_normalPrice << " vnd" << endl;
			cout << "Student price: " << this->_studentPrice << " vnd" << endl;
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			cout << "****SEAT MAP****" << endl;

			for (int i = 0; i < this->_rows; i++)
			{
				for (int j = 0; j < this->_cols; j++)
				{
					if (j == this->_cols - 1)
						cout << " " << j + 1 + (i * this->_cols) << ": " << this->_seat[i][j] << "\n";
					else
					{
						cout << " " << j + 1 + (i * this->_cols) << ": " << this->_seat[i][j] << "\t";

					}

				}
			}
			system("pause");
			break;
		}
		case 5:
			return;
		default: 
			cout << "Unvalid option, you will be redirect to menu." << endl;
			Sleep(1000);
			break;
		}
	}
	else {
		return;
	}
	this->show(id);
}

bool Bus::operator==(const Bus& b)
{
	if (this->_ID == b._ID)
		return 1;
	return 0;
}

Bus& Bus::operator=(const Bus& b)
{
	this->_ID = b._ID;
	this->_start = b._start;
	this->_end = b._end;
	this->_routeStart = b._routeStart;
	this->_routeEnd = b._routeEnd;
	this->_spacing = b._spacing;
	this->_normalPrice = b._normalPrice;
	this->_studentPrice = b._studentPrice;
	this->_rows = b._rows;
	this->_cols = b._cols;
	this->_seat.resize(this->_rows);
	for (int i = 0; i < this->_rows; i++)
	{
		this->_seat[i].resize(this->_cols);
		for (int j = 0; j < this->_cols; j++)
		{
			this->_seat[i][j] = b._seat[i][j];
		}
	}
	this->_Starttime = b._Starttime;
	this->_Endtime = b._Endtime;
	this->_IsActive = b._IsActive;
	return*this;
}
ostream& operator<<(ostream& os, const Bus& bus)
{
	cout << "ID: " << bus._ID << endl;
	cout << "Name: " << bus._start << "-" << bus._end << endl;
	cout << "Worktime: " << bus._Starttime << "-" << bus._Endtime << endl;
	return os;
}

istream& operator>>(istream& is, Bus& bus)
{
	cout << "Input ID: " << endl;
	while (getchar() != '\n');
	getline(is, bus._ID, '\n');

	cout << "Start position: " << endl;
	getline(is, bus._start, '\n');

	cout << "End position: " << endl;
	getline(is, bus._end, '\n');

	cout << "Start ROUTE(Ex:X-Y-Z): " << endl;
	getline(is, bus._routeStart, '\n');

	cout << "End ROUTE: " << endl;
	getline(is, bus._routeEnd, '\n');

	cout << "Spacing time(Ex:7-10 phut): " << endl;
	getline(is, bus._spacing, '\n');

	cout << "Normal price(Ex:5 000):" << endl;
	getline(is, bus._normalPrice, '\n');

	cout << "Student price(Ex:3 000):" << endl;
	getline(is, bus._studentPrice, '\n');

	cout << "Rows of seats :" << endl;
	is >> bus._rows;

	cout << "Colums of seats" << endl;
	is >> bus._cols;

	bus._seat.resize(bus._rows);
	for (int i = 0; i < bus._rows; i++)
	{
		bus._seat[i].resize(bus._cols);
		for (int j = 0; j < bus._cols; j++)
		{
			bus._seat[i][j] = "Empty";
		}
	}

	while (getchar() != '\n');
	cout << "Worktime" << endl;
	cout << "Start time(Ex: 13:00): " << endl;
	getline(is, bus._Starttime, '\n');

	cout << "End time: " << endl;
	getline(is, bus._Endtime, '\n');

	cout << "Is Active?(1/0)" << endl;
	is >> bus._IsActive;

	//Create list stations
	bus.createStations();
	
	return is;
}
bool Bus::changeID()
{
	int choice;
	cout << "Bus ID " << this->_ID << endl;
	cout << "Do you want to change it ?" << endl;
	cout << "1: Yes" << endl;
	cout << "2: No" << endl;
	cin >> choice;

	if (choice == 2)
		return 0;

	string id;
	cout << "Input new ID :";
	cin >> id;

	//doc lai file de ghi lai
	vector<Bus> a;
	ifstream f1("../Data\\Buses.txt");
	if (!f1.is_open())
	{
		cout << "Can not open buses.txt" << endl;
		return 0;
	}
	else
	{
		while (!f1.eof())
		{
			Bus tmp;
			f1 >> tmp;

			if (f1.eof())//tranh doc du o cuoi file
				break;

			a.push_back(tmp);
		}
		for (int i = 0; i < a.size(); i++)
		{
			//sua id va ghi lai
			if (this->_ID == a[i]._ID)
			{

				a[i]._ID = id;

				ofstream out("../Data\\Buses.txt");
				if (!out.is_open())
				{
					cout << "Can not open Buses.txt" << endl;
					return 0;
				}
				else
				{
					for (int i = 0; i < a.size(); i++)
					{
						out << a[i];
					}
					cout << "Change id successfully!!!" << endl;
					out.close();
					return 1;
				}
			}
		}
	}

}
bool Bus::changePosition()// tuong tu ham changeID
{

	int choice;
	cout << "Bus ID " << this->_ID << endl;
	cout << "Start position: " << this->_start << endl;
	cout << "Final position: " << this->_end << endl;
	cout << "What position you want to change ?" << endl;
	cout << "1: Start" << endl;
	cout << "2: End" << endl;
	cin >> choice;

	system("cls");
	string position;

	while (getchar() != '\n');

	cout << "Your alternative position: " << endl;
	getline(cin, position);

	vector<Bus> a;
	ifstream f1("../Data\\Buses.txt");
	if (!f1.is_open())
	{
		cout << "Can not open buses.txt" << endl;
		return 0;
	}
	else
	{
		while (!f1.eof())
		{
			Bus tmp;
			f1 >> tmp;
			if (f1.eof())
				break;
			a.push_back(tmp);
		}
		for (int i = 0; i < a.size(); i++)
		{
			if (this->_ID == a[i]._ID)
			{
				if (choice == 1)
					a[i]._start = position;
				else
					a[i]._end = position;

				ofstream out("../Data\\Buses.txt");
				if (!out.is_open())
				{
					cout << "Can not open Buses.txt" << endl;
					return 0;
				}
				else
				{
					for (int i = 0; i < a.size(); i++)
					{
						out << a[i];
					}

					if (choice == 1)
						cout << "Change start position successfully!!!" << endl;
					else
						cout << "Change end position successfully!!!" << endl;
					out.close();
					return 1;
				}
			}
		}
	}

}
bool Bus::changeRoute()
{

	int choice;
	cout << "Bus ID " << this->_ID << endl;
	cout << "Start route: " << this->_routeStart << endl;
	cout << "\nEnd route: " << this->_routeEnd << endl;
	cout << "\nWhat route you want to change ?" << endl;
	cout << "1: Start route" << endl;
	cout << "2: End route" << endl;
	cin >> choice;
	system("cls");

	string position;

	vector<string> route;

	int n;
	cout << "How many position your route have?" << endl;
	cin >> n;

	if (choice == 1)
		cout << "START ROUTE" << endl;
	else
		cout << "END ROUTE" << endl;
	cout << "Position ";
	while (getchar() != '\n');
	//cho nguoi ta nhap tung position de tranh bi sai, roi noi chuoi lai bang ham join
	for (int i = 0; i < n; i++)
	{
		string position;
		cout << i + 1 << ": ";

		getline(cin, position);

		route.push_back(position);
	}
	string routeJoin = Tokenizer::join(route, " - ");
	vector<Bus> a;
	ifstream f1("../Data\\Buses.txt");
	if (!f1.is_open())
	{
		cout << "Can not open buses.txt" << endl;
		return 0;
	}
	else
	{
		while (!f1.eof())
		{
			Bus tmp;
			f1 >> tmp;
			if (f1.eof())
				break;
			a.push_back(tmp);
		}
		for (int i = 0; i < a.size(); i++)
		{
			if (this->_ID == a[i]._ID)
			{
				if (choice == 1)
					a[i]._routeStart = routeJoin;
				else
					a[i]._routeEnd = routeJoin;

				ofstream out("../Data\\Buses.txt");
				if (!out.is_open())
				{
					cout << "Can not open Buses.txt" << endl;
					return 0;
				}
				else
				{
					for (int i = 0; i < a.size(); i++)
					{
						out << a[i];
					}

					if (choice == 1)
						cout << "Change start route successfully!!!" << endl;
					else
						cout << "Change end route successfully!!!" << endl;
					out.close();
					return 1;
				}
			}
		}
	}

}
bool Bus::changeSpacing()
{
	int choice;
	cout << "Bus ID " << this->_ID << endl;
	cout << "Spacing time: " << this->_spacing << endl;
	cout << "Do you want to change it ?" << endl;
	cout << "1:Yes" << endl;
	cout << "2:No" << endl;
	cin >> choice;
	if (choice == 2)
		return 0;

	system("cls");

	string spacing;
	cout << "Your alternative spacing time(Ex:10-15 phut): ";
	while (getchar() != '\n');
	getline(cin, spacing);

	vector<Bus> a;
	ifstream f1("../Data\\Buses.txt");
	if (!f1.is_open())
	{
		cout << "Can not open buses.txt" << endl;
		return 0;
	}
	else
	{
		while (!f1.eof())
		{
			Bus tmp;
			f1 >> tmp;
			if (f1.eof())
				break;
			a.push_back(tmp);
		}
		for (int i = 0; i < a.size(); i++)
		{
			if (this->_ID == a[i]._ID)
			{
				a[i]._spacing = spacing;

				ofstream out("../Data\\Buses.txt");
				if (!out.is_open())
				{
					cout << "Can not open Buses.txt" << endl;
					return 0;
				}
				else
				{
					for (int i = 0; i < a.size(); i++)
					{
						out << a[i];
					}
					cout << "Change spacing time successfully!!!" << endl;
					out.close();
					return 1;
				}
			}
		}
	}

}
bool Bus::changePrice()
{

	int choice;
	cout << "Bus ID " << this->_ID << endl;
	cout << "Student Price: " << this->_studentPrice << endl;
	cout << "Normal Price: " << this->_normalPrice << endl;
	cout << "What price do you want to change?" << endl;
	cout << "1:Student Price" << endl;
	cout << "2:Normal Price" << endl;
	cin >> choice;

	system("cls");
	string price;
	while (getchar() != '\n');
	if (choice == 1)
		cout << "Your student price(Ex:3000): " << endl;
	else
		cout << "Your normal price(Ex:7000): " << endl;
	getline(cin, price);

	vector<Bus> a;
	ifstream f1("../Data\\Buses.txt");
	if (!f1.is_open())
	{
		cout << "Can not open buses.txt" << endl;
		return 0;
	}
	else
	{
		while (!f1.eof())
		{
			Bus tmp;
			f1 >> tmp;
			if (f1.eof())
				break;
			a.push_back(tmp);
		}
		for (int i = 0; i < a.size(); i++)
		{
			if (this->_ID == a[i]._ID)
			{
				if (choice == 1)
					a[i]._studentPrice = price;
				else
					a[i]._normalPrice = price;

				ofstream out("../Data\\Buses.txt");
				if (!out.is_open())
				{
					cout << "Can not open Buses.txt" << endl;
					return 0;
				}
				else
				{
					for (int i = 0; i < a.size(); i++)
					{
						out << a[i];
					}

					if (choice == 1)
						cout << "Change student price successfully!!!" << endl;
					else
						cout << "Change normal price successfully!!!" << endl;
					out.close();
					return 1;
				}
			}
		}
	}

}
bool Bus::changeSeat()
{

	int choice;
	cout << "Bus ID " << this->_ID << endl;
	cout << "SEAT" << endl;
	for (int i = 0; i < this->_rows; i++)
	{
		for (int j = 0; j < this->_cols; j++)
		{
			if (j == this->_cols - 1)
				cout << " " << j + 1 + (i * this->_cols) << ": " << this->_seat[i][j] << "\n";
			else
			{
				cout << " " << j + 1 + (i * this->_cols) << ": " << this->_seat[i][j] << "\t";

			}

		}
	}
	cout << "Do you want to change seat?" << endl;
	cout << "1: Yes" << endl;
	cout << "2: No" << endl;
	cout << "NOTE!!!IF YOU CHANGE SEAT ,ALL CUSTOMERS WHO RESERVED SEAT WILL BE ERASE" << endl;
	cin >> choice;

	if (choice == 2)
		return 0;

	system("cls");
	int n, m;
	cout << "Input rows of seats: ";
	cin >> n;
	cout << "Input cols of seats: ";
	cin >> m;

	vector<Bus> a;
	ifstream f1("../Data\\Buses.txt");
	if (!f1.is_open())
	{
		cout << "Can not open buses.txt" << endl;
		return 0;
	}
	else
	{
		while (!f1.eof())
		{
			Bus tmp;
			f1 >> tmp;
			if (f1.eof())
				break;
			a.push_back(tmp);
		}
		for (int i = 0; i < a.size(); i++)
		{
			if (this->_ID == a[i]._ID)
			{
				a[i]._rows = n;
				a[i]._cols = m;
				a[i]._seat.clear();
				a[i]._seat.resize(n);
				for (int j = 0; j < n; j++)
				{
					a[i]._seat[j].resize(m);
					for (int z = 0; z < m; z++)
					{
						a[i]._seat[j][z] = "Empty";
					}
				}
				ofstream out("../Data\\Buses.txt");
				if (!out.is_open())
				{
					cout << "Can not open Buses.txt" << endl;
					return 0;
				}
				else
				{
					for (int i = 0; i < a.size(); i++)
					{
						out << a[i];
					}


					cout << "Change SEAT successfully!!!" << endl;

					out.close();
					return 1;
				}
			}
		}
	}
}

bool Bus::changeTime()
{

	int choice;
	cout << "Bus ID " << this->_ID << endl;
	cout << "Start time: " << this->_Starttime << endl;
	cout << "End time: " << this->_Endtime << endl;
	cout << "What time do you want to change?" << endl;
	cout << "1:Start time" << endl;
	cout << "2:End time" << endl;
	cin >> choice;

	system("cls");
	string time;
	while (getchar() != '\n');
	if (choice == 1)
		cout << "Your start time(Ex: 04:30): " << endl;
	else
		cout << "Your end time(Ex: 20:30): " << endl;
	getline(cin, time);

	vector<Bus> a;
	ifstream f1("../Data\\Buses.txt");
	if (!f1.is_open())
	{
		cout << "Can not open buses.txt" << endl;
		return 0;
	}
	else
	{
		while (!f1.eof())
		{
			Bus tmp;
			f1 >> tmp;
			if (f1.eof())
				break;
			a.push_back(tmp);
		}
		for (int i = 0; i < a.size(); i++)
		{
			if (this->_ID == a[i]._ID)
			{
				if (choice == 1)
					a[i]._Starttime = time;
				else
					a[i]._Endtime = time;

				ofstream out("../Data\\Buses.txt");
				if (!out.is_open())
				{
					cout << "Can not open Buses.txt" << endl;
					return 0;
				}
				else
				{
					for (int i = 0; i < a.size(); i++)
					{
						out << a[i];
					}

					if (choice == 1)
						cout << "Change start time successfully!!!" << endl;
					else
						cout << "Change end time successfully!!!" << endl;
					out.close();
					return 1;
				}
			}
		}
	}

}
bool Bus::changeActive()
{

	int choice;
	cout << "Bus ID " << this->_ID << endl;
	if (this->_IsActive == 1)
	{
		cout << "This bus is active" << endl;
	}
	else
	{
		cout << "This bus is inactive" << endl;
	}

	cout << "Do you want to change it?" << endl;
	cout << "1:Yes" << endl;
	cout << "2:No" << endl;
	cin >> choice;
	if (choice == 2)
		return 0;

	system("cls");

	vector<Bus> a;
	ifstream f1("../Data\\Buses.txt");
	if (!f1.is_open())
	{
		cout << "Can not open buses.txt" << endl;
	}
	else
	{
		while (!f1.eof())
		{
			Bus tmp;
			f1 >> tmp;
			if (f1.eof())
				break;
			a.push_back(tmp);
		}
		for (int i = 0; i < a.size(); i++)
		{
			if (this->_ID == a[i]._ID)
			{
				if (this->_IsActive == true)
					a[i]._IsActive = false;
				else
					a[i]._IsActive = true;
				ofstream out("../Data\\Buses.txt");
				if (!out.is_open())
				{
					cout << "Can not open Buses.txt" << endl;
					return 0;
				}
				else
				{
					for (int i = 0; i < a.size(); i++)
					{
						out << a[i];
					}
					if (this->_IsActive == true)
					{
						cout << "Make this bus to inactive successfully" << endl;
					}
					else
						cout << "Make this bus to active successfully" << endl;
					out.close();
					return 1;
				}
			}
		}
	}
}
void Bus::change(string Id)
{
	if (this->_ID == Id)
	{
		system("cls");
		int choice;
	OPTION:
		cout << "~~~~~~BUS " << this->_ID << "~~~~~~" << endl;
		cout << "What do you want to change?" << endl;
		cout << "1.ID" << endl;
		cout << "2.Position" << endl;
		cout << "3.Route" << endl;
		cout << "4.Spacing time" << endl;
		cout << "5.Price" << endl;
		cout << "6.Seat" << endl;
		cout << "7.Time" << endl;
		cout << "8.Active/Inactive" << endl;
		cout << "0:Back" << endl;
		cout << "Your choice: " << endl;
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
		{
			if (this->changeID() == 1)
			{
				system("pause");
			}
			else
			{
				cout << "Change is fail!" << endl;
				system("pause");
				goto OPTION;
			}
			break;
		}
		case 2:
		{
			if (this->changePosition() == 1)
			{
				system("pause");
			}
			else
			{
				cout << "Change is fail!" << endl;
				system("pause");
				goto OPTION;
			}
			break;
		}
		case 3:
		{

			if (this->changeRoute() == 1)
				system("pause");
			else
			{
				cout << "Change is fail!" << endl;
				system("pause");
				goto OPTION;
			}
			break;
		}
		case 4:
		{
			if (this->changeSpacing() == 1)
				system("pause");
			else
			{
				cout << "Change is fail!" << endl;
				system("pause");
				goto OPTION;
			}
			break;
		}
		case 5:
		{
			if (this->changePrice() == 1)
				system("pause");
			else
			{
				cout << "Change is fail!" << endl;
				system("pause");
				goto OPTION;
			}
			break;
		}
		case 6:
		{
			if (this->changeSeat() == 1)
				system("pause");
			else
			{
				cout << "Change is fail!" << endl;
				system("pause");
				goto OPTION;
			}
			break;
		}
		case 7:
		{
			if (this->changeTime() == 1)
				system("pause");
			else
			{
				cout << "Change is fail!" << endl;
				system("pause");
				goto OPTION;
			}
			break;
		}
		case 8:
		{
			if (this->changeActive() == 1)
				system("pause");
			else
			{
				cout << "Change is fail!" << endl;
				system("pause");
				goto OPTION;
			}
			break;
		}
		case 0:
		{
			return;
		}
		default:
		{
			goto OPTION;
		}
		}
	}
}

//Show list station that this go through
vector<string> Bus::listOfStationGoThrough() const {
	return this->_stations;
}