#include "ValidateInputWorkflow.h"

bool ValidateInputWorkflow::validateNameForm(const string& name) {
    const string regEx = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM ";
	for (int i = 0; i < name.length(); i++)
		//If a character is not include in regEx(valid) return false mean == npos
		if (regEx.rfind(name[i]) == string::npos)
			return false;
	return true;
}

bool ValidateInputWorkflow::validateDateFrom() 
{
    return true;
}

bool ValidateInputWorkflow::validatePasswordForm(const string& password) {
    const string regEx = " /";
    for (int i = 0; i < password.length(); i++) {
        if (regEx.rfind(password[i]) != string::npos)
            return false;
    }

    return true;
}
