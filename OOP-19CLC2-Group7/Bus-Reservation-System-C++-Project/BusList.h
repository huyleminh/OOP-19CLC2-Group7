#ifndef BUS_LIST_H
#define BUS_LIST_H
#include"Bus.h"
class BusList
{
private:
	Bus* list;
	int size;
public:
	friend ifstream& operator>>(ifstream& ifs, BusList& list);
	void PrintList();
	void Show();
	~BusList()
	{
		delete[]list;
	}
};
#endif
