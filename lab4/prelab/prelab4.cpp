//prelab4.cpp
/*
Shan Akiraj
sra9qsw
09/20/21
*/
#include <iostream>
#include <stack>
using namespace std;


string sizeOfTest(){

  cout << "Size of int: " << sizeof(int) << endl;
  cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
  cout << "Size of float: " << sizeof(float) << endl;
  cout << "Size of double: " << sizeof(double) << endl;
  cout << "Size of char: " << sizeof(char) << endl;
  cout << "Size of bool: " << sizeof(bool) << endl;
  cout << "Size of int*: " << sizeof(int*) << endl;
  cout << "Size of char*: " << sizeof(char*) << endl;
  cout << "Size of double*: " << sizeof(double*) << endl;
  return "";
}

string overflow(){
  unsigned int obunga = 4294967295;
  cout << obunga << " + 1 = " << obunga+1 << endl;
  return "";
}

string outputBinary(unsigned int x){
  
  stack<int> binaryStack;
  
  while(x>0){
    binaryStack.push(x%2);
    x = x/2;
  }

  while(binaryStack.size() < 32){
    binaryStack.push(0);
  }
  
  for(int i = 1; i<34; i++){
    if(!binaryStack.empty()){
    cout << binaryStack.top();
    binaryStack.pop();
    }
     if(i != 0 && (i%4)==0){
      cout << " ";
    }
   
  }
  return "";

  
}

int main (){
  int x;
  cin >> x;
  cout << sizeOfTest();
  cout << overflow();
  cout << outputBinary(x) << endl;
  
}
