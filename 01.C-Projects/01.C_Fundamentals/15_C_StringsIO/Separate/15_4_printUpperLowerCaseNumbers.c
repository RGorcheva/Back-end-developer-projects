/*
Напишете програма, която моли потребителя да въведе текст на няколко
реда до достигането на EOF. След това принтирайте въведения текст, но
само част от символите му:
● само главните букви от въведения текст
● само малки букви от въведения текст
● само числата от въведения текст
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
		if ('A' <= *p && *p <= 'Z')
		{
			printf("%c", *p);
		}
	}
	printf("\n\n");
	for (char* p = buff; *p != '\0'; ++p)
	{
		if ('a' <= *p && *p <= 'z')
		{
			printf("%c", *p);
		}
	}
	printf("\n\n");
	for (char* p = buff; *p != '\0'; ++p)
	{
		if ('0' <= *p && *p <= '9')
		{
			printf("%c", *p);
		}
	}
	printf("\n");
	return 0;
}