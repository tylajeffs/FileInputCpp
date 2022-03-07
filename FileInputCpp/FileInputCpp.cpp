// Hello301.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Node.h"

using namespace std;


//global variables
vector<string> lines;
int numLines;
Node* root = NULL;



//methods
void insertNode(Node* n);
void preOrder(Node* n);


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

        //add to the vector
        lines.push_back(trash);
    }


    //close the scanner thingy
    ifs.close();




    //start going through the instructions
    for (string line : lines)
    {
        //check to see what instructions the line contains
        if (line.contains("ADD"))
        {

        }
    }










    

    //perform the hash division algorithm
    hashPartThree(employeeHash);


   



    //print number of collisions
    cout << "\nTotal collisions during lookup phase: ";

}



//method to add node to the binary search tree
void insertNode(Node* n)
{
    //nodes
    Node* y = NULL;
    Node* x = root;

    //check if x has anything in it
    while (x != NULL)
    {
        //set y equal to x
        y = x;

        //check the keys
        if (n->key < x->key)
        {
            //move down to the left
            x = x->left;
        }
        else
        {
            //move down to the right
            x = x->right;
        }

    }


    if (y == NULL)
    {
        //tree is empty, use node as the root
        root = n;
    }
    else if (n->key < y->key)
    {
        //put the node on the left
        y->left = n;

    }
    else
    {
        //put the node on the right
        y->right = n;
    }
}





//preorder traversal of binary tree
void preOrder(Node* n)
{
    if()
}