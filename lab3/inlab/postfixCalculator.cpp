//postfixCalculator.cpp
/*
Shan Akiraj
sra9qsw
09/14/21
*/


#include <iostream>
#include "postfixCalculator.h"
//#include <vector>
#include <stack>
using namespace std;

postfixCalculator::postfixCalculator(){

}

postfixCalculator::~postfixCalculator(){
  //calculator.clear();
}

void postfixCalculator:: add(){
  int holder = calculator.top();
  calculator.pop();
  holder += calculator.top();
  calculator.pop();
  calculator.push(holder);
}

void postfixCalculator:: subtract(){
  int holder = calculator.top();
  calculator.pop();
  int holder2 = calculator.top();
  calculator.pop();
  
  calculator.push(holder2-holder);
}
void postfixCalculator:: negate(){
  int holder = calculator.top();
  calculator.pop();
  holder = -holder;
  calculator.push(holder);
}
void postfixCalculator:: divide(){
  int holder = calculator.top();
  calculator.pop();
  int holder2 = calculator.top();
  calculator.pop();
  calculator.push(holder2/holder);
}
void postfixCalculator:: multiply(){
  int holder = calculator.top();
  calculator.pop();
  holder *= calculator.top();
  calculator.pop();
  calculator.push(holder);
}




/*
postfixCalculator& operator=(const postfixCalculator& calc){
  if(this == &calc){
    return *this;
  }else{
    calculator.erase();
    
}*/

/*
void  postfixCalculator::push (int e){
  //calculator.push_back(e);
}
int postfixCalculator::top(){
  //return calculator.back();

}
void postfixCalculator:: pop(){
  //calculator.pop_back();
 
}
bool postfixCalculator:: empty(){
  //return calculator.empty();

}
int postfixCalculator:: size(){
  //return calculator.size();
}
*/
/*
int postfixCalculator:: add(postfixCalculator x){
  int math = x.top();
  x.pop();
  math += x.top();
  x.pop();
  x.push(math);
  }*/

//void postfixCalculator:: subtract(){
//}


