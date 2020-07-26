#include "BusList.h"

void BusList::PrintList()
{
	for (int i = 0; i < size; i++)
	{
		cout << "~~~~~~BUS " << i << "~~~~~~" << endl;
		cout << this->list[i];
	}
}
void BusList::Show()
{
	int id;
	cout << "Input ID bus you want to see information: ";
	cin >> id;
	int flag = 0;
	for (int i = 0; i < this->size; i++)
	{
		flag += this->list[i].Show(id);
	}
	if (flag == this->size)
		cout << "There is no ID bus like this" << endl;

}
ifstream& operator>>(ifstream& ifs, BusList& list)
{
	ifs >> list.size;
	list.list = new Bus[list.size];
	for (int i = 0; i < list.size; i++)
	{
		list.list[i].ReadFromfile(ifs);
	}
	return ifs;
}