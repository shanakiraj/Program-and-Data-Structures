
CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2
DOXY=doxygen
DEBUG=-g
OBJECTS= puzzle.o

a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS)
		$(DOXY)

puzzle.o: puzzle.cpp
	$(CXX) -c puzzle.cpp


.PHONY: clean
clean:
	-rm -f *.o *~ a.out


puzzle.o: puzzle.cpp




