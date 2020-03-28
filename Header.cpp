#include "Header.h"
#include"iostream"
#include"fstream"
#include"string"

using namespace std;


Employees* employees;
int SIZE = 0;
int choice;
int number;
string name;
string surname;
string age;
string fileName = "employees.txt";


void init()
{

	ifstream fin;
	fin.open(fileName);
	bool isOpen = fin.is_open();
	string data1;
	int num = 0;
	int currentString = 0;
	if (isOpen == false)
	{
		cout << "File not opened" << endl;
	}
	else
	{
		while (!fin.eof())
		{
			getline(fin, data1);
			num++;
		}
		SIZE = (num - 1) / 3;
	}
	fin.close();

	if (SIZE != 0)
	{
		fin.open(fileName);
		Employees* new1Employees = new Employees[SIZE];
		bool isOpen1 = fin.is_open();
		if (isOpen1 == false)
		{
			cout << "File not opened" << endl;
		}
		else {
			int i = 0;
			while (!fin.eof())
			{

				currentString++;
				getline(fin, data1);
				for (int j = i; j < SIZE;)
				{
					if (currentString == 1)
					{
						new1Employees[i].Surname = data1;
						break;
					}

					else if (currentString == 2)
					{
						new1Employees[i].Name = data1;
						break;
					}
					else if (currentString == 3)
					{
						new1Employees[i].Age = data1;
						currentString = 0;
						i++;

						break;

					}
				}
			}
		}
		fin.close();
		employees = new1Employees;
	}
	PAUSE
	CLEAR
}

void add_an_employee()
{
	Employees* newEmployees = new Employees[SIZE + 1];

	for (int i = 0; i < SIZE; i++)
	{
		newEmployees[i] = employees[i];
	}
	cout << "Enter Surname employees\n:";
	cin >> newEmployees[SIZE].Surname;
	cout << "Enter name employees\n:";
	cin >> newEmployees[SIZE].Name;
	cout << "Enter Age employees\n:";
	cin >> newEmployees[SIZE].Age;

	ofstream fout;
	fout.open(fileName, fstream::app);
	bool isOpen = fout.is_open();
	if (isOpen == true)
	{
		fout << newEmployees[SIZE].Surname << endl;
		fout << newEmployees[SIZE].Name << endl;
		fout << newEmployees[SIZE].Age << endl;

		fout.close();
		SIZE++;
		delete[] employees;
		employees = newEmployees;
		cout << "new employee added" << endl;
	}
	else
	{
		cout << "File not opened";
	}
	PAUSE
		CLEAR

}

void editing_an_employee()
{
	do
	{
		for (int i = 0; i < SIZE; i++)
		{
			cout << i << ":" << employees[i].Surname << ":" << employees[i].Name << ":" << employees[i].Age << endl;
		}
		cout << endl;

		cout << "what you want to edit" << endl;
		cout << "1-Name" << endl;
		cout << "2-Surname" << endl;
		cout << "3-Age" << endl;
		cout << "4-Exit the program\/:" << endl;
		cin >> choice;
		if (choice != 4)
		{
			cout << "Enter number employees you want to edit\n:";
			cin >> number;
		}
		
		switch (choice)
		{
		case 1:
		{   CLEAR
			cout << "Enter name one you want to edit" << endl;
			cout << "Name:";
			cin >> name;
			for (int i = 0; i < SIZE; i++)
			{
				if (i == number)
				{
					employees[i].Name = name;
				}
			}
		
			break;
		}
		case 2:
		{
			CLEAR
			cout << "Enter surname you want to edit" << endl;
			cout << "Surname:";
			cin >> surname;
			for (int i = 0; i < SIZE; i++)
			{
				if (i == number)
				{
					employees[i].Surname = surname;
				}
			}
			
			break;
		}
		case 3:
		{
			CLEAR
			cout << "Enter age you want to edit" << endl;
			cout << "Age:";
			cin >> age;
			for (int i = 0; i < SIZE; i++)
			{
				if (i == number)
				{
					employees[i].Age = age;
				}
			}
			
			break;
		}
		case 4:
		{
			ofstream fout;
			fout.open(fileName);
			bool isOpen = fout.is_open();
			if (isOpen == false)
			{
				cout << "file not opened" << endl;
			}
			else
			{
				for (int i = 0; i < SIZE; i++)
				{   fout << employees[i].Surname << endl;
					fout << employees[i].Name << endl;
					fout << employees[i].Age << endl;
				}
				cout << "written to a file" << endl;
			}
			
			fout.close();	
		}
		break;
		}

	} while (choice != 4);
	PAUSE
	CLEAR
}

void showALL_employee()
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << i << ":" << employees[i].Surname << ":" << employees[i].Name << ":" << employees[i].Age << endl;
	}
	PAUSE
	CLEAR
}

void removal_of_employee()
{
	Employees* deleteEmployees = new Employees[SIZE - 1];
	for (int i = 0; i < SIZE; i++)
	{
		cout << i << ":" << employees[i].Surname << ":" << employees[i].Name << ":" << employees[i].Age << endl;
	}
	cout << endl;


	cout << "Enter number employees you want to delete " << endl;
	cin >> number;
	ofstream fout;
	fout.open(fileName);
	bool isOpen = fout.is_open();
	string data1;
	if (isOpen == false)
	{
		cout << "File not opened" << endl;
	}
	else
	{

		for (int i = 0, j = 0; i < SIZE; i++)
		{
			if (i != number)
			{
				deleteEmployees[j] = employees[i];
				j++;
			}

		}
		SIZE--;
		for (int i = 0; i < SIZE; i++)
		{
			fout << deleteEmployees[i].Surname << endl;
			fout << deleteEmployees[i].Name << endl;
			fout << deleteEmployees[i].Age << endl;
		}

		delete[] employees;
		employees = deleteEmployees;
		fout.close();
	}
	cout << " employe  delete " << endl;
	PAUSE
	CLEAR
}

void search_employee_by_last_name()
{
	cout << "Enter  search surname\n:";
	cin >> surname;
	for (int i = 0; i < SIZE; i++)
	{
		if (surname == employees[i].Surname)
		{
			cout << i << ":" << employees[i].Surname << ":" << employees[i].Name << ":" << employees[i].Age << endl;
		}
	}
	PAUSE
	CLEAR
}

void search_employee_by_age()
{
	cout << "Enter search age \n:";
	cin >> age;
	for (int i = 0; i < SIZE; i++)
	{
		if (age == employees[i].Age)
		{
			cout << i << ":" << employees[i].Surname << ":" << employees[i].Name << ":" << employees[i].Age << endl;
		}
	}
	PAUSE
	CLEAR
}

void by_the_first_letter()
{
	char surname1;
	cout << "enter  search  letter surname \n:";
	cin >> surname1;
	for (int i = 0; i < SIZE; i++)
	{
		if (surname1 == employees[i].Surname[0])
		{
			cout << i << ":" << employees[i].Surname << ":" << employees[i].Name << ":" << employees[i].Age << endl;
		}

	}
	PAUSE
	CLEAR
}



