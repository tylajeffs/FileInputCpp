
#pragma once

#include <string>

using namespace std;

class Employee
{
public:

	string name;
	int id;
	int age;
	string job;
	int year;


	Employee(string, int, int, string, int);

	Employee();

	void printInfo();

	string writeInfo();


};

