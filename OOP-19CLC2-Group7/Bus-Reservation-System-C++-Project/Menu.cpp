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

    if (items.size() != 2 || items[1] != "Admin" || items[0] != user.getUsername()) {
        cout << "Your request to Admin menu is not permitted.\n";
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

    system("cls");
MENU:
    cout << "*******************************************************\n";
    cout << "*                    WELCOME ADMIN                    *\n";
    cout << "*  1. Bus Management                                  *\n";
    cout << "*  2. Search departure and destination.               *\n";
    cout << "*  3. Driver Management.                              *\n";
    cout << "*  4. Change your information.                        *\n";
    cout << "*  5. Change password.                                *\n";
    cout << "*  6. View your information.                          *\n";
    cout << "*  7. Logout.                                         *\n";
    cout << "*  8. Exit app.                                       *\n";
    cout << "*                                                     *\n";
    cout << "*******************************************************\n";

    int option;
OPTION:
    cout << "Enter you option: ";
    cin >> option;

    //Check valid option from 1 to 8.
    if (option < 1 || option > 8)
        goto OPTION;

    cin.ignore(1);

    vector<Admin> admins = this->getUserInformation<Admin>(items[1], user);
    Admin admin;

    for (int i = 0; i < admins.size(); i++)
        if (admins[i].includeUsername(user)) {
            admin = admins[i];
            break;
        }

    switch (option) {
    case 1:
    {
        system("cls");
        int choice;

        cout << "************************************************\n";
        cout << "*              BUS MANAGEMENT                  *\n";
        cout << "*  1. Search Id Bus.                           *\n";
        cout << "*  2. Add new bus.                             *\n";
        cout << "*  3. Delete bus.                              *\n";
        cout << "*  4. Edit bus.                                *\n";
        cout << "*  5. Back to menu                             *\n";
        cout << "*                                              *\n";
        cout << "************************************************\n";

        cout << "Enter your choice" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            system("cls");
            break;
        }
        case 2:
        {
            system("cls");
            admin.addBus();
            break;
        }
        case 3:
        {
            system("cls");
            admin.deleteBus();
            break;
        }
        case 4:
        {
            system("cls");
            admin.editBus();
            break;
        }
        case 5:
        {
            goto MENU;
        }
        }
        break;
    }
    case 2: 
        //Search departure and destination
        break;
    case 3:
    {   
        system("cls");
        int choice;

        cout << "************************************************\n";
        cout << "*              DRIVER MANAGEMENT               *\n";
        cout << "*  1. Add new driver.                          *\n";
        cout << "*  2. Delete driver.                           *\n";
        cout << "*  3. Edit driver.                             *\n";
        cout << "*  4. Back to menu.                            *\n";
        cout << "*                                              *\n";
        cout << "************************************************\n";

        cout << "Enter your choice" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {  
            system("cls");
            admin.addDriver();
            break;
        }  
        case 2:
        {
            system("cls");
            admin.deleteDriver();
            break;
        }
        case 3:
        {
            system("cls");
            admin.editDriver();
            break;
        }
        case 4:
        {
            goto MENU;
        }
        }
        break;
    }
    case 4: {
        admin.changeInformation(user);

        for (int i = 0; i < admins.size(); i++)
            if (admins[i].includeUsername(user)) {
                admins[i] = admin;
                break;
            }

        ofstream out("../Data/Admin.txt");
        for (int i = 0; i < admins.size(); i++)
            out << admins[i];
        out.close();

        break;
    }
    case 5: 
    {
        string newPassword = "";
        cout << "Enter password, your password must not have any space or '/' : ";
        getline(cin, newPassword, '\n');
        
        User tmp = user;

        if (user.changePassword(newPassword) == true) {
            List<User> users;
            users.loadListDataFromFile("../Data/Users.txt");

            for (int i = 0; i < users.size(); i++) {
                if (users[i] == tmp)
                    users[i] = user;
            }

            users.saveListDataToFile("../Data/Users.txt");

            cout << "Change password successfully.\n";
        } 
        else
            cout << "Unvalid input password, please try again.\n";

        cout << "Press enter to back to menu.\n";
        while (true) {
            if (cin.get() == '\n')
                break;
        }
        break;
    }
    case 6:

        cout << "********Your information********" << endl;
        cout << admin;

        cout << "Press enter button to continue." << endl;
        while (true) {
            if (cin.get() == '\n')
                break;
        }

        break;
    case 7:
        local.clear("../Data/LocalStorage.txt");
        return;
    case 8:
        exit(0);
    }

    Menu::renderAdminMenu(user);
}

