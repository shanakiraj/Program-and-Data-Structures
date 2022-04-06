#include <iostream>
#include "stack.h"
using namespace std;

stack::stack(){
  List myList;
}

void stack::push(int a){
  mylist.insertAtTail(a);
}

int stack::top(){
  return mylist.last().current->value;
}

void stack::pop(){
  mylist.removeTop();
}

bool stack::empty(){
 return  mylist.isEmpty();
}


