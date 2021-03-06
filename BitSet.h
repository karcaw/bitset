#include <stdint.h>

class BitSet {
public:
	BitSet(int size=64);
	~BitSet();
	BitSet Union(const BitSet &other);
	BitSet Intersect(const BitSet &other);
	void Set(long member);
	bool IsMember(long member);
	void Invert();
	BitSet Inverted();
	int Count();
	void Print();
	void PrintBinary();
	void operator=(const BitSet &other);
	bool operator==(const BitSet &other);	
	BitSet operator|(const BitSet &other);
	void operator|=(const BitSet &other);
	BitSet operator&(const BitSet &other);
	void operator&=(const BitSet &other);
	BitSet operator~();
private:
	uint64_t *bits;
	int num;
	int maxnum;
};

/* sample code 

a = new BitSet(1000);
a.Set(40);
b = a;


b = ~a;
*/