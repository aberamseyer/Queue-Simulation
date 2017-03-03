#include "stdafx.h"
#ifndef QUEUE_H_
#define QUEUE_H_
#include "LinkedList.h"
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>

class Queue
{
	private:
		int gap;
		LinkedList list;
		void run(LinkedList& list, int gap);
		void enqueue(LinkedList& list, int data);
		void dequeue(LinkedList& list);
	public:
		Queue(const int& gap) : gap(gap)
		{
			LinkedList list;
			run(list, gap);
		};
		~Queue();
};
#endif
