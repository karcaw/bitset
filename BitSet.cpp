#include <stdint.h>
#include <iostream>
#include "BitSet.h"

using namespace std;


BitSet::BitSet(int size) {
  maxnum = size;
  num = (size / 64) + 1;
  bits = new uint64_t[num];
  cout << num << " num " << bits << " bits" << endl;
 
  for (int i = 0; i < num; i++)
  {
    bits[i] = 0;
  }
}

BitSet::~BitSet() {
	//cout << "Death! " << bits << endl;
	delete [] bits;
}

BitSet BitSet::Union(const BitSet &other) {
	BitSet result(maxnum);
	
	for(int chunk = 0; chunk < num ; chunk++) {
	  result.bits[chunk] = bits[chunk] | other.bits[chunk];
	}
	
	return result;
}

BitSet BitSet::Intersect(const BitSet &other) {
  BitSet result(maxnum);
	
	for(int chunk = 0; chunk < num ; chunk++) {
	  result.bits[chunk] = bits[chunk] & other.bits[chunk];
	}
	
	return result;
}

void BitSet::Set(long member) {
  // add something to catch when member is too big
  int bit = member % 64;
  int chunk = member / 64;
  bits[chunk] |= 1LL << bit;
  cout <<"bit " << bit << " chunk " << chunk << " member " << member << endl; 
}

bool BitSet::IsMember(long member) {
  int bit = member % 64;
  int chunk = member / 64;
  
  return bits[chunk] & 1LL << bit ? 1 : 0;
}

void BitSet::operator=(const BitSet &other) {
	for (int chunk=0; chunk<num; chunk++)
		bits[chunk] = other.bits[chunk];
	return;
}

int BitSet::Count() {
	//count = __builtin_popcount(i);
	int count = 0;
  	for (int i = 0; i < num; i++) {
    	count = count + __builtin_popcount(bits[i]);
  	}
  return count;
}

void BitSet::PrintBinary() {
	for (int chunk=num-1; chunk>=0; chunk--) {
		for (uint64_t loop=1LL<<63; loop; loop>>=1 ) {
			cout << ((loop & bits[chunk]) ? "1":"0");
		}
	}
	cout << endl;
}

void BitSet::Print() {
	cout << "{";
	for (int chunk=0; chunk<num; chunk++)
		for (int bit=0; bit<63; bit++) {
			if (chunk*64+bit > maxnum)
				break;
			if (bits[chunk] & 1LL << bit)
				cout << chunk*64+bit << ",";
		}
	cout << "\b}" << endl;
}

void BitSet::Invert() {
	for (int chunk=0; chunk<num;chunk++)
	  bits[chunk] = ~bits[chunk];
}

BitSet BitSet::Inverted() {
	BitSet other(maxnum);
	//cout << "Inverted" << endl;
	other = *this;
	other.Invert();
	//cout << "Inverted2" << endl;
	return other;
}

BitSet BitSet::operator|(const BitSet &other) {
 
  	return (this->Union(other));
}

void BitSet::operator|=(const BitSet &other) {
	for(int chunk = 0; chunk < num ; chunk++) {
	  bits[chunk] |= other.bits[chunk];
	}
}

BitSet BitSet::operator&(const BitSet &other) {
	return (this->Intersect(other));
}

void BitSet::operator&=(const BitSet &other) {
	for(int chunk = 0; chunk < num ; chunk++) {
	  bits[chunk] &= other.bits[chunk];
	}
}

BitSet BitSet::operator~() {
	return this->Inverted();
}

bool BitSet::operator==(const BitSet &other){
	for(int chunk = 0; chunk < num ; chunk++) {
	  if (bits[chunk] != other.bits[chunk])
	  	return false;
	}
	return true;
}	

