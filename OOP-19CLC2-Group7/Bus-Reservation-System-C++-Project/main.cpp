#include "Header.h"
#include "Menu.h"
#include "User.h"
#include "BusList.h"
#include "Admin.h"
#include "List.h"
#include "Passenger.h"


int main() {
	vector<Bus> b;
	ifstream f1("../Data\\Buses.txt");
	if (!f1.is_open())
	{

	}
	else
	{
		while (!f1.eof())
		{
			Bus c;
			f1 >> c;
			if (f1.eof())
				break;
			b.push_back(c);
		}
		cout << b[2] << endl;
		b[2].change("25");
	}
	return 0;
}
