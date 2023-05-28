/*
Напишете програма, която моли потребителя да въведе текст на няколко
реда до достигането на EOF. След това принтирайте целия текст, но без
whitespace characters(space, newline, tab)
*/

#include "../Library/stringFunctions.h"
#include <stdio.h>

int main(void)
{
	char buff[256] = { 0 };
	io_strEnterMultilineEOF(buff);
	printf("\n\n");
	for (char* p = buff; *p != '\0'; ++p)
	{
		if (*p == ' ' || *p == '\t' || *p == '\n')
		{
			continue;
		}
		printf("%c", *p);
	}
	printf("\n\n");
	return 0;
}