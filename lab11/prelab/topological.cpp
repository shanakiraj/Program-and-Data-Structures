// This program shows how C++-based file I/O works.
// It will open a file, read in the first two strings, and print them to the screen.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <array>
#include <algorithm>
#include <unordered_map>
#include <stack>

using namespace std;



vector<string> holder;
unordered_map<string, int> theMap; //puts all the the classes in a map and removes duplicates

unordered_map<string, vector<string>> m; //used to create the graph
unordered_map<string, int> three; //holds the indegree
vector<string> thing;

void topsort();


// we want to use parameters
int main(int argc, char** argv) {
 
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    // read in two strings
    string s1, s2;
    
    while(file >> s1 && file >> s2){
      
      if(!(s1 == "0")){
	 m[s1].push_back(s2);
      } 
    }
    //cout << m.size();
    
    //vector<string> bruh[];
    for(auto const& pair : m){
      //cout << pair.first;
      for(int i = 0; i< pair.second.size(); i++){
	//cout << " -> " <<  pair.second[i]; 
      }
      //cout << endl;
      }
    
     file.clear();
     file.seekg(0);

     
     auto t = m.begin();
     while(t != m.end()){
       three.insert(make_pair(t->first, 0));
       ++t;
     }
     
     for(auto const& pair : m){
       for(int i = 0; i < pair.second.size(); i++){
	     three[pair.second[i]]++; 
       }
     }

    string vertex;

     file.clear();
     file.seekg(0);
     
      //int count = 0;
      while(file >> vertex){
	  if(theMap.find(vertex) == theMap.end()){
	    //count++;
	    if(!(vertex == "0")){
	      
	    theMap.insert(make_pair(vertex, 1));
	    }
      }
	  //count = theMap.size();
      }
      // cout << count << endl;

    // close the file before exiting

      for(auto const& pair : three){
	//cout << pair.first << " " << pair.second << endl;
      }

    topsort();
    cout << endl;
    file.close();
}


void topsort() {
  stack<string> q;
  int counter = 0;
  string v, w;

  //q.makeEmpty(); // initialize the queue   
  for(auto const& pair : three){
      if(pair.second == 0){
	q.push(pair.first);
    }
  }
  while (!q.empty()) {
    v = q.top(); // get vertex of indegree 0
    //thing[++counter] = v;
    cout << v << " ";
    q.pop();

  for(auto it : m[v]){
    //cout << it << endl;
    three[it]--;
    if(three[it] == 0){
      q.push(it);
    }
  }
 
  }
  
}
  


