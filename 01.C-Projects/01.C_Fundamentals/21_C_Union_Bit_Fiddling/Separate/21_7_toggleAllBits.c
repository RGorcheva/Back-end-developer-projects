/*
Дефинирайте функция:
u8 u8_toggle_bits(u8 num);,
която променя всичките битове от число num на обратните, така че да са равни на обратните им стойности.
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
	u8 numChange = u8_toggle_bits(num);
	printf("\nnumChange = 0b");
	u8_print_bits(stdout, numChange);

	num = 0b00000000;
	printf("\nnum = 0b");
	u8_print_bits(stdout, num);
	pos = 3;
	printf("\npos = %d", pos);
	numChange = u8_toggle_bits(num);
	printf("\nnumChange = 0b");
	u8_print_bits(stdout, numChange);

	return 0;
}