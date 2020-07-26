#ifndef _BUS_H_
#define _BUS_H_
#include"Header.h"
class Bus {
private: 
	string _ID;//ID cua bus
	string _start; //Dia diem bat dau
	string _end;//Dia diem ket thuc
	string _routeStart;//Lo trinh tu noi bat dau
	string _routeEnd;//Lo trinh tu noi ket thuc
	string _spacing;//Thoi gian gian cach
	string _price[2];//price[0] : gia ve binh thuong , price[1] : gia ve sinh vien
	string** _seat;//cho ngoi 
	int n, m;//size ma tran cho ngoi
	string _Worktime;//thoi gian hoat dong ,Ex: 7:30 -> 19:30
	int _IsActive;// 1:Active , 0:Inactive
public:
	ifstream& ReadFromfile(ifstream& ifs);
	void ShowName();
	int Show(int id);
	~Bus()
	{
		for (int i = 0; i < n; i++)
			delete[]_seat[i];
		delete[]_seat;
	}
};
class BusList
{
private:
	Bus* list;
	int size;
public:
	friend ifstream& operator>>(ifstream& ifs, BusList& list);
	friend ostream& operator<<(ostream& os,BusList List);
	void Show();
	~BusList()
	{
		delete[]list;
	}
};
#endif
