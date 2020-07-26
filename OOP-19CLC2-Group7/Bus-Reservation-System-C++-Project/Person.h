#ifndef _PERSON_H_
#define _PERSON_H_

#include "Header.h"
#define MALE 0
#define FEMALE 1

class Person {

private:
	string _name;
	string _Dob;
	int _sex;


public:
	Person();
	Person(const Person& p);
	Person& operator = (const Person& p);

	static vector<string> spiltDatestring(const string Dob, const string separator = "/");

	ifstream& getPersonfile(ifstream& in);
	ofstream& setPersonfile(ofstream& out);

	friend ostream& operator << (ofstream& os, const Person& p);


};

#endif