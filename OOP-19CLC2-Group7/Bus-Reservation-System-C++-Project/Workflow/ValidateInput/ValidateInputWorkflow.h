#ifndef _VALIDATE_INPUT_H_
#define _VALIDATE_INPUT_H_

#include "../../Header.h"

class ValidateInputWorkflow {
public:
    static bool validateNameForm(const string& name);
    static bool validateDateFrom();
    static bool validatePasswordForm(const string& password);
};

#endif