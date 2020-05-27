//Archana Neupane and Maya Ha
#ifndef TESTS_H
#define TESTS_H
#include <iostream>
using namespace std; 

void runAll();
void test_insert();
void test_member_functions();
void test_accessors_mutators();

void test_insert_empty_list();
//void test_insert_single_node();


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







#endif