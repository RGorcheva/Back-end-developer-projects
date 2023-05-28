/*
Напишете програма, която отваря три файла едновременно:
● файл с имена, всяко на нов ред ( в режим на четене )
● файл с фамилии, всяка на нов ред ( в режим на четене )
● файл с произволно-генерирани двойки от име + фамилия. ( в режим на
писане )
Програмата трябва да пита потребителя за желан брой нови генерирания
на произволна двойка име-фамилия и за това дали да добави
новогенерираните имена в края на файла или да замести съдържанието
му изцяло.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));
	FILE* inName = 0;
	FILE* inSurname = 0;
	FILE* out = 0;
	if ((inName = fopen("name.txt", "r")) == NULL)
	{
		fprintf(stderr, "Can't open input file name.txt\n");
		exit(EXIT_FAILURE);
	}
	if ((inSurname = fopen("surname.txt", "r")) == NULL)
	{
		fprintf(stderr, "Can't open input file surname.txt\n");
		exit(EXIT_FAILURE);
	}
	//Ако сме стигнали до тук, значи е отворило файловете и създало третия.
	int choiceFileMode = 0;
	do
	{
		printf("\nPress 1 if you want to keep old data in file.");
		printf("\nPress 2 if you want to remove the old data from file.");
		scanf_s("%d", &choiceFileMode);
	} while (choiceFileMode != 1 && choiceFileMode != 2);
	if (choiceFileMode == 1)
	{
		if ((out = fopen("random_names.txt", "a")) == NULL)
		{
			fprintf(stderr, "Can't create output file.\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if ((out = fopen("random_names.txt", "w")) == NULL)
		{
			fprintf(stderr, "Can't create output file.\n");
			exit(EXIT_FAILURE);
		}
	}
	int countCombinations = 0;
	printf("Enter number  of name-surname combinations:");
	scanf_s("%d", &countCombinations);
	for (int it = 0; it < countCombinations; it++)
	{
		char ch = '0';
		int countNewLine = 0;
		rewind(inName);
		while ((ch = getc(inName)) != EOF)
		{
			if (ch == '\n')
			{
				countNewLine++;
			}
		}
		int randName = rand() % countNewLine;
		rewind(inName);
		countNewLine = 0;
		while ((ch = getc(inName)) != EOF)
		{
			if (ch == '\n')
			{
				countNewLine++;
			}
			if ((countNewLine == randName) && isalpha(ch))
			{
				fputc(ch, out);
			}
		}
		fputc(' ', out);
		rewind(inSurname);
		countNewLine = 0;
		while ((ch = getc(inSurname)) != EOF)
		{
			if (ch == '\n')
			{
				countNewLine++;
			}
		}
		int randSurname = rand() % countNewLine;
		rewind(inSurname);
		countNewLine = 0;
		while ((ch = getc(inSurname)) != EOF)
		{
			if (ch == '\n')
			{
				countNewLine++;
			}
			if ((countNewLine == randSurname) && isalpha(ch))
			{
				fputc(ch, out);
			}
		}
		fputc('\n', out);
	}
	if (fclose(inSurname) != 0 || fclose(inName) != 0 || fclose(out) != 0)
		fprintf(stderr, "Error in closing files\n");
	return EXIT_SUCCESS;
}


