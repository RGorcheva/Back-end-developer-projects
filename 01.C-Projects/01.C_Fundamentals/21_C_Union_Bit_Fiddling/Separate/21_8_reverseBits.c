/*
Дефинирайте функция:
u8 u8_reverse_bits(u8 num);,
която обръща стойностите на битовете на число num в обратен ред
*/

#include "../Library/bitsfunc.h"

int main(void)
{
	u8 num = 0b11110000;
	printf("\nnum = 0b");
	u8_print_bits(stdout, num);
	u8 numChange = u8_reverse_bits(num);
	printf("\nnumChange = 0b");
	u8_print_bits(stdout, numChange);
}