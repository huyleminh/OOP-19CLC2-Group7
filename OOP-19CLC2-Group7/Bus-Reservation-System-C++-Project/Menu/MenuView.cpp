#include "MenuView.h"
#include "../Workflow/LoginWorkflow/LoginWorkflow.h"
#include "../Workflow/DecentralizeWorkflow/DecentralizeWorkflow.h"
#include "../Workflow/LogoutWorkflow/LogoutWorkflow.h"

//Static attribute 
MenuView* MenuView::_menuview = NULL;


//Method 
MenuView::MenuView(User& user) {
    if (LoginWorkflow::validateLogin(user)) {
        this->_status = this->validateViewRequest();
        return;
    }
    else 
        this->_status = NULL_USER;
}

int MenuView::validateViewRequest() {
    string authorized = DecentralizeWorkflow::onDecentralizeUser();

    if (authorized == "Admin")
       return ADMIN_USER;
    else if (authorized == "Driver")
       return DRIVER_USER;
    else if (authorized == "Passenger")
       return PASSENGER_USER;
    else 
       return NULL_USER;
}

MenuView* MenuView::getMenuView(User& user) {
    if (_menuview == NULL) {
        _menuview = new MenuView(user);
    }
    else {
        delete _menuview;
        _menuview = new MenuView(user);
    }
    return _menuview;
}

void MenuView::forbiddenView() {
    LogoutWorkflow::logout();
    system("cls");
    cout << "You are not allow to access or not logged in yet." << endl;
    cout << "Do the following to go back to global menu." << endl;
    system("pause");
}

void MenuView::mainMenuView() {
    system("cls"); 
    Graphic::changeColour("", WHITE);
    Graphic::setWidth(2); cout << "                / \\"                                 << endl;
    Graphic::setWidth(2); cout << "     __________/ o \\/\\_________      _________"    << "\t\t\t                          __" << endl;
    Graphic::setWidth(2); cout << " ___|               | | # # #  |____|o o o o  | /|\\" << "\t\t .-----------------------'  |" << endl;
    Graphic::setWidth(2); cout << "|. .|               |o| # # #  |. . |o o o o  |//|\\\\"<< "\t\t/| _ .---. .---. .---. .---.|" << endl;
    Graphic::setWidth(2); cout << "|. .| []  []  []  []|o| # # #  |. . |o o o o  |((|))" << "\t\t|j||||___| |___| |___| |___||" << endl;
    Graphic::setWidth(2); cout << "|. .| []  []  []    |o| # # #  |. . |o o o o  |((|))" << "\t\t|=|||=======================|" << endl;
    Graphic::setWidth(2); cout << "|__<|____________;;_|_|___/\\___|_.|_|____[]___|  |" << "\t\t[_|j||(O)\\__________|(O)\\___]" << endl;
    Graphic::setHeight(2);
    Graphic::setWidth(6); Graphic::changeColour("    BUS FOR ALL HOMES", LIGHT_GREEN);
    Graphic::setHeight(2);
    Graphic::setWidth(4);
    Graphic::changeColour("*********************************************************\n",LIGHT_YELLOW);
    Graphic::setWidth(4); cout << "*\t\t\t  "; Graphic::changeColour("M", PINK); Graphic::changeColour("E", LIGHT_PURPLE); Graphic::changeColour("N", LIGHT_AQUA); Graphic::changeColour("U", LIGHT_GREEN); Graphic::changeColour("", LIGHT_YELLOW); cout << "\t\t\t\t*\n";
    Graphic::setWidth(4); cout << "*\t1. Search bus no.\t\t\t\t*\n";
    Graphic::setWidth(4); cout << "*\t2. Search station.\t\t\t\t*\n";
    Graphic::setWidth(4); cout << "*\t3. Log in.\t\t\t\t\t*\n";
    Graphic::setWidth(4); cout << "*\t4. Register.\t\t\t\t\t*\n";
    Graphic::setWidth(4); cout << "*\t5. Exit app.\t\t\t\t\t*\n";
    Graphic::setWidth(4); cout << "*\t\t\t\t\t\t\t*\n";
    Graphic::setWidth(4); cout << "*********************************************************\n";
}

