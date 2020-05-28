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
    root = nullptr; 
} 

/*Node::~Node(){
    if(left){
        delete left;
    }
    if(right){
        delete right;
    }
}*/

void BST::destroy(Node* n){
    if(n){
        destroy(n->getLeft());
        destroy(n->getRight());
        delete n;
    }
}

BST::~BST() {  
    destroy(root);
 }

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
    if(name_source == tmp -> getMovieName()){
        return false; 
    }

    if(name_source < tmp -> getMovieName()){
        if(tmp -> getLeft()){
            return insert(name_source, rating_source, tmp->getLeft(), level+1);
        }
        else{
            tmp->setLeft(new Node("", 0, level+1));
            counter++;
            node_level= level +1;
            tmp->getLeft()->setMovieName(name_source);
            tmp->getLeft()->setRating(rating_source);
            tmp->getLeft()->setParent(tmp);
            return true;
        }
    }
    else{ 
        if(tmp -> getRight()){
            return insert(name_source, rating_source, tmp ->getRight(), level+1);
        }
        else{
        tmp->setRight(new Node("", 0 , level+1));
        counter++;
        node_level = level +1;
        tmp->getRight()->setMovieName(name_source);
        tmp->getRight()->setRating(rating_source);
        tmp->getRight()->setParent(tmp);
        return true;
        }
            
    }
}

BST* BST :: searchPrefix(string prefix, Node *n){
    BST* newTree = new BST; 
    if (!n){
        return NULL;
    }
    searchPrefixHelper(prefix,newTree, n);
    return newTree;
} 

void BST :: searchPrefixHelper(string prefix, BST* newTree, Node* n){ //change type to BST*
    if(n){
        if(n->getMovieName().substr(0, prefix.size()) == prefix){
            newTree->insert(n->getMovieName(), n->getRating());
            searchPrefixHelper(prefix, newTree, n->getLeft());
            searchPrefixHelper(prefix, newTree, n->getRight()); 
        }
        if(n->getMovieName().substr(0, prefix.size()) < prefix){
            return searchPrefixHelper(prefix,newTree, n->getRight());
        }
        else{
            return searchPrefixHelper(prefix, newTree, n->getLeft());
        } 
    }   
        
}

Node* BST :: highestRating(BST* n){
    if(!n->getRoot()){
        return NULL;
    } 
    Node* tmp2 = highestRatingHelper(n->getRoot());
    Node* p = new Node(tmp2->getMovieName(), tmp2->getRating(), tmp2->getDepth());
    delete n;
    return p;
}

Node* BST :: highestRatingHelper(Node* n){
    Node* tmp = n;
    if(n==NULL){
        return 0;
    }
    if(n->getLeft()){
       Node* maxLeft = highestRatingHelper(n->getLeft());
        if(tmp ->getRating() < maxLeft->getRating()){
            tmp = maxLeft;
        }
    }
    if(n->getRight()){
        Node* maxRight = highestRatingHelper(n->getRight());
        if(tmp -> getRating() < maxRight-> getRating()){
            tmp = maxRight; 
        } 
    }
    return tmp;  
}

Node* BST :: search(string name, Node* n){
    Node* tmp = n;
    while(tmp){
        if(name ==  tmp->getMovieName()){
            return tmp;
        }
        if(name < tmp->getMovieName()){
            search(name, tmp->getLeft());
        }
        else{
            search(name, tmp-> getRight());
        }
    }
    return tmp;
}


