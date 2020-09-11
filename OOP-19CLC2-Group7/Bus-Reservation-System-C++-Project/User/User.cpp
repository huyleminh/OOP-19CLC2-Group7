#include "User.h"
#include "../../Library/Tokenizer.h"
#include "../List.h"
#include "../Information/Information.h"
#include "../Workflow/ValidateInput/ValidateInputWorkflow.h"

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

    //Read ignore line has ""
    getline(ifs, line, '\n');

    getline(ifs, line, '\n');
    user._username = line;

    getline(ifs, line, '\n');
    user._password = line;

    getline(ifs, line, '\n');
    user._role = line;

    return ifs;
}

ofstream& operator <<(ofstream& ofs, const User& user) {
    ofs << endl;
    ofs << user._username << endl;
    ofs << user._password << endl;
    ofs << user._role << endl;
    return ofs;
}

istream& operator >>(istream& is, User& user) {
    cout << "Enter your username: ";
    getline(is, user._username, '\n');

    string tmpPassword = "";
    cout << "Enter password, your password must not have any space or '/' : ";
    
    getline(is, tmpPassword, '\n');

    while (!ValidateInputWorkflow::validatePasswordForm(tmpPassword)) {
        cout << "Wrong input password form." << endl;
        Sleep(1000);
        cout << "Enter password, your password must not have any space or '/' : ";
        getline(is, tmpPassword, '\n');
    }

    user._password = tmpPassword;
    
    return is;
}

ostream& operator <<(ostream& os, const User& user) {
    os << "Username: " << user._username << endl;
    os << "Password: " << user._password << endl;
    return os;
}

User& User::operator =(const User& user) {
    this->_username = user._username;
    this->_password = user._password;
    this->_role = user._role;

    return *this;
}

//Operator ==
bool User::operator ==(User& user) {
    if (this->_username == user._username && this->_password == user._password) {
        user._role = this->_role;
        return true;
    }
    else
        return false;
}

//Methods
bool User::changePassword(const string& password) {
    if (!ValidateInputWorkflow::validatePasswordForm(_password))
        return false;

    this->_password = password;
    return true;
}

void User::changeUserRole(const string& role) {
    this->_role = role;
}

bool User::isUnValidUsername(const User& user) {
    return this->_username == user._username;
}

//Return string to storage
string User::storageString() {
    return this->_username + " " + this->_role;
}

//Release
void User::release() {
    this->_username = "";
    this->_password = "";
    this->_role = "";
}

string User::getUsername() const {
    return this->_username;
}

User::~User() {
    this->_username = "";
    this->_password = "";
    this->_role = "";
}