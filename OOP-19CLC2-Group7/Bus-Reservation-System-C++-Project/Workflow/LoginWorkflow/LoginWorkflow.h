#ifndef _LOGIN_WORKFLOW_H_
#define _LOGIN_WORKFLOW_H_

#include "../../User/User.h"

class LoginWorkflow {
public: 
	static bool validateLogin(User& user);
};

#endif