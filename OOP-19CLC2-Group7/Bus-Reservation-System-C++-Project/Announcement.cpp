#include "Announcement.h"
ofstream& operator<<(ofstream& ofs, const Announcement& a)
{
	for (int i = 0; i < a.title.size(); i++)
	{
		ofs << endl;
		ofs << a.title[i] << endl;
		ofs << a.content[i] << endl;
		ofs << a.time[i] << endl;

	}
	return ofs;
}

ifstream& operator>>(ifstream& ifs, Announcement& a)
{
	while (!ifs.eof())
	{
		string tmp;

		getline(ifs, tmp);//ignore \n

		if (ifs.eof())// make sure there is end of file
			break;

		getline(ifs, tmp);
		a.title.push_back(tmp);

		getline(ifs, tmp);
		a.content.push_back(tmp);

		getline(ifs, tmp);
		a.time.push_back(tmp);

	}
	return ifs;
}

ostream& operator<<(ostream& os, const Announcement& a)
{
	for (int i = 0; i < a.title.size(); i++)
	{
		os << endl;
		os << i + 1 << ") " << a.title[i] << endl;
		os << a.content[i] << endl;
		os << a.time[i] << endl;
	}
	return os;
}

