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
    cout << "**********************************************************\n";
    cout << "*                          MENU                          *\n";
    cout << "*  1. Search bus no.                                     *\n";
    cout << "*  2. Search station.                                    *\n";
    cout << "*  3. Log in.                                            *\n";
    cout << "*  4. Register.                                          *\n";
    cout << "*  5. Exit app.                                          *\n";
    cout << "*                                                        *\n";
    cout << "**********************************************************\n";
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
    cout << "*  5. Change your information.                        *\n";
    cout << "*  6. Change password.                                *\n";
    cout << "*  7. View your information.                          *\n";
    cout << "*  8. Logout.                                         *\n";
    cout << "*  9. Exit app.                                       *\n";
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
    cout << "*  3. Change your information.                         *\n";
    cout << "*  4. Day off.                                         *\n";
    cout << "*  5. Announcement                                     *\n";
    cout << "*  6. Change password.                                 *\n";
    cout << "*  7. View your information.                           *\n";
    cout << "*  8. Log out.                                         *\n";
    cout << "*  9. Exit app.                                        *\n";
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
    cout << "*  6. Change your information.                         *\n";
    cout << "*  7. Change password.                                 *\n";
    cout << "*  8. View your information.                           *\n";
    cout << "*  9. Log out.                                         *\n";
    cout << "*  10. Exit app.                                       *\n";
    cout << "*                                                      *\n";
    cout << "********************************************************\n";
    return true;
}