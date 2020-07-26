//#include "Header.h"
#include"BusList.h"
int main() {
	BusList a;
	ifstream f1("../Data\\Buses.txt");
	if (!f1.is_open())
	{
		cout << "Can not open file";
	}
	else
	{
		f1 >> a;
		a.PrintList();
		a.Show();
		f1.close();
	}
	return 0;
}
