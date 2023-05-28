/*
Напишете програма, която моли потребителя да въведе текст на няколко
реда до достигането на EOF. След това принтирайте въведения текст, но
само редовете по-дълги от 3 символа.
*/


#include "../Library/stringFunctions.h"
#include <stdio.h>

int main(void)
{
	char buff[256] = { 0 };
	char temp[256] = { 0 };
	int countSymbol = 0;
	io_strEnterMultilineEOF(buff);
	int lenght = strlen(buff);
	int j = 0;
	for (int i = 0; i <= lenght; ++i)
	{
		
		if (buff[i] != '\n')
		{
			temp[j] = buff[i];
			j++;
		}
		if ((buff[i] == '\n') || (buff[i] == '\0'))
		{
			temp[j] = '\0';
			if (strlen(temp) >= 3)
			{
				printf(temp);
				printf("\n");
			}
			j = 0;
		}
		
	}
	return 0;
}