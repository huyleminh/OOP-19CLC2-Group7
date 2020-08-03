#include "Menu.h"
#include "User.h"
#include "List.h"

//Render main menu after start app
void Menu::renderMainMenu() {
    cout << "**********************************************************\n";
    cout << "*                          MENU                          *\n";
    cout << "*  1. Search bus no.                                     *\n";
    cout << "*  2. Search departure and destination.                  *\n";
    cout << "*  3. Log in.                                            *\n";
    cout << "*  4. Register.                                          *\n";
    cout << "*  5. Exit app.                                          *\n";
    cout << "*                                                        *\n";
    cout << "**********************************************************\n";

    int option;
OPTION:
    cout << "Enter you option: ";
    cin >> option;

    //Check valid option from 1 to 5.
    if (option < 1 || option > 5)
        goto OPTION;

    switch (option) {
    case 1:
        //Search bus no
        break;
    case 2: 
        //Search departure and destination
        break;
    case 3:
        cin.ignore(1);
        this->login();
        break;
    case 4: 
        cin.ignore(1);
        this->registerUser();
        break;
    case 5:
        exit(0);
    }
}

//If login successfully with Admin, render this menu
void Menu::renderAdminMenu(User& user) {
    cout << "*******************************************************\n";
    cout << "*                    WELCOME ADMIN                    *\n";
    cout << "*  1. Search bus no.                                  *\n";
    cout << "*  2. Search departure and destination.               *\n";
    cout << "*  3. Change password.                                *\n";
    cout << "*  4. Register.                                       *\n";
    cout << "*  5. Exit app.                                       *\n";
    cout << "*                                                     *\n";
    cout << "*******************************************************\n";

    int option;
OPTION:
    cout << "Enter you option: ";
    cin >> option;

    //Check valid option from 1 to 5.
    if (option < 1 || option > 5)
        goto OPTION;

    switch (option) {
    case 1:
        //Search bus no
        break;
    case 2: 
        //Search departure and destination
        break;
    case 3:
        break;
    case 4: 
        break;
    case 5:
        exit(0);
    }
}

//If login successfully with Diver, render this menu
void Menu::renderDriverMenu(User& user) {
    cout << "********************************************************\n";
    cout << "*                    WELCOME DRIVER                    *\n";
    cout << "*  1. Search bus no.                                   *\n";
    cout << "*  2. Search departure and destination.                *\n";
    cout << "*  3. Change password.                                 *\n";
    cout << "*  4. Register.                                        *\n";
    cout << "*  5. Exit app.                                        *\n";
    cout << "*                                                      *\n";
    cout << "********************************************************\n";

    int option;
OPTION:
    cout << "Enter you option: ";
    cin >> option;

    //Check valid option from 1 to 5.
    if (option < 1 || option > 5)
        goto OPTION;

    switch (option) {
    case 1:
        //Search bus no
        break;
    case 2: 
        //Search departure and destination
        break;
    case 3:
        break;
    case 4: 
        break;
    case 5:
        exit(0);
    }
}

//If login successfully with Passenger, render this menu
void Menu::renderPassengerMenu(User& user) {
    cout << "***********************************************************\n";
    cout << "*                    WELCOME PASSENGER                    *\n";
    cout << "*  1. Search bus no.                                      *\n";
    cout << "*  2. Search departure and destination.                   *\n";
    cout << "*  3. Change password.                                    *\n";
    cout << "*  4. Register.                                           *\n";
    cout << "*  5. Exit app.                                           *\n";
    cout << "*                                                         *\n";
    cout << "***********************************************************\n";

    int option;
OPTION:
    cout << "Enter you option: ";
    cin >> option;

    //Check valid option from 1 to 5.
    if (option < 1 || option > 5)
        goto OPTION;

    switch (option) {
    case 1:
        //Search bus no
        break;
    case 2: 
        //Search departure and destination
        break;
    case 3:
        break;
    case 4: 
        break;
    case 5:
        exit(0);
    }
}

//**Another feature when call in menu
// *1: Main mennu

//Login feature
void Menu::login() {
    system("cls");

    User loginUser;

    //Login interface
    cout << "***************************LOGIN***************************" << endl;
    cin >> loginUser;

    //Load users data and check valid login
    List<User> list;
    list.loadListDataFromFile("../Data/Users.txt");
    
    if (list.includes(loginUser)) {
        cout << "Login successfully!" << endl;
        //LocalStorage.setItem()

        Sleep(2000);
        system("cls");
        return;
    }
    else {
        cout << "Wrong username or password!" << endl;

        Sleep(2000);
        system("cls");

        loginUser.release();
        this->login();
    }
}

//Register feature
void Menu::registerUser() {
    List<User> list;
    list.loadListDataFromFile("../Data/Users.txt");

    //Register interface
    cout << "***************************REGISTER***************************" << endl;
}