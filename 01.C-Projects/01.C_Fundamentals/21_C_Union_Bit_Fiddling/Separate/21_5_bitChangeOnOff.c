/*
Дефинирайте функция:
u8 u8_set_bit(u8 num, u8bitpos pos, u8bit val);,
която връща стойността на число,
образувано от числото num с променен бит на позиция pos. Стойността на бита се подава от val.
*/

#include "../Library/bitsFunc.h"
#include <stdio.h>

int main(void)
{
	u8 num = 0b11111111;
	printf("\nnum = 0b");
	u8_print_bits(stdout, num);
	u8bit val = 0;
	printf("\nval = %d", val);
	unsigned char pos = 3;
	printf("\npos = %d", pos);

	u8 numChange = u8_set_bit(num, pos, val);
	printf("\nnumChange = 0b");
	u8_print_bits(stdout, numChange);

	num = 0b00000000;
	printf("\nnum = 0b");
	u8_print_bits(stdout, num);
	val = 1;
	printf("\nval = %d", val);
	pos = 3;
	printf("\npos = %d", pos);

	numChange = u8_set_bit(num, pos, val);
	printf("\nnumChange = 0b");
	u8_print_bits(stdout, numChange);

	return 0;
}
