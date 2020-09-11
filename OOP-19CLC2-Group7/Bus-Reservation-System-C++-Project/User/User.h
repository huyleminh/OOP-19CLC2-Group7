#ifndef _USER_H_
#define _USER_H_

#include "../Header.h"


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

    //Copy constructor
    User& operator =(const User&);

    //Assignment operator
    bool operator ==(User& user);

    //Methods change data
    bool changePassword(const string& password);
	void changeUserRole(const string& role);

    //Check
    bool isUnValidUsername(const User& user);

    //Return string to storage
    string storageString();

    //Release
    void release();

    string getUsername() const;

    friend class Admin;//De admin co the truy xuat duoc tai khoan nay no
    ~User();
};

#endif
