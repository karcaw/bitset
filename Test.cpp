

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "BitSet.h"
#include "utils.h"

using namespace std;

int main(int argc,char *argv[]) {
	
	uint64_t val;
	
	BitSet b(100);

	val=strtol(argv[1],NULL,36);

	printf("Input was: %llu  %llx\n",val,val);

	PrintBinary64(val);
	CountBinary64(val);

	cout << "b's Count: " << b.Count() << endl;
	
	b.Set(10);
	b.Set(20);
	b.Set(100);
	cout << "b's Count: " << b.Count() << endl;
	b.Print();
	cout << "IsMember 10: " << b.IsMember(10) << endl;
	cout << "IsMember 15: " << b.IsMember(15) << endl;
	BitSet a = ~b;
	a.Print();
	
	
	BitSet c(100);
	c.Set(5);
	c.Set(4);
	c.Set(100);
	cout << endl << "Union Test" << endl;
	c.Print();
	b.Print();
	BitSet d = c|b;
	d.Print();
	d |= a;
	d.Print();

	cout << endl << "Intersect Test" << endl;
	c.Print();
	b.PrintBinary();
	BitSet e = c&b;
	e.Print();
	e &= a;
	e.PrintBinary();

	cout << endl << "Equality Test" << endl;
	cout << (e==e) << endl;
	cout << ((~a | ~b) == ~(a & b)) << endl;  // De Morgan's law
	cout << "Done" << endl;
}