/*
Дефинирайте функция:
u8bit u8_get_bit(u8 num, u8bitpos pos);,
която връща стойността на бит от число num на дадена позиция pos*
*/

#include "../Library/bitsFunc.h"
#include <stdio.h>

int main(void)
{
	u8 num = 0b00001000;
	printf("\nnum = 0b");
	u8_print_bits(stdout, num);
	unsigned char pos = 3;
	printf("\npos = %d", pos);
	u8bit bitValie = u8_get_bit(num, pos);
	(bitValie) ? printf("\n1") : printf("\n0");

	return 0;
}