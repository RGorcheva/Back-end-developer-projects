/*
Дефинирайте функция:
u8 u8_set_bit_on(u8 num, u8bitpos pos);, 
която променя стойността на бит от число num на дадена позиция pos на 1.
*/

#include "../Library/bitsFunc.h"
#include <stdio.h>

int main(void)
{
	u8 num = 0b00000000;
	printf("\nnum = 0b");
	u8_print_bits(stdout, num);
	unsigned char pos = 3;
	printf("\npos = %d", pos);
	u8 numChange = u8_set_bit_on(num, pos);
	printf("\nnumChange = 0b");
	u8_print_bits(stdout, numChange);

	return 0;
}