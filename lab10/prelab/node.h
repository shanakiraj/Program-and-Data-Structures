
#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

class node {
public:
    node(); //default constructor
    node(char character, int frequency);         // Constructor
    char character;
    int frequency;  // frequency of the character
    node* left;     // left node pointer
    node* right;    // right node pointer
};

#endif