//If login successfully with Diver, render this menu
void Menu::renderDriverMenu(User& user) {
    LocalStorage local;
    vector<string> items = local.getItem("../Data/LocalStorage.txt");

    if (items.size() != 2 || items[1] != "Driver" || items[0] != user.getUsername()) {
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

    system("cls");

    cout << "********************************************************\n";
    cout << "*                    WELCOME DRIVER                    *\n";
    cout << "*  1. Search bus no.                                   *\n";
    cout << "*  2. Search departure and destination.                *\n";
    cout << "*  3. Change your information.                         *\n";
    cout << "*  4. Change password.                                 *\n";
    cout << "*  5. View your information.                           *\n";
    cout << "*  6. Log out.                                         *\n";
    cout << "*  7. Exit app.                                        *\n";
    cout << "*                                                      *\n";
    cout << "********************************************************\n";

    int option;
OPTION:
    cout << "Enter you option: ";
    cin >> option;

    //Check valid option from 1 to 7.
    if (option < 1 || option > 7)
        goto OPTION;

    cin.ignore(1);

    vector<Driver> drivers = this->getUserInformation<Driver>(items[1], user);
    Driver driver;

    for (int i = 0; i < drivers.size(); i++)
        if (drivers[i].includeUsername(user)) {
            driver = drivers[i];
            break;
        }

    switch (option) {
    case 1:
        //Search bus no
        break;
    case 2: 
        //Search departure and destination
        break;
    case 3: {
        driver.changeInformation(user);
        
        for (int i = 0; i < drivers.size(); i++)
            if (drivers[i].includeUsername(user)) {
                drivers[i] = driver;
                break;
            }

        ofstream out("../Data/Admin.txt");
        for (int i = 0; i < drivers.size(); i++)
            out << drivers[i];
        out.close();
       
        break;
    }
       
    case 4: 
    {
        string newPassword = "";
        cout << "Enter password, your password must not have any space or '/' : ";
        getline(cin, newPassword, '\n');
        
        User tmp = user;

        if (user.changePassword(newPassword) == true) {
            List<User> users;
            users.loadListDataFromFile("../Data/Users.txt");

            for (int i = 0; i < users.size(); i++) {
                if (users[i] == tmp)
                    users[i] = user;
            }

            users.saveListDataToFile("../Data/Users.txt");

            cout << "Change password successfully.\n";
        } 
        else
            cout << "Unvalid input password, please try again.\n";

        cout << "Press enter to back to menu.\n";
        while (true) {
            if (cin.get() == '\n')
                break;
        }
        break;
    }
    case 5: 

        cout << "********Your information********" << endl;
        cout << driver;

        cout << "Press enter button to continue." << endl;
        while (true) {
            if (cin.get() == '\n')
                break;
        }

        break;
    case 6:
        local.clear("../Data/LocalStorage.txt");
        return;
    case 7:
        exit(0);
    }

    Menu::renderDriverMenu(user);
}

//If login successfully with Passenger, render this menu
void Menu::renderPassengerMenu(User& user) {
    LocalStorage local;
    vector<string> items = local.getItem("../Data/LocalStorage.txt");

    if (items.size() != 2 || items[1] != "Passenger" || items[0] != user.getUsername()) {
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

    system("cls");

    cout << "********************************************************\n";
    cout << "*                    WELCOME PASSENGER                 *\n";
    cout << "*  1. Search bus no.                                   *\n";
    cout << "*  2. Search departure and destination.                *\n";
    cout << "*  3. Change your information.                         *\n";
    cout << "*  4. Change password.                                 *\n";
    cout << "*  5. View your information.                           *\n";
    cout << "*  6. Log out.                                         *\n";
    cout << "*  7. Exit app.                                        *\n";
    cout << "*                                                      *\n";
    cout << "********************************************************\n";

    int option;
OPTION:
    cout << "Enter you option: ";
    cin >> option;

    //Check valid option from 1 to 7.
    if (option < 1 || option > 7)
        goto OPTION;

    cin.ignore(1);

    vector<Passenger> passengers = this->getUserInformation<Passenger>(items[1], user);
    Passenger passenger;

    for (int i = 0; i < passengers.size(); i++)
        if (passengers[i].includeUsername(user)) {
            passenger = passengers[i];
            break;
        }

    switch (option) {
    case 1:
        //Search bus no
        break;
    case 2: 
        //Search departure and destination
        break;
    case 3:{
        passenger.changeInformation(user);
        
        for (int i = 0; i < passengers.size(); i++)
            if (passengers[i].includeUsername(user)) {
                passengers[i] = passenger;
                break;
            }

        ofstream out("../Data/Admin.txt");
        for (int i = 0; i < passengers.size(); i++)
            out << passengers[i];
        out.close();
       
        break;
    }
    case 4:
    {
        string newPassword = "";
        cout << "Enter password, your password must not have any space or '/' : ";
        getline(cin, newPassword, '\n');
        
        User tmp = user;

        if (user.changePassword(newPassword) == true) {
            List<User> users;
            users.loadListDataFromFile("../Data/Users.txt");

            for (int i = 0; i < users.size(); i++) {
                if (users[i] == tmp)
                    users[i] = user;
            }

            users.saveListDataToFile("../Data/Users.txt");

            cout << "Change password successfully.\n";
        } 
        else
            cout << "Unvalid input password, please try again.\n";

        cout << "Press enter to back to menu.\n";
        while (true) {
            if (cin.get() == '\n')
                break;
        }
        break;
    }
    case 5: 

        cout << "********Your information********" << endl;
        cout << passenger;

        cout << "Press enter button to continue." << endl;
        while (true) {
            if (cin.get() == '\n')
                break;
        }

        break;
    case 6:

        local.clear("../Data/LocalStorage.txt");

        return;
    case 7:
        exit(0);
    }

    Menu::renderPassengerMenu(user);
}

//**Another feature when call in menu

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

        //Set store identify string to local storage
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
        loginUser.release();
        cout << "Wrong username or password!" << endl;
        Sleep(1000);
        cout << "You will be redirect to main menu.\n";
        Sleep(1000);
        system("cls");
    }
}

//Register feature
void Menu::registerUser() {
    List<User> list;
    list.loadListDataFromFile("../Data/Users.txt");

    //Register interface
    system("cls");
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

    int type = 0;
    
    cout << "1. Student.\n";
    cout << "2. Normal.\n";

TYPE:
    cout << "Choose your type(student or normal passenger): ";
    cin >> type;

    if (type < 1 || type > 2)
    goto TYPE;
    cin.ignore(1);

    Information info;
    cin >> info;
    info.updateUsername(user.getUsername());
    
    ofstream out;
    out.open("../Data/Users.txt", ios::app);
    if (!out.is_open()) {
        cout << "Can not open Users.txt" << endl;
        return;
    }
    
    user.changeUserRole("Passenger");
    out << user;
    out.close();

    out.open("../Data/Passenger.txt", ios::app);
    if (!out.is_open()) {
        cout << "Can not open Passenger.txt" << endl;
        return;
    }

    out << info << ((type == 1) ? "Student" : "Normal") << endl;
    out.close();

    cout << "Register successfully.\n";
    Sleep(1000);
    cout << "You will be redirect to main menu and login again to confirm.\n";

    Sleep(1000);
    system("cls");

    Menu::renderMainMenu();
}