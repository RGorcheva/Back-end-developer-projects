/*
Write a function that takes three arguments : a character and two integers.
The character is to be printed. The first integer specifies the number of times
that the character is to be printed on a line, and the second integer specifies
the number of lines that are to be printed. Write a program that makes use of this
function.
*/

#include <stdio.h>

void printLetter(char c, int iSymbolPerRow, int iRows)
{
	for (int i = 0; i < iRows; i++)
	{
		for (int j = 0; j < iSymbolPerRow; j++)
		{
			printf("%c", c);
		}
		printf("\n");
	}
}

int main()
{
	char cSymbol = '0';
	int iNumberOfRows = -1;
	int iNumberOfSymbolsPerRow = -1;

	printf("\nEnter a symbol to be print:");
	scanf(" %c", &cSymbol);
	printf("\nEnter number of symbols per row:");
	scanf("%d", &iNumberOfSymbolsPerRow);
	printf("\nEnter number of rows:");
	scanf(" %d", &iNumberOfRows);

	printLetter(cSymbol, iNumberOfSymbolsPerRow, iNumberOfRows);

	return 0;
}