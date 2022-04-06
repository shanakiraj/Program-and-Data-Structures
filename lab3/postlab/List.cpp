//List.cpp
/*
Shan Akiraj
sra9qsw
09/6/21
*/
#include "List.h"

List::List(){
  head = new ListNode();
  tail = new ListNode();
  head->next=tail;
  head->previous = NULL;
  tail-> next = NULL;
  tail-> previous = head;
  }

// Copy constructor
// Called when the code looks something like List list2 = list1;
// (In other words, it is called when you are trying to construct a **new** list from an existing one)
List::List(const List& source) {
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

// Copy assignment operator
// Called when the code looks something like list2 = list1;
// (In other words, it is called when you are trying to set an **existing** list equal to another one)
List& List::operator=(const List& source) {
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}
List::~List(){
  makeEmpty();
  delete head;
  delete tail;
}

void List::insertAtTail(int x){
  ListNode *temp = new ListNode();
  temp->value = x;
  temp->previous = tail->previous;
  temp->next = tail;
  tail->previous->next = temp;
  tail->previous = temp;
  count++;
}

ListItr List::first(){
  ListItr temp;
  temp.current = head->next;
  return temp;
}
int List::size()const{
  return count;
}

void printList(List& source, bool forward){
  ListItr temp;
  if(forward){
    temp = source.first();
    while(!(temp.isPastEnd())){
    cout << temp.retrieve() << " ";
    temp.moveForward();
    }
  }else{
      temp = source.last();
      while(!temp.isPastBeginning()){
	cout << temp.retrieve() << " ";
	temp.moveBackward();
      }
    }
}
    

bool List::isEmpty() const{
  if(count == 0){
    return true;
  }else{
    return false;
  }
  
}
void List::makeEmpty(){
  
  ListItr temp;
  temp.current = head->next;
 
  while(!temp.isPastEnd()){
    temp.moveForward();
    delete (temp.current-> previous);
    count--;
  }
  if(temp.current){
  temp.current = temp.current -> next;
  delete temp.current;
  }
  
  count = 0;
  head-> next = tail;
  head-> previous = NULL;
  tail->next = NULL;
  tail-> previous = head;
}

ListItr List::last(){
  ListItr temp;
  temp.current = tail->previous;
  return temp;
}

void List::insertAfter(int x, ListItr position){
  ListNode *temp = new ListNode();
  temp -> value = x;
  temp -> next = position.current ->next;
  position.current -> next = temp;
  temp->previous = position.current;
  position.current ->next -> previous = temp;
  count++;
  
}
void List::insertBefore(int x, ListItr position){
  ListNode *temp = new ListNode();
  temp -> value = x;
  temp -> next = position.current;
  position.current-> previous = temp;
  temp -> previous = position.current-> previous;
  position.current -> previous -> next = temp;
  count++;
  
}

ListItr List::find(int x){
  ListItr temp;
  temp.current = head;
  while(!temp.isPastEnd()){
    temp.moveForward();
    if(temp.current->value == x){
      return temp;
    }
  }
  return temp;
}
void List::remove(int x){
  ListItr temp = find(x);
  if(temp.current -> value == x){
   temp.current -> previous-> next = temp.current -> next;
   temp.current -> next-> previous = temp.current -> previous;
   delete temp.current;
   count--;
  }
 
  }
 void List::removeTop(){
    ListItr temp;
    temp.current = tail->previous;
    temp.current -> previous-> next = tail;
    temp.current -> next-> previous = temp.current -> previous;
    delete temp.current;
    count--;

}


  

    
    



