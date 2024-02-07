CC = g++

CFLAGS = -Wall -std=c++1y

p0: p0.o tree.o scanner.o
	$(CC) $(CFLAGS) -o p0 p0.o tree.o scanner.o

p0.o: p0.cpp tree.cpp tree.hpp node.hpp scanner.cpp scanner.hpp
	$(CC) $(CFLAGS) -c p0.cpp

tree.o: tree.cpp tree.hpp node.hpp
	$(CC) $(CFLAGS) -c tree.cpp

scanner.o: scanner.cpp scanner.hpp
	$(CC) $(CFLAGS) -c scanner.cpp

clean: 
	rm *.o p0 *.preorder *.postorder *inorder