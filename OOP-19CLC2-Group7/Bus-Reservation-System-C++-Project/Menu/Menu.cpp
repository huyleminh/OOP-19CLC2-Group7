#include "Menu.h"
#include "../List.h"
#include "../Bus/Bus.h"
#include "../Workflow/LoginWorkflow/LoginWorkflow.h"
#include "../Workflow/DecentralizeWorkflow/DecentralizeWorkflow.h"
#include "../Workflow/LogoutWorkflow/LogoutWorkflow.h"
#include "../Workflow/ValidateInput/ValidateInputWorkflow.h"
#include "../Menu/MenuView.h"

//Render main menu after start app
void Menu::renderMainMenu() {
    system("cls");

    LogoutWorkflow::logout();

    //This line call menu view that is global menu view
    MenuView::mainMenuView();

    string option;
OPTION: 
    cout << "Enter you option: ";
    getline(cin, option, '\n');
    //Check valid option
    if (!ValidateInputWorkflow::validateMenuOption(1, 5, option)) {
        goto OPTION;
    }

    switch (stoi(option)) {
    case 1:
        this->searchAndViewBus();
        break;
    case 2: 
        this->searchFromStation();
        break;
    case 3:
        this->login();
        break;
    case 4: 
        this->registerUser();
        break;
    case 5:
        exit(0);
    }

    Menu::renderMainMenu();
}

