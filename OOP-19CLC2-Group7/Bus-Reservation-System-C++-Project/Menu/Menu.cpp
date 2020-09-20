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
    LogoutWorkflow::logout(); //Clear storerage 

    //This line call menu view that is global menu view
    MenuView::mainMenuView();

    string option;
OPTION: 
    cout << "Enter you option: ";
    getline(cin, option, '\n');
    //Check valid option
    if (!ValidateInputWorkflow::validateMenuOption(1, 5, option))
        goto OPTION;

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
    if (!ValidateInputWorkflow::validateMenuOption(1, 7, option)) {
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
    case 1: {
        system("cls");

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
        if (!ValidateInputWorkflow::validateMenuOption(1, 5, option))
            goto OPTION_BUS;

        switch (stoi(option_bus)) {
        case 1:
            this->searchAndViewBus();
            system("cls");
            break;
        case 2:
            system("cls");
            admin.addBus();
            break;
        case 3:
            system("cls");
            admin.deleteBus();
            break;
        case 4:
            system("cls");
            admin.editBus();
            break;
        case 5:
            break;
        }
        break;
    }
    case 2: 
        this->searchFromStation();
        break;
    case 3: {   
        system("cls");

        cout << "************************************************\n";
        cout << "*              DRIVER MANAGEMENT               *\n";
        cout << "*  1. Add new driver.                          *\n";
        cout << "*  2. Delete driver.                           *\n";
        cout << "*  3. Edit driver.                             *\n";
        cout << "*  4. Promote driver.                          *\n";
        cout << "*  5. Back to menu.                            *\n";
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

        switch (stoi(option_driver)) {
        case 1:
            system("cls");
            admin.addDriver();
            break;
        case 2:
            system("cls");
            admin.deleteDriver();
            break;
        case 3:
            system("cls");
            admin.editDriver();
            break;
        case 4:
            system("cls");
            admin.promoteDriver();
            break;
        case 5:
            break;
        }
        break;
    }
    case 4: {
        system("cls");

        cout << "************************************************\n";
        cout << "*               ANNOUNCEMENT                   *\n";
        cout << "*  1. Driver.                                  *\n";
        cout << "*  2. Passenger.                               *\n";
        cout << "*  3. Back to menu                             *\n";
        cout << "*                                              *\n";
        cout << "************************************************\n";
        string option;
OPTION_AN:
        cout << "Enter you option: ";
        getline(cin, option, '\n');
    
        if (!ValidateInputWorkflow::validateMenuOption(1, 3, option)) {
            goto OPTION_AN;
        }

        switch (stoi(option)) {
        case 1: {
            system("cls");
            cout << "************************************************\n";
            cout << "*             ANNOUNCEMENT DRIVER              *\n";
            cout << "*  1. See announcement.                        *\n";
            cout << "*  2. Add announcement.                        *\n";
            cout << "*  3. Edit/Delete announcement.                *\n";
            cout << "*  4. Back to menu.                            *\n";
            cout << "*                                              *\n";
            cout << "************************************************\n";
            string op;
        OPTION_AN1:
            cout << "Enter you option: ";
            getline(cin, op, '\n');

            if (!ValidateInputWorkflow::validateMenuOption(1, 4, op)) 
                goto OPTION_AN1;

            ifstream f("../Data/AnnounceDriver.txt");
            if (!f.is_open())
                return;
            Announcement an;
            f >> an;

            switch (stoi(op)) {
            case 1:
                system("cls");
                cout << "\t\tAnnouncement Driver" << endl;
                cout << an;
                system("pause");
                f.close();
                break;
            case 2: {
                system("cls");
                admin.addAnnounce(an);
                cout << "Add successfully!!!" << endl;
                ofstream f2("../Data/AnnounceDriver.txt");
                f2 << an;
                system("pause");
                break;
            }
            case 3: {
                system("cls");
                cout << "\t\tAnnouncement Passenger" << endl;
                cout << an << endl;

                cout << "1.Edit" << endl;
                cout << "2.Delete" << endl;
                string op1;
                cin >> op1;
                if (stoi(op1) == 1){
                    admin.editAnnounce(an);
                    ofstream f2("../Data/AnnounceDriver.txt");
                    f2 << an;
                    f2.close();
                    system("pause");
                }
                else {
                    admin.deleteAnnounce(an);
                    ofstream f2("../Data/AnnounceDriver.txt");
                    f2 << an;
                    f2.close();
                    system("pause");
                }
                break;
            }
            case 4:
                break;
            }
            break;
        }
        case 2: {
            system("cls");
            cout << "************************************************\n";
            cout << "*             ANNOUNCEMENT PASSENGER           *\n";
            cout << "*  1. See announcement.                        *\n";
            cout << "*  2. Add announcement.                        *\n";
            cout << "*  3. Edit/Delete announcement.                *\n";
            cout << "*  4. Back to menu.                            *\n";
            cout << "*                                              *\n";
            cout << "************************************************\n";
            string op;
        OPTION_AN2:
            cout << "Enter you option: ";
            getline(cin, op, '\n');

            if (!ValidateInputWorkflow::validateMenuOption(1, 4, op)) {
                goto OPTION_AN2;
            }

            ifstream f("../Data/AnnouncePassenger.txt");
            if (!f.is_open())
                return;
            Announcement an;
            f >> an;
            f.close();
            switch (stoi(op)) {
            case 1:
            {
                system("cls");
                cout << "\t\tAnnouncement Passenger" << endl;
                cout << an;
                system("pause");
                f.close();
                break;
            }
            case 2:
            {
                system("cls");
                admin.addAnnounce(an);
                cout << "Add successfully!!!" << endl;
                ofstream f2("../Data\\AnnouncePassenger.txt");
                f2 << an;
                f2.close();
                system("pause");
                break;
            }
            case 3:
            {
                system("cls");
                cout << "\t\tAnnouncement Passenger" << endl;
                cout << an << endl;

                cout << "1.Edit" << endl;
                cout << "2.Delete" << endl;
                string op1;
                do {
                    cout << "Enter option: ";
                    getline(cin, op1, '\n');
                } while (!ValidateInputWorkflow::validateMenuOption(1, 2, op1));
                
                if (stoi(op1) == 1)
                {
                    admin.editAnnounce(an);
                    ofstream f2("../Data\\AnnouncePassenger.txt");
                    f2 << an;
                    f2.close();
                    system("pause");
                }
                else
                {
                    admin.deleteAnnounce(an);
                    ofstream f2("../Data\\AnnouncePassenger.txt");
                    f2 << an;
                    f2.close();
                    system("pause");
                }
                break;
            }
            case 4:
                break;
            }
            break;
        }
        case 3:
            break;
        }
        break;
    }
    case 5: {
        system("cls");
        cout << "************************************************\n";
        cout << "*              ACCOUNT MANAGEMENT              *\n";
        cout << "*  1. Change your information.                 *\n";
        cout << "*  2. Change password.                         *\n";
        cout << "*  3. View your information.                   *\n";
        cout << "*  4. Back to menu                             *\n";
        cout << "*                                              *\n";
        cout << "************************************************\n";
        string optionA = "";
    OPTION_AC:
        cout << "Enter you option: ";
        getline(cin, optionA, '\n');
        //Check valid option
        if (!ValidateInputWorkflow::validateMenuOption(1, 4, optionA)) 
            goto OPTION_AC;
        
        switch (stoi(optionA))
        {
        case 1:
        {   
            system("cls");
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
            break;
        }
        case 2:
        {
            system("cls");
            string old = "";
            cout << "Input your old password: "; 
            getline(cin, old, '\n');
            if (!ValidateInputWorkflow::validatePasswordForm(old))
            {
                cout << "Your password form is incorrect" << endl;
                system("pause");
                Menu::renderAdminMenu(user);
                return;
            }
            if (user.isPassword(old) == 0)
            {
                cout << "Incorrect!!!" << endl;
                system("pause");
                Menu::renderAdminMenu(user);
                return;
            }

            string newPassword = "";
            cout << "Enter new password, your password must not have any space or '/' : ";
            getline(cin, newPassword, '\n');

            if (!ValidateInputWorkflow::validatePasswordForm(newPassword))
            {
                cout << "Your password form is incorrect" << endl;
                system("pause");
                Menu::renderAdminMenu(user);
                return;
            }

            string newPassword2 = "";
            cout << "Enter again new password: ";
            getline(cin, newPassword2, '\n');

            if (!ValidateInputWorkflow::validatePasswordForm(newPassword2))
            {
                cout << "Your password form is incorrect" << endl;
                system("pause");
                Menu::renderAdminMenu(user);
                return;
            }
            if (newPassword != newPassword2)
            {
                cout << "Two new password is not the same, fail to change password!!" << endl;
                system("pause");
                Menu::renderAdminMenu(user);
                return;
            }
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

            system("pause");
            break;
        }
        case 3:
        {
            system("cls");
            cout << "********Your information********" << endl;
            cout << admin;
            system("pause");

            break;
        }
        case 4:
        {
            Menu::renderAdminMenu(user);
        }
        }
        break;
    }
    case 6:
        LogoutWorkflow::logout();
        return;
    case 7:
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
    if (!ValidateInputWorkflow::validateMenuOption(1, 9, option)) {
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
        this->searchAndViewBus();
        break;
        break;
    case 2:
        this->searchFromStation();
        break;
    case 3: 
        driver.Dayoff();
        break;
    case 4: 
        driver.viewDayoff();
        break;
    case 5: {
        int salary = driver.salary();
        if (salary == -1)
            cout << "Can not calculate your salary" << endl;
        else 
            cout << "You salary = " << salary << endl;
        system("pause");
        break;
    }
    case 6: 
    {
        ifstream f("../Data/AnnounceDriver.txt");
        if (!f.is_open())
            return;
        Announcement an;
        f >> an;
        system("cls");
        cout << "\t\tAnnouncement Driver" << endl;
        cout << an << endl;
        system("pause");
        break;
    }
    case 7:
    {
        system("cls");
        cout << "************************************************\n";
        cout << "*              ACCOUNT MANAGEMENT              *\n";
        cout << "*  1. Change your information.                 *\n";
        cout << "*  2. Change password.                         *\n";
        cout << "*  3. View your information.                   *\n";
        cout << "*  4. Back to menu                             *\n";
        cout << "*                                              *\n";
        cout << "************************************************\n";
        string optionA = "";
    OPTION_AC:
        cout << "Enter you option: ";
        getline(cin, optionA, '\n');
        //Check valid option
        if (!ValidateInputWorkflow::validateMenuOption(1, 4, optionA)) {
            goto OPTION_AC;
        }
        switch (stoi(optionA))
        {

        case 1:
        {   
            system("cls");
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
        case 2:
        {
            system("cls");
            string old = "";
            cout << "Input your old password: "; 
            getline(cin, old, '\n');
            if (!ValidateInputWorkflow::validatePasswordForm(old))
            {
                cout << "Your password form is incorrect" << endl;
                system("pause");
                Menu::renderDriverMenu(user);
                return;
            }
            if (user.isPassword(old) == 0)
            {
                cout << "Incorrect!!!" << endl;
                system("pause");
                Menu::renderDriverMenu(user);
                return;
            }

            string newPassword = "";
            cout << "Enter new password, your password must not have any space or '/' : ";
            getline(cin, newPassword, '\n');

            if (!ValidateInputWorkflow::validatePasswordForm(newPassword))
            {
                cout << "Your password form is incorrect" << endl;
                system("pause");
                Menu::renderDriverMenu(user);
                return;
            }

            string newPassword2 = "";
            cout << "Enter again new password: ";
            getline(cin, newPassword2, '\n');

            if (!ValidateInputWorkflow::validatePasswordForm(newPassword2))
            {
                cout << "Your password form is incorrect" << endl;
                system("pause");
                Menu::renderDriverMenu(user);
                return;
            }

            if (newPassword != newPassword2)
            {
                cout << "Two new password is not the same!!" << endl;
                system("pause");
                Menu::renderDriverMenu(user);
                return;
            }
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

            system("pause");
            break;
        }
        case 3:
        {
            system("cls");
            cout << "********Your information********" << endl;
            cout << driver;

            system("pause");

            break;
        }
        case 4:
        {
            Menu::renderDriverMenu(user);
        }
        }
        break;
        
    }
   
    case 8:
        LogoutWorkflow::logout();
        return;
    case 9:
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

    if (!ValidateInputWorkflow::validateMenuOption(1, 10, option)) {
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
    case 4:
        passenger.viewTicketResult();
        break;
    case 5: {
        ifstream f("../Data/AnnouncePassenger.txt");
        if (!f.is_open())
            return;
        Announcement an;
        f >> an;
        system("cls");
        cout << "\t\tAnnouncement Passenger" << endl;
        cout << an << endl;
        system("pause");
        break;
    }
    case 6: {
        system("cls");
        cout << "************************************************\n";
        cout << "*              ACCOUNT MANAGEMENT              *\n";
        cout << "*  1. Change your information.                 *\n";
        cout << "*  2. Change password.                         *\n";
        cout << "*  3. View your information.                   *\n";
        cout << "*  4. Back to menu                             *\n";
        cout << "*                                              *\n";
        cout << "************************************************\n";
        string optionA = "";
    OPTION_AC:
        cout << "Enter you option: ";
        getline(cin, optionA, '\n');
        //Check valid option
        if (!ValidateInputWorkflow::validateMenuOption(1, 4, optionA)) {
            goto OPTION_AC;
        }
        switch (stoi(optionA))
        {
        case 1:
        {   
            system("cls");
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
        case 2:
        {system("cls");
        string old = "";
        cout << "Input your old password: "; 
        getline(cin, old, '\n');
        if (!ValidateInputWorkflow::validatePasswordForm(old))
        {
            cout << "Your password form is incorrect" << endl;
            system("pause");
            Menu::renderPassengerMenu(user);
            return;
        }
        if (user.isPassword(old) == 0)
        {
            cout << "Incorrect!!!" << endl;
            system("pause");
            Menu::renderPassengerMenu(user);
            return;
        }

        string newPassword = "";
        cout << "Enter new password, your password must not have any space or '/' : ";
        getline(cin, newPassword, '\n');

        if (!ValidateInputWorkflow::validatePasswordForm(newPassword))
        {
            cout << "Your password form is incorrect" << endl;
            system("pause");
            Menu::renderPassengerMenu(user);
            return;
        }

        string newPassword2 = "";
        cout << "Enter again new password: ";
        getline(cin, newPassword2, '\n');
        if (!ValidateInputWorkflow::validatePasswordForm(newPassword2))
        {
            cout << "Your password form is incorrect" << endl;
            system("pause");
            Menu::renderPassengerMenu(user);
            return;
        }
        if (newPassword != newPassword2)
        {
            cout << "Two new password is not the same!!" << endl;
            system("pause");
            Menu::renderPassengerMenu(user);
            return;
        }
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

            system("pause");
            break;
        }
        case 3:
        {
            system("cls");
            cout << "********Your information********" << endl;
            cout << passenger;

            system("pause");

            break;
        }
        case 4:
        {
            Menu::renderPassengerMenu(user);
        }
        }
        break;

       
    }
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
    Sleep(2000);
    //Decentralize user (find valid router)
    const string identify = DecentralizeWorkflow::onDecentralizeUser();
    if (identify == "Admin")
        Menu::renderAdminMenu(loginUser);
    else if (identify == "Driver")
        Menu::renderDriverMenu(loginUser);
    if (identify == "Passenger")
        Menu::renderPassengerMenu(loginUser);
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

    if (!ValidateInputWorkflow::validateMenuOption(1, 2, type))
        goto TYPE;

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
    for (int i = 0; i < list.size(); i++)
        cout << list[i] << endl;

    cout << "********Enter bus Id to view more information********" << endl;

    string option = "";
OPTION:
    cout << "Enter your option: ";
    getline(cin, option, '\n');

    if (!ValidateInputWorkflow::validateMenuOption(1, INT_MAX, option))
        goto OPTION;

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
    vector<string> stations = this->createListStations(); //Take list of all station already have 

    //Sort station A - Z
    std::sort(stations.begin(), stations.end(), sortStation);
    
    //Render stations
    system("cls");
    cout << "\n********STATIONS********" << endl;
    for (int i = 0; i < stations.size(); i++) {
        cout << setw(2) << left << i + 1 << ". " << setw(50) << left << stations[i];
        if (i % 3 == 2)
            cout << endl;
    }
    cout << endl;
    cout << "****************************" << endl;

    string option = "";
OPTION:
    cout << "Enter station you want to view: ";
    getline(cin, option, '\n');

    if (!ValidateInputWorkflow::validateMenuOption(1, int(stations.size()), option))
        goto OPTION;

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
    Sleep(1000);
    cout << "These are buses that go through " << stations[stoi(option) - 1] << " station." << endl;
    system("pause");
}

//Render list station
vector<string> Menu::createListStations() {
   //Request to bus to render stations
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