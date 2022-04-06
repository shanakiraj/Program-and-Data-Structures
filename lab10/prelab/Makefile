
CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2
DEBUG=-g
OBJECTS=heap.o huffmanenc.o node.o

a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out

heap.o: heap.cpp
	$(CXX) -c heap.cpp

huffmanenc.o: huffmanenc.cpp
	$(CXX) -c huffmanenc.cpp

node.o: node.cpp
	$(CXX) -c node.cpp

.PHONY: clean
clean:
	-rm -f *.o *~ a.out

heap.o: heap.cpp heap.h

huffmanenc.o: huffmanenc.cpp

node.o: node.cpp node.h
