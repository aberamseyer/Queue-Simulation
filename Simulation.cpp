
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include "Queue.h"

//using namespace std;

void getMenuChoice();

void displayMenu()
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

void getMenuChoice()
{
	std::string acknowledge = "";
	int choice = 0;
	int gap = 0;
	std::cout << "  Your choice: ";
	std::cin >> choice;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		choice = 0;
		std::cout << "\n  You must enter a number from the menu." << std::endl;
		std::cout << "  Redirecting to main menu.\n" << std::endl;
		displayMenu();
	}
	else if (choice < 1 || choice > 2)
	{
		std::cout << "\n  You must enter a number from the menu." << std::endl;
		std::cout << "  Redirecting to main menu.\n" << std::endl;
		std::cin >> acknowledge;
		displayMenu();
	}
	else
	{
		if (choice == 1)
		{
			std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
			std::cout << "|||| Run Simulation |||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
			std::cout << "\n  Enter the maximum time gap between customers." << std::endl;
			std::cout << "  The simulatin will run to completion.\n" << std::endl;
			std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
			std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << std::endl;
			std::cout << "  Time gap in minutes: ";
			std::cin >> gap;
			Queue queue(gap);
			displayMenu();
		}
		else if (choice == 2)
		{
			std::cout << "\n  Goodbye" << std::endl;
		}
	}
}

int main()
{
	displayMenu();
	return 0;
}



