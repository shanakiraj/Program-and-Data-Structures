#include "postfixCalculator.h"
//#include "postfixCalculator.cpp"
#include <string>
//#include <vector>
#include <stack>
#include <iostream>
using namespace std;

string token;
 bool isOperator(){
  if(token == "/")
    return true;
  else if(token == "+")
    return true;
  else if(token == "-")
    return true;
  else if(token == "*")
    return true;
  return false;
 }

int main () {
  int math = 0;
  postfixCalculator calc;
  //cout << "Enter your calculation" << endl;
  while(cin >> token){    
    if(!isOperator()){
      int holder = stoi(token);
      calc.calculator.push(holder);
    }
    else if(token == "+"){ 
      calc.add();
    }
    else if(token == "-"){
      calc.subtract();
    }
    }
  cout << calc.calculator.top() << endl;
  }

