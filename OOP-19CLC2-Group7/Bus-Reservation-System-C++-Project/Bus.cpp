#include "Bus.h"

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
	this->_rows = 15;

	//Colum
	this->_cols = 4;

	//Empty seat
	this->_seat.resize(_rows);
	for (int i = 0; i < this->_rows; i++)
		for (int j = 0; j < this->_cols; j++)
			this->_seat[i].push_back("Empty");

	//Default time
	this->_Starttime = "00:00";
	this->_Endtime = "00:00";
	this->_IsActive = false;
}

//Operator
ifstream& operator >>(ifstream& ifs, Bus& bus) {
	string line = "";

	//Read ignore line
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

	getline(ifs, line, ' ');
	bus._rows = stoi(line);
	getline(ifs, line, '\n');
	bus._cols = stoi(line);

	getline(ifs, line, '\n');

	return ifs;
}

ofstream& operator <<(ofstream& ofs, const Bus& bus) {
	ofs << endl;
	ofs << bus._ID;
	ofs << bus._start;
	ofs << bus._end;
	ofs << bus._routeStart;
	ofs << bus._routeEnd;
	ofs << bus._spacing;
	ofs << bus._normalPrice;
	ofs << bus._studentPrice;
	ofs << bus._rows;
	ofs << bus._cols;

	for (int i = 0; i < bus._rows; i++) {
		for (int j = 0; j < bus._cols; j++)
			ofs << bus._seat[i][j] << " ";
		ofs << endl;
	} 
	ofs << endl;

	ofs << bus._Starttime << " - " << bus._Endtime << endl;
	ofs << ((bus._IsActive == true) ? 1 : 0) << endl;

	return ofs;
}
	
// ifstream & Bus::ReadFromfile(ifstream & ifs)
// {
// 	ifs.ignore(100, '\n');

// 	getline(ifs, this->_ID, '\n');
// 	getline(ifs, this->_start, '\n');
// 	getline(ifs, this->_end, '\n');
// 	getline(ifs, this->_routeStart, '.');
// 	getline(ifs, this->_routeEnd, '.');

// 	ifs.ignore(100, '\n');

// 	getline(ifs, this->_spacing, '\n');
// 	getline(ifs, this->_normalPrice, '\n');
// 	getline(ifs, this->_studentPrice, '\n');

// 	ifs >> this->n >> this->m;
// 	this->_seat.resize(n);
// 	ifs.ignore(100, '\n');
// 	for (int i = 0; i < n; i++)
// 	{
// 		this->_seat[i].resize(m);
// 		for (int j = 0; j < m; j++)
// 		{
// 			if (j == m - 1)
// 			{
// 				getline(ifs, this->_seat[i][j], '\n');
// 			}
// 			else
// 				getline(ifs, this->_seat[i][j], ' ');
// 		}
// 	}

// 	getline(ifs, this->_Starttime, '-');
// 	getline(ifs, this->_Endtime, '\n');

// 	ifs >> this->_IsActive;
// 	ifs.ignore(100, '\n');

// 	return ifs;
// }

//  int Bus::Show(int id)
//  {
// 	 if (id == stoi(this->_ID, NULL, 10))
// 	 {
// 		 int i;
// 		 cout << "What information you want to see?" << endl;
// 		 cout << "0: Name,Worktime" << endl;
// 		 cout << "1:Route" << endl;
// 		 cout << "2:Price" << endl;
// 		 cout << "3:Seat" << endl;
// 		 cin >> i;
// 		 switch (i)
// 		 {
// 		 case 0:
// 		 {
// 			 system("cls");
// 			 cout << "ID: " << this->_ID << endl;
// 			 cout << "Name: " << this->_start << "-" << this->_end << endl;
// 			 cout << "Worktime: " << this->_Starttime << " - " << this->_Endtime << endl;
// 			 cout << "Status: ";
// 			 if (this->_IsActive == 0)
// 				 cout << "Inactive" << endl;
// 			 else
// 				 cout << "Active" << endl;
// 			 system("pause");
// 			 break;
// 		 }
// 		 case 1:
// 		 {
// 			 system("cls");
// 			 cout << "Route from " << this->_start << " to " << this->_end << ": " << endl;
// 			 cout << this->_routeStart << endl;
// 			 cout << "Route from " << this->_end << " to " << this->_start << ": " << endl;
// 			 cout << this->_routeEnd << endl;
// 			 cout << "Spacing time: " << this->_spacing << endl;
// 			 system("pause");
// 			 break;
// 		 }
// 		 case 2:
// 		 {
// 			 system("cls");
// 			 cout << "$$$$Price$$$$" << endl;
// 			 cout << "Normal: " << this->_normalPrice << endl;
// 			 cout << "Student: " << this->_studentPrice << endl;
// 			 system("pause");
// 			 break;
// 		 }
// 		 case 3:
// 		 {
// 			 system("cls");
// 			 cout << "!!!!!SEAT!!!!!" << endl;

// 			 for (int i = 0; i < this->n; i++)
// 			 {
// 				 for (int j = 0; j < this->m; j++)
// 				 {
// 					 if (j == this->m - 1)
// 						 cout << " " << j + 1 + (i * this->m) << ": " << this->_seat[i][j] << "\n";
// 					 else
// 					 {
// 						 cout << " " << j + 1 + (i * this->m) << ": " << this->_seat[i][j] << "\t";

// 					 }

// 				 }
// 			 }
// 			 break;
// 		 }
// 		 }
// 		 return 0;
// 	 }
// 	 return 1;
//  }


//  ostream& operator<<(ostream& os, Bus bus)
// {
// 	cout << "ID: " << bus._ID << endl;
// 	cout << "Name: " << bus._start << "-" << bus._end << endl;
// 	cout << "Worktime: " << bus._Starttime <<"-"<<bus._Endtime<< endl;
// 	return os;
// }
