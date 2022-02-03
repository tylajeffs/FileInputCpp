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
	cout << "Name: " << name << ", ";
	cout << "ID: " << id << ", ";
	cout << "Age: " << age << ", ";
	cout << "Hired: " << year << endl;


}


string Employee::writeInfo()
{
	return name + "|" + id + "|" + age + "|" + year;
}