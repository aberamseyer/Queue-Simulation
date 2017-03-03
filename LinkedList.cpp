/*
* LinkedList.cpp
* Defines an implementation for the Linked List ADT. Contains methods for
* inserting/deleting/looking up elements and printing the list.
*
* @Abe Ramseyer
* 2-14-2017
*/
#include "LinkedList.h"

LinkedList::LinkedList() // Default constructor; constant time
{
	this->head = NULL;
	size = 0;
}

LinkedList::LinkedList(LinkedList& other) // Copy constructor; O(n)
{
	head = NULL;
	size = 0;
	// int size = other.getSize();
	Node* curr = other.getHead();
	while (curr != NULL) 
	{
		this->add(curr->data);
		curr = curr->next;
	}
}

LinkedList::~LinkedList() // Destructor; O(n)
{
	Node* curr = head;
	while (head != NULL) 
	{
		head = head->next;
		delete curr;
		curr = head;
	}
	head = NULL;
	tail = NULL;
}

LinkedList::Node* LinkedList::getHead() const // Returns a reference to the head node; constant time
{
	return head;
}

LinkedList::Node* LinkedList::getTail() const // Returns a reference to the tail node; constant time
{
	return tail;
}

int LinkedList::getSize() const // Returns a list's size; constant time
{
	return size;
}

int LinkedList::at(int index) const // Returns the data value at a specified index, -1 is returned if index is invalid; O(n)
{
	if (index < 0 || index >= size) 
	{
		return -1;
	}

	Node* curr = NULL;
	if (index < size / 2) 
	{
		curr = head;
		for (int i = 0; i < index; i++) 
		{
			curr = curr->next;
		}
	}
	else 
	{
		curr = tail;
		for (int i = size - 1; i > index; i--) 
		{
			curr = curr->prev;
		}
	}
	return curr->data;
}

void LinkedList::add(int toAdd) // Adds a value to the end of the list; constant time
{
	if (head == NULL) 
	{
		Node* newNode = new Node();
		newNode->data = toAdd;
		head = newNode;
		tail = newNode;
		size++;
	}
	else 
	{
		Node* curr = tail;
		Node* newNode = new Node();
		newNode->data = toAdd;
		curr->next = newNode;
		newNode->prev = curr;
		size++;
		tail = newNode;
	}
}

bool LinkedList::remove(int index) {
	Node* curr = head;
	if (index < 0 || index >= size) {
		return false; // index out of range
	}
	else if (index == 0) {
		if (size != 1) {
			curr->next->prev = NULL;  // disconnect next node's prev
			head = curr->next;        // move head up one
			curr->next = NULL;        // disconnect head from next node
			delete curr;
			curr = NULL;      // remove dangling pointer
		}
		else {
			head = NULL;
			tail = NULL;
			delete curr;
			curr = NULL;
		}
	}
	else if (index == size - 1) {
		curr = tail;     // change curr to tail
		curr->prev->next = NULL;  // disconnect previous node from tail
		tail = curr->prev;        // move tail one back
		curr->prev = NULL;        // isolate last Node
		delete curr;
		curr = NULL; // remove dangling pointer
	}
	else {
		for (int i = 0; i < index; i++) {
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

void LinkedList::printForward() const // Prints entire list forward; O(n)
{
	Node* curr = head;
	for (int i = 0; i < size; i++) 
	{
		std::cout << i << ": " << curr->data << std::endl;
		curr = curr->next;
	}
}

void LinkedList::printBackward() const // Prints entire list backward; O(n)
{
	Node* curr = tail;
	for (int i = size; i > 0; i--) 
	{
		std::cout << i - 1 << ": " << curr->data << std::endl;
		curr = curr->prev;
	}
}