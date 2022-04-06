#include "node.h"

node::node(){
  character = 0;
  frequency = 0;
  left = NULL;
  right = NULL;
}

node::node(char character, int frequency){
  this->character = character;
  this->frequency = frequency;
  left = NULL;
  right = NULL;
}
