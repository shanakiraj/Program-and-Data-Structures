//postfixCalculator.h
/*
Shan Akiraj
sra9qsw
09/14/21
*/

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include "stack.h"
using namespace std;


class postfixCalculator{
  
 public:
  //default constructor
  postfixCalculator();
  
  //destructor
  ~postfixCalculator();

  //copy assignment operator
   postfixCalculator& operator=(const postfixCalculator& calc);

 
  
  //performs the addition operator
  void add();

  //performs the subtraction operator
  void subtract();
  
  //performs negation
  void negate();
  //performs division
  void divide();
  //performs multiplication
  void multiply();
  
  stack calculator;
  
};


#endif
