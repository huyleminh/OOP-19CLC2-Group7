#ifndef _USER_H_
#define _USER_H_

#include "Header.h"
#include "Information.h"

class User
{
private:
    //Atributes: 
    string _username;
    string _password;
    string _role;

public: 
    //Constructors
    User();
    User(const User& user);

    //Operators
    friend ifstream& operator >>(ifstream& ifs, User& user);
    friend ofstream& operator <<(ofstream& ofs, const User& user);
    friend istream& operator >>(istream& is, User& user);
    friend ostream& operator <<(ostream& os, const User& user);

    bool operator ==(const User& user);

    //Methods
    void changePassword(const string& password);
    void changeUserRole(const string& role);

    //Release
    void release();

    ~User();
};


class Driver : public Information
{
private:
	//Attributes
	User user;

public:

};

class Passenger : public Information
{
private:
	//Attributes
	User user;

public:

};

#endif
