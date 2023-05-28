/*
Напишете програма, която отваря файл по зададено име на файл от командния ред и умножава
всяко число, което отркие във файла по две.
*/

#include "../Library/stringFunc.h"
#include "../Library/fileFunc.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char* argv[])
{
	FILE* in = 0;
	if (argc != 2)
	{
		fprintf(stderr, "Wrong number of arguments.\n");
		exit(EXIT_FAILURE);
	}
	in = file_open(in, argv[1], "r");
	char str[256] = { 0 };
	char ch = '0';
	int i = 0;
	while ((ch = getc(in)) != EOF)
	{
		str[i++] = ch;
	}
	str[i] = '\0';
	file_close(in);

	char* pStr = str;
	pStr = string_multipleNumbersBy2(str);

	in = file_open(in, argv[1], "w");
	int strLen = (int)strlen(str);
	for (int i = 0; i < strLen; i++)
	{
		fprintf(in, "%c", str[i]);
	}
	file_close(in);
	return EXIT_SUCCESS;
	return 0;
}