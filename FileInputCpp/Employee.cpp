#include "Employee.h"
#include <iostream>
#include <climits>

//constructor
Employee::Employee(string n, int i, int a, string j, int y)
{
	name = n;
	id = i;
	age = a;
	job = j;
	year = y;
}


//default constructor
Employee::Employee()
{
	id = INT_MAX;
	age = 40;

}


//to print
void Employee::printInfo()
{
	cout << "Name: " << name << ", ";
	cout << "ID: " << id << ", ";
	cout << "Age: " << age << ", ";
	cout << "Job: " << job << ", ";
	cout << "Hired: " << year << endl;


}


string Employee::writeInfo()
{
	return (name + "|" + to_string(id) + "|" + to_string(age) + "|" + job + "|" + to_string(year));
}