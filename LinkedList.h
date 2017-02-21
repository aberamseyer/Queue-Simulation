/*
 * LinkedList.h
 *
 * @Abe Ramseyer
 * 2-14-2017
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>

class LinkedList {

 private:
  struct Node {
    int data;
    Node* next;
  };

  Node* head;
  Node* tail;
  int size;

public:
	LinkedList();
  ~LinkedList();

  LinkedList::Node* getHead() const;
  LinkedList::Node* getTail() const;
  int getSize() const;
  int at(int index) const;
  void add(int toAdd);
	void print() const;

};

#endif
