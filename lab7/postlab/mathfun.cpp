#include <iostream>
using namespace std;

extern "C" long product(long, long);
extern "C" long power (long, long);

int main(){
  
  long num1, num2, prod, pow;
  
  //first num
  cout<<"Enter integer 1: ";
  cin>>num1;

  //second num
  cout<< "Enter integer 2: ";
  cin>>num2;

  prod = product(num1, num2);
  cout << "Product: "<< prod<<endl;

  pow = power(num1, num2);
  cout << "Power: "<< pow<<endl;
  
  
}