bool MenuView::adminMenuView() {
    system("cls");
    if (this->_status != ADMIN_USER || this->validateViewRequest() != ADMIN_USER) {
        this->forbiddenView();
        return false;
    }
    Graphic::changeColour("", YELLOW);
    Graphic::setWidth(4); cout << "*******************************************************\n";
    Graphic::setWidth(4); cout << "*                    WELCOME ADMIN                    *\n";
    Graphic::setWidth(4); cout << "*  1. Bus Management.                                 *\n";
    Graphic::setWidth(4); cout << "*  2. Search stations.                                *\n";
    Graphic::setWidth(4); cout << "*  3. Driver Management.                              *\n";
    Graphic::setWidth(4); cout << "*  4. Announcement                                    *\n";
    Graphic::setWidth(4); cout << "*  5. Account management.                             *\n";
    Graphic::setWidth(4); cout << "*  6. Logout.                                         *\n";
    Graphic::setWidth(4); cout << "*  7. Exit app.                                       *\n";
    Graphic::setWidth(4); cout << "*                                                     *\n";
    Graphic::setWidth(4); cout << "*******************************************************\n";
    return true;
}

bool MenuView::driverMenuView() {
    system("cls");
    if (this->_status != DRIVER_USER || this->validateViewRequest() != DRIVER_USER) {
        this->forbiddenView();
        return false;
    }
    Graphic::changeColour("", LIGHT_AQUA);
    Graphic::setWidth(4); cout << "********************************************************\n";
    Graphic::setWidth(4); cout << "*                    WELCOME DRIVER                    *\n";
    Graphic::setWidth(4); cout << "*  1. Search bus no.                                   *\n";
    Graphic::setWidth(4); cout << "*  2. Search departure and destination.                *\n";
    Graphic::setWidth(4); cout << "*  3. Day off request.                                 *\n";
    Graphic::setWidth(4); cout << "*  4. Day off histoyry.                                *\n";
    Graphic::setWidth(4); cout << "*  5. Salary.                                          *\n";
    Graphic::setWidth(4); cout << "*  6. Announcement                                     *\n";
    Graphic::setWidth(4); cout << "*  7. Account management.                              *\n";
    Graphic::setWidth(4); cout << "*  8. Log out.                                         *\n";
    Graphic::setWidth(4); cout << "*  9. Exit app.                                        *\n";
    Graphic::setWidth(4); cout << "*                                                      *\n";
    Graphic::setWidth(4); cout << "********************************************************\n";
    return true;
}

bool MenuView::passengerMenuView() {
    system("cls");
    if (this->_status != PASSENGER_USER || this->validateViewRequest() != PASSENGER_USER) {
        this->forbiddenView();
        return false;
    }
    Graphic::changeColour("", LIGHT_GREEN);
    Graphic::setWidth(4); cout << "********************************************************\n";
    Graphic::setWidth(4); cout << "*                    WELCOME PASSENGER                 *\n";
    Graphic::setWidth(4); cout << "*  1. Search bus no.                                   *\n";
    Graphic::setWidth(4); cout << "*  2. Search station.                                  *\n";
    Graphic::setWidth(4); cout << "*  3. Buy ticket.                                      *\n";
    Graphic::setWidth(4); cout << "*  4. View ticket.                                     *\n";
    Graphic::setWidth(4); cout << "*  5. Announcement.                                    *\n";
    Graphic::setWidth(4); cout << "*  6. Account management.                              *\n";
    Graphic::setWidth(4); cout << "*  7. Log out.                                         *\n";
    Graphic::setWidth(4); cout << "*  8. Exit app.                                        *\n";
    Graphic::setWidth(4); cout << "*                                                      *\n";
    Graphic::setWidth(4); cout << "********************************************************\n";
    return true;
}