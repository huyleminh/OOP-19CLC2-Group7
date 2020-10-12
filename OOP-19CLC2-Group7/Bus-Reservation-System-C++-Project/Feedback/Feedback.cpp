#include "../Feedback/Feedback.h"

Feedback::Feedback()
{
	
}

void Feedback::addFeedback(Feedback* f)
{
	f->createFeedback();
	list.push_back(f);
}

void Feedback::Feedbackmenu(User& user)
{
	Feedback list;
	if (LoginWorkflow::validateLogin(user) == 1)
	{
		string role = DecentralizeWorkflow::onDecentralizeUser();
		if (role == "Admin")
		{
			int menu;

			system("cls");
			cout << "*****************************************************************************************\n";
			cout << "*\t	=========================================================== \t\t*\n";
			cout << "*\t\t|   Feedback Management System - BUS RESERVATION SYSTEM	  |\t\t*\n";
			cout << "*\t\t=========================================================== \t\t*\n";
			cout << "*\t\t                                                             \t\t*\n";
			cout << "*\t\t                                                             \t\t*\n";
			cout << "*\t\t                                                             \t\t*\n";
			cout << "*****************************************************************************************\n";
			cout << "\t\t\t  Administrator / Staff Login      \n";
			cout << "\t\t----------------------------------------------------\n\n";

			do
			{
				system("cls");
				cout << "*****************************************************************************************\n";
				cout << "*\t	=========================================================== \t\t*\n";
				cout << "*\t\t|   Feedback Management System - BUS RESERVATION SYSTEM	  |\t\t*\n";
				cout << "*\t\t=========================================================== \t\t*\n";
				cout << "*\t\t                                                             \t\t*\n";
				cout << "*\t\t                                                             \t\t*\n";
				cout << "*\t\t                                                             \t\t*\n";
				cout << "*****************************************************************************************\n";
				cout << "\t\t||\t1. Create a Feedback \t\t\t ||\n";
				cout << "\t\t||\t2. View Feedback\t\t\t ||\n";
				cout << "\t\t||\t3. Update Feedback Status \t\t ||\n";
				cout << "\t\t||\t4. Print the Feedback \t\t\t ||\n";
				cout << "\t\t||\t5. Delete a Feedback \t\t\t ||\n";
				cout << "\t\t||\t6. Logout\t\t\t\t ||4\n";
				cout << "\t\t----------------------------------------------------------------------\n";
				cout << "Enter choice: ";
				cin >> menu;

				switch (menu)
				{
				case 1:
				{
					list.addFeedback(new Feedback);
					break;
				}


				case 2:
				{
					Feedback::viewFeedback();
					system("PAUSE");
					break;
				}

				case 3:
				{
					Feedback::updateFeedback();
					system("PAUSE");
					break;
				}

				case 4:
				{
					Feedback::printFeedback();
					system("PAUSE");
					break;
				}
				case 5:
				{
					Feedback::deleteFeedback();
					system("PAUSE");
					break;
				}
				case 6:
				{
					cout << "You are Logged Out...!\n\n\n\n";
					system("PAUSE");
					break;
				}

				}

			} while (menu != 6);
			cout << "THANK YOU" << endl;
			system("PAUSE");
		}
		else if (role == "Driver")
		{
			int menu;

			system("cls");
			cout << "*****************************************************************************************\n";
			cout << "*\t	=========================================================== \t\t*\n";
			cout << "*\t\t|   Feedback Management System - BUS RESERVATION SYSTEM	  |\t\t*\n";
			cout << "*\t\t=========================================================== \t\t*\n";
			cout << "*\t\t                                                             \t\t*\n";
			cout << "*\t\t                                                             \t\t*\n";
			cout << "*\t\t                                                             \t\t*\n";
			cout << "*****************************************************************************************\n";
			cout << "\t\t\t					 Driver Login				\n";
			cout << "\t\t----------------------------------------------------\n\n";

			do
			{
				system("cls");
				cout << "*****************************************************************************************\n";
				cout << "*\t	=========================================================== \t\t*\n";
				cout << "*\t\t|   Feedback Management System - BUS RESERVATION SYSTEM	  |\t\t*\n";
				cout << "*\t\t=========================================================== \t\t*\n";
				cout << "*\t\t                                                             \t\t*\n";
				cout << "*\t\t                                                             \t\t*\n";
				cout << "*\t\t                                                             \t\t*\n";
				cout << "*****************************************************************************************\n";
				cout << "\t\t||\t1. Create a Feedback \t\t\t ||\n";
				cout << "\t\t||\t2. View Feedback\t\t\t ||\n";
				cout << "\t\t||\t3. Print the Feedback \t\t\t ||\n";
				cout << "\t\t||\t4. Logout\t\t\t\t ||4\n";
				cout << "\t\t--------------------------------------------------------------------------------------\n";
				cout << "Enter choice: ";

				cin >> menu;

				switch (menu)
				{
				case 1:
				{
					Feedback::createFeedback();
					break;
				}


				case 2:
				{
					Feedback::viewFeedback();
					system("PAUSE");
					break;
				}

				case 3:
				{
					Feedback::printFeedback();
					system("PAUSE");
					break;
				}

				case 4:
				{
					cout << "You are Logged Out...!\n\n\n\n";
					system("PAUSE");
					break;
				}

				}

			} while (menu != 4);

			cout << "THANK YOU" << endl;
			system("PAUSE");
		}

		else if (role == "Passenger")
		{
			int menu;

			system("cls");
			cout << "*****************************************************************************************\n";
			cout << "*\t	=========================================================== \t\t*\n";
			cout << "*\t\t|   Feedback Management System - BUS RESERVATION SYSTEM	  |\t\t*\n";
			cout << "*\t\t=========================================================== \t\t*\n";
			cout << "*\t\t                                                             \t\t*\n";
			cout << "*\t\t                                                             \t\t*\n";
			cout << "*\t\t                                                             \t\t*\n";
			cout << "*****************************************************************************************\n";

			do
			{
			system("cls");
			cout << "*****************************************************************************************\n";
			cout << "*\t	=========================================================== \t\t*\n";
			cout << "*\t\t|   Feedback Management System - BUS RESERVATION SYSTEM	  |\t\t*\n";
			cout << "*\t\t=========================================================== \t\t*\n";
			cout << "*\t\t                                                             \t\t*\n";
			cout << "*\t\t                                                             \t\t*\n";
			cout << "*\t\t                                                             \t\t*\n";
			cout << "*****************************************************************************************\n";
			cout << "\t\t||\t1. Create a Feedback \t\t\t ||\n";
			cout << "\t\t||\t2. View Feedback\t\t\t ||\n";
			cout << "\t\t||\t3. Print the Feedback \t\t\t ||\n";
			cout << "\t\t||\t4. Logout\t\t\t\t ||4\n";
			cout << "\t\t--------------------------------------------------\n";
			cout << "Enter choice: ";
			
			cin >> menu;

			switch (menu)
			{
			case 1:
			{
				Feedback::createFeedback();
				break;
			}


			case 2:
			{
				Feedback::viewFeedback();
				system("PAUSE");
				break;
			}

			case 3:
			{
				Feedback::printFeedback();
				system("PAUSE");
				break;
			}
	
			case 4:
			{
				cout << "You are Logged Out...!\n\n\n\n";
				system("PAUSE");
				break;
			}

			}

			} while (menu != 4);
			cout << "THANK YOU" << endl;
			system("PAUSE");
		}

	}
	
	else
	{
		cout << "\n\n\t\tInvalid login attempt. Please try again.\n" << '\n';
		system("PAUSE");
		system("cls");
		Feedback::Feedbackmenu(user);
	}
}

