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

    User& operator =(const User&);

    bool operator ==(User& user);

    //Methods change data
    void changePassword(const string& password);
    void changeUserRole(const string& role);

    //Check
    bool isUnValidUsername(const User& user);

    //Return string to storage
    string storageString();

    //Release
    void release();

    ~User();
};

#endif
