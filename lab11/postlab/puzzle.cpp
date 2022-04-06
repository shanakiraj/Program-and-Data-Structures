#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <iostream>
#include "puzzleNode.cpp"
#include <queue>

using namespace std;

vector<puzzleNode*> generateNeighbor(puzzleNode* p);

string total;
string finalform = "123456780";
bool found =false;
bool visited = false;
unordered_map<string,vector<puzzleNode*>> everyPuzzle;
unordered_map<string, int> mapdistance;

vector<string> distance1;
vector<int> intdistance;
int holdDistance = 999;
int y;

/**
 *@author Shan
 *@see thing
 */
int main(){
  
  string a, b, c, d, e, f, g, h, i;
  
  
  cout << "Enter Puzzle" << endl;
  
  cin >> a; cin >> b; cin >> c; cin >> d; cin >> e;
  cin >> f; cin >> g; cin >> h; cin >> i;

  total = a+b+c+d+e+f+g+h+i;


  puzzleNode *p = new puzzleNode(total);
  p->distance = 9999;
  everyPuzzle.insert(make_pair(p->getBoard(), generateNeighbor(p)));
  
  //generateNeighbor(p);
  
  string s = p->getBoard();
  sort(s.begin(), s.end());
  while(next_permutation(s.begin(), s.end())){
    
    puzzleNode* p1 = new puzzleNode(s);
    p1->distance = 9999;
    mapdistance.insert(make_pair(p1->getBoard(), 9999));
    everyPuzzle.insert(make_pair(p1->getBoard(), generateNeighbor(p1)));
    }	  
  
  queue<string> q;
  string v, w;
  q.push(p->getBoard());
  mapdistance[p->getBoard()] = 0;

  while (!q.empty()) {
    //cout << "hello" << endl;
    v = q.front();
    q.pop();
    if(v == finalform){
      cout << mapdistance[v] << endl;
      break;
    }
    
    for(int i =0; i< everyPuzzle[v].size(); i++){
      
      if(mapdistance[everyPuzzle[v][i]->getBoard()] == 9999) {
        mapdistance[everyPuzzle[v][i]->getBoard()] = mapdistance[v] + 1;
        q.push(everyPuzzle[v][i]->getBoard()); 
      }
    }
    //cout << "IMPOSSIBLE" << endl;
    }
  if(v != finalform){
  cout << "IMPOSSIBLE" << endl;
  }
  
  return 0;
}

vector<puzzleNode*> generateNeighbor(puzzleNode* p){
  vector<puzzleNode*> neighbors;
  string holder;
  string tempholder;
  char swap;
  int x;
  
  tempholder = p->getBoard();
  
  for(int i = 0; i< 9; i++){
    if(tempholder[i] == '0'){
      x = i;
    }
  }
  
  if(x > 2){
    //swapUp
    holder = tempholder;
    swap = holder[x];
    holder[x] = holder[x-3];
    holder[x-3] = swap;
    puzzleNode * p1 = new puzzleNode(holder);
    neighbors.push_back(p1);
 
  }
  if(x < 6){
    //swapdown
    holder = tempholder;
    swap = holder[x];
    holder[x] = holder[x+3];
    holder[x+3] = swap;
    puzzleNode * p1 = new puzzleNode(holder);
    neighbors.push_back(p1);
  }
  if(x>0 && x<3 || x>3 && x< 6 || x> 6){
    //swapleft
    holder = tempholder;
    swap = holder[x];
    holder[x] = holder[x-1];
    holder[x-1] = swap;
    puzzleNode * p1 = new puzzleNode(holder);
    neighbors.push_back(p1);
  }
  if(x < 2 || x>2 && x<5 || x > 5 && x< 8){
    //swapright
    holder = tempholder;
    swap = holder[x];
    holder[x] = holder[x+1];
    holder[x+1] = swap;
    puzzleNode * p1 = new puzzleNode(holder);
    neighbors.push_back(p1);
  }

  return neighbors;
 
  }

 








