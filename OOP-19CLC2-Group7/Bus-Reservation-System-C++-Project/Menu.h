#ifndef _MENU_H_
#define _MENU_H_

#include "Header.h"
#include "User.h"

class Menu {
public:    
    //Render dynamic menu with each role
    void renderMainMenu();
    void renderAdminMenu(User& user);
    void renderDriverMenu(User& user);
    void renderPassengerMenu(User& user);

    //**Another feature when call in menu
    // *1: Main mennu
    
    //Login feature
    void login();
    
};

#endif