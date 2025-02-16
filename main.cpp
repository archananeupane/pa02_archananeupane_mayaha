//Archana Neupane and Maya Ha
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstdlib>
#include "time.h"
#include <iomanip>
#include <cstring>
#include <algorithm>
#include "movies.h"

using namespace std;

bool parseLine(string &line, string &movieName, double &movieRating);
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
  ofstream out;
  out.open("out.csv");
  out<<"N"<<"," << "N_visited" <<endl;
  BST tree; 
  vector <string> movieNames;
  vector <double> runTimes;

  while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
    tree.insert(movieName, movieRating); 
    movieNames.push_back(movieName);
    out<<tree.counter<<","<<tree.node_level<<endl;
  }
  out.close();
  movieFile.close();
  if (flag == true){
   tree.printPreOrder();
  Node* tmp = tree.highestRating(tree.searchPrefix(argv[3], tree.getRoot()));
   cout<< endl << "Best movie is " << tmp ->getMovieName() <<" with rating " << tmp->getRating() <<endl;
   delete tmp;
  }
  else{
    clock_t t, p;
    t = clock(); 
    for(int i = 0; i < atoi(argv[3]); i++){
      for(int j = 0; j <movieNames.size(); j++){
        tree.search(movieNames[j], tree.getRoot());
      }
      p = clock();
      double time_taken = (double(p - t)*1000000)/ double(CLOCKS_PER_SEC);
      runTimes.push_back(time_taken);
     }
    cout<< "Minimum time is " << *min_element(runTimes.begin(),runTimes.end()) <<endl;
    cout<< "Maximum time is " << *max_element(runTimes.begin(), runTimes.end()) <<endl;
    sort(runTimes.begin(), runTimes.end());
    cout<< "Median time is " << runTimes[atoi(argv[3])/2] <<endl;
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

