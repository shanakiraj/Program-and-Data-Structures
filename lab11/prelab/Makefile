
CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2
DOXY= doxygen
DEBUG=-g
OBJECTS=topological.o

a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS)
		$(DOXY)

topological.o: topological.cpp
	$(CXX) -c topological.cpp


.PHONY: clean
clean:
	-rm -f *.o *~ a.out


topological.o: topological.cpp