//If login successfully with Admin, render this menu
void Menu::renderAdminMenu(User& user) {
MENU:
    MenuView* view = MenuView::getMenuView(user);
    if (view == NULL) {
        LogoutWorkflow::logout();
        return;
    }

    if (!view->adminMenuView()) {
        return;
    }

    string option = "";
OPTION: 
    cout << "Enter you option: ";
    getline(cin, option, '\n');
    //Check valid option
    if (!ValidateInputWorkflow::validateMenuOption(1, 8, option)) {
        goto OPTION;
    }

    vector<Admin> admins = this->getUserInformation<Admin>("Admin", user);
    Admin admin;

    for (int i = 0; i < admins.size(); i++)
        if (admins[i].includeUsername(user)) {
            admin = admins[i];
            break;
        }

    switch (stoi(option)) {
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

        string option_bus;
OPTION_BUS: 
        cout << "Enter you option: ";
        getline(cin, option_bus, '\n');
        //Check valid option
        if (!ValidateInputWorkflow::validateMenuOption(1, 5, option)) {
            goto OPTION_BUS;
        }

        switch (stoi(option_bus))
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

        cout << "************************************************\n";
        cout << "*              DRIVER MANAGEMENT               *\n";
        cout << "*  1. Add new driver.                          *\n";
        cout << "*  2. Delete driver.                           *\n";
        cout << "*  3. Edit driver.                             *\n";
        cout << "*  4. Back to menu.                            *\n";
        cout << "*                                              *\n";
        cout << "************************************************\n";

        string option_driver;
OPTION_DRIVER: 
        cout << "Enter you option: ";
        getline(cin, option_driver, '\n');
        //Check valid option
        if (!ValidateInputWorkflow::validateMenuOption(1, 5, option)) {
            goto OPTION_DRIVER;
        }

        switch (stoi(option_driver))
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
            goto MENU;
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

        ofstream out;
        out.open("../Data/Admin.txt");
        if (!out.is_open()) 
        {
            cout << "Error" << endl;
            system("pause");
        }
        for (int i = 0; i < admins.size(); i++)
            out << admins[i];
        out.close();
        // ofstream out;
        // out.open("../Data/Admin.txt");
        // if (out.is_open()) 
        //     cout << "1" << endl;
        // else 
        //     cout << "2" << endl;
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
    //Driver menu view
    MenuView* view = MenuView::getMenuView(user);
    if (view == NULL) {
        LogoutWorkflow::logout();
        return;
    }

    if (!view->driverMenuView()) {
        return;
    }

    string option;
OPTION:
    cout << "Enter you option: ";
    getline(cin, option, '\n');
    //Check valid option
    if (!ValidateInputWorkflow::validateMenuOption(1, 8, option)) {
        goto OPTION;
    }

    vector<Driver> drivers = this->getUserInformation<Driver>("Driver", user);
    Driver driver;

    for (int i = 0; i < drivers.size(); i++)
        if (drivers[i].includeUsername(user)) {
            driver = drivers[i];
            break;
        }

    switch (stoi(option)) {
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
        driver.Dayoff();
        break;
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
        cout << driver;

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

    Menu::renderDriverMenu(user);
}

//If login successfully with Passenger, render this menu
void Menu::renderPassengerMenu(User& user) {
    //Passenger menu view
    MenuView* view = MenuView::getMenuView(user);
    if (view == NULL) {
        LogoutWorkflow::logout();
        return;
    }

    if (!view->passengerMenuView())
        return;

    string option = "";
OPTION:
    cout << "Enter your option: ";
    getline(cin, option, '\n');

    if (!ValidateInputWorkflow::validateMenuOption(1, 8, option)) {
        goto OPTION;
    }

    vector<Passenger> passengers = this->getUserInformation<Passenger>("Passenger", user);
    Passenger passenger;

    for (int i = 0; i < passengers.size(); i++)
        if (passengers[i].includeUsername(user)) {
            passenger = passengers[i];
            break;
        }

    switch (stoi(option)) {
    case 1:
        this->searchAndViewBus();
        break;
    case 2: 
        this->searchFromStation();
        break;
    case 3:
        passenger.buyTicket();
        break;
    case 4:{
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
        cout << passenger;

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
        Sleep(1000);
        cout << "You will be redirect to menu." << endl;
        Sleep(1000);
        system("cls");
        return;
    }

    cout << "Login successfully." << endl;

    //Decentralize user 
    const string identify = DecentralizeWorkflow::onDecentralizeUser();
    if (identify == "Admin")
        Menu::renderAdminMenu(loginUser);
    else if (identify == "Driver")
        Menu::renderDriverMenu(loginUser);
    if (identify == "Passenger")
        Menu::renderPassengerMenu(loginUser);

    Sleep(2000);
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

    string type = "";
    
    cout << "1. Student.\n";
    cout << "2. Normal.\n";

TYPE:
    cout << "Choose your type(student or Normal passenger): ";
    getline(cin, type, '\n');

    if (!ValidateInputWorkflow::validateMenuOption(1, 2, type)) {
        goto TYPE;
    }

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

    out << info << ((stoi(type) == 1) ? "Student" : "Normal") << endl;
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

    string option = "";
OPTION:
    cout << "Enter your option: ";
    getline(cin, option, '\n');

    if (!ValidateInputWorkflow::validateMenuOption(1, INT_MAX, option)) {
        goto OPTION;
    }

    Bus bus;
    for (int i = 0; i < list.size(); i++) {
        bus = list[i];
        bus.show(option);
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

    string option = "";
OPTION:
    cout << "Enter station you want to view: ";
    getline(cin, option, '\n');

    if (!ValidateInputWorkflow::validateMenuOption(1, stations.size(), option)) {
        goto OPTION;
    }

    List<Bus> list;
    list.loadListDataFromFile("../Data/Buses.txt");

    system("cls");
    cout << "\n********List Buses********" << endl;
    for (int i = 0; i < list.size(); i++) {
        vector<string> tmpStation = list[i].listOfStationGoThrough();
        vector<string>::iterator iter;

        iter = std::find(tmpStation.begin(), tmpStation.end(), stations[stoi(option) - 1]);
        if (iter != tmpStation.end())
            cout << list[i];
    }
    system("pause");

    cout << "These are buses that go through " << stations[stoi(option) - 1] << " station." << endl;
    Sleep(1000);
    cout << "Enter to go back to menu and choose option 1 to view details." << endl;
    
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