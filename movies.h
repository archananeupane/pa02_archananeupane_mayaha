//Archana Neupane and Maya Ha
#include <string>
using namespace std; 
#ifndef MOVIES_H
#define MOVIES_H

class BST{

public:
BST() {root = 0;} //constructor
//~BST();
bool insert();
void printPreOrder() const;

private:
struct Node{
    string movie_name;
    int rating; 
    int depth; // number of nodes on the path from the root to the node containing the movie
    Node *left, *right, *parent; 
    Node(int v = 0) : info(v), left(0), right(0), parent(0) {} //constructor
};
Node *root; 
bool insert( Node *n); 
void printPreOrder(Node *n) const; 

};









#endif