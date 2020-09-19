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
    Graphic::setHeight(7);
    Graphic::setWidth(4);
    Graphic::changeColour("*********************************************************\n",LIGHT_YELLOW);
    Graphic::setWidth(4); cout << "*\t\t\t"; Graphic::changeColour("M", PINK); Graphic::changeColour("E", LIGHT_PURPLE); Graphic::changeColour("N", LIGHT_AQUA); Graphic::changeColour("U", LIGHT_GREEN); Graphic::changeColour("", LIGHT_YELLOW); cout << "\t\t\t\t*\n";
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

    cout << "*******************************************************\n";
    cout << "*                    WELCOME ADMIN                    *\n";
    cout << "*  1. Bus Management.                                 *\n";
    cout << "*  2. Search stations.                                *\n";
    cout << "*  3. Driver Management.                              *\n";
    cout << "*  4. Announcement                                    *\n";
    cout << "*  5. Account management.                             *\n";
    cout << "*  6. Logout.                                         *\n";
    cout << "*  7. Exit app.                                       *\n";
    cout << "*                                                     *\n";
    cout << "*******************************************************\n";
    return true;
}

bool MenuView::driverMenuView() {
    system("cls");
    if (this->_status != DRIVER_USER || this->validateViewRequest() != DRIVER_USER) {
        this->forbiddenView();
        return false;
    }

    cout << "********************************************************\n";
    cout << "*                    WELCOME DRIVER                    *\n";
    cout << "*  1. Search bus no.                                   *\n";
    cout << "*  2. Search departure and destination.                *\n";
    cout << "*  3. Day off.                                         *\n";
    cout << "*  4. Announcement                                     *\n";
    cout << "*  5. Account management.                              *\n";
    cout << "*  6. Log out.                                         *\n";
    cout << "*  7. Exit app.                                        *\n";
    cout << "*                                                      *\n";
    cout << "********************************************************\n";
    return true;
}

bool MenuView::passengerMenuView() {
    system("cls");
    if (this->_status != PASSENGER_USER || this->validateViewRequest() != PASSENGER_USER) {
        this->forbiddenView();
        return false;
    }

    cout << "********************************************************\n";
    cout << "*                    WELCOME PASSENGER                 *\n";
    cout << "*  1. Search bus no.                                   *\n";
    cout << "*  2. Search station.                                  *\n";
    cout << "*  3. Buy ticket.                                      *\n";
    cout << "*  4. View ticket.                                     *\n";
    cout << "*  5. Announcement.                                    *\n";
    cout << "*  6. Account management.                              *\n";
    cout << "*  7. Log out.                                         *\n";
    cout << "*  8. Exit app.                                       *\n";
    cout << "*                                                      *\n";
    cout << "********************************************************\n";
    return true;
}