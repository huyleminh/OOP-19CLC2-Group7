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

	//Save list data to file
	void saveListDataToFile(const string& filename);

	//Check whether t is included in List or not
	bool includes(T& t);

	//Return an item
	T getItemInData(const int& index);

	//size of data
	int size();

	//Destructor
	~List();
	friend class Bus;
};

//Operators
template<class T>
bool List<T>::includes(T& t) {
	for (int i = 0; i < this->_data.size(); i++)
		if (this->_data[i] == t) {
			return true;
		}
	return false;
}

template<class T>
T List<T>::getItemInData(const int& index) {
	T t = this->_data[index];
	return t;
}

//size of data
template<class T>
int List<T>::size() {
	return this->_data.size();
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

//Save list data to file
template<class T>
void List<T>:: saveListDataToFile(const string& filename) {
	ofstream out(filename);
	if (!out.is_open()) {
		cout << "Can not open " << filename << endl;
		return;
	}

	for (int i = 0; i < this->_data.size(); i++) {
		out << this->_data[i];
	}
}

//Destructor
template<class T>
List<T>::~List() {
	this->_data.clear();
}

#endif