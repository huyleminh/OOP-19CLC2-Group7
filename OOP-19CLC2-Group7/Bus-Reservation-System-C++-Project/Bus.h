#ifndef _BUS_H_
#define _BUS_H_

#include"Header.h"

class Bus {
private:
	string _ID;						//ID cua bus
	string _start;					//Dia diem bat dau
	string _end;					//Dia diem ket thuc
	string _routeStart;				//Lo trinh tu noi bat dau
	string _routeEnd;				//Lo trinh tu noi ket thuc
	string _spacing;				//Thoi gian gian cach
	string _normalPrice;			//gia ve binh thuong ,
	string _studentPrice;			// gia ve sinh vien
	vector<vector<string>> _seat;	//cho ngoi 
	int _rows, _cols;				//size ma tran cho ngoi
	string _Starttime;				//thoi gian hoat dong ,Ex: 7:30 -> 19:30
	string _Endtime;
	bool _IsActive;					// 1:Active , 0:Inactive
	vector<string> _stations;		//List stations

	//construct for stations
	void createStations();

public:
	//Default constructor
	Bus();

	//Operator
	bool operator==(const Bus& b);
	Bus& operator=(const Bus& b);
	friend ifstream& operator >>(ifstream& ifs, Bus& bus);
	friend ofstream& operator <<(ofstream& ofs, const Bus& bus);
	friend ostream& operator<<(ostream& os, const Bus& bus);
	friend istream& operator>>(istream& is, Bus& bus);
	
	//Methods
	void show(string Id);

	bool changeID();
	bool changePosition();
	bool changeRoute();
	bool changeSpacing();
	bool changePrice();
	bool changeSeat();
	bool changeTime();
	bool changeActive();
	void change(string Id);//Nguoi ta nhap id muon doi, roi goi ham change cua tung bus ra o ham main, bus nao co id giong thi doi

	//Show list station that this go through
	vector<string> listOfStationGoThrough() const;

	friend class Admin;
};

#endif
