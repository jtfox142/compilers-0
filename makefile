CC = g++

CFLAGS = -Wall

main: main.o tree.o scanner.o
	$(CC) $(CFLAGS) -o main main.o tree.o scanner.o

main.o: main.cpp tree.cpp tree.hpp node.hpp scanner.cpp scanner.hpp
	$(CC) $(CFLAGS) -c main.cpp

tree.o: tree.cpp tree.hpp node.hpp
	$(CC) $(CFLAGS) -c tree.cpp

scanner.o: scanner.cpp scanner.hpp
	$(CC) $(CFLAGS) -c scanner.cpp

clean: 
	rm *.o main *.preorder *.postorder *inorder