#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H
//#include <vector>
#include <stack>
using namespace std;


class postfixCalculator{
  
 public:
  //default constructor
  postfixCalculator();
  
  //destructor
  ~postfixCalculator();

  //copy assignment operator
   postfixCalculator& operator=(const postfixCalculator& calc);

  //adds to top of stack
  // void push(int e);

  //returns element on top of stack
  //int top();

  //removes element on the top of stack
  // void pop();

  //tells whether or not elements are left in the stack
  // bool empty();

  //returns the number of elements
  // int size();
  
  //performs the addition operator
  void add();

  //performs the subtraction operator
  void subtract();
  
  stack<int> calculator;
};


#endif
