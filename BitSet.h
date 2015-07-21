#include <stdint.h>

class BitSet {
public:
	BitSet Union(const BitSet &other);
	BitSet Intersect(const BitSet &other);
	Set(long member);
	IsMember(long member);
	Invert();
	BitSet Inverted();
	int Count();
	BitSet operator=(const BitSet &other);	
	BitSet operator|(const BitSet &other);
	operator|=(const BitSet &other);
	BitSet operator&(const BitSet &other);
	operator&=(const BitSet &other);
	BitSet operator~();
private:
	uint64_t *bits;
}



/* sample code 

a = new BitSet(1000);
a.Set(40);
b = a;


b = ~a;
*/