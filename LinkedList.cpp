/*
 * LinkedList.cpp
 * Defines an implementation for the Linked List ADT. Contains methods for
 * inserting/deleting/looking up elements and printing the list.
 *
 * @Abe Ramseyer
 * 2-14-2017
 */

#include <iostream>
#include "LinkedList.h"

/*
 * Default constructor
 * Constant Time
 */
LinkedList::LinkedList() {
  this->head = NULL;
  size = 0;
}

/*
 * Copy constructor
 * Worst case O(n)
 */
LinkedList::LinkedList(LinkedList& other) {
  head = NULL;
  size = 0;
  // int size = other.getSize();
  Node* curr = other.getHead();
  while(curr != NULL) {
    this->add(curr->data);
    curr = curr->next;
  }
}

/*
 * Destructor
 * O(n)
 */
LinkedList::~LinkedList() {
  Node* curr = head;
  while(head != NULL) {
    head = head->next;
    delete curr;
    curr = head;
  }
  head = NULL;
  tail = NULL;
}

/*
 * Returns a reference to the head Node
 * Constant time
 */
LinkedList::Node* LinkedList::getHead() const {
  return head;
}

/*
 * Returns a reference to the tail Node
 * Constant time
 */
LinkedList::Node* LinkedList::getTail() const {
  return tail;
}

/*
 * Returns the list's size
 * Constant time
 */
int LinkedList::getSize() const {
  return size;
}

/*
 * Returns the data value at the specified index
 * -1 is returned for an invalid index
 * Worst case O(n/2)
 */
int LinkedList::at(int index) const {
  if(index < 0 || index >= size) {
    return -1;
  }

  Node* curr = NULL;
  if(index < size/2) {
    curr = head;
    for(int i=0; i < index; i++) {
      curr = curr->next;
    }
  }
  else {
    curr = tail;
    for(int i=size-1; i > index; i--) {
      curr = curr->prev;
    }
  }

  return curr->data;
}

/*
 * Adds a value to the end of the linked list
 * Constant time
 */
void LinkedList::add(int toAdd) {
  if(head == NULL) {
    Node* newNode = new Node();
    newNode->data = toAdd;
    head = newNode;
    tail = newNode;
    size++;
  }
  else {
    Node* curr = tail;
    Node* newNode = new Node();
    newNode->data = toAdd;
    curr->next = newNode;
    newNode->prev = curr;
    size++;
    tail = newNode;
  }
}

/*
 * Deletes the node at the specified index from the list, returns true if valid index (successful)
 * Constant time for the head and tail, O(n-index) worst case for any index inbetween
 */
bool LinkedList::remove(int index) {
  Node* curr = head;
  if(index == 0) {
    curr->next->prev = NULL;  // disconnect next node's prev
    head = curr->next;        // move head up one
    curr->next = NULL;        // disconnect head from next node
    delete curr;
    curr = NULL;      // remove dangling pointer
  }
  else if(index == size-1) {
    curr = tail;     // change curr to tail
    curr->prev->next = NULL;  // disconnect previous node from tail
    tail = curr->prev;        // move tail one back
    curr->prev = NULL;        // isolate last Node
    delete curr;
    curr = NULL; // remove dangling pointer
  }
  else if(index < 0 || index >= size) {
    return false; // index out of range
  }
  else {
    for(int i=0; i < index; i++) {
      curr = curr->next;
    }                   //curr should hold the Node at the index to delete
    curr->prev->next = curr->next;  //attach previous to the next Node
    curr->next->prev = curr->prev;  //attach next node's previous to the previous node
    delete curr;
    curr = NULL; // remove dangling pointer
  }

  size--;
  return true;
}

/*
 * Prints out all the values in the list forward
 * O(n)
 */
void LinkedList::printForward() const {
  Node* curr = head;
  for(int i=0; i < size; i++) {
    std::cout << i << ": " << curr->data << std::endl;
    curr = curr->next;
  }
}

/*
 * Prints out all the values in the list backward
 * O(n)
 */
void LinkedList::printBackward() const {
  Node* curr = tail;
  for(int i=size; i > 0; i--) {
    std::cout << i-1 << ": " << curr->data << std::endl;
    curr = curr->prev;
  }
}
