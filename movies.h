//Archana Neupane and Maya Ha
#include <string>
#include <cstring>
using namespace std; 
#ifndef MOVIES_H
#define MOVIES_H
class Node{
    public:
    Node();
    Node(string name, double rank) : movie_name(name) , rating(rank){
    left = right = parent = 0;}
    //accessors
    string getMovieName() const;
    double getRating() const;
    int getDepth() const; 
    Node* getLeft() const;
    Node* getRight() const;
    Node* getParent() const;
    //mutators 
    void setMovieName(string source);
    void setRating(double source);
    void setDepth(int source);
    void setParent(Node* n);
    void setRight(Node* n);
    void setLeft(Node *n);
    Node* newNode(Node *n);


    private:
    string movie_name;
    double rating; 
    int depth; // number of nodes on the path from the root to the node containing the movie
    Node *left, *right, *parent; 

};

class BST{

public:
BST(); //constructor
//~BST();
bool insert(string name_source, double rating_source);
void search(Node *n,string argv[3]); 
void printPreOrder() const;
Node * getRoot() const; 


private:
void printPreOrder(Node *n) const;
bool insert(string name_source, double rating_source, Node *tmp);
Node *root; 
};


#endif