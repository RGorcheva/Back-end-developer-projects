/*
Напишете програма, която принтира статистики за текст от файл. Програмата трябва да работи със
следните command-line аргументи
● първи аргумент(задължителен): име на файл, който да прочете
● от 0 до 3 аргумента за това каква информация да изведе програмата
○ брой символи - ако има аргумент “-c”
○ брой думи - “-w”
○ брой редове - “-l”
○ Ако не е подаден нито един от трите аргумента, да принтира само броя думи във файла
Направете програмата да пише в stderr при грешки или невалидни аргументи.
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
	if (argc < 2)
	{
		fprintf(stderr, "%d - Not enough arguments.\n", argc);
		exit(EXIT_FAILURE);
	}
	in = file_open(in, argv[1], "r");
	_Bool isPrinted = 0;
	for (int i = 0; i < argc; i++)
	{
		if (!strcmp(argv[i], "-c"))
		{
			rewind(in);
			printf("\nSymbols in text: %lu", file_countSymbols(in));
			isPrinted = 1;
		}
		if (!strcmp(argv[i], "-l"))
		{
			rewind(in);
			printf("\nRows in text: %d", file_countRows(in));
			isPrinted = 1;
		}
		if (!strcmp(argv[i], "-w"))
		{
			rewind(in);
			printf("\nWords in text: %d", file_countWords(in));
			isPrinted = 1;
		}
	}
	if (isPrinted == 0)
	{
		rewind(in);
		printf("\nWords in text: %d", file_countWords(in));
	}
	file_close(in);
	return EXIT_SUCCESS;
	return 0;
}
