/*
Дефинирайте функция:
u8 u8_scan_bits(FILE* f);,
която парсва число на побитов принцип от следващите осем символа в подадения й файлов поток.
*/

#include "../Library/inputOutputFunc.h"
#include "../Library/fileFunc.h"
#include "../Library/bitsFunc.h"
#include <stdio.h>

int main(void)
{
	FILE* in = NULL;
	FILE* out = NULL;
	char filename[20];
	printf("\nEnter input file name:");
	io_strEnter(filename, 20);
	in = file_open(in, filename, "r");


	u8 num = 0b00000000;
	num = u8_scan_bits(in);
	printf("\nnum = 0b");
	u8_print_bits(stdout, num);

	file_close(in);
	return 0;
}