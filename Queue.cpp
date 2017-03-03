// Program: IT279 Group Project 1 - The Queue Simulation
// Filename: Queue.cpp
// Submission Deadline: 3.7.17
// Description:

#include "stdafx.h"
#include "Queue.h"



Queue::~Queue()
{
	
}

void Queue::enqueue(LinkedList& list, int data)
{
	list.add(data);
}

void Queue::dequeue(LinkedList& list)
{
	list.remove(0);
}

void Queue::run(LinkedList& list, int gap)	// This function runs the simulation. 
{
	int queueSize = 0;
	int totalCustomers = 0;
	srand(time(NULL));
	int arrivalCountdown = (rand() % gap) + 1;
	int departureCountdown = (rand() % gap) + 1;

	std::cout << "  VALUE OF ARRIVALCOUNTDOWN: " << arrivalCountdown << std::endl;
	std::cout << "  VALUE OF TRANSACTIONCOUNTDOWN: " << arrivalCountdown << std::endl;

	for (int minuteOfDay = 0; minuteOfDay < 60; minuteOfDay++)
	{
		//std::cout << "  ITERATION " << minuteOfDay << std::endl;
		
		if (arrivalCountdown <= 0)
		{
			enqueue(list, arrivalCountdown);
			arrivalCountdown = (rand() % gap) + 1;
			totalCustomers++;
			queueSize++;
			if (totalCustomers == 0)
			{
				std::cout << "  First customer arrived at " << minuteOfDay << std::endl;
			}
			else
			{
				std::cout << "  New customer arrived at " << minuteOfDay << std::endl;
			}
		}
		
		else
		{
			arrivalCountdown--;
		}

		if (departureCountdown <= 0 && queueSize > 0)
		{
			dequeue(list);
			departureCountdown = (rand() % gap) + 1;
			queueSize--;
			std::cout << "  DEPARTURECOUNTDOWN RESET TO: " << departureCountdown << ". QUEUESIZE: "<< queueSize << std::endl;
		}
		else
		{
			departureCountdown--;
		}
	}
}