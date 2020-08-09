#ifndef _LIST_H_
#define _LIST_H_

#include "Header.h"

template<class T>
class List {
private:
	vector<T> _data;
public:	
	//Methods
	//Load data to list from file
	void loadListDataFromFile(const string& filename);

	//Check whether t is included in List or not
	bool includes(const T& t);

	//Destructor
	~List();
};

//Operators
template<class T>
bool List<T>::includes(const T& t) {
	for (int i = 0; i < this->_data.size(); i++)
		if (this->_data[i] == t) {
			return true;
		}
	return false;
}

//Methods
template<class T>
void List<T>::loadListDataFromFile(const string& filename) {
	ifstream in(filename);
	if (!in.is_open()) {
		cout << "Can not open " << filename << endl;
		return;
	}

	while (!in.eof()) {
		T temp;
		in >> temp;
		this->_data.push_back(temp);
	}
	this->_data.pop_back();
	in.close();
}

//Destructor
template<class T>
List<T>::~List() {
	this->_data.clear();
}

#endif