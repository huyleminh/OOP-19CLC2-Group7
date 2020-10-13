#include "LoginWorkflow.h"
#include "../../List.h"

bool LoginWorkflow::validateLogin(User& user) {
    List<User> list;
    list.loadListDataFromFile("../Data/Users.txt");

    LocalStorage local;
    vector<string> tmp = local.getItem("../Data/LocalStorage.txt");
    string check = "";
    check = Tokenizer::join(tmp, " ");

    if (check == "") {
        if (list.includes(user)) {
            local.setItem("../Data/LocalStorage.txt", user.storageString());
            return true;
        }
    }
    else {
        string validate = user.storageString();

        if (check == validate) {
            if (list.includes(user)) {
                local.setItem("../Data/LocalStorage.txt", user.storageString());
                return true;
            }
        }
    }
    return false;
}