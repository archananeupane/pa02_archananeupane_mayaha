//Archana Neupane and Maya Ha
#include <iostream>
using namespace std; 
#include "movies.h"

BST :: BST () : root(0) {} //constructor

//BST :: ~BST () {   }

void BST :: printPreOrder() const{
    printPreOrder(root);
}

void BST :: printPreOrder(Node *n) const{

}

BST :: Node(string name, int rank, int location ) {
    movie_name = name;
    rating = rank;
    depth = location;
}