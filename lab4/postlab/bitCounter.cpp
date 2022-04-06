#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

int counter(int n){
  if(n == 0){
    return 0;
  }
  if(n%2 == 0){
    return counter(n/2);
  }
  else{
    return 1+counter(n/2);
  }
}

int convertLetter(char x){
  if(x>='0' && x<= '9'){;
    int converter = x-48;
    return converter;
  }else{
    int converter = x-55;
    return converter;
  }
}

int convertToChar(int x){

  char temp = x+55;
  return temp;
}

int power(int x, int startBase, int pwr){
  return  x*(pow(startBase, pwr));
}

string power2(int x, int endBase){
  string temp = "";
  while(x>0){
    if(x%endBase > 9){
      temp.insert(0, to_string(convertToChar(x%endBase)));
    }
    temp.insert(0, to_string(x%endBase));
    x=x/endBase;
  }
  return temp;
}



string converter(string number, int startBase, int endBase){
  int temp =0;
  int baseTen = 0;
  int pwr = 0;
  int remainder =0;
 
  for(int i =number.length()-1; i >= 0; i--){
    temp = convertLetter(number[i]);
    baseTen += power(temp, startBase, pwr);
    pwr++;
  }
  return power2(baseTen, endBase);

}

int main(int argc, char *argv[]){
  if(argc != 5){
    cout << "error: must have 4 parameters"<< endl;
    exit (-1);
  }
  
  cout << argv[1] << " has " << counter(stoi(argv[1])) << " bit(s) " << endl;
  cout << argv[2] << " (base " << argv[3] << ") = "<< converter(argv[2], stoi(argv[3]), stoi(argv[4]))<< " (base "<< argv[4]<< ")"<< endl;
  
}
