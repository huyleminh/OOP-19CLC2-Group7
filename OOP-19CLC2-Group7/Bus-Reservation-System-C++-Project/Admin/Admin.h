#ifndef _ADMIN_H_
#define _ADMIN_H_

#include "../Information/Information.h"
#include "../User/User.h"
#include "../List.h"
#include "../Driver/Driver.h"
#include "../Bus/Bus.h"
#include "../Announcement.h"
class Admin : public Information
{
private:
public:
	//Constructor
	Admin();
	Admin(const Admin& ad);

	//Operator assignment
	Admin& operator= (const Admin& ad);

	//Operator input output(console and form file)
	friend istream& operator >> (istream& is, Admin& ad);
	friend ostream& operator << (ostream& os, const Admin& ad);
	friend ifstream& operator >> (ifstream& ifs, Admin& ad);
	friend ofstream& operator << (ofstream& ofs, const Admin& ad);

	//Methods change information
	void changeInformation(User& user); //Render change information interface

	void addDriver();
	void deleteDriver();
	void editDriver();

	void addBus();
	void deleteBus();
	void editBus();

	void editAnnounce(Announcement& a);
	void addAnnounce(Announcement& a);
	void deleteAnnounce(Announcement& a);
private:
	bool changeName(const string& name);
	void changeSex(const string& sex);
	bool changeBirthday(const string& dob);
};

#endif