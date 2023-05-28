/*
 Дефинирайте функция:
u8 u8_set_bit_off(u8 num, u8bitpos pos);, 
която променя стойността на бит от число num на дадена позиция pos на 0
*/

#include "../Library/bitsFunc.h"
#include <stdio.h>

int main(void)
{
	u8 num = 0b11111111;
	printf("\nnum = 0b");
	u8_print_bits(stdout, num);
	unsigned char pos = 3;
	printf("\npos = %d", pos);
	u8 numChange = u8_set_bit_off(num, pos);
	printf("\nnumChange = 0b");
	u8_print_bits(stdout, numChange);

	return 0;
}