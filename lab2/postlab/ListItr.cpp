//ListItr.cpp
/*
Shan Akiraj
sra9qsw
09/6/21
*/

#include "List.h"
#include "ListNode.h"

ListItr::ListItr(){
}
ListItr::ListItr(ListNode* theNode){
  current = theNode;
}
bool ListItr::isPastEnd() const{
  if(!(current-> next)){
    return true;
  }else{
    return false;
  }
    
}
bool ListItr::isPastBeginning() const{
  if(!(current->previous)){
    return true;
  }else{
    return false;
}
}
void ListItr::moveForward(){
  if(current -> next){
    current = current -> next;
  }
  
}
void ListItr::moveBackward(){
  if(current -> previous){
  current = current -> previous;
  }
}
int ListItr::retrieve() const{
  return current->value;
}
