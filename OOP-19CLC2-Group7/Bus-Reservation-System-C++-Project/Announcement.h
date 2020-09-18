#ifndef ANNOUNCEMENT_H
#define ANNOUNCEMENT_H
#include"Header.h"
#include"Workflow/ValidateInput/ValidateInputWorkflow.h"
class Announcement
{
private:
	vector<string> title;
	vector<string> content;
	vector<string> time;
public:
	//Operator
	friend ofstream& operator<<(ofstream& ofs, const Announcement &a);
	friend ifstream& operator>>(ifstream& ifs, Announcement& a);
	friend ostream& operator<<(ostream& os, const Announcement& a);

	friend class Admin;


};

#endif

