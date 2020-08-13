#include "Admin.h"

Admin::Admin() : Information() {}

Admin::Admin(const Admin& ad) : Information(ad) {
	this->user = ad.user;
}

Admin& Admin::operator =(const Admin& ad)
{
	Information::operator=(ad);
	this->user = ad.user;

	return *this;
}

istream& operator >>(istream& is, Admin& ad)
{
	is >> (Information&)ad;

	return is;
}

ostream& operator << (ostream& os, const Admin& ad)
{
	os << (Information const&)ad;

	return os;
}
ifstream& operator >> (ifstream& ifs, Admin& ad)
{
	ifs >> (Information&)(ad);

	return ifs;
}

ofstream& operator << (ofstream& ofs, const Admin& ad)
{
	ofs << (Information const&)(ad);

	return ofs;
}