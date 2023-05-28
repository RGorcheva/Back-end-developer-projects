#include "fileFunc.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>


int				file_countRows(FILE* pFile)
{
	char ch = '0';
	int countNewLine = 0;
	while ((ch = getc(pFile)) != EOF)
	{
		if (ch == '\n')
		{
			countNewLine++;
		}
	}
	//rewind(pFile);
	//ch = getc(pFile);
	//if (ch == '\n')
	//{
	//	--countNewLine;
	//}
	return countNewLine;
}
unsigned long 	file_countSymbols(FILE* pFile)
{
	char ch = '0';
	unsigned long  countSymbols = 0;
	while ((ch = getc(pFile)) != EOF)
	{
		countSymbols++;
	}
	return countSymbols;
}
int				file_countWords(FILE* pFile)
{
	int numLettersInWord = 0;
	int numWords = 0;
	char ch = '0';
	int countSymbols = 0;
	while ((ch = getc(pFile)) != EOF)
	{
		if (isalpha(ch))
		{
			if (numLettersInWord == 0)
			{
				++numWords;
			}
			++numLettersInWord;
		}
		else
		{
			numLettersInWord = 0;
		}
	}
	return numWords;
}

FILE*			file_open(FILE* pFile, const char* pFileName, char* mode)
{
	if ((pFile = fopen(pFileName, mode)) == NULL)
	{
		fprintf(stderr, "Can't create output file.\n");
		exit(EXIT_FAILURE);
	}
	return pFile;
}
void			file_close(FILE* pFile)
{
	if (fclose(pFile) != 0)
		fprintf(stderr, "Error in closing file\n");
}

FILE*			int_deserilization(FILE* in, int* pCount)
{
	int ifscan = fscanf(in, "(%d)\n", pCount);
	return in;
}
FILE*			int_serilization(FILE* out, int* pCount)
{
	fprintf(out, "(%d)\n", *pCount);
	return out;
}
FILE*			double_deserilization(FILE* in, double* pCount)
{
	int ifscan = fscanf(in, "(%lf)\n", pCount);
	return in;
}
FILE*			double_serilization(FILE* out, double* pCount)
{
	fprintf(out, "(%lf)\n", *pCount);
	return out;
}