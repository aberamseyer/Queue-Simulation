#
# makefile for Project 1 Queue Simulation
# 2-21-2017
#

CC = g++

all:main

main: Queue.o Simulation.o
	${CC} Queue.o Simulation.o -o main
Stack.o:
	${CC} -c Queue.cpp
Simulation.o:
	${CC} -c Simulation.cpp
clean:
	rm *.o
run:
	clean main
