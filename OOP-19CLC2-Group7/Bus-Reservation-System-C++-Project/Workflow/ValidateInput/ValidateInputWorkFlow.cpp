#include "ValidateInputWorkflow.h"

bool ValidateInputWorkflow::validateNameForm(const string& name) {
    const string regEx = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM ";
	for (int i = 0; i < name.length(); i++)
		//If a character is not include in regEx(valid) return false mean == npos
		if (regEx.rfind(name[i]) == string::npos)
			return false;
	return true;
}

bool ValidateInputWorkflow::validatePasswordForm(const string& password) {
    const string regEx = " /";
    if (password == "")
        return false;
    for (int i = 0; i < password.length(); i++) {
        if (regEx.rfind(password[i]) != string::npos)
            return false;
    }

    return true;
}

bool ValidateInputWorkflow::validateMenuOption(const int& min, const int& max, const string& option) {
    const string regex = "0123456789";

    //Check number input
    if (option == "")
        return false;
    for (int i = 0; i < option.length(); i++) {
        if (regex.rfind(option[i]) == string::npos)  {
            return false;
        }
    }

    int check = stoi(option);
    if (check > max || check < min)
        return false;
    return true;
}