
CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2
DEBUG=-g
OBJECTS=hashTable.o wordPuzzle.o timer.o

a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out

hashTable.o: hashTable.cpp
	$(CXX) -c hashTable.cpp

wordPuzzle.o: wordPuzzle.cpp
	$(CXX) -c wordPuzzle.cpp

timer.o: timer.cpp
	$(CXX) -c timer.cpp

.PHONY: clean
clean:
	-rm -f *.o *~ a.out

hashTable.o: hashTable.cpp hashTable.h

wordPuzzle.o: wordPuzzle.cpp hashTable.h

timer.o: timer.cpp timer.h

