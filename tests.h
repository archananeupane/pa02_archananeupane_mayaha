//Archana Neupane and Maya Ha
#ifndef TESTS_H
#define TESTS_H
#include <iostream>
#include "movies.h"
using namespace std; 

void runAll();
void test_insert();
void test_member_functions();
void test_accessors_mutators();

void test_insert_empty_BST();
void test_insert_single_node();
void test_node_construtor();
void test_BST_constructor();
void test_search_prefix();
void test_search();
void test_highest_rating();
void test_print_preorder();
void test_get_root();
void test_get_parent();
void test_set_parent();
void test_get_movie_name();
void test_set_movie_name();
void test_get_rating();
void test_set_rating();
void test_get_left();
void test_set_left();
void test_get_right();
void test_set_right();

void START_TEST(string testname){
  cout<<"Start "<<testname<<endl;
}

void END_TEST(string testname) {
  cout<<"End "<<testname<<endl<<endl;
}

void assertEquals(string expected, string actual, string testDescription){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}

void assertEquals(int expected, int actual, string testDescription){
    if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}

void assertEquals(Node* expected, Node* actual, string testDescription){
    if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}

void assertEquals(string expected1, string expected2, string expected3, string actual1, string actual2, string actual3,
 string testDescription){
  if ((expected1 == actual1)&&(expected2 == actual2) && (expected3 == actual3)) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected1 << expected2 << expected3<< 
     " Actual: " << actual1 << actual2 << actual3 << endl;
  }
}

void assertEquals(double expected, double actual, string testDescription){
    if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}


#endif