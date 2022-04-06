
CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2
DEBUG=-g
OBJECTS=AVLNode.o AVLPathTest.o AVLTree.o

a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out

AVLNode.o: AVLNode.cpp
	$(CXX) -c AVLNode.cpp

AVLPathTest.o: AVLPathTest.cpp
	$(CXX) -c AVLPathTest.cpp

AVLTree.o: AVLTree.cpp
	$(CXX) -c AVLTree.cpp

.PHONY: clean
clean:
	-rm -f *.o *~ a.out

AVLNode.o: AVLNode.cpp AVLNode.h

AVLPathTest.o: AVLPathTest.cpp AVLTree.h AVLNode.h

AVLTree.o: AVLTree.cpp AVLNode.h AVLTree.h
