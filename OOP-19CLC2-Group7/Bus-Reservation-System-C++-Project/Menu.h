#ifndef _MENU_H_
#define _MENU_H_

#include "Header.h"
#include "User.h"

class Menu {
public:    
    void renderMainMenu();
    void renderAdminMenu(User& user);
    void renderDriverMenu(User& user);
    void renderPassengerMenu(User& user);
};

#endif