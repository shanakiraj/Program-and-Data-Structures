

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2
DEBUG=-g
OBJECTS=TreeCalcTest.o TreeNode.o TreeCalc.o

a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out

TreeCalc.o: TreeCalc.cpp
	$(CXX) -c TreeCalc.cpp

TreeCalcTest.o: TreeCalcTest.cpp
	$(CXX) -c TreeCalcTest.cpp

TreeNode.o: TreeNode.cpp
	$(CXX) -c TreeNode.cpp

.PHONY: clean
clean:
	-rm -f *.o *~ a.out

TreeCalc.o: TreeCalc.cpp TreeCalc.h TreeNode.h

TreeCalcTest.o: TreeCalcTest.cpp TreeCalc.h TreeNode.h

TreeNode.o: TreeNode.cpp TreeNode.h
