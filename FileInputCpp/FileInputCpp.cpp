// Hello301.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Employee.h"

using namespace std;


//global variables
Employee** employees;
int comparisons;
double total = 0;

int binarySearch(int idToFind, int numRecords);

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
    employees = new Employee * [numRecords];

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



    //loop through all queries and print all employee info for those queries
    for (int i = 0; i < numQue; i++)
    {
        //get the index of the employee using binary search
        int indexOfEmp = binarySearch(queries[i],numRecords);

        //print the info
        cout << "FOUND: ";
        
        employees[indexOfEmp]->printInfo();

        //print index and comparisons
        cout << "at index " << indexOfEmp << " after " << comparisons << " comparisons" << endl;

        //for formatting
        cout << endl;
        cout << "DONE! Average amount of comparisons: " << (total/numQue) << endl;
    }



}


int binarySearch(int idToFind, int numRecords)
{
    //variables
    int low = 0;
    int high = numRecords; 
    int mid;


    //set comparisons to 0
    comparisons = 0;
    


    while (low < high)
    {
        //divide the array in half
        mid = floor((low + high) / 2);


        //figure out which half the id is in
        if (idToFind <= employees[mid]->id)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }

        //increase comparisons
        comparisons += 1;
    }

    //increase the total comparisons
    total += comparisons;


    //return the index of the employee with the given id number
    return high;

}
