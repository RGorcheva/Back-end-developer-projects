/*
Напишете стандартната програма за Linux: cat, която приема като аргументи от командния ред
имена на файлове и изкарва съдържанието им на стандартния изход. Ако на програмата не са
подадени никакви аргументи, то тя да изкара съдържанието подадено от стандартния вход на
стандартния изход.
*/

#include "../Library/stringFunc.h"
#include "../Library/fileFunc.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	FILE* fp = 0;
	if (argc < 2)
	{
		fprintf(stderr, "%d - Not enough arguments.\n", argc);
		exit(EXIT_FAILURE);
	}
	for (int fileCount = 1; fileCount < argc; fileCount++)
	{
		fp = file_open(fp, argv[fileCount], "r");
		unsigned long countSymbolsInFile = file_countSymbols(fp);
		rewind(fp);
		char ch = '0';
		for (unsigned long count = 1L; count <= countSymbolsInFile; count++)
		{
			ch = getc(fp);
			//for Macintosh:
			if (ch == '\r')
			{
				putchar('\n');
			}
			else
			{
				putchar(ch);
			}
		}
		putchar('\n');
		file_close(fp);
		return EXIT_SUCCESS;
	}
	return 0;
}