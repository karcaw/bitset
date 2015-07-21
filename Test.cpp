

#include <stdio.h>
#include <stdlib.h>
#include "BitSet.h"
#include "utils.h"



int main(int argc,char *argv[]) {
	
	uint64_t val;
	BitSet b,a,c;

	val=strtol(argv[1],NULL,36);

	printf("Input was: %llu  %llx\n",val,val);

	PrintBinary64(val);
	CountBinary64(val);

	b = BitSet(100);
	b.Set(10);
	b.Set(20);
	a = BitSet(100);
	a.Set(5);
	a.Set(4);
	a.Set(3);
	c = a.Union(b);

}