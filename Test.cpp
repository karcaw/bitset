

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "BitSet.h"
#include "utils.h"

using namespace std;

int main(int argc,char *argv[]) {
	
	uint64_t val;
// 	BitSet a,c;
	
	BitSet b(300);

	val=strtol(argv[1],NULL,36);

	printf("Input was: %llu  %llx\n",val,val);

	PrintBinary64(val);
	CountBinary64(val);

	cout << "b's Count: " << b.Count() << endl;
	
	b.Set(10);
	b.Set(20);
	b.Set(150);
	cout << "b's Count: " << b.Count() << endl;
	b.Print();
	cout << "IsMember 10: " << b.IsMember(10) << endl;
	cout << "IsMember 15: " << b.IsMember(15) << endl;
	BitSet a = b.Inverted();
	a.Print();
	//a = BitSet(100);
	//a.Set(5);
	//a.Set(4);
	//a.Set(3);
	//c = a.Union(b);
	cout << "Done" << endl;
}