#pragma once
#include"string"
using namespace std;

#define CLEAR system("cls");
#define PAUSE system("pause");

struct Employees
{
    string Surname;
    string Name;
    string Age;
 
};

void init();
void add_an_employee();
void editing_an_employee();
void showALL_employee();
void removal_of_employee();
void search_employee_by_last_name(); 
void search_employee_by_age();
void by_the_first_letter();

