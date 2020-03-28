#include"iostream"
#include"string"
#include "Header.h"


using namespace std;
void main()
{
	init();
	int SEARCH = 0;
	do
	{
	  
		cout << "1 - Add new employee" << endl;
		cout << "2 - Editing an employee" << endl;
		cout << "3 - Show ALL employee" << endl;
		cout << "4 - Removal of employee" << endl;
		cout << "5 - List employee by first letter of surname" << endl;
		cout << "6 - List employee by first letter of Age" << endl;
		cout << "7 - List employee by first letter of the first letter" << endl;
		cout << "0 - Exit" << endl;
		cin >> SEARCH;

		switch (SEARCH)
		{
		case 1:
		{   CLEAR
		
			cout << "Add employee" << endl;
		    cout << "-------------------" << endl;
			add_an_employee();
		}
		break;
		case 2:
		{   CLEAR
			
			cout << "Editing an employee" << endl;
		    cout << "-------------------" << endl;
			editing_an_employee();

		}
		break;
		case 3:
		{   CLEAR
		
			cout << "show ALL employee" << endl;
		    cout << "-------------------" << endl;
			showALL_employee();
		}
		break;
		case 4:
		{   CLEAR
			cout << "removal of employee" << endl;
			cout << "-------------------" << endl;
	        removal_of_employee();
		}
		break;
		case 5:
		{CLEAR
			cout << "List employee by first letter of surname" << endl;
		    cout << "----------------------------------------" << endl;
			search_employee_by_last_name();
		}
		break;
		case 6:
		{CLEAR
			cout << "List employee by first letter of Age" << endl;
		    cout << "------------------------------------" << endl;
			 search_employee_by_age();
			
		}
		break;
		case 7:
		{CLEAR
			cout << "List employee by first letter of the first letter" << endl;
		    cout << "-------------------------------------------------" << endl;
		 by_the_first_letter();
		}
		break;
		case 0:
		{
			exit(0);
			break;
		}

		}
	} while (SEARCH != 0);
	system("pause");
}

