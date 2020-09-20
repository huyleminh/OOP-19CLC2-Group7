#include "../Feedback/Feedback.h"

Feedback::Feedback()
{
	headlist = NULL;
}

void Feedback::Feedbackmenu(User& user)
{
	if (LoginWorkflow::validateLogin(user) == 1)
	{
		string role = DecentralizeWorkflow::onDecentralizeUser();
		if (role == "Admin")
		{
			int menu;

			system("cls");
			cout << "\n";
			cout << "\t\t ===================================================\n";
			cout << "\t\t|   Feedback Management System - BUS RESERVATION SYSTEM    |\n";
			cout << "\t\t ===================================================\n\n\n";
			cout << "\t\t----------------------------------------------------\n";
			cout << "\t\t\t  Administrator / Staff Login      \n";
			cout << "\t\t----------------------------------------------------\n\n";

			do
			{
				system("cls");
				cout << "\n";
				cout << "\t\t ===================================================\n";
				cout << "\t\t|   Feedback Management System - BUS RESERVATION SYSTEM    |\n";
				cout << "\t\t ===================================================\n\n\n";
				cout << "\t\t--------------------------------------------------\n";
				cout << "\t\t||\t1. Create a Feedback \t\t\t ||\n";
				cout << "\t\t||\t2. View Feedback\t\t\t ||\n";
				cout << "\t\t||\t3. Update Feedback Status \t\t ||\n";
				cout << "\t\t||\t4. Print the Feedback \t\t\t ||\n";
				cout << "\t\t||\t5. Delete a Feedback \t\t\t ||\n";
				cout << "\t\t||\t6. Logout\t\t\t\t ||4\n";
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
			cout << "\n";
			cout << "\t\t ===================================================\n";
			cout << "\t\t|   Feedback Management System - BUS RESERVATION SYSTEM    |\n";
			cout << "\t\t ===================================================\n\n\n";
			cout << "\t\t----------------------------------------------------\n";
			cout << "\t\t\t					 Driver Login				\n";
			cout << "\t\t----------------------------------------------------\n\n";

			do
			{
				system("cls");
				cout << "\n";
				cout << "\t\t ===================================================\n";
				cout << "\t\t|   Feedback Management System - BUS RESERVATION SYSTEM    |\n";
				cout << "\t\t ===================================================\n\n\n";
				cout << "\t\t--------------------------------------------------\n";
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

		else if (role == "Passenger")
		{
			int menu;

			system("cls");
			cout << "\n";
			cout << "\t\t ===================================================\n";
			cout << "\t\t|   Feedback Management System - BUS RESERVATION SYSTEM    |\n";
			cout << "\t\t ===================================================\n\n\n";
			cout << "\t\t----------------------------------------------------\n";
			cout << "\t\t\t					Passenger Login				 \n";
			cout << "\t\t----------------------------------------------------\n\n";

			do
			{
			system("cls");
			cout << "\n";
			cout << "\t\t ===================================================\n";
			cout << "\t\t|   Feedback Management System - BUS RESERVATION SYSTEM    |\n";
			cout << "\t\t ===================================================\n\n\n";
			cout << "\t\t--------------------------------------------------\n";
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
	system("cls");

	cout << "*****************************************************************************************\n";
	cout << "*\t	=========================================================== \t\t*\n";
	cout << "*\t\t|   Feedback Management System - BUS RESERVATION SYSTEM	  |\t\t*\n";
	cout << "*\t\t=========================================================== \t\t*\n";
	cout << "*\t\t                                                             \t\t*\n";
	cout << "*\t\t                                                             \t\t*\n";
	cout << "*\t\t                                                             \t\t*\n";
	cout << "*****************************************************************************************\n";

	cout << "\n		Add Feedback Details of Customer\n";
	cout << "_____________________________________________ \n\n";

	NodeFeedback* temp;
	temp = new NodeFeedback;
	cout << "Type Feedback no: (Remember this if you want to view or print) ";
	cin >> temp->feedback_number;
	
	cout << "Enter Name: ";
	cin.ignore();
	getline(cin, temp->Name);

	while (!StdFormat::stdName(temp->Name)) //sai hàm
	{
		cout << "Wrong input. Input again: "; getline(cin, temp->Name); 
	}


	cout << "Enter Date (DD//MM//YYYY) : ";
	getline(cin, temp->date);

	while (!StdFormat::stdDate(temp->date)) //sai hàm
	{
		cout << "Wrong input. Input again: "; getline(cin, temp->date);
	}

	cout << "Feedback Description:";

	cout << "( you must have enter / at the end of your feedback and press enter one more time ) \n";
	cin.ignore();
	getline(cin, temp->x, '/');

	cout << "===========================================================================" << endl;
	cout << "Feedback added Successfully" << endl;
	cout << "===========================================================================" << endl;
	cout << "Go to Print Feedback to print the Feedback" << endl;
	cout << "===========================================================================" << endl;
	system("PAUSE");

	temp->next = NULL;
	if (this->headlist == NULL)
	{
		headlist = temp;
	}
	else
	{
		NodeFeedback* cur;
		cur= headlist;
		while (cur->next == NULL)
		{
			cur->next = temp;
		}

	}
	system("cls");
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
	
	
	NodeFeedback* prev  = headlist;
	NodeFeedback* cur = prev->next;

	if (cur == NULL)
		cout << "Can not cancel from an empty list.\n";
	else
	{
		while(cur->next != NULL)
		{
			if (cur->feedback_number == num)
			{
				prev->next = cur->next;
				
				if (cur->next == NULL)
				{
					prev->next = NULL;
				}

				cout << "This Feedback is deleted successfully" << endl;
				break;
			}
			
			else {
				cur = cur->next;
				prev = prev->next;
			}
		}
		cout << "The Feedback to be deleted is not in this list " << endl;
	}
}

void Feedback::updateFeedback()
{
	system("cls");
	int num;
	NodeFeedback* cur;

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
	if (headlist == NULL)
	{
		cout << "No Feedback To Update..!" << endl;
	}

	else
	{
		for(cur = headlist; cur; cur = cur->next)
		{
			if (cur->feedback_number == num)
			{
				cout << "Change Feedback Number: ";
				cin >> cur->feedback_number;

				cout << "Change Name: ";
				cin.ignore();
				getline(cin, cur->Name);

				while (!StdFormat::stdDate(cur->Name)) //sai hàm
				{
					cout << "Wrong input. Input again: "; getline(cin, cur->Name);
				}

				cout << "Change Date : ";
				getline(cin, cur->date);

				while (!StdFormat::stdDate(cur->date)) //sai hàm
				{
					cout << "Wrong input. Input again: "; getline(cin, cur->date);
				}


				cout << "Feedback Description:" << endl;
				cout << "( 1000 words maximum ) \n";
				cout << "  ";
				cin.ignore();
				getline(cin, cur->x,'/');

				system("PAUSE");

			}

			cout << "FEEDBACK RECORD UPDATED....!\n\n" << endl;
		}
	}

}	

void Feedback::viewFeedback()
{
	int num;

	system("cls");
	NodeFeedback* cur;

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


	if (headlist == NULL)
	{
		cout << "\t\tThere is no Feedback to show\n";
		cout << "\t\tSo The List is Empty\n";
	}
	for (cur = headlist ;cur ; cur = cur->next)
	{
		if (cur->feedback_number == num)
		{
			
			cout << "Feedback Number : " << cur->feedback_number<< endl;
			cout << "Name: " << cur->Name << endl;

			cout << "Feedback Date : " << cur->date << endl;

			cout << "*****************************************************************************************\n";
			cout << "*_______________________________________________________________________________________*" << endl;
			cout << "*-------------------------													 *" << endl;
			cout << "*|Feedback description: |													 *" << endl;
			cout << "*-------------------------													 *" << endl;
			cout << cur->x;

			cout << "\n";
			cout << "*____________________________________________________________________________________*" << endl;

		}

		break;
	}
}

void Feedback::printFeedback()
{
	int num;
	system("cls");
	ofstream fout;
	fout.open("C:/Users/Dell/source/githubrepo/OOP - 19CLC2 - Group7/OOP - 19CLC2 - Group7/Bus - Reservation - System - C++ - Project/Feedback/FeedbackPrint.txt");
	NodeFeedback* cur = headlist;

	cout << "\n";
	cout << "\t\t ==========================================================\n";
	cout << "\t\t|   Feedback Management System - BUS RESERVATION SYSTEM |\n";
	cout << "\t\t ==========================================================\n\n\n";
	fout << "\n";
	fout << "\t\t ========================================================\n";
	fout << "\t\t|  Feedback Management System - BUS RESERVATION SYSTEM |\n";
	fout << "\t\t ========================================================\n\n\n";
	cout << " Enter the Feedback Number To Print The Feedback Details\n";
	cin >> num;
	cout << "\n";
	cout << "---------------------------------------------------------------------------" << endl;
	cout << "\t\tHere is the Feedback list\n";
	cout << "---------------------------------------------------------------------------" << endl;


	if (cur == NULL)
	{
		cout << "\tThere is no Feedback to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	for(cur = headlist; cur; cur= cur->next)
	{
		if (cur->feedback_number == num)
		{
		
			cout << "Feedback Number : " << cur->feedback_number;
			fout << "Feedback Number : " << cur->feedback_number << endl;
			cout << "\n";
			fout << "\n";

			cout << " Name: " << cur->Name << endl;
			fout << " Name: " << cur->Name << endl;
			cout << "\n";
			fout << "\n";

			cout << "Order Date : " << cur->date << endl;
			fout << "Order Date : " << cur->date << endl;
			cout << "____________________________________________________________________________" << endl;
			fout << "____________________________________________________________________________" << endl;

			cout << "Feedback description: " << endl;
			fout << "Feedback description: " << endl;

			cout << "----------------------" << endl;
			fout << "------------------------------------------------------------------------------" << endl;
			cout << cur->x;
			fout << cur->x << endl;
			cout << "\n";
			cout << "____________________________________________________________________________" << endl;
			fout << "____________________________________________________________________________" << endl;
			break;

		}
		fout.close();
		cout << "Feedback Printed Succesfully....!\n";

	}
}

void Feedback::exit() 
{
	cout << "\nYou choose to exit.\n" << endl;
}	

