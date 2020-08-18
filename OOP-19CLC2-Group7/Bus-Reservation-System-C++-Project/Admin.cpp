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

void Admin::changeInformation(User& user)
{
	cout << "1.change password\n"
		<< "2.change role\n"
		<< "3.change name\n"
		<< "4.change sex\n"
		<< "5.change birthday\n"
		<< "6.exit\n";

	int temp = 0;
	cin >> temp;

	while (temp != 1 || temp != 2 || temp != 3 || temp != 4 || temp != 5 || temp != 6)
	{
		cout << "enter 1, 2, 3, 4 or 5 \n";
		cin >> temp;
	}

	if (temp == 6)
	{
		return;
	}

	switch (temp)
	{
	case 1: 
	{
		cout << "Enter password, your password must not have any space or '/' : ";

		//Read to temp password before standarlized, split " " and "/" and set to password.
		string tmpPassword = "";
		getline(cin, tmpPassword, '\n');

		vector<string> tmp = Tokenizer::split(tmpPassword, " ");
		tmpPassword = Tokenizer::join(tmp);

		tmp.clear();
		tmp = Tokenizer::split(tmpPassword, "/");
		tmpPassword = Tokenizer::join(tmp);

		user.changePassword(tmpPassword);
		cout << "SUCCESS\n";

		break;
	}

	case 2:
	{
		string tmpRole;
		getline(cin, tmpRole, '\n');

		user.changeUserRole(tmpRole);
		cout << "SUCCESS\n";

		break;
	}

	case 3:
	{
		cout << "enter name : ";
		string tmp_name;
		getline(cin, tmp_name, '\n');
		while (changeName(tmp_name) == false)
		{
			cout << "FALSE\n"
				<< "1.Enter name: "
				<< "2.Menu";

			int choose = 0;
			cin >> choose;

			while (choose != 1 || choose != 2)
			{
				cout << "choose 1 or 2";
				cin >> choose;
			}

			if (choose == 1)
			{
				getline(cin, tmp_name, '\n');
			}
			else
			{
				changeInformation(user);
			}
		}

		changeName(tmp_name);
		cout << "SUCCESS\n";
		break;
	}

	case 4:
	{
		cout << "Sex: ";
		string tmp_sex;
		getline(cin, tmp_sex, '\n');
		while (tmp_sex != "MALE" || tmp_sex != "FEMALE")
		{
			cout << "FALSE\n"
				<< "1.Enter MALE or FEMALE :"
				<< "2.Menu";

			int choose = 0;
			cin >> choose;

			while (choose != 1 || choose != 2)
			{
				cout << "choose 1 or 2";
				cin >> choose;
			}

			if (choose == 1)
			{
				getline(cin, tmp_sex, '\n');
			}
			else
			{
				changeInformation(user);
			}
		}

		changeSex(tmp_sex);
		cout << "SUCCESS\n";
		break;
	}

	case 5:
	{
		cout << "Enter birthday(dd/mm/yyyy): ";

		string tmp_dob;
		getline(cin, tmp_dob, '\n');

		while (changeBirthday(tmp_dob) == false)
		{
			cout << "FALSE\n"
				<< "1.Enter birthday(dd/mm/yyyy): "
				<<"2.Menu";

			int choose = 0;
			cin >> choose;

			while (choose != 1 || choose != 2)
			{
				cout << "choose 1 or 2";
				cin >> choose;
			}

			if (choose == 1)
			{
				getline(cin, tmp_dob, '\n');
			}
			else
			{
				changeInformation(user);
			}
		}

		changeBirthday(tmp_dob);
		cout << "SUCCESS\n";
		break;
	}

	}

	changeInformation(user);
}

bool Admin::changeName(const string& name)
{
	const string regEx = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM ";
	for (int i = 0; i < name.length(); i++)
		if (regEx.rfind(name[i] == string::npos))
			return false;

	vector<string> tmpStr = Tokenizer::split(name, " ");
	for (int i = 0; i < tmpStr.size(); i++)
		tmpStr[i][0] = tolower(tmpStr[i][0]);

	this->_name = Tokenizer::join(tmpStr, " ");
}

void Admin::changeSex(const string& sex)
{
	this->_sex = sex;
}

bool Admin::changeBirthday(const string& dob)
{
	vector<string> tmpBirthday = Tokenizer::split(dob, "/");

	int a[3];
	for (int i = 0; i < 3; i++)
	{
		a[i] = stoi(tmpBirthday[i]);
	}

	if (a[2] < 1898)
	{
		return false;
	}

	if (a[1] < 1 || a[1] > 12)
	{
		return false;
	}

	switch (a[1])
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (a[0] < 1 || a[0] > 31)
		{
			return false;
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (a[0] < 1 || a[0] > 30)
		{
			return false;
		}
		break;

	case 2:
		if (a[2] % 4 == 0 && a[2] % 100 != 0 || a[2] % 400 == 0)
		{
			if (a[0] < 1 || a[0] > 29)
			{
				return false;
			}
		}
		else
		{
			if (a[0] < 1 || a[0] > 28)
			{
				return false;
			}
		}
		break;
	}

	this->_birthday = dob;
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