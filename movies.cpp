//Archana Neupane and Maya Ha
#include <iostream>
#include <string>
using namespace std; 
#include "movies.h"
#include <cstring>
//Node Functions
//DEFAULT CONSTRUCTOR
Node :: Node(){
    movie_name = "";
    rating = 0.0;
    depth = 0;
    left = right = parent = 0;
}

string Node :: getMovieName() const{
    return movie_name;
}

void Node:: setMovieName(string source){
    movie_name = source;
}
double Node :: getRating() const{
    return rating;
}

void Node:: setRating(double source){
    rating = source;
}

int Node :: getDepth() const{
    return depth; 
}

void Node :: setDepth(int source){
    depth = source;
}

Node* Node :: getLeft() const{
    return left; 
}

void Node :: setLeft(Node *n){
    left = n;
}

Node* Node :: getRight() const{
        return right;
}

void Node :: setRight(Node* n){
    right = n;
}

Node* Node :: getParent() const{
    return parent;
}

void Node :: setParent(Node *n){
    parent = n; 
}
Node* Node :: newNode(Node*n){
n = new Node; 
return n;
}

/*bool Node :: operator<(const Node& n1){
    return (this->getMovieName()<n1.getMovieName());
}*/
/*bool operator<(const Node& n1, const Node& n2){
    return n1.getMovieName()<n2.getMovieName();
}*/

//BST Functions
BST::BST(){ //constructor
    root = NULL; 
} 

//BST :: ~BST () {   }

void BST :: printPreOrder() const{
    printPreOrder(getRoot());
}

void BST :: printPreOrder(Node *n) const{
    if(n){
        cout << n->getMovieName()<< ", " << n->getRating() << ", " << n->getDepth() << endl;
        printPreOrder(n->getLeft());
        printPreOrder(n->getRight());
    }
}

Node* BST :: getRoot() const{
return root; 
}

bool BST :: insert(string name_source, double rating_source){
    if(root == NULL){
        root = new Node;
        root->setMovieName(name_source);
        root->setRating(rating_source);
    }
    return insert(name_source,rating_source, root);
}

bool BST :: insert(string name_source, double rating_source, Node *tmp){
    static int depthleft = 0;
    static int depthright = 0;
    if(name_source == tmp -> getMovieName()){
        return false; 
    }

    if(name_source < tmp -> getMovieName()){
        if(tmp -> getLeft()){
            depthleft++;
            return insert(name_source, rating_source, tmp->getLeft());
        }
        else{
            /*tmp = tmp->newNode(tmp->getLeft()); //doesnt work
            tmp -> setMovieName(name_source);
            tmp->setRating(rating_source);
            tmp -> setParent(tmp -> getLeft());*/
            tmp->setLeft(new Node());
            tmp->getLeft()->setMovieName(name_source);
            tmp->getLeft()->setRating(rating_source);
            tmp->setDepth(depthleft);
            tmp->getLeft()->setParent(tmp);
            return true;
        }
    }
    else{ 
        if(tmp -> getRight()){
            depthright++;
            return insert(name_source, rating_source, tmp ->getRight());
        }
        else{
        /*tmp = tmp->newNode(tmp->getRight());
        tmp -> setMovieName(name_source);
        tmp->setRating(rating_source);
        tmp->setParent(tmp -> getRight());*/
        tmp->setRight(new Node());
        tmp->getRight()->setMovieName(name_source);
        tmp->getRight()->setRating(rating_source);
        tmp->setDepth(depthright);
        tmp->getRight()->setParent(tmp);
        return true;
        }
            
    }
}
/*
bool BST :: insert(string name_source, double rating_source){
    Node *tmp = root; 
    int count = 0;
    
    if(root == NULL){
        root = new Node;
        root->setMovieName(name_source);
        root->setRating(rating_source);
    } 
   
    else{ 
    while(tmp != NULL){    
    if (name_source == tmp->getMovieName()){
       return false; 
    } 

    if(name_source < tmp -> getMovieName()){
        tmp = tmp -> getLeft();
        tmp = new Node;
        tmp -> setMovieName(name_source);
        tmp->setRating(rating_source); 
        }
        else{
            tmp = tmp ->getRight();
            tmp = new Node;
            tmp -> setMovieName(name_source);
            tmp->setRating(rating_source);
        }
    }
    }
    return true; 
}
*/
    


//void BST :: search(Node *n, string argv[3]){}
