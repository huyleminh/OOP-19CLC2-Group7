#include "Header.h"
#include"Bus.h"
int main() {
	BusList a;
	ifstream f1("D:\\OOP-19CLC2-Group7\\Data\\Buses.txt");
	if (!f1.is_open())
	{
		cout << "Can not open file";
	}
	else
	{
		f1 >> a;
		cout << a <<endl;
		a.Show();
		f1.close();
	}
	return 0;
}
