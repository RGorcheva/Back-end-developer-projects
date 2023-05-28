/*
Напишете програма, която моли потребителя да въведе текст на
няколко реда до достигането на EOF. След това принтирайте текста
и след него, на отделни редове:
● броя на всички символи от текста.
● броя на всички букви от текста.
● броя на всички пунктуационни знаци от текста.
*/

#include "../Library/stringFunctions.h"
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	const char buff[256] = { 0 };

	int countsymbols = 0;
	int countletters = 0;
	int countpunct = 0;
	io_strEnterMultilineEOF(buff);
	int lenght = strlen(buff);
	printf(buff);
	for (const char* p = buff; *p != '\0'; ++p)
	{
		if (isalpha(*p))
		{
			++countletters;
		}
		if (ispunct(*p))
		{
			++countpunct;
		}
	}
	printf("\nnumber of symbols: %d", lenght);
	printf("\nnumber of letters: %d", countletters);
	printf("\nnumber of punctoation symbols: %d", countpunct);

	return 0;
}