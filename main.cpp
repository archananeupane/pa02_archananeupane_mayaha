//Archana Neupane and Maya Ha
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>
#include "movies.h"

using namespace std;

bool parseLine(string &line, string &movieName, double &movieRating);
/*
bool operator<(const Node& n1, const Node& n2){
    return n1.getMovieName()<n2.getMovieName();
} */
int main(int argc, char** argv){
  if(argc < 4){
    cerr << "Usage: " << argv[ 0 ] << "arg1 arg2 arg3" << endl;
    exit(1);
  }

  bool flag = false;
  if(strcmp(argv[1], "true") == 0){
    flag = true;
  } else if(strcmp(argv[1], "false") == 0) {
    flag = false;
  } else {
    cerr << "Argument 1 must be a boolean (true/false)" << endl;
    exit(1);
  }
  
  ifstream movieFile (argv[2]);
  string line, movieName;
  double movieRating;

  if (movieFile.fail()){
    cerr << "Could not open file " << argv[2];
    exit(1);
  }

  // Create an objects of the BST class you defined 
  // to contain the name and rating in the input file

  // Read each file and store the name and rating
  BST tree; 
  while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
  tree.insert(movieName, movieRating); 
   //cout << movieName << " has rating " << movieRating << endl;
  }
  movieFile.close();
    
  if (flag == true){
   tree.printPreOrder();
   cout<< "Best movie is ";

  }
  return 0;
}

bool parseLine(string &line, string &movieName, double &movieRating) {
  if(line.length() <= 0) return false;
  string tempRating = "";

  bool flag = false;
  movieName = tempRating = "", movieRating = 0.0, flag = false;

  for (int i = 0; i < line.length(); i++){
    if(flag) tempRating += line[i];
    else if(line[i]==','&& line[0]!='"') flag = true;
    else {
      if(i==0 && line[0]=='"') continue;
      if(line[i]=='"'){ i++; flag=true; continue;}
      movieName += line[i];
    }
  }
  
  movieRating = stod(tempRating);
  return true;
}

