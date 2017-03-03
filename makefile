#
# makefile for Project 1 Queue Simulation
# 2-21-2017
#

CC = g++
FLAGS = -std=c++11

all:main

main: LinkedList.o Queue.o Simulation.o
	${CC} ${FLAGS} LinkedList.o Queue.o Simulation.o -o QueueSimulation
Queue.o:
	${CC} ${FLAGS} -c Queue.cpp
LinkedList.o:
	${CC} ${FLAGS} -c LinkedList.cpp
Simulation.o:
	${CC} ${FLAGS} -c Simulation.cpp
clean:
	rm *.o
run: clean main
