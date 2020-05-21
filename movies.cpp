//Archana Neupane and Maya Ha
#include <iostream>
#include <string>
using namespace std; 
#include "movies.h"

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

bool BST :: insert(string name_source, int rating_source){
    Node * tmp = root; 
    int count = 0;
    if(root==NULL){
        root = new Node;
        root->setMovieName(name_source);
        root->setRating(rating_source);
        return true;
    }
    while(name_source < tmp -> getMovieName()){
        if()
        tmp = tmp -> getLeft();
            }
        
        }
    

    }


}


void BST :: search(Node *n, string argv[3]){
    
}
//Node Functions
//DEFAULT CONSTRUCTOR
Node::Node(){
    movie_name = "";
    rating = 0;
    depth = 0;
    left = right = parent = 0;
}

string Node :: getMovieName() const{
    return movie_name;
}

void Node:: setMovieName(string source){
    movie_name = source;
}
int Node :: getRating() const{
    return rating;
}

void Node:: setRating(int source){
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

Node* Node :: getRight() const{
        return right;
}

Node* Node :: getParent() const{
    return parent;
}

/*bool Node :: operator<(const Node& n1){
    return (this->getMovieName()<n1.getMovieName());
}*/
/*bool operator<(const Node& n1, const Node& n2){
    return n1.getMovieName()<n2.getMovieName();
}*/
