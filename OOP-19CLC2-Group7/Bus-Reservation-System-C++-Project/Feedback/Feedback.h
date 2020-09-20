#ifndef _FEEDBACK_H_
#define _FEEDBACK_H_

#include "../Header.h"
#include "../User/User.h"
#include "../Workflow/LoginWorkflow/LoginWorkflow.h"
#include "../Workflow/DecentralizeWorkflow/DecentralizeWorkflow.h"

class NodeFeedback
{
private:
	int feedback_number;
	string Name; //
	string date;
	string x;

	NodeFeedback* next;

public:

	friend class Feedback;

};

class Feedback : public User
{
private:
	NodeFeedback* headlist;

public:

	Feedback();

	//Methods
	void Feedbackmenu(User& user);
	void createFeedback();
	void viewFeedback();
	void updateFeedback();
	void printFeedback();
	void deleteFeedback();
	void exit();

};





#endif