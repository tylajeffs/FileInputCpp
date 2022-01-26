#include "Employee.h"
#include <iostream>

//constructor
Employee::Employee(string n, int i, int a, string j, int y)
{
	name = n;
	id = i;
	age = a;
	job = j;
	year = y;
}


//to print
void Employee::printInfo()
{
	cout << "Name:         " << name << endl;
	cout << "ID:           " << id << endl;
	cout << "Age:          " << age << endl;
	cout << "Hire Year:    " << year << endl;
	cout << "************************************" << endl;

}