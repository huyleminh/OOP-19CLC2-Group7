#ifndef _VALIDATE_INPUT_H_
#define _VALIDATE_INPUT_H_

#include "../../Header.h"

class ValidateInputWorkflow {
public:
    static bool validateNameForm(const string& name);
    static bool validatePasswordForm(const string& password);
    static bool validateMenuOption(const int& min, const int& max, const string& option);
};

#endif