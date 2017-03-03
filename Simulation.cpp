/* Program: The Queue Simulation
*  Filename: Simulation.cpp
*  Due: 2.7.16
*  Author: Harry Manny
*  Description: This is the driver for the program. This file contains the run function that actually runs the simulation.
*				This file also has no direct contact with the LinkedList class or its objects - class Queue is the intermediary
*				between this file and class LinkedList.
*/
#include <iostream>
#include <cstdlib>
#include "Queue.h"

void getMenuChoice();				// Prototype for getMenuChoice, the function that catches the user's decisions for the main menu.
void run(Queue& queue, int gap);	// Prototype for the run function, which actually runs the simulation.

void displayMenu()	// This function only displays the menu contents, user input is caught in getMenuChoice.
{
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
	std::cout << "|||| MENU |||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
	std::cout << "  1. Run Simulation" << std::endl;
	std::cout << "  2. Quit" << std::endl;
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
	getMenuChoice();
}

void getMenuChoice()	// This function catches the user input regarding running the simulation or quitting.
{
	std::string acknowledge = "";
	int choice = 0;
	int gap = 0;
	std::cout << "  Your choice: ";
	std::cin >> choice;
	if (std::cin.fail())	// The case wherein the user enters erroneous data into the menu dialog
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		choice = 0;
		std::cout << "\n  You must enter a number from the menu." << std::endl;
		std::cout << "  Redirecting to main menu.\n" << std::endl;
		displayMenu();
	}
	else if (choice < 1 || choice > 2)	// The case wherein the user enters non-extant numbers into the menu dialog
	{
		std::cout << "\n  You must enter a number from the menu." << std::endl;
		std::cout << "  Redirecting to main menu.\n" << std::endl;
		std::cin >> acknowledge;
		displayMenu();
	}
	else
	{
		if (choice == 1)	// The user selected "Run Simulation"
		{
			std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
			std::cout << "|||| Run Simulation |||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
			std::cout << "\n  Enter the maximum time gap between customers." << std::endl;
			std::cout << "  The simulation will run to completion.\n" << std::endl;
			std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
			std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
			std::cout << "  Time gap in minutes: ";
			std::cin >> gap;
			Queue queue(gap);
			run(queue, gap);
			displayMenu();
		}
		else if (choice == 2)	// The user selected "Quit"
		{
			std::cout << "\n  Goodbye" << std::endl;
		}
	}
}

void run(Queue& queue, int gap)	// This function actually runs the simulation.
{
	int queueSize = 0;		// Holds current size of queue. Changeable from one iteration of the loop to the next.
	int totalCustomers = 0;	// Holds the total number of customers that have arrived over the course of one business day.
	srand(time(NULL));		// We seed rand() with null time.
	int arrivalCountdown = (rand() % gap) + 1;		// We generate a random number for arrivalCountdown. This int holds the time until the next user arrives.
	int departureCountdown = (rand() % gap) + 1;	// We generate a different random number for departureCountdown. This int holds the time until the current head of the line departs.
	int arrivalCounter = 1;		// This int holds the number of arrivals that have happened over the course of one business day.
	int departureCounter = 0;	// This int holds the number of departures that have happened over the course of one business day.
	int maxWait = 0;			// Holds the maximum wait that a customer has experienced all day.
	int maxSize = 0;			// Holds the maximum number of people in the queue at any one time.

	for (int minuteOfDay = 0; minuteOfDay < 720; minuteOfDay++)
	{
		if (arrivalCountdown == 0)	// The case wherein it's time to add a new person to the queue.
		{
			if (totalCustomers == 0)	// The case wherein the first customer arrives.
			{
				std::cout << "  First customer arrived at " << minuteOfDay << std::endl;
			}
			else    // The case wherein a non-first customer arrives.
			{
				std::cout << "  Customer  " << arrivalCounter << " arrived at minute " <<  minuteOfDay << "." <<  std::endl;
			}
			queue.enqueue(minuteOfDay);				// Here we actually add the customer to the list.
			arrivalCountdown = (rand() % gap) + 1;	// We have to reset the value of arrivalCountdown so the next customer can arrive.
			totalCustomers++;						
			queueSize++;
			arrivalCounter++;
			if (queueSize > maxSize)	// The case wherein the current queue size is larger than the previous max
			{
				maxSize = queueSize;
			}
		}
		else    // The case wherein it's not time to add a new customer.
		{
			arrivalCountdown--;
		}

		if (departureCountdown == 0)	// The case wherein it's time for the customer at the head of the queue to leave
		{
			
			if (queueSize > 0)	// We only dequeue a customer if there is one.
			{
				departureCountdown = (rand() % gap) + 1;	// Here we reinitialize the departure timer.
				queueSize--;
				departureCounter++;
				std::cout << "  Customer " << departureCounter << " left at minute " << minuteOfDay << "." << std::endl;
				int currentWait = minuteOfDay - queue.front();
				if (maxWait < currentWait)	// The case wherein the current wait time is larger than the previous max.
				{
					maxWait = currentWait;	
				}
				queue.dequeue();
			}
		}
		else if(queue.getSize() > 0)	// The case wherein no customer leaves.
		{
			departureCountdown--;
		}
		
	}
	std::cout << "\n  The maximum wait time was " << maxWait << " minutes." << std::endl;
	std::cout << "\n  The maximum number of people in the queue was " << maxSize << ".\n" <<  std::endl;
}

int main()
{
	displayMenu();
	return 0;
}



