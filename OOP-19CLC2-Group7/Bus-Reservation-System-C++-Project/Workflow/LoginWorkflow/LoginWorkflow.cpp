#include "LoginWorkflow.h"
#include "../../List.h"

bool LoginWorkflow::validateLogin(User& user) {
    List<User> list;
    list.loadListDataFromFile("../Data/Users.txt");

    if (list.includes(user)) {
        //Set store identify string to local storage
        LocalStorage local;
        local.setItem("../Data/LocalStorage.txt", user.storageString());

        return true;
    }
    user.release();
    return false;
}