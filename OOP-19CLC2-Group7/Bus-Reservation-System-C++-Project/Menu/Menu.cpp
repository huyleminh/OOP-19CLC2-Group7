#include "Menu.h"
#include "../List.h"
#include "../Bus/Bus.h"
#include "../Workflow/LoginWorkflow/LoginWorkflow.h"
#include "../Workflow/DecentralizeWorkflow/DecentralizeWorkflow.h"
#include "../Workflow/LogoutWorkflow/LogoutWorkflow.h"

//Render main menu after start app
void Menu::renderMainMenu() {
    system("cls");

    LogoutWorkflow::logout();

    cout << "**********************************************************\n";
    cout << "*                          MENU                          *\n";
    cout << "*  1. Search bus no.                                     *\n";
    cout << "*  2. Search station.                                    *\n";
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
        this->searchAndViewBus();
        break;
    case 2: 
        this->searchFromStation();
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
    if (!LoginWorkflow::validateLogin(user)) {
        cout << "You are not login.!!!" << endl;
        Sleep(1000);
        LogoutWorkflow::logout();
        return;
    }

    if (DecentralizeWorkflow::onDecentralizeUser() != "Admin") {
        cout << "You are not allow to access." << endl;
        Sleep(1000);
        return;
    }

    system("cls");
MENU:
    cout << "*******************************************************\n";
    cout << "*                    WELCOME ADMIN                    *\n";
    cout << "*  1. Bus Management.                                 *\n";
    cout << "*  2. Search stations.                                *\n";
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

    vector<Admin> admins = this->getUserInformation<Admin>("Admin", user);
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
            this->searchAndViewBus();
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
        this->searchFromStation();
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
        LogoutWorkflow::logout();
        return;
    case 8:
        exit(0);
    }

    Menu::renderAdminMenu(user);
}

//If login successfully with Diver, render this menu
void Menu::renderDriverMenu(User& user) {
    if (!LoginWorkflow::validateLogin(user)) {
        cout << "You are not login.!!!" << endl;
        Sleep(1000);
        LogoutWorkflow::logout();
        return;
    }

    if (DecentralizeWorkflow::onDecentralizeUser() != "Driver") {
        cout << "You are not allow to access." << endl;
        Sleep(1000);
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

    vector<Driver> drivers = this->getUserInformation<Driver>("Driver", user);
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

        ofstream out("../Data/Driver.txt");
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
        LogoutWorkflow::logout();
        return;
    case 7:
        exit(0);
    }

    Menu::renderDriverMenu(user);
}

