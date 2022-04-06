CXX=clang $(CXXFLAGS)
CXXFLAGS=-Wall -O2
DEBUG=-g
OBJECTS=linkedlist.o

a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out

linkedlist.o: linkedlist.c
	$(CXX) -c linkedlist.c

.PHONY: clean
clean:
	-rm -f *.o *~ a.out

linkedlist.o: linkedlist.c

