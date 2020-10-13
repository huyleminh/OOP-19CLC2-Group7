#ifndef _DATE_H_
#define _DATE_H_

#include <string>
using namespace std;

class Date
{
private: 
	int _day;
	int _month;
	int _year;
public:
	Date();
	Date(const string& date);
	Date(const Date& date);

	string toString();
	static bool isValidDate(const string& date);
	int operator -(const Date& date);
	static int calcDays(const Date& date); // Convert date to days
};

#endif