#include <iostream>
#include "hashTable.h"
#include <fstream>
//#include <unordered_set>

using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

// Forward declarations
bool readInGrid(string filename, int& rows, int& cols);
string getWordInGrid(int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);

/** The main() function shows how to call both the readInGrid()
 * function as well as the getWordInGrid() function.
 */




string printfile(string filename, hashTable *table){
  
  int numlines;
  string data;

  ifstream file(filename);

  if(!file.is_open()){
    return "file isn't open";
  }
  
  //supposed to find the number of lines in the file and store them in numlines
   if(file.is_open()){
    while(getline(file, data)){
      numlines++;
    }
   }
   
  file.clear();
  file.seekg(0);

  int x = numlines;

  //loops until numlines is 0
  // numlines--;

  while(x>0){
  string data1;
  file >> data1;
  table->insert(data1);
  //cout << data1 << endl;
  x--;
  }
  
  file.close();
  return "";  
}

string dir(int dir){
  if(dir == 0){
    return "N";
  }
  if(dir == 1){
    return "NE";
  }
  if(dir == 2){
    return "E";
  }
  if(dir == 3){
    return "SE";
  }
  if(dir == 4){
    return "S";
  }
  if(dir == 5){
    return "SW";
  }
  if(dir == 6){
    return "W";
  }
  if(dir == 7){
    return "NW";
  }
  return "";
}



void getWords(string filename, hashTable *table){
  int count=0;
  
  int rows;
  int cols;
  string thing;
    
  for(int a = 0; a < rows; a++){

    for(int b = 0; b < cols; b++){

      for(int c = 0; c <= 7; c++){

	for(int d = 3; d < 22; d++){
	  
	  string holder;
	  
	  holder = getWordInGrid(a, b, c, d, rows, cols);
	  
	  if(table->find(holder) && thing != holder){
	    if(holder.length() == d){
	      
	      thing = holder;
	      count++;
	      cout << dir(c) << " (" << a << ", " << b << "):    " << holder<<  endl;
	    }
	    }
 
	}
      }
    }
  }
}




int main(int argc, char *argv[]){

  if(argc != 3){
    cout << "need 2 parameters" << endl;
    exit(1);
  }

  
  hashTable *dictionary = new hashTable(10000);

  
  //printfile(argv[1], dictionary);
  
  int numlines = 0;
  string data;

  ifstream file(argv[1]);

  if(!file.is_open()){
    cout << "file isn't open";
  }
  
  //supposed to find the number of lines in the file and store them in numlines
   if(file.is_open()){
    while(getline(file, data)){
      numlines++;
    }
   }
   
  file.clear();
  file.seekg(0);

  int x = numlines;

  //loops until numlines is 0
  // numlines--;

  while(x>0){
  string data1;
  file >> data1;
  dictionary->insert(data1);
  //cout << data1 << endl;
  x--;
  }
  file.close(); 

   // to hold the number of rows and cols in the input file
  int rows= 0;
  int cols = 0;

    // attempt to read in the file

   string holder1 = argv[2];
   bool result = readInGrid(holder1, rows, cols);
    // if there is an error, report it
   if (!result) {
        cout << "Error reading in file!" << endl;
        return 1;
    }


  
  //getWords(argv[2], dictionary);
   
  int count=0;
  string thing;
  
  for(int a = 0; a < rows; a++){

    for(int b = 0; b < cols; b++){

      for(int c = 0; c <= 7; c++){

	for(int d = 3; d < 22; d++){
	  
	  string holder;
	  
	  holder = getWordInGrid(a, b, c, d, rows, cols);

	  if(dictionary->find(holder) && thing != holder)
	    
	    {
	      thing = holder;
	      count++;
	      cout << dir(c) << " (" << a << ", " << b << "):    " << holder<<  endl;
	    }
 
	}
      }
    }
  }
  cout << count << " words found" << endl;
 
  return 0;

}

bool readInGrid(string filename, int& rows, int& cols) {
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }

    // first comes the number of rows
    file >> rows;
    //cout << "There are " << rows << " rows." << endl;

    // then the columns
    file >> cols;
    //cout << "There are " << cols << " cols." << endl;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
            //cout << grid[r][c];
        }
        //cout << endl;
    }
    return true;
}

string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }

    return output;
}
