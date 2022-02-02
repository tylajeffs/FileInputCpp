// Hello301.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Employee.h"

using namespace std;



int main(int argc, char** argv)
{

    //get the file from the command line
    string filename = argv[1];//"C:/users/config/Desktop/pokemon.txt";
    ifstream ifs;

    //open the file
    ifs.open(filename, ios::in);

    //some basic error-checking...
    if (!ifs) 
    {
        cout << "Error opening file: " << filename << endl;
        return -1;
    }

    //get and store the first line of the file (number of records in the file)
    string firstline;
    getline(ifs, firstline);

    //convert to int
    int numRecords = stoi(firstline);



 





    //create list of employees using the size we read
    Employee** employees = new Employee * [numRecords];

    //loop through all the lines in the file
    for (int i = 0; i < numRecords; i++)
    {
        //create variables
        string empName, empI, empA, empJob, empY;
        int empID, empAge, empYear;

        //get the info from the file, separating with the "|"
        getline(ifs, empName, '|');
        getline(ifs, empI, '|');
        getline(ifs, empA, '|');
        getline(ifs, empJob, '|');
        getline(ifs, empY);

        //convert to int
        empID = stoi(empI);
        empAge = stoi(empA);
        empYear = stoi(empY);

        //create the new employee using the info from the file and store in the arraylist
        Employee* e = new Employee(empName, empID, empAge, empJob, empYear);
        employees[i] = e;

    }




    //Find the queries
    string temp;

    getline(ifs, temp);
    int numQue = stoi(temp);


    //create list of queries
    vector<int> queries;

    //loop through lines of queries
    for (int i = 0; i < numQue; i++)
    {
        string temp1;
        getline(ifs, temp1);

        //store in the array of queries
        queries.push_back(stoi(temp1));
    }



    //close the scanner thingy
    ifs.close();



    


    //TEST TEST


   
     //loop through all queries and print all employee info for those queries
    for (int i = 0; i < numQue; i++)
    {
        //index variable
        int index;

        //loop through employees
        for (int j = 0; j < numRecords; j++)
        {
            if (queries[i] == (employees[j]->id))
            {
                index = j;
                break;
            }
        }

        cout << "FOUND: ";

        employees[index]->printInfo();

        //print where it was found and how many comparisons
        cout << "at index " << index << " after " << index + 1 << " comparisons." << endl;
        cout << endl;

    }

}
