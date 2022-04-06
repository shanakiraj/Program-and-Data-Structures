#ifndef PUZZLENODE_H
#define PUZZLENODE_H
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class puzzleNode {
 public:
  puzzleNode(string total);
  puzzleNode();
  
  int getDistance();
  string getBoard();
  string board;
  int distance;
  
};

#endif
