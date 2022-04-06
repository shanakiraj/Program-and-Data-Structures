// This program shows how C++-based file I/O works.
// It will print a file to the screen two times.

// included so we can use cout
#include <iostream>
// file I/O
#include <fstream>
// cstdlib is where exit() lives
#include <cstdlib>
#include <vector>
#include <unordered_map>
#include "node.h"
#include "heap.h"


using namespace std;

void code(node* root, string c);
void printIt();

vector<node> minheap;
unordered_map<char, int> thing;
unordered_map<char, string> anotherThing;

int sum = 0;
binary_heap* heap = new binary_heap();



// we want to use parameters
int main(int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // ifstream stands for "input file stream"
    ifstream file(argv[1]);
    // if the file wasn't found, output an error message and exit
    if (!file.is_open()) {
        cout << "Unable to open '" << argv[1] << "' for reading" << endl;
        exit(2);
    }

    // read in characters one by one, until reading fails (we hit the end of the file)
    char g;
    
    while (file.get(g)) {   
      if(g != '\n'){  //newlines are not included as characters
	
      //got the idea for this from https://tinyurl.com/m8adef8x
      if (thing.find(g) == thing.end()){ //if not found then insert into map with frequency of 1
	  thing.insert(make_pair(g, 1));
	}
	//if already in the map increase frequency of the character by 1
	else{
	  thing[g]++;
	}
      }
	
    }
    //from stl unordered set
    for(auto const& pair  : thing) {
      node* huffman = new node(pair.first, pair.second);
      heap->insert(huffman);
    }
    //thing->print();
    
    
    while(heap->size() > 1){
      node* n = heap->deleteMin();
      node* n2 = heap->deleteMin();
      node* dummy = new node();
      dummy->left = n2;
      dummy->right = n;
      dummy->frequency = ((n2->frequency)+(n->frequency));
      //cout<< dummy->frequency<< endl;
      heap->insert(dummy);
    }
    
    
    //heap->print();
    code(heap->findMin(), "");
    cout << "----------------------------------------" << endl;
    
    file.clear(); // Clears the _state_ of the file, not its contents!
    file.seekg(0);
    
    //char f;
    //int sum = 0;
    while (file.get(g)) {
	  cout << anotherThing[g] << " ";
	  sum += anotherThing[g].length();
    }
     cout << endl;


    // a nice pretty separator
    cout << "----------------------------------------" << endl;
    printIt();

    return 0;
}

void code(node* root, string c){
  string right = "1";
  string left = "0";
  
  if(root != NULL){
  if(root->left == NULL && root->right == NULL){
    if(root->character == ' '){
      anotherThing.insert(make_pair(root->character, c));
      cout << "space " << c << endl; 
    }else{
      anotherThing.insert(make_pair(root->character, c));
    cout << root->character<< " " <<  c <<endl;
    }
  }
  else{
       code(root->right, c + right);
       code(root->left, c + left);
  }
  }else{
    return;
  }
}

void printIt(){
    cout << "There are a total of " << heap->findMin()->frequency << " symbols that are encoded." <<endl;
    cout << "There are " << thing.size()  << " distinct symbols used." << endl;
    cout << "There were " << (heap->findMin()->frequency)*8 << " bits in the original file." << endl;
    cout << "There were " << sum << " in the compressed file." << endl;
    cout << "This gives a compression ratio of " << (double)((heap->findMin()->frequency)*8)/(double)(sum) << "." << endl;
    cout << "The cost of the Huffman tree is " << (double)(sum)/(double)(heap->findMin()->frequency) << " bits per character." << endl;
  

}

