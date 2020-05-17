//Archana Neupane and Maya Ha
#include <string>
using namespace std; 
#ifndef MOVIES_H
#define MOVIES_H
class Node{
    public:
    Node();
    Node(string name, int rank) : movie_name(name) , rating(rank){
        left = right = parent = 0;
    }
    //accessors
    string getMovieName() const;
    int getRating() const;
    int getDepth() const; 
    Node* getLeft() const;
    Node* getRight() const;
    Node* getParent() const;
    //mutators 
    void setMovieName(string source);
    void setRating(int source);
    void setDepth(int source);

    private:
    string movie_name;
    int rating; 
    int depth; // number of nodes on the path from the root to the node containing the movie
    Node *left, *right, *parent; 

};

class BST{

public:
BST(); //constructor
//~BST();
//bool insert( Node &n); 
void printPreOrder() const;
Node * getRoot() const; 
void printPreOrder(Node *n) const;

private:

Node *root; 
};








#endif