void Feedback::createFeedback()
{
}

void Feedback::viewFeedback()
{
	int num;

	system("cls");

	cout << "*****************************************************************************************\n";
	cout << "*\t	=========================================================== \t\t*\n";
	cout << "*\t\t|   Feedback Management System - BUS RESERVATION SYSTEM	  |\t\t*\n";
	cout << "*\t\t=========================================================== \t\t*\n";
	cout << "*\t\t                                                             \t\t*\n";
	cout << "*\t\t                                                             \t\t*\n";
	cout << "*\t\t                                                             \t\t*\n";
	cout << "*****************************************************************************************\n";

	cout << endl;
	cout << "* Enter the Feedback Number To Look into The Feedback Details:";
	cin >> num;
	cout << endl;

	cout << "------------------------------------------------------------------------------------------" << endl;
	cout << "\t\tHere is the Feedback list\n";
	cout << "------------------------------------------------------------------------------------------" << endl;


	if (list.size() == 0)
	{
		cout << "\t\tThere is no Feedback to show\n";
		cout << "\t\tSo The List is Empty\n";
	}
	else
	{
		for (int i = 0; i < list.size(); i++)
		{
			if (num - 1 == i)
			{
				list[num-1]->viewFeedback();
				break;
			}
		}
	}
}

void Feedback::updateFeedback()
{
	system("cls");
	int num;

	cout << "*****************************************************************************************\n";
	cout << "*\t	=========================================================== \t\t*\n";
	cout << "*\t\t|   Feedback Management System - BUS RESERVATION SYSTEM	  |\t\t*\n";
	cout << "*\t\t=========================================================== \t\t*\n";
	cout << "*\t\t                                                             \t\t*\n";
	cout << "*\t\t                                                             \t\t*\n";
	cout << "*\t\t                                                             \t\t*\n";
	cout << "*****************************************************************************************\n";

	cout << "Enter Feedback Number To Update: ";
	cin >> num;
	if (list.size() == 0)
	{
		cout << "No Feedback To Update..!" << endl;
	}

	else
	{
		for (int i = 0; i < list.size(); i++)
		{
			if (num - 1 == i)
			{
				list[num-1]->updateFeedback();
			}
		}
	}
}

