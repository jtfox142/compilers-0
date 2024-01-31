CC = g++

CFLAGS = -Wall

main: main.o tree.o
	$(CC) $(CFLAGS) -o main main.o tree.o

main.o: main.cpp tree.cpp tree.hpp node.hpp
	$(CC) $(CFLAGS) -c main.cpp

tree.o: tree.cpp tree.hpp node.hpp
	$(CC) $(CFLAGS) -c tree.cpp

clean: 
	rm *.o main