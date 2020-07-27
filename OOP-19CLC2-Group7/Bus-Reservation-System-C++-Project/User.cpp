#include "User.h"

//Constructor
User::User() {
    this->_username = "";
    this->_password = "";
    this->_role = "";
}

//Copy constructor
User::User(const User& user) {
    this->_username = user._username;
    this->_password = user._password;
    this->_role = user._role;
}

//Operators
ifstream& operator >>(ifstream& ifs, User& user) {
    string line = "";

    getline(ifs, line, '\n');
    user._username = line;

    getline(ifs, line, '\n');
    user._password = line;

    getline(ifs, line, '\n');
    user._role = line;

    //Read ignore line has ""
    getline(ifs, line, '\n');

    return ifs;
}

ofstream& operator <<(ofstream& ofs, const User& user) {
    ofs << user._username << endl;
    ofs << user._password << endl;
    ofs << user._role << endl;
    ofs << endl;

    return ofs;
}

istream& operator >>(istream& is, User& user) {
    cout << "Enter username: ";
    getline(is, user._username, '\n');

    cout << "Enter password, your password must not have any space and / :";
    getline(is, user._password, '\n');
    
    return is;
}

ostream& operator <<(ostream& os, const User& user) {
    os << "Username: " << user._username << endl;
    os << "Password: " << user._password << endl;
    return os;
}

//Operator ==
bool User::operator ==(const User& user) {
    return (this->_username == user._username && this->_password == user._password && this->_role == user._role);
}

//Methods
void User::changePassword(const string& password) {
    this->_password = password;
}

void User::changeUserRole(const string& role) {
    this->_role = role;
}

//Release
void User::release() {
    this->_username = "";
    this->_password = "";
    this->_role = "";
}