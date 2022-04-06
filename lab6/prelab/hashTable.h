#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <list>
#include <vector>

using namespace std;

class hashTable {

 public:

  int size;
  
  vector<list<string>> myTable;
  
  hashTable(int x);
  
  void insert(string key);

  bool find(string key);
  
  int hashFunction(string x);
  
};

#endif
