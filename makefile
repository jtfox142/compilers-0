CC = g++

CFLAGS = -Wall

main: main.o tree.o
	$(CC) $(CFLAGS) -o main main.o tree.o

main.o: main.cpp tree.hpp
	$(CC) $(CFLAGS) -c main.cpp

tree.o: tree.hpp node.hpp