//If login successfully with Passenger, render this menu
void Menu::renderPassengerMenu(User& user) {
     if (!LoginWorkflow::validateLogin(user)) {
        cout << "You are not login.!!!" << endl;
        Sleep(1000);
        LogoutWorkflow::logout();
        return;
    }

    if (DecentralizeWorkflow::onDecentralizeUser() != "Passenger") {
        cout << "You are not allow to access." << endl;
        Sleep(1000);
        return;
    }

    system("cls");

    cout << "********************************************************\n";
    cout << "*                    WELCOME PASSENGER                 *\n";
    cout << "*  1. Search bus no.                                   *\n";
    cout << "*  2. Search station.                                  *\n";
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

    vector<Passenger> passengers = this->getUserInformation<Passenger>("Passenger", user);
    Passenger passenger;

    for (int i = 0; i < passengers.size(); i++)
        if (passengers[i].includeUsername(user)) {
            passenger = passengers[i];
            break;
        }

    switch (option) {
    case 1:
        this->searchAndViewBus();
        break;
    case 2: 
        this->searchFromStation();
        break;
    case 3:{
        passenger.changeInformation(user);
        
        for (int i = 0; i < passengers.size(); i++)
            if (passengers[i].includeUsername(user)) {
                passengers[i] = passenger;
                break;
            }

        ofstream out("../Data/Passenger.txt");
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
        LogoutWorkflow::logout();
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

    //Validate login
    if (!LoginWorkflow::validateLogin(loginUser)) {
        cout << "Wrong username or password." << endl;
        cout << "You will be redirect to menu." << endl;
        Sleep(2000);
        system("cls");
        return;
    }

    cout << "Login successfully." << endl;

    //Decentralize user 
    const string identify = DecentralizeWorkflow::onDecentralizeUser();
    if (identify == "Admin")
        Menu::renderAdminMenu(loginUser);
    else if (identify == "Diver")
        Menu::renderDriverMenu(loginUser);
    if (identify == "Passenger")
        Menu::renderPassengerMenu(loginUser);

    Sleep(1000);
    system("cls");
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

//Search bus with number (no of bus)
void Menu::searchAndViewBus() {
    system("cls");

    List<Bus> list;
    list.loadListDataFromFile("../Data/Buses.txt");

    cout << "********List of bus********" << endl;
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << endl;
    }

    cout << "********Enter bus Id to view more information********" << endl;
    int option = 0;
OPTION:
    cin >> option;
    if (cin.fail()) {
        cout << "Wrong option, please try again." << endl;
        goto OPTION;
    }

    Bus bus;
    for (int i = 0; i < list.size(); i++) {
        bus = list[i];
        bus.show(to_string(option));
    }
}

//Search bus from departure and destination
bool sortStation(const string& left, const string& right) {
    return left < right;
}
void Menu::searchFromStation() {
    vector<string> stations = this->createListStations();

    //Sort station A - Z
    sort(stations.begin(), stations.end(), sortStation);
    
    //Render stations
    system("cls");
    cout << "\n********STATIONS********" << endl;
    for (int i = 0; i < stations.size(); i++) {
        cout << setw(2) << left << i + 1 << ". " << setw(50) << left << stations[i];
        if (i % 3 == 2)
            cout << endl;
    }
    cout << endl;

    //Stop screen
    cout << "****************************" << endl;
    Sleep(1000);

    size_t option = 0;
OPTION:
    cout << "Enter station (number): ";
    cin >> option;

    if (cin.fail()) {
        cout << "Unvalid option." << endl;
        goto OPTION;
    }

    if (option <= 0 || option > stations.size()) {
        cout << "Unvalid station." << endl;
        goto OPTION;
    }

    List<Bus> list;
    list.loadListDataFromFile("../Data/Buses.txt");

    system("cls");
    cout << "\n********List Buses********" << endl;
    for (int i = 0; i < list.size(); i++) {
        vector<string> tmpStation = list[i].listOfStationGoThrough();
        vector<string>::iterator iter;

        iter = std::find(tmpStation.begin(), tmpStation.end(), stations[option - 1]);
        if (iter != tmpStation.end())
            cout << list[i];
    }
    system("pause");

    cout << "These are buses that go through " << stations[option - 1] << " station." << endl;
    Sleep(1000);
    cout << "Enter to go back to menu and choose option 1 to view details." << endl;
    
    cin.ignore(1);
    while (true) {
        if (cin.get() == '\n')
            break;
        else 
            cout << "Please press enter." << endl;
    }
}

//Render list station
vector<string> Menu::createListStations() {
   //Request to bus to render stations
   //
   //Get list bus first
    List<Bus> list;
    list.loadListDataFromFile("../Data/Buses.txt");

    //Create list of stations of all bus (not repeat stations)
    vector<string> stations = list[0].listOfStationGoThrough();
    vector<string>::iterator iter;

    for (int i = 1; i < list.size(); i++) {
        vector<string> tmp = list[i].listOfStationGoThrough();

        for (int j = 0; j < tmp.size(); j++) {
            iter = std::find(stations.begin(), stations.end(), tmp[j]);

            if (iter == stations.end())
                stations.push_back(tmp[j]);
        }
    }

    return stations;
}