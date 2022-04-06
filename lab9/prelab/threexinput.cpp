//c++ run file

#include <iostream>
#include <string>
#include "timer.h"

using namespace std;
extern "C" long threexplusone(long num);


int main(){
  long num;
  long iter;
  long output;
  timer findTime;

  cout<< "Enter a number: ";
  cin >> num;
  cout<< "Enter iterations of subroutine: ";
  cin >> iter;

  findTime.start();
  for(long i = 0; i < iter; i++){
  output = threexplusone(num);
  }
  findTime.stop();
  
  cout << "time: " << findTime.getTime()*1000/iter << endl;
  cout << "Steps: " << output << endl;

  

 
  return 0;
  
}
