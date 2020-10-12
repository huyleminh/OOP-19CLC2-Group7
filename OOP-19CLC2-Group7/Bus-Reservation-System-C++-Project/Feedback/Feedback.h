#ifndef _FEEDBACK_H_
#define _FEEDBACK_H_

#include "../Header.h"
#include "../User/User.h"
#include "../Workflow/LoginWorkflow/LoginWorkflow.h"
#include "../Workflow/DecentralizeWorkflow/DecentralizeWorkflow.h"



class Feedback : public User
{
private:
	vector<Feedback*> list;

public:

	Feedback();

	//Methods 
	void addFeedback(Feedback* f);
	void Feedbackmenu(User& user);

	virtual void createFeedback();
	virtual void updateFeedback();
	virtual void viewFeedback();
	
	virtual void printFeedback();
	void deleteFeedback();
	void exit();

	/*void loadFeedbackFile(Feedback* f);
	void saveFeedbackFile();

	void loadFeedbacktoFile();
	void saveFeedbacKtoFile();*/

};

class NodeFeedback : public Feedback
{
private:

	string Name; 
	string date;
	string x;

public:

	void createFeedback();
	void updateFeedback();
	void viewFeedback();
	void printFeedback();

	/*void loadFeedbacktoFile(NodeFeedback f);
	void saveFeedbacKtoFile(NodeFeedback f);*/
};




#endif