/*
Напишете програма, която моли потребителя да въведе текст на няколко
реда до достигането на EOF. След това принтирайте средната дължина
на всички думи от текста (пунктуация и whitespace не е част от думите)
*/

#include "../Library/stringFunctions.h"
#include <stdio.h>

int main(void)
{
	char buff[256] = { 0 };

	int countletters = 0;
	int iNumberOfWords = 0;
	float averageLettersInWord = 0;
	io_strEnterMultilineEOF(buff);
	printf(buff);
	for (const char* p = buff; *p != '\0'; ++p)
	{
		if (('a' <= *p && *p <= 'z') || ('A' <= *p && *p <= 'Z'))
		{
			++countletters;
		}
	}
	iNumberOfWords = string_countWords(buff);
	printf("\nNumbers ofwords: %d", iNumberOfWords);
	averageLettersInWord = (float)countletters / (float)iNumberOfWords;
	printf("\nAverage numbers of symbols in word: %.1f", averageLettersInWord);
	return 0;
}