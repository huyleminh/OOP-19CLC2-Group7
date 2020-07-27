#include "Menu.h"
#include "User.h"

//Render main menu after start app
void Menu::renderMainMenu() {
    cout << "MENU\n";
    cout << "1. Search bus no.\n";
    cout << "2. Search departure and destination.\n";
    cout << "3. Log in.\n";
    cout << "4. Register.\n";
    cout << "5. Exit app.\n";

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
    case 2: 
        //Search departure and destination
    case 3:
        
    case 4: 

    case 5:
        exit(0);
    }
}

//If login successfully with Admin, render this menu
void Menu::renderAdminMenu(User& user) {
    cout << "WELCOME ADMIN\n";
    cout << "1. Search bus no.\n";
    cout << "2. Search departure and destination.\n";
    cout << "3. Change password.\n";
    cout << "4. Register.\n";
    cout << "5. Exit app.\n";

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
    case 2: 
        //Search departure and destination
    case 3:

    case 4: 

    case 5:
        exit(0);
    }
}

//If login successfully with Diver, render this menu
void Menu::renderDriverMenu(User& user) {
    cout << "WELCOME DRIVER\n";
    cout << "1. Search bus no.\n";
    cout << "2. Search departure and destination.\n";
    cout << "3. Change password.\n";
    cout << "4. Register.\n";
    cout << "5. Exit app.\n";

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
    case 2: 
        //Search departure and destination
    case 3:

    case 4: 

    case 5:
        exit(0);
    }
}

//If login successfully with Passenger, render this menu
void Menu::renderPassengerMenu(User& user) {
    cout << "WELCOME PASSENGER\n";
    cout << "1. Search bus no.\n";
    cout << "2. Search departure and destination.\n";
    cout << "3. Change password.\n";
    cout << "4. Register.\n";
    cout << "5. Exit app.\n";

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
    case 2: 
        //Search departure and destination
    case 3:

    case 4: 

    case 5:
        exit(0);
    }
}