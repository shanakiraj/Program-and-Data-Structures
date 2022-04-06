#include <iostream>
#include "puzzleNode.h"
#include <vector>
#include <string>


using namespace std;


puzzleNode::puzzleNode(string total){
  board = total;
  distance = 0;
  
}

puzzleNode::puzzleNode(){
  
}

string puzzleNode::getBoard(){
  return board;
}
int  puzzleNode::getDistance(){
  return distance;
}



