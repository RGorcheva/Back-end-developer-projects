/*
Напишете програма, която моли потребителя да въведе текст на
няколко реда до достигането на EOF. След това принтирайте на
отделни редове:
● броя на редовете.
● броя на space-овете (шпациите)
● броя на табулациите
*/

#include "../Library/stringFunctions.h"
#include <stdio.h>

int main(void)
{
	char buff[256] = { 0 };
	char c = 0;
	io_strEnterMultilineEOF(buff);
	printf(buff);

	printf("\nNumber of rows: %d", string_countRows(buff));
	printf("\nNumber of space: %d", string_countSymbols(buff, ' '));
	printf("\nNumber of tabs: %d", string_countSymbols(buff, '\t'));
	return 0;
}