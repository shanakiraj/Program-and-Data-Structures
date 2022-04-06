#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <unordered_map>

using namespace std;

#include "middleearth.h"


unordered_map<string, vector<string>> alg;

float computeDistance(MiddleEarth& me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);

string findStart(vector<string> thing);

int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);
    vector<string> holder;
    vector<string> extra;
    string startingpoint;

    startingpoint = findStart(dests);

    //cout << startingpoint << endl;

    dests.erase(dests.begin());
    
    sort(dests.begin(), dests.end());
    
    holder = dests;
    extra = holder;

    
    float smol = computeDistance(me, startingpoint, extra);
  
    do{
      float len = computeDistance(me, startingpoint, dests);
      if(len < smol) {
	smol = len;
	holder = dests;
      }
    }while(next_permutation(dests.begin(), dests.end()));
 
    
    cout << "Minimum path has distance " << smol << ": ";
    printRoute(startingpoint, holder);
    //cout << endl;
    // cout << "length " << smol << endl;
   
    return 0;
}

string findStart(vector<string> thing){
  return thing[0];
}


// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance(MiddleEarth& me, const string& start, vector<string> dests) {
    // TODO: YOUR CODE HERE
  float holder = 0;
  float anotherone = 0;
  anotherone = me.getDistance(dests[dests.size()-1], start);
  holder = me.getDistance(start, dests[0]);
  // cout << endl;
  //cout << "distance" << holder << endl;

  for(int i = 0; i< dests.size()-1; i++){
    holder += me.getDistance(dests[i], dests[i+1]);
    //cout << "distance" << me.getDistance(dests[i], dests[i+1]) << endl;
  }
  
  holder += anotherone;
  
  return holder;
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute(const string& start, const vector<string>& dests) {
    // TODO: YOUR CODE HERE

  cout << start << " -> ";
  for(int i = 0; i< dests.size(); i++){
    cout << dests[i] << " -> ";
  }
  cout << start<< endl;

  
}
