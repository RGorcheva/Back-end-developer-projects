#include "inputOutputFunc.h"
#include "stringFunc.h"
#include <stdio.h>
#include <string.h>

void	io_arrEnter(char* arrName, int* arr, int sizeArr)
{
	for (int* i = arr; i < arr + sizeArr; ++i)
	{
		printf("%s[%lld]=", arrName, i - arr);
		scanf_s("\n%d", i);
	}
	printf("\n");
}
void	io_arrPrintName(char* arrName, int* arr, int sizeArr)
{

	for (int* i = arr; i < arr + sizeArr; ++i)
	{
		printf("%s[%lld]=%d\n", arrName, i - arr, *i);
	}
	printf("\n");
}
void	io_arrPrint(int* arr, int sizeArr)
{

	for (int* i = arr; i < arr + sizeArr; ++i)
	{
		printf("%d\n", *i);
	}
	printf("\n");
}
void	io_arrPrintSquareScopes(char* arrName, int* arr, int sizeArr)
{
	printf("%s=", arrName);
	for (int* i = arr; i < arr + sizeArr; ++i)
	{
		printf("[%d]", *i);
	}
	printf("\n");
}
void	io_arrPrintBackwards(char* arrName, int* arr, int sizeArr)
{

	for (int* i = arr + sizeArr - 1; i >= arr; --i)
	{
		printf("%s[%lld]=%d\n", arrName, i - arr, *i);
	}
	printf("\n");
}

int		io_intEnter(char* str)
{
	int i = 0;
	printf("Enter %s:", str);
	scanf_s("%d", &i);
	return i;
} 
void	io_intPrint(char* str, int i)
{
	printf("\n%s=%d", str, i);
}

char*	io_strEnter(char* str, int strMaxSize)
{
	setbuf(stdin, NULL);
	fgets(str, strMaxSize, stdin);
	char* p = 0;
	p = string_strchrFindFirstChar(str, '\n');
	*p = '\0';
	return str;
}
void	io_strEnterMultilineEOF(char* str)
{
	char c = 0;
	*str = getchar();
	for (int i = 1; str[i - 1] != EOF; ++i)
	{
		str[i] = getchar();
	}
	str[strlen(str) - 2] = '\0';
}
void	io_strPrintInCol(char* s)
{
	char* c = s;
	while (*c != '\0')
	{
		putchar(*c);
		putchar('\n');
		++c;
	}
}
void	io_strPrintInRow(char* s)
{
	char* c = s;
	while (*c != '\0')
	{
		putchar(*c);
		++c;
	}
	putchar('\n');
}
void	io_strPrintBackwords(const char* str)
{
	int lenght = (int)strlen(str);
	for (const char* p = str + lenght - 1; p >= str; --p)
	{
		printf("%c", *p);
	}
}
void	io_strPrintRowsBackwards(const char* str)
{
	int lenght = (int)strlen(str);
	for (const char* p = str + lenght - 1; p >= str; --p)
	{
		if (p == str)
		{
			const char* q = 0;
			for (q = p; (*q != '\0') && (*q != '\n'); ++q)
			{
				printf("%c", *q);
			}
			printf("%c", '\n');
		}
		else if (*p == '\n')
		{
			const char* q = 0;
			for (q = p + 1; (*q != '\0') && (*q != '\n'); ++q)
			{
				printf("%c", *q);
			}
			printf("%c", '\n');
		}
	}
}
void	io_strPrintBackwardsEveryRow(const char* str)
{
	int lenght = (int)strlen(str);
	for (const char* pEnd = str; pEnd <= str + lenght; ++pEnd)
	{
		if ((*pEnd == '\n') || (*pEnd == '\0'))
		{
			for (const char* pBegin = pEnd - 1; ((*pBegin != '\n') && (pBegin >= str)); --pBegin)
			{
				printf("%c", *pBegin);
			}
			printf("%c", '\n');
		}
	}
}

void	io_matrixIntEnter(const int* arr, int rows, int cols)
 {
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			printf("[%d][%d]=", i, j);
			scanf_s("%d", (int*)&arr[i * cols + j]);
		}
	}
	printf("\n");
}
void	io_matrixIntPrint(const int* arr, int rows, int cols)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			printf("%d\t", arr[i * cols + j]);
		}
		printf("\n");
	}
}
void	io_matrixIntEnterFixCols(int(*arr)[COLS_4], int rows)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < COLS_4; ++j)
		{
			printf("[%d][%d] =", i, j);
			scanf_s("%d", &arr[i][j]);
		}
	}
	printf("\n");
}
void	io_matrixIntPrintFixCols(const int(*arr)[COLS_4], int rows)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < COLS_4; ++j)
		{
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void	io_matrixDoubleEnter(double* arr, int rows, int cols)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			printf("[%d][%d]=", i, j);
			scanf_s(" %lf", &arr[i * cols + j]);
		}
	}
	printf("\n");
}
void	io_matrixDoublePrint(const double* arr, int rows, int columns)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			printf("%.2lf\t", arr[i * columns + j]);
		}
		printf("\n");
	}
	printf("\n");
}
void	io_matrixDoubleEnterFixCols(double(*arr)[COLS_4], int rows)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < COLS_4; ++j)
		{
			printf("[%d][%d] =", i, j);
			scanf_s("%lf", &(*(*(arr + i) + j)));
		}
	}
}
void	io_matrixDoublePrintFixCols(const double(*arr)[COLS_4], int rows)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < COLS_4; ++j)
		{
			printf("%.2lf\t", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void	io_matrixCharEnter(char* arr, int rows, int cols)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			printf("[%d][%d]=", i, j);
			scanf_s("%c", &arr[i * cols + j], 1);
		}
	}
	printf("\n");
}
void	io_matrixCharPrint(const char* arr, int rows, int cols)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			printf("%c\t", arr[i * cols + j]);
		}
		printf("\n");
	}
}



