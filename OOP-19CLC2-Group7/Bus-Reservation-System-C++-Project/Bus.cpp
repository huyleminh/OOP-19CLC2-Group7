#include "Bus.h"
 ifstream & Bus::ReadFromfile(ifstream & ifs)
{
	ifs.ignore(100, '\n');

	getline(ifs, this->_ID, '\n');
	getline(ifs, this->_start, '\n');
	getline(ifs, this->_end, '\n');
	getline(ifs, this->_routeStart, '.');
	getline(ifs, this->_routeEnd, '.');

	ifs.ignore(100, '\n');

	getline(ifs, this->_spacing, '\n');
	getline(ifs, this->_priceNormal, '\n');
	getline(ifs, this->_priceStudent, '\n');

	ifs >> this->n >> this->m;
	this->_seat.resize(n);
	ifs.ignore(100, '\n');
	for (int i = 0; i < n; i++)
	{
		this->_seat[i].resize(m);
		for (int j = 0; j < m; j++)
		{
			if (j == m - 1)
			{
				getline(ifs, this->_seat[i][j], '\n');
			}
			else
				getline(ifs, this->_seat[i][j], ' ');
		}
	}

	getline(ifs, this->_Starttime, '-');
	getline(ifs, this->_Endtime, '\n');

	ifs >> this->_IsActive;
	ifs.ignore(100, '\n');

	return ifs;
}

 int Bus::Show(int id)
 {
	 if (id == stoi(this->_ID, NULL, 10))
	 {
		 int i;
		 cout << "What information you want to see?" << endl;
		 cout << "0: Name,Worktime" << endl;
		 cout << "1:Route" << endl;
		 cout << "2:Price" << endl;
		 cout << "3:Seat" << endl;
		 cin >> i;
		 switch (i)
		 {
		 case 0:
		 {
			 system("cls");
			 cout << "ID: " << this->_ID << endl;
			 cout << "Name: " << this->_start << "-" << this->_end << endl;
			 cout << "Worktime: " << this->_Starttime << " - " << this->_Endtime << endl;
			 cout << "Status: ";
			 if (this->_IsActive == 0)
				 cout << "Inactive" << endl;
			 else
				 cout << "Active" << endl;
			 system("pause");
			 break;
		 }
		 case 1:
		 {
			 system("cls");
			 cout << "Route from " << this->_start << " to " << this->_end << ": " << endl;
			 cout << this->_routeStart << endl;
			 cout << "Route from " << this->_end << " to " << this->_start << ": " << endl;
			 cout << this->_routeEnd << endl;
			 cout << "Spacing time: " << this->_spacing << endl;
			 system("pause");
			 break;
		 }
		 case 2:
		 {
			 system("cls");
			 cout << "$$$$Price$$$$" << endl;
			 cout << "Normal: " << this->_priceNormal << endl;
			 cout << "Student: " << this->_priceStudent << endl;
			 system("pause");
			 break;
		 }
		 case 3:
		 {
			 system("cls");
			 cout << "!!!!!SEAT!!!!!" << endl;

			 for (int i = 0; i < this->n; i++)
			 {
				 for (int j = 0; j < this->m; j++)
				 {
					 if (j == this->m - 1)
						 cout << " " << j + 1 + (i * this->m) << ": " << this->_seat[i][j] << "\n";
					 else
					 {
						 cout << " " << j + 1 + (i * this->m) << ": " << this->_seat[i][j] << "\t";

					 }

				 }
			 }
			 break;
		 }
		 }
		 return 0;
	 }
	 return 1;
 }


 ostream& operator<<(ostream& os, Bus bus)
{
	cout << "ID: " << bus._ID << endl;
	cout << "Name: " << bus._start << "-" << bus._end << endl;
	cout << "Worktime: " << bus._Starttime <<"-"<<bus._Endtime<< endl;
	return os;
}
