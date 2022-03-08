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
void inOrder(Node* n);
void postOrder(Node* n);
void iterativeTreeSearch(int k);


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
        if (line.find("ADD") != -1)
        {
            //get the key from the string
            int pos = line.find(" ");

            int key = stoi(line.substr(pos + 1));

            //create a new node
            Node* n = new Node(key);


            //print what we are trying to add
            cout << "Adding " << key << endl;

            //add the node to the binary tree
            insertNode(n);
        }
        else if(line.find("FIND") != -1)
        {
            //get the key from the string
            int pos = line.find(" ");

            int key = stoi(line.substr(pos + 1));



            //print what we are looking for
            cout << "Looking for: 10   ---   ";


            iterativeTreeSearch(key);

            //formatting
            cout << endl;

        }
        else if(line.find("CLEAR") != -1)
        {
            //clear the entire tree
            root = NULL;

            //print that the tree is deleted
            cout << "(tree deleted!)" << endl;

            //TO DO delete all nodes??



        }
        else if(line.find("PREORDER") != -1)
        {
            //print 
            cout << "PREORDER: ";

            //call preorder function using root
            preOrder(root);

            //formatting
            cout << endl;
        }
        else if(line.find("INORDER") != -1)
        {
            //print 
            cout << "INORDER: ";

            //call in order function using root
            inOrder(root);

            //formatting
            cout << endl;
        }
        else  //call post order function
        {
            //print 
            cout << "POSTORDER: ";

            //call the post order fuction using root
            postOrder(root);

            //formatting
            cout << endl;
        }

    }



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
    if (n != NULL)
    {
        cout << n->key;

        //recursive call on children (LEFT FIRST)
        preOrder(n->left);
        preOrder(n->right);

    }
}




//in order traversal of binary tree
void inOrder(Node* n)
{
    if (n != NULL)
    {
        //recursive call on left child
        inOrder(n->left);

        cout << n->key;

        //recursive call on right child
        inOrder(n->right);

    }

}




//post order traversal of binary tree
void postOrder(Node* n)
{
    if (n != NULL)
    {
        //recursive call on children (LEFT FIRST)
        postOrder(n->left);
        postOrder(n->right);

        cout << n->key;


    }


}



// iterative search function
void iterativeTreeSearch(int k)
{
    //variables
    Node* x = root;
    int kk = x->key;

    //go through the tree
    while (x != NULL && k != x->key)
    {
        //check stuff
        if (kk < x->key)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }

        cout << x->key;
    }

    if (x->key == k)
    {
        cout << "   :   found";
    }
    else
    {
        cout << "   :   not found";
    }
}