#include "Node.h"
#include <cstddef>



//constructor
Node::Node(int k)
{
	key = k;
	left = NULL;
	right = NULL;
}



//deconstructor
Node::~Node()
{
	delete left;
	delete right;
}




