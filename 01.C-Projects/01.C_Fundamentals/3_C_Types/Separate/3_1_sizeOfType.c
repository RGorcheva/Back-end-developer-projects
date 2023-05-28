/*
Изведете размерите в байтове и битове на основните типове на вашата машина
● char
● int
● short
● long
● long long
● size_t
● float
● double
● bool
*/

#include <stdio.h>
#include <limits.h>
# include <stdbool.h>

int main()
{
	int bitsPerByte = CHAR_BIT;   
	printf("\nbits per byte %d", bitsPerByte);

	size_t intSizeBytes1 = sizeof(char); 
	printf("\nBytes per char: %zu", intSizeBytes1);
	size_t intSizeBits1 = intSizeBytes1 * bitsPerByte;
	printf("\tBits per char: %zu", intSizeBits1);

	size_t intSizeBytes2 = sizeof(int);
	printf("\nBytes per int: %zu", intSizeBytes2);
	size_t intSizeBits2 = intSizeBytes2 * bitsPerByte;
	printf("\tBits per int: %zu", intSizeBits2);

	size_t intSizeBytes3 = sizeof(short int); 
	printf("\nBytes per short int: %zu", intSizeBytes3);
	size_t intSizeBits3 = intSizeBytes3 * bitsPerByte;
	printf("\tBits per short int: %zu", intSizeBits3);

	size_t intSizeBytes4 = sizeof(long int);
	printf("\nBytes per long int: %zu", intSizeBytes4);
	size_t intSizeBits4 = intSizeBytes4 * bitsPerByte;
	printf("\tBits per long int: %zu", intSizeBits4);

	size_t intSizeBytes5 = sizeof(long long int);
	printf("\nBytes per long long int: %zu", intSizeBytes5);
	size_t intSizeBits5 = intSizeBytes5 * bitsPerByte;
	printf("\tBits per long long int: %zu", intSizeBits5);

	size_t intSizeBytes6 = sizeof(size_t);
	printf("\nBytes per size_t: %zu", intSizeBytes6);
	size_t intSizeBits6 = intSizeBytes6 * bitsPerByte;
	printf("\tBits per size_t: %zu", intSizeBits6);

	size_t intSizeBytes7 = sizeof(float);
	printf("\nBytes per float: %zu", intSizeBytes7);
	size_t intSizeBits7 = intSizeBytes7 * bitsPerByte;
	printf("\tBits per float: %zu", intSizeBits7);

	size_t intSizeBytes8 = sizeof(double);
	printf("\nBytes per double: %zu", intSizeBytes8);
	size_t intSizeBits8 = intSizeBytes8 * bitsPerByte;
	printf("\tBits per double: %zu", intSizeBits8);

	size_t intSizeBytes9 = sizeof(bool);
	printf("\nBytes per bool: %zu", intSizeBytes9);
	size_t intSizeBits9 = intSizeBytes9 * bitsPerByte;
	printf("\tBits per bool: %zu", intSizeBits9);

	return 0;
}