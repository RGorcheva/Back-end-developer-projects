/*
Напишете програма, която моли потребителя да въведе текст на
няколко реда до достигането на EOF. След това принтирайте
въведения текст, но със премахнати дублиращи се последователни
space-а(шпации), пример:
hello,     world.
->
hello, world.
*/

#include "../Library/stringFunctions.h"
#include <stdio.h>

int main(void)
{
	char buff[256] = { 0 };
	io_strEnterMultilineEOF(buff);
	for (int i = 0; buff[i] != '\0'; ++i)
	{
		if ((buff[i] == ' ') && (buff[i + 1] == ' '))
		{
			for (int j = i; buff[j] != '\0'; ++j)
			{
				buff[j] = buff[j + 1];
			}
			i--;
		}
	}
	printf(buff);
	return 0;
}