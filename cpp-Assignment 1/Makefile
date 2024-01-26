# Purpose: Makefile for Assignment 1
Assignment.out: Assignment1.o Vector.o
	g++ Assignment1.o Vector.o -o Assignment.out

Assignment1.o:
	g++ -c Assignment1.cpp -o Assignment1.o

Vector.o:
	g++ -c Vector.cpp Vector.h -o Vector.o

clean:
	rm -f *.o Assignment.out
    