void Feedback::printFeedback()
{
	int num;
	system("cls");

	cout << "\n";
	cout << "\t\t ==========================================================\n";
	cout << "\t\t|   Feedback Management System - BUS RESERVATION SYSTEM |\n";
	cout << "\t\t ==========================================================\n\n\n";
	cout << " Enter the Feedback Number To Print The Feedback Details\n";
	cin >> num;
	cout << "\n";
	cout << "---------------------------------------------------------------------------" << endl;
	cout << "\t\tHere is the Feedback list\n";
	cout << "---------------------------------------------------------------------------" << endl;


	if (list.size() == 0)
	{
		cout << "\tThere is no Feedback to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	for (int i = 0; i < list.size(); i++)
	{
		if (num - 1 == i)
		{
			list[num-1]->printFeedback();
			break;
		}
	}
}

void Feedback::deleteFeedback()
{
	system("cls");
	int num;

	cout << "*****************************************************************************************\n";
	cout << "*\t	=========================================================== \t\t*\n";
	cout << "*\t\t|   Feedback Management System - BUS RESERVATION SYSTEM	  |\t\t*\n";
	cout << "*\t\t=========================================================== \t\t*\n";
	cout << "*\t\t                                                             \t\t*\n";
	cout << "*\t\t                                                             \t\t*\n";
	cout << "*\t\t                                                             \t\t*\n";
	cout << "*****************************************************************************************\n";

	cout << "Enter the Feedback number you want to delete \n";
	cin >> num;

	if (num > list.size()) {
		cout << "The Feedback to be deleted is not in this list " << endl;
	}
	else list.erase(list.begin() + num - 1);

	cout << "Every time u delete, the number feedback u view, is not the last one, will minus by 1 \n ex: you have feed 1 and 2 and u delete 1 then if u want to view feed 2 then choose 1 not 2  " << endl;
	system("pause");

}

void NodeFeedback::createFeedback()
{
	system("cls");

	cout << "*****************************************************************************************\n";
	cout << "*\t	=========================================================== \t\t*\n";
	cout << "*\t\t|   Feedback Management System - BUS RESERVATION SYSTEM	  |\t\t*\n";
	cout << "*\t\t=========================================================== \t\t*\n";
	cout << "*\t\t                                                             \t\t*\n";
	cout << "*\t\t                                                             \t\t*\n";
	cout << "*\t\t                                                             \t\t*\n";
	cout << "*****************************************************************************************\n";

	cout << "\n			       Add Feedback Details of Customer\n";
	cout << "__________________________________________________________________________________________ \n\n";
	
	
	cout << "Enter Name: ";
	getline(cin, this->Name);

	//while (!StdFormat::stdName(this->Name)) // sai hamf
	//{
	//	cout << "Wrong input. Input again: "; getline(cin, this->Name); 
	//}


	cout << "Enter Date (DD//MM//YYYY) : ";
	getline(cin, this->date);

	//while (!StdFormat::stdDate(this->date)) //sai hàm
	//{
	//	cout << "Wrong input. Input again: "; getline(cin, this->date);
	//}

	cout << "Feedback Description: (1000 words max) ";

	cout << "( if you want to down a line then press space -> enter ) \n";
	string temp;
	do
	{
		getline(cin, temp);
		temp += "\n";
		this->x.append(temp);
		
	} while (temp != "\n");
	

	cout << "===========================================================================" << endl;
	cout << "Feedback added Successfully" << endl;
	cout << "===========================================================================" << endl;
	cout << "Go to Print Feedback to print the Feedback" << endl;
	cout << "===========================================================================" << endl;
	system("PAUSE");

	system("cls");
}

void NodeFeedback::updateFeedback()
{

	cout << "Change Name: ";
	cin.ignore();
	getline(cin, this->Name);


	//while (!StdFormat::stdDate(this->Name)) //sai hàm
	//{
	//	cout << "Wrong input. Input again: "; getline(cin, this->Name);
	//}

	cout << "Change Date : ";
	getline(cin, this->date);

	//while (!StdFormat::stdDate(this->date)) //sai hàm
	//{
	//	cout << "Wrong input. Input again: "; getline(cin, this->date);
	//}


	cout << "Feedback Description ( 1000 words maximum ): " << endl;
	cout << "  ";

	this->x = "";
	string temp;
	do
	{
		getline(cin, temp);
		temp += "\n";
		this->x.append(temp);

	} while (temp != "\n");

	cout << "FEEDBACK RECORD UPDATED....!\n\n" << endl;

	system("PAUSE");
}

void NodeFeedback::viewFeedback()
{

	cout << "Name: " << this->Name << endl;

	cout << "Feedback Date : " << this->date << endl;

	cout << "*****************************************************************************************\n";
	cout << "*_______________________________________________________________________________________*" << endl;
	cout << "*-------------------------													 *" << endl;
	cout << "*|Feedback description: |													 *" << endl;
	cout << "*-------------------------													 *" << endl;
	cout << this->x;

	cout << "\n";
	cout << "*________________________________________________________________________________________*" << endl;

	system("PAUSE");
}

void NodeFeedback::printFeedback()
{
	ofstream fout;
	fout.open("C:/Users/Dell/source/githubrepo/OOP-19CLC2-Group7/OOP-19CLC2-Group7/Bus-Reservation-System-C++-Project/Feedback/FeedbackPrint.txt");

	fout << "\n";
	fout << "\t\t ========================================================\n";
	fout << "\t\t|  Feedback Management System - BUS RESERVATION SYSTEM |\n";
	fout << "\t\t ========================================================\n\n\n";
	cout << " Name: " << this->Name << endl;
	fout << " Name: " << this->Name << endl;
	cout << "\n";
	fout << "\n";

	cout << "Order Date : " << this->date << endl;
	fout << "Order Date : " << this->date << endl;
	cout << "____________________________________________________________________________" << endl;
	fout << "____________________________________________________________________________" << endl;

	cout << "Feedback description: " << endl;
	fout << "Feedback description: " << endl;

	cout << "----------------------" << endl;
	fout << "------------------------------------------------------------------------------" << endl;
	cout << this->x;
	fout << this->x << endl;
	cout << "\n";
	cout << "____________________________________________________________________________" << endl;
	fout << "____________________________________________________________________________" << endl;

	fout.close();
	cout << "Feedback Printed Succesfully....!\n";

}

//void NodeFeedback::loadFeedbacktoFile(NodeFeedback f)
//{
//	ifstream fin;
//	getline(fin,f.Name);
//	getline(fin, f.date);
//	getline(fin, f.x);
//}
//
//void NodeFeedback::saveFeedbacKtoFile(NodeFeedback f)
//{
//	ofstream fout;
//	fout << f.Name << endl;
//	fout << f.date << endl;
//	fout << f.x << endl;
//
//}
//
//void Feedback::exit()
//{
//	cout << "\nYou choose to exit.\n" << endl;
//}
//void Feedback::loadFeedbackFile(Feedback* f)
//{
//	ifstream fin;
//	fin.open("C:/Users/Dell/source/githubrepo/OOP - 19CLC2 - Group7/OOP - 19CLC2 - Group7/Data/Feedback.txt");
//
//	if (!fin.is_open())
//	{
//		cout << "Can not open the file";
//	}
//	else
//	{
//		list.clear();
//
//		/*if(!fin.eof()
//		list.push_back()*/
//
//	}
//}
//
//void Feedback::saveFeedbackFile()
//{
//	ofstream fout;
//	fout.open("C:/Users/Dell/source/githubrepo/OOP - 19CLC2 - Group7/OOP - 19CLC2 - Group7/Data/Feedback.txt");
//
//	if (!fout.is_open())
//	{
//		cout << "Can not open the file";
//	}
//
//	else
//	{
//		for (int i = 0; i < list.size(); i++)
//		{
//			NodeFeedback temp;
//			list[i]->saveFeedbacKtoFile(temp);
//		}
//	}
//}
//
//void Feedback::loadFeedbacktoFile()
//{
//
//}
//
//void Feedback::saveFeedbacKtoFile()
//{
//
//}
