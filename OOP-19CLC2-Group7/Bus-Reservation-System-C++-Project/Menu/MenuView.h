#ifndef _MENU_VIEW_H
#define _MENU_VIEW_H

#include "../Header.h"
#include "../User/User.h"

class MenuView {
protected:  
    static MenuView* _menuview;
    int _status;

    MenuView(User& user);
    int validateViewRequest();
public:
    //Prevent clone MenuView
    MenuView(MenuView& other) = delete;
    void operator = (const MenuView& ) = delete;

    //Singleton get instance method
    static MenuView* getMenuView(User& user);

    //Menu view    
    //
    //Error view (403)
    //
    void forbiddenView();
    void notAuthorized();
    
    //Global view
    //
    static void mainMenuView();

    //Admin view mangement
    //
    bool adminMenuView();
    //
    //Bus management view 

    //Driver view management
    //
    bool driverMenuView();

    //Passenger view management
    //
    bool passengerMenuView();

};

#endif