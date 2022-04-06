
CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2
DEBUG=-g
OBJECTS=BinaryNode.o BinarySearchTree.o BSTPathTest.o

a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out

BinaryNode.o: BinaryNode.cpp
	$(CXX) -c BinaryNode.cpp

BinarySearchTree.o: BinarySearchTree.cpp
	$(CXX) -c BinarySearchTree.cpp

BSTPathTest.o: BSTPathTest.cpp
	$(CXX) -c BSTPathTest.cpp

.PHONY: clean
clean:
	-rm -f *.o *~ a.out


BinaryNode.o: BinaryNode.cpp BinaryNode.h

BinarySearchTree.o: BinarySearchTree.cpp BinaryNode.h BinarySearchTree.h

BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h

