#ifndef _INFORMATION_H_
#define _INFORMATION_H_

#include "Header.h"

class Information
{
protected:
    string name;
    string sex; 
    string birthday;
    string CMNN;
    string phone;

public:
    Information();
    Information(const Information& info);
    Information& operator=(const Information& info);
    friend ifstream& operator >>(ifstream& ifs, Information&info);
    friend ofstream& operator <<(ofstream& ofs, const Information& info);
    friend istream& operator >>(istream& is, Information& info);
    friend ostream& operator <<(ostream& os, const Information& info);

};

#endif