LDFLAGS=-lstdc++

all: test 

Bitset.o: BitSet.cpp

test.o: test.cpp

utils.o: utils.cpp

test: test.o BitSet.o utils.o

check: test
	./test 1023

clean: 
	-rm *.o
	-rm test