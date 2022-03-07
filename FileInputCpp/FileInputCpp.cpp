// Hello301.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Employee.h"
#include<cstdlib>

using namespace std;


//global variables
vector<string> lines;




Employee** employees;
int comparisons;
int numLines;
int heapSize;
//set the counter
int counter = 0;
int arraySize;
int lookUpCollisions = 0;
int numQ;
vector<string> queries;





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

    //get and store the first line of the file (number of lines)
    string firstline;
    getline(ifs, firstline);

    //convert to int
    numLines = stoi(firstline);

    


    



    //read in all of the lines into the vector
    for (int i = 0; i < numLines; i++)
    {
        //get and store the line into the vector
        string trash;
        getline(ifs, trash);

        //convert to int
        lines.push_back(trash);
    }


    //close the scanner thingy
    ifs.close();



    

    //perform the hash division algorithm
    hashPartThree(employeeHash);


   



    //print number of collisions
    cout << "\nTotal collisions during lookup phase: " << lookUpCollisions <<endl;

}



void preOrder(Node* n)
{
    if()
}