#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "utils.h"
/*Print MSB to LSB in binary.
 * 0xff  -> 11111111
 * 0x55  -> 01010101
 * 0x00  -> 00000000   
 */

void PrintBinary8(uint8_t i) {
	uint8_t loop;
	
	for ( loop=0x80; loop; loop>>=1 ) {
		if (loop & i)
			printf("1");
		else
			printf("0");
	}

	printf("\n");
}

void PrintBinary64(uint64_t i) {
	uint64_t loop;
	
	for ( loop=1LL<<63; loop; loop>>=1 ) {
		if (loop & i)
			printf("1");
		else
			printf("0");
	}

	printf("\n");
}

void CountBinary64(uint64_t i){
	uint64_t loop;
	int count=0;
/*	
	for ( loop=1LL<<63; loop; loop>>=1 ) {
		if (loop & i)
			count++;
	}
*/
	count = __builtin_popcount(i);
	printf("%d\n",count);
}


