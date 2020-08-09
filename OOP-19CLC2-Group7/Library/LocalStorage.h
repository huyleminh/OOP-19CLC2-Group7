#ifndef _LOCAL_STRORAGE_H_
#define _LOCAL_STRORAGE_H_

#include <string>
#include <fstream>
#include <vector>
using namespace std;

class LocalStorage
{
public:
	vector<string> getItem(const string&);
	void setItem(const string&, const string&);
	void clear(const string&);
};

#endif