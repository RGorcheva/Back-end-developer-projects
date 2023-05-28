/*
Дефинирайте функция:
void u8_print_bits(FILE* f, u8 num);,
която принтира битовете на число num на подадения й файлов поток
*/

#include "../Library/bitsFunc.h"
#include <stdio.h>

int main(void)
{
	u8 num = 0b00001000;
    printf("\nnum = 0b");
    u8_print_bits(stdout, num);
    return 0;
}