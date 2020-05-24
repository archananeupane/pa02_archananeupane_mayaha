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
    node_level = 0;
    if(root == NULL){
        root = new Node;
        root->setMovieName(name_source);
        root->setRating(rating_source);
        root->setDepth(0);
        counter = 1;
        return true;
    }
    return insert(name_source,rating_source, root, 0);
}

bool BST :: insert(string name_source, double rating_source, Node *tmp, int level){
    //static int depthleft = 0;
    //static int depthright = 0;
    if(name_source == tmp -> getMovieName()){
        return false; 
    }

    if(name_source < tmp -> getMovieName()){
        if(tmp -> getLeft()){
            //depthleft++;
            return insert(name_source, rating_source, tmp->getLeft(), level+1);
        }
        else{
            tmp->setLeft(new Node("", 0, level+1));
            counter++;
            node_level= level +1;
            tmp->getLeft()->setMovieName(name_source);
            tmp->getLeft()->setRating(rating_source);
            //tmp->setDepth(depthleft);
            tmp->getLeft()->setParent(tmp);
            return true;
        }
    }
    else{ 
        if(tmp -> getRight()){
           // depthright++;
            return insert(name_source, rating_source, tmp ->getRight(), level+1);
        }
        else{
        tmp->setRight(new Node("", 0 , level+1));
        counter++;
        node_level = level +1;
        tmp->getRight()->setMovieName(name_source);
        tmp->getRight()->setRating(rating_source);
        //tmp->setDepth(depthright);
        tmp->getRight()->setParent(tmp);
        return true;
        }
            
    }
}

Node* BST :: searchPrefix(string prefix, Node *n){
    BST* newTree = new BST; 
    if (!n){
        return NULL;
    }
    return searchPrefixHelper(prefix,newTree, n);
} 

Node* BST :: searchPrefixHelper(string prefix, BST* newTree, Node* n){
    if(n){
        if(n->getMovieName().substr(0, prefix.size()) == prefix){
            newTree->insert(n->getMovieName(), n->getRating());
        }
        if(n->getMovieName().substr(0, prefix.size()) < prefix){
            return searchPrefix(prefix, n->getRight());
        }
        else{
            return searchPrefix(prefix, n->getLeft());
        }
    }
        return newTree->getRoot();
}

Node* BST :: highestRating(Node* n){
    Node* tmp = root;
    if(!n){
        return NULL;
    }
    return highestRatingHelper(n);
}

Node* BST :: highestRatingHelper(Node* n){
    Node* tmp = root;
    if(n->getRating() == tmp -> getRating()) {
        return n;
    }
    else{
    if(n->getLeft()){
        Node* max = highestRatingHelper(n->getLeft());
        if(tmp ->getRating() < max->getRating()){
            tmp = max;
        }
    }
    if(n->getRight()){
        Node* max = highestRatingHelper(n->getRight());
        if(tmp -> getRating() > max-> getRating()){
            tmp = max; 
        }
    }
    return tmp; 
    }
}

