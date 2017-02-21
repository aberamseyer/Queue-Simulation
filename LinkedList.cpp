/*
 * LinkedList.cpp
 * Defines an implementation for the Linked List ADT. Contains methods for
 * inserting elements and printing the list.
 *
 * @Abe Ramseyer
 * 2-14-2017
 */

#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList() {
  this->head = NULL;
  size = 0;
}

LinkedList::~LinkedList() {
  Node* curr = head;
  while(head->next != NULL) {
    head = head->next;
    delete curr;
    curr = head;
  }
  head = NULL;
  tail = NULL;
}

/*
 * Returns a reference to the head Node
 */
LinkedList::Node* LinkedList::getHead() const {
  return head;
}

/*
 * Returns a reference to the tail Node
 */
LinkedList::Node* LinkedList::getTail() const {
  return tail;
}

/*
 * Returns the list's size
 */
int LinkedList::getSize() const {
  return size;
}

/*
 * Returns the data value at the specified index
 */
int LinkedList::at(int index) const {
  Node* curr = head;
  for(int i=0; i < index; i++) {
    curr = curr->next;
  }
  return curr->data;
}

/*
 * Adds a value to the linked list
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
    size++;
    tail = newNode;
  }
}

/*
 * Prints out all the values in the list
 */
void LinkedList::print() const {
  Node* curr = head;
  for(int i=0; i < size; i++) {
    std::cout << i << ": " << curr->data << std::endl;
    curr = curr->next;
  }
}
