//stack.h
/*
Shan Akiraj
sra9qsw
09/15/21
*/

#ifndef STACK_H
#define STACK_H
#include "List.h"


class stack{
 public:
  stack();

 //adds to top of stack
  void push(int e);

  //returns element on top of stack
  int top();

  //removes element on the top of stack
  void pop();

  //tells whether or not elements are left in the stack
  bool empty();

  //returns the number of elements
  int size();

  List mylist;
  
};
#endif
