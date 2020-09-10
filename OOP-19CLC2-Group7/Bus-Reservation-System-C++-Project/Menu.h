#ifndef _MENU_H_
#define _MENU_H_

#include "Header.h"
#include "User.h"
#include "Passenger.h"
#include "Information.h"
#include "Driver.h"
#include "Admin.h"

class Menu {
public:
    //Render dynamic menu with each role
    void renderMainMenu();
    void renderAdminMenu(User& user);
    void renderDriverMenu(User& user);
    void renderPassengerMenu(User& user);

    //**Another feature when call in menu

    //Login feature
    void login();

    //Register feature
    void registerUser();

    //Search bus with number (no of bus)
    void searchAndViewBus(); 

    //Search bus from departure and destination
    void searchFromStation();

    //Render list station
    vector<string> createListStations();

    //Get Admin or Driver or Passenger 
private:
    template<class T>
    vector<T> getUserInformation(const string& role, const User& user);
};

//Get Admin or Driver or Passenger 
template<class T>
vector<T> Menu::getUserInformation(const string& role, const User& user) {
    const string filename = "../Data/" + role + ".txt";
    
    vector<T> items;
    T item;

    ifstream in(filename);
    if (!in.is_open()) {
        cout << "Can not open " << filename << endl;
        return items;
    }

    while (!in.eof()) {
        in >> item;
        items.push_back(item);
    }
    in.close();
    
    items.pop_back();
    return items;
}

#endif