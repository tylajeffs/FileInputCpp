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
int numRecords;
int heapSize;
//set the counter
int counter = 0;







int binarySearch(int idToFind, int numRecords);

void bubbleSort();

void insertionSort();

void selectionSort();


//p is first index to sort, r is last index
void mergeSort(int p, int r);

void merge(int p, int q, int r);

void heapSort();
void maxHeapify(int i);
void buildMaxHeap();

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
    numRecords = stoi(firstline);



 





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


    //close the scanner thingy
    ifs.close();



    

    //perform the heap sort algorithm
    heapSort();


    //print all of the id numbers SMALL ONLY
    for (int k = 0; k < numRecords; k++)
    {
        cout << employees[k]->id << " ";
    }

    //formatting
    cout << endl;

    //print it out
    cout << "it took " << counter << " comparisons to sort this list" << endl;




    //write out the sorted array to an external file
    ofstream ofs;
    ofs.open("C:/users/config/desktop/heapSorted.txt", ios::out);

    for (int i = 0; i < numRecords; i++)
    {
        //make a method to return a string 
        ofs << employees[i]->writeInfo() << endl;

    }

    //close it
    ofs.close();

}




//binary search algorithm
int binarySearch(int idToFind, int numRecords)
{
    //variables
    double average;
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


    //return the index of the employee with the given id number
    return high;

}






//bubble sort algorithm
void bubbleSort()
{
    //set comparisons to 0
    comparisons = 0;



    //sort the array
    for (int i = 0; i < numRecords - 1; i++)
    {
        for (int j = numRecords - 1; j >= i+1; j--)
        {
            //increase comparisons
            comparisons++;


            //check the values at indexes
            if (employees[j]->id < employees[j - 1]->id)
            {
                //store one employee in a temporary variable
                Employee* temp = employees[j];

                //switch the employees
                employees[j] = employees[j - 1];
                employees[j-1] = temp;





                //for small values!! print out the whole list of id #s
                for (int k = 0; k < numRecords; k++)
                {
                    //print the id # of the employee
                    cout << employees[k]->id;
                }




                //print a new line
                cout << endl;


                

            }

        }

    }

    //print number of comparisons
    cout << "it took " << comparisons << " comparisons to sort this list" << endl;

}







//insertion sort algorithm
void insertionSort()
{
    //set comparisons to 0
    comparisons = 0;

    for (int i = 1; i < numRecords; i++)
    {
        //set the key
        Employee* key = employees[i];

        //insert the value where it belongs
        int j = i - 1;

        //while loop moves everything over so there is space to add the key
        while (j >= 0 && (employees[j]->id > key->id))
        {
            //increase comparisons
            comparisons++;

           
            employees[j + 1] = employees[j];
            
            //decrease j
            j = j - 1;
        }

        //insert the employee at the right place
        employees[j + 1] = key;

        //print all of the id numbers SMALL ONLY
        for (int k = 0; k < numRecords; k++)
        {
            cout << employees[k]->id << " ";
        }

        //formatting
        cout << endl;

    }

    cout << "it took " << comparisons << " comparisons to sort this list" << endl;



}





void selectionSort()
{

    //set comparisons to 0
    comparisons = 0;

    for (int i = 0; i < numRecords - 1; i++)
    {
        //set minimum index
        int minIndex = i;

        for (int j = i + 1; j < numRecords; j++)
        {
            //increase comparisons
            comparisons++;

            //compare employee id's
            if (employees[j]->id < employees[minIndex]->id)
            {
                minIndex = j;
            }
        }

        //store employee in temporary variable
        Employee* temp = employees[minIndex];

        //exchange the employees
        employees[minIndex] = employees[i];
        employees[i] = temp;




        //print all of the id numbers SMALL ONLY
        for (int k = 0; k < numRecords; k++)
        {
            cout << employees[k]->id << " ";
        }

        //formatting
        cout << endl;


    }

    //print comparisons
    cout << "it took " << comparisons << " comparisons to sort this list" << endl;


}





//merge sort algorithm - takes in the first and last index of the array
void mergeSort(int p, int r)
{

    if (p < r)
    {
        //midpoint between p and r
        int q = (p + r) / 2;

        mergeSort(p, q);
        mergeSort((q + 1), r);
        merge(p, q, r);


    }

    
}



void merge(int p, int q, int r)
{

    int num1 = q - p + 1;
    int num2 = r - q;

    //create new sub arrays of employees
    Employee** L = new Employee * [num1];
    Employee** R = new Employee * [num2];

    for (int i = 0; i < num1; i++)
    {
        L[i] = employees[p + i];
    }

    for (int j = 0; j < num2; j++)
    {
        R[j] = employees[q + j + 1];
    }

    L[num1] = new Employee();
    R[num2] = new Employee();

    int i = 0;
    int j = 0;

    for (int k = p; k <= r; k++)
    {
        counter++;

        if(L[i]->id <= R[j]->id)
        {
            employees[k] = L[i];
            i += 1;
        }
        else
        {
            employees[k] = R[j];
            j = j + 1;
        }
    }

    //print all of the id numbers SMALL ONLY
    for (int k = 0; k < numRecords; k++)
    {
        cout << employees[k]->id << " ";
    }

    //formatting
    cout << endl;
    
    




}





void heapSort()
{
    //print all of the id numbers SMALL ONLY
    for (int k = 0; k < numRecords; k++)
    {
        cout << employees[k]->id << " ";
    }

    //formatting
    cout << endl;




    //call build max heap
    buildMaxHeap();

    for (int i = numRecords - 1; i >= 1; i--)
    {

        //print all of the id numbers SMALL ONLY
        for (int k = 0; k < numRecords; k++)
        {
            cout << employees[k]->id << " ";
        }

        //formatting
        cout << endl;



        //exchange the employees
        Employee* temp = employees[i];
        employees[i] = employees[0];
        employees[0] = temp;

        //decrease the heap size
        heapSize--;

        //call max heapify passing in the first index of the array (0)
        maxHeapify(0);

    }



}



void maxHeapify(int i)
{

    //find the indexes of the left and right of the array
    int l = (2*i) + 1;
    int r = 2 * (i + 1);
    int largest;

    //increase the counter
    counter++;

    //check to see if the id numbers are different
    if (l <= heapSize && employees[l]->id > employees[i]->id)
    {
        largest = l;
    }
    else
    {
        largest = i;
    }

    //increase counter again
    counter++;

    //comparisons
    if (r <= heapSize && employees[r]->id > employees[largest]->id)
    {
        largest = r;
    }
    if (largest != i)
    {
        //exchange the employees
        Employee* temp = employees[i];
        employees[i] = employees[largest];
        employees[largest] = temp;

        //recursive call to max heapify
        maxHeapify(largest);


    }

}


void buildMaxHeap()
{
    //set heap size
    heapSize = numRecords -1;

    for (int i = numRecords/2; i >= 0; i--)
    {
        //call max heapify
        maxHeapify(i);
    }

}