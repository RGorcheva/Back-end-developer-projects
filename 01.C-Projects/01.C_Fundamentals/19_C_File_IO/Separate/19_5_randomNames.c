/*
Напишете алтернативна версия на горната програма, която да приема
входните си данни не от клавиатурата, ами от command-line аргументите
си (от аргументите на на main функцията)
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main(int argc, char* argv[])
{
	srand(time(NULL));
	FILE* inName = 0;
	FILE* inSurname = 0;
	FILE* out = 0;

	if (argc != 4)
	{
		printf("Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	inName = file_open(inName, argv[1], "r");
	inSurname = file_open(inSurname, argv[2], "r");
	int choiceFileMode = 0;
	do
	{
		printf("\nPress 1 if you want to keep old data in file.");
		printf("\nPress 2 if you want to remove the old data from file.");
		scanf_s("%d", &choiceFileMode);
	} while (choiceFileMode != 1 && choiceFileMode != 2);
	if (choiceFileMode == 1)
	{
		out = file_open(out, argv[3], "a");
	}
	else
	{
		out = file_open(out, argv[3], "w");
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