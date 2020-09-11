#ifndef _INFORMATION_H_
#define _INFORMATION_H_

#include "../Header.h"
#include "../User/User.h"

class Information
{
protected:
    string _name;
    string _sex; 
    string _birthday;
    string _username;

public:
    //Default constructor
    Information();
    void updateUsername(const string& username);

    //Copy constructors
    Information(const Information& info);
    
    //Operator
    Information& operator =(const Information& info);

    friend ifstream& operator >>(ifstream& ifs, Information& info);
    friend ofstream& operator <<(ofstream& ofs, const Information& info);
    friend istream& operator >>(istream& is, Information& info);
    friend ostream& operator <<(ostream& os, const Information& info);

    bool includeUsername(const User & user);

    bool changeName(const string& name);
    void changeSex(const string& sex);
    bool changeBirthday(const string& birthday);
    
    friend class Admin;
};

#endif