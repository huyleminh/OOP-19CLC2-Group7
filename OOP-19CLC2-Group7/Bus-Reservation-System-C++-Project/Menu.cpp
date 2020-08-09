#include "Menu.h"
#include "List.h"

//Render main menu after start app
void Menu::renderMainMenu() {
    system("cls");

    LocalStorage local;
    local.clear("../Data/LocalStorage.txt");

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

    Menu::renderMainMenu();
}

//If login successfully with Admin, render this menu
void Menu::renderAdminMenu(User& user) {
    LocalStorage local;
    vector<string> items = local.getItem("../Data/LocalStorage.txt");

    if (items.size() != 2 || items[1] != "Admin") {
        cout << "Your request is not permitted.\n";
        cout << "=============================\n";
        cout << "1. Back to home.\n";
        cout << "2. Exit app.\n";

        string option = "";
        getline(cin, option, '\n');

        if (stoi(option) == 1) {
            local.clear("../Data/LocalStorage.txt");
            Menu::renderMainMenu();
        }
        else {
            local.clear("../Data/LocalStorage.txt");
            exit(0);
        }
        return;
    }

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

    string newPassword = "";

    switch (option) {
    case 1:
        //Search bus no
        break;
    case 2: 
        //Search departure and destination
        break;
    case 3:
        cin.ignore(1);
        cout << "Enter password, your password must not have any space or '/' : ";
        getline(cin, newPassword, '\n');
        user.changePassword(newPassword);
        cout << "Change password successfully.\n";
        break;
    case 4: 
        break;
    case 5:
        exit(0);
    }

    Menu::renderAdminMenu(user);
}

//If login successfully with Diver, render this menu
void Menu::renderDriverMenu(User& user) {
    LocalStorage local;
    vector<string> items = local.getItem("../Data/LocalStorage.txt");

    if (items.size() != 2 || items[1] == "Passenger") {
        cout << "Your request is not permitted.\n";
        cout << "=============================\n";
        cout << "1. Back to home.\n";
        cout << "2. Exit app.\n";

        string option = "";
        getline(cin, option, '\n');

        if (stoi(option) == 1)
            Menu::renderMainMenu();
        else {
            local.clear("../Data/LocalStorage.txt");
            exit(0);
        }
        return;
    }

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

    string newPassword = "";

    switch (option) {
    case 1:
        //Search bus no
        break;
    case 2: 
        //Search departure and destination
        break;
    case 3:
        cin.ignore(1);
        cout << "Enter password, your password must not have any space or '/' : ";
        getline(cin, newPassword, '\n');
        user.changePassword(newPassword);
        cout << "Change password successfully.\n";
        break;
    case 4: 
        break;
    case 5:
        exit(0);
    }
    Menu::renderDriverMenu(user);
}

//If login successfully with Passenger, render this menu
void Menu::renderPassengerMenu(User& user) {
    LocalStorage local;
    vector<string> items = local.getItem("../Data/LocalStorage.txt");

    if (items.size() != 2) {
        cout << "Your request is not permitted.\n";
        cout << "=============================\n";
        cout << "1. Back to home.\n";
        cout << "2. Exit app.\n";

        string option = "";
        getline(cin, option, '\n');

        if (stoi(option) == 1)
            Menu::renderMainMenu();
        else {
            local.clear("../Data/LocalStorage.txt");
            exit(0);
        }
        return;
    }

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

    string newPassword = "";

    switch (option) {
    case 1:
        //Search bus no
        break;
    case 2: 
        //Search departure and destination
        break;
    case 3:
        cin.ignore(1);
        cout << "Enter password, your password must not have any space or '/' : ";
        getline(cin, newPassword, '\n');
        user.changePassword(newPassword);
        cout << "Change password successfully.\n";
        break;
    case 4: 
        break;
    case 5:
        exit(0);
    }

    Menu::renderPassengerMenu(user);
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
        LocalStorage local;
        local.setItem("../Data/LocalStorage.txt", loginUser.storageString());

        vector<string> items = local.getItem("../Data/LocalStorage.txt");

        Sleep(2000);
        system("cls");

        if (items[1] == "Admin")
            Menu::renderAdminMenu(loginUser);
        else if (items[1] == "Driver")
            Menu::renderDriverMenu(loginUser);
        else
            Menu::renderPassengerMenu(loginUser);
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
    
    User user;
INPUT:
    cin >> user;
    
    for (int i = 0; i < list.size(); i++) {
        User check = list.getItemInData(i);
        if (check.isUnValidUsername(user) == true) {
            cout << "This username is already existed.\n";
            goto INPUT;
        }
    }

    Information info;
    cin >> info;
    
    ofstream out;
    out.open("../Data/Users.txt", ios::app);
    if (!out.is_open()) {
        cout << "Can not open Users.txt" << endl;
        return;
    }

    out << user;
    out.close();

    out.open("../Data/Passengers.txt", ios::app);
    if (!out.is_open()) {
        cout << "Can not open Passengers.txt" << endl;
        return;
    }

    out << info;
    out.close();

    cout << "Register successfully.\n";

    Sleep(2000);

    Menu::renderPassengerMenu(user);
}