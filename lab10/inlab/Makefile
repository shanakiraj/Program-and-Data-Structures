
CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2
DEBUG=-g
OBJECTS=huffmandec.o

a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out

huffmandec.o: huffmandec.cpp
	$(CXX) -c huffmandec.cpp


.PHONY: clean
clean:
	-rm -f *.o *~ a.out


huffmandec.o: huffmandec.cpp


