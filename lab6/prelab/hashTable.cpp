#include <iostream>
#include "hashTable.h"
#include <iterator>
using namespace std;


hashTable::hashTable(int x){
  
  myTable.resize(x);

}


void hashTable::insert(string key){
  //int holder = hashFunction(key);
  if(key.length() < 3){
    return;
  }
  myTable[hashFunction(key)].push_back(key);
}

bool hashTable::find(string key){
  int holder = hashFunction(key);

  list<string>::iterator i = myTable[hashFunction(key)].begin();
  
  while(*i !=key && i!=myTable[holder].end()){
    i++;
  }
  if(*i == key){
    return true;
  }
  else{
    return false;
  }
  
}
  
int hashTable::hashFunction(string x){
  int temp = 0;
  for(int i = 0; i< x.length(); i++){
    temp += ((int)x[i]);
  }
  return temp % 10000;
}
