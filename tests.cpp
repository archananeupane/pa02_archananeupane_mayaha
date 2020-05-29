//Archana Neupane and Maya Ha
#include <iostream>
using namespace std; 
#include "tests.h"
#include "movies.h"
#include <vector>

int main(){
runAll();
return 0;
}

void runAll(){
    test_insert();
    test_member_functions();
    test_accessors_mutators();
}

void test_insert(){
    START_TEST("test_insert");
    test_insert_empty_BST();
    test_insert_single_node();
    END_TEST("test_insert");
}

void test_member_functions(){
        START_TEST("test_member_functions");
        test_node_construtor();
        test_BST_constructor();
        test_search_prefix();
        test_search();
        test_highest_rating();
        test_print_preorder();
        END_TEST("test_member_functions");
}

void test_accessors_mutators(){
    START_TEST("test_accessors_mutators");
    //functions
    test_get_root();
    test_get_parent();
    test_set_parent();
    test_get_movie_name();
    test_set_movie_name();
    test_get_rating();
    test_set_rating();
    test_get_left();
    test_set_left();
    test_get_right();
    test_set_right();
    END_TEST("test_accessors_mutators");
}


void test_insert_empty_BST(){
    string testname = "append node Lion King with rating 8.5 to empty BST";
    BST b1;
    b1.insert("Lion King", 8.5);
    assertEquals("Lion King", b1.getRoot()->getMovieName(), testname);
}
void test_insert_single_node(){
    string testname = "append node to BST with a node already";
    int count =0; 
    BST b1;
    b1.insert("Parasite", 9.0);
    b1.insert("Titanic", 8.7);
    Node* tmp = b1.getRoot();
    while(tmp){
        count++;
        if(tmp->getLeft()){
        tmp = tmp->getLeft();
        }
        else{
        tmp = tmp->getRight();
        }
    }
    assertEquals(2, count, testname);
}

void test_node_construtor(){
    string testname= "check Node constructor";
    Node tmp;
    assertEquals(0.0, tmp.getRating(), testname);
}

void test_BST_constructor(){
    string testname = "check BST constructor";
    BST tmp;
    assertEquals(nullptr,tmp.getRoot(),testname);
}

void test_search_prefix(){
    string testname = "find movies with the same prefix";
    BST b1;
    b1.insert("Lion King", 8.7);
    b1.insert("Parasite", 9.0);
    b1.insert("Lazy Larry", 2.4);
    assertEquals("Parasite", b1.searchPrefix("Par", b1.getRoot())->getRoot()->getMovieName(), testname);
}

void test_search(){
    string testname = "returns pointer to node with wanted prefix";
    BST b1;
    b1.insert("Lion King", 8.7);
    b1.insert("Parasite", 9.0);
    b1.insert("Lazy Larry", 2.4);
    Node* tmp = b1.search("Lazy Larry", b1.getRoot());
    assertEquals("Lazy Larry", tmp -> getMovieName(), testname);
}
void test_highest_rating(){
    string testname = "returns node with highest rating movie of given prefix of BST";
    BST b1; 
    b1.insert("Lion King", 8.7);
    b1.insert("Parasite", 9.0);
    b1.insert("Lazy Larry", 2.4);
    Node* tmp = b1.highestRating(b1.searchPrefix("L", b1.getRoot()));
    assertEquals(8.7, tmp ->getRating(), testname);
}

void test_print_preorder(){
    string testname = "print out preorder of BST";
    BST b1;
    b1.insert("Lion King", 8.7);
    b1.insert("Parasite", 9.0);
    b1.insert("Lazy Larry", 2.4);
    assertEquals("Lion King","Lazy Larry","Parasite", b1.getRoot()->getMovieName(), b1.getRoot()->getLeft()->getMovieName(),
    b1.getRoot()->getRight()->getMovieName(), testname);
}

void test_get_root(){
    string testname = "check get root";
    BST b1;
    assertEquals(NULL, b1.getRoot(), testname);
}

void test_set_parent(){
    string testname= "check set parent";
    Node* n1 = new Node();
    n1->setMovieName("Lion King");
    Node n2;
    n2.setParent(n1);
    assertEquals(n1, n2.getParent(), testname);

}

void test_get_parent(){
    string testname = "check get parent";
    Node n1;
    assertEquals(0, n1.getParent(), testname);
}

void test_get_movie_name(){
    string testname = "check get movie name";
    Node n1;
    assertEquals("", n1.getMovieName(), testname);
}


void test_set_movie_name(){
    string testname = "check set movie name";
    Node n1;
    n1.setMovieName("Lion King");
    assertEquals("Lion King", n1.getMovieName(), testname);
}

void test_get_rating(){
    string testname = "check get rating";
    Node n1;
    assertEquals(0.0, n1.getRating(), testname);
}

void test_set_rating(){
    string testname = "check set rating";
    Node n1;
    n1.setRating(4.0);
    assertEquals(4.0, n1.getRating(), testname);
}

void test_get_left(){
    string testname = "check get left";
    Node n1;
    assertEquals(0, n1.getLeft(), testname);
}

void test_set_left(){
    string testname = "check set left";
    Node n1;
    Node* n2 = new Node;
    n2->setMovieName("Lion King");
    n1.setLeft(n2);
    assertEquals(n2, n1.getLeft(), testname);
}

void test_get_right(){
    string testname = "check get right";
    Node n1;
    assertEquals(0, n1.getRight(), testname);
}

void test_set_right(){
    string testname = "check set right";
    Node n1;
    Node* n2 = new Node;
    n2->setMovieName("Lion King");
    n1.setRight(n2);
    assertEquals(n2, n1.getRight(), testname);
}