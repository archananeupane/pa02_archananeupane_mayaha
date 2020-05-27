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
    test_insert_empty_list();
    //test_insert_single_node();
    END_TEST("test_insert");
}

void test_member_functions(){
        START_TEST("test_member_functions");
        //functions
        END_TEST("test_member_functions");
}

void test_accessors_mutators(){
    START_TEST("test_accessors_mutators");
    //functions
    END_TEST("test_accessors_mutators");
}


void test_insert_empty_list(){
    string testname = "append node Lion King with rating 8.5";
    BST b1;
    b1.insert("Lion King", 8.5);
    assertEquals("Lion King", b1.getRoot()->getMovieName(), testname);
}