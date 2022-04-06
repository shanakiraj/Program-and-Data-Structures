
CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2
DOXY=doxygen
DEBUG=-g
OBJECTS=traveling.o middleearth.o

a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS)
		$(DOXY)

traveling.o: traveling.cpp
	$(CXX) -c traveling.cpp

middleearth.o: middleearth.cpp
	$(CXX) -c middleearth.cpp

.PHONY: clean
clean:
	-rm -f *.o *~ a.out


traveling.o: traveling.cpp

middleearth.o: middleearth.cpp middleearth.h


