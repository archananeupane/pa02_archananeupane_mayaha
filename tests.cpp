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
        //test_highest_rating();
        test_print_preorder();
        END_TEST("test_member_functions");
}

void test_accessors_mutators(){
    START_TEST("test_accessors_mutators");
    //functions
    test_get_root();
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
    assertEquals(0, tmp.getRating(), testname);
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
    assertEquals("Parasite", b1.searchPrefix("Par", b1.getRoot())->getMovieName(), testname);
}

void test_print_preorder(){
    string testname = "print out preorder of BST";
    BST b1;
    b1.insert("Lion King", 8.7);
    b1.insert("Parasite", 9.0);
    b1.insert("Lazy Larry", 2.4);
    //assertEquals("Lazy Larry, 2.4, 1", b1.printPreOrder(), testname);
}

void test_get_root(){
    string testname = "check get root";
    BST b1;
    assertEquals(NULL, b1.getRoot(), testname);
}