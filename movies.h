//Archana Neupane and Maya Ha
#include <string>
#include <cstring>
using namespace std; 
#ifndef MOVIES_H
#define MOVIES_H
class Node{
    public:
    Node();
    Node(string name, double rank, int level) : movie_name(name) , rating(rank), depth(level){
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

    private:
    string movie_name;
    double rating; 
    int depth; 
    Node *left, *right, *parent; 
};

class BST{

public:
BST(); //constructor
~BST();
bool insert(string name_source, double rating_source);
BST* searchPrefix(string prefix, Node *n);
Node* highestRating(BST* n) ;
void printPreOrder() const;
Node * getRoot() const; 
Node* search(string name, Node* n);
int node_level;
int counter;

private:
void printPreOrder(Node *n) const;
bool insert(string name_source, double rating_source, Node *tmp, int level);
void searchPrefixHelper(string prefix, BST* newTree, Node* n);
Node* highestRatingHelper(Node* n);
Node *root; 
void destroy(Node* n);
};

#endif