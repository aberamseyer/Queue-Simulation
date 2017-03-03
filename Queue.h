/* Program: The Queue Simulation
*  Filename: Simulation.cpp
*  Due: 2.7.16
*  Author: Harry Manny
*  Description: This is the Queue ADT implementation's header. It's just got the standard functions.
*/
#ifndef QUEUE_H_
#define QUEUE_H_
#include "LinkedList.h"

class Queue
{
	private:
		int gap;
		LinkedList list;
	public:
		Queue(const int& gap) : gap(gap)
		{
			LinkedList list;
		};
		void enqueue(int data);
		void dequeue();
		int getSize();
		int front();
		~Queue();
};
#endif
