// Program: IT279 Group Project 1 - The Queue Simulation
// Filename: Queue.cpp
// Submission Deadline: 3.7.17
// Description: This is the implementation of the Queue ADT.

#include "Queue.h"

Queue::~Queue() {}

void Queue::enqueue(int data)
{
	list.add(data);
}

void Queue::dequeue()
{
	list.remove(0);
}

int Queue::getSize()
{
	return list.getSize();
}

int Queue::front()
{
	return list.getHead()->data;
}
