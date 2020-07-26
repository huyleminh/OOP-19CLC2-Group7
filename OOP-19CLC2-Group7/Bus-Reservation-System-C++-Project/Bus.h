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
	string _priceNormal;//gia ve binh thuong ,
	string _priceStudent;// gia ve sinh vien
	vector<vector<string>> _seat;//cho ngoi 
	int n, m;//size ma tran cho ngoi
	string _Starttime;//thoi gian hoat dong ,Ex: 7:30 -> 19:30
	string _Endtime;
	bool _IsActive;// 1:Active , 0:Inactive
public:
	ifstream& ReadFromfile(ifstream& ifs);
	int Show(int id);
	friend ostream& operator<<(ostream& os, Bus bus);
};

#endif
