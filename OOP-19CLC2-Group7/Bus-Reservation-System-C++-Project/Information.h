#ifndef _INFORMATION_H_
#define _INFORMATION_H_

#include "Header.h"

class Information
{
protected:
    string _name;
    string _sex; 
    string _birthday;

public:
    //Default constructor
    Information();

    //Copy constructor
    Information(const Information& info);
    
    //Operator
    Information& operator=(const Information& info);
    friend ifstream& operator >>(ifstream& ifs, Information& info);
    friend ofstream& operator <<(ofstream& ofs, const Information& info);
    friend istream& operator >>(istream& is, Information& info);
    friend ostream& operator <<(ostream& os, const Information& info);

};

#endif