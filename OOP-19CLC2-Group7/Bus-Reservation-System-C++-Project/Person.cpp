#include "Person.h"

Person::Person()
{
	this->_name = "";
	this->_Dob = "";
	this->_gender = "";
}

Person::Person(const Person& p)
{
	this->_name = p._name;
	this->_Dob = p._Dob;
	this->_gender = p._gender;

}

Person& Person::operator=(const Person& p)
{
	this->_name = p._name;
	this->_Dob = p._Dob;
	this->_gender = p._gender;

	return *this;
}

vector<string> Person::spiltDatestring(const string Dob, const string separator)
{
	vector<string> result;

	int startPos = 0;

	size_t foundPos;


	do
	{
		foundPos = Dob.find(separator, startPos);

		result.push_back(Dob.substr(startPos, foundPos - startPos));

		startPos = separator.length() + foundPos;



	} while (foundPos != string::npos);

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}

	return result;
}

ifstream& Person::getPersonfile(ifstream& in)
{
	return in;
}

ofstream& Person::setPersonfile(ofstream& out)
{
	return out;
}



ostream& operator<<(ofstream& os, const Person& p)
{
	cout << "Name: " << p._name << " Date of birth: " << p._Dob << " Sex: " << p._gender << endl;
	return os;
}
