/*
Напишете програма, която преобразува c string литерала в целочислено
число(unsigned int). Низът може да има представка, коята променя типа на литералата:
○ 0b, 0B - binary
○ 0x, 0X - hex
○ 0 - oct*/#include <stdio.h>
#include <string.h>
#include <math.h>

unsigned charToInt(char a);
unsigned maxN(unsigned a, unsigned b);
unsigned maxChar(char* cArr, int k);

int main()
{
	char str[] = { "100007" };
	unsigned uNum = 0;
	unsigned max = 0;
	int size = (int)sizeof(str);
	int i = 0;

	if ((str[0] == '0') && (str[1] == 'b' || str[1] == 'B'))
	{
		max = maxChar(str, 2);
		printf("0b-Number system base %d", maxN(2, max+1));
		for ( i = 2; i <= size - 2; i++)
		{
			uNum += charToInt(str[i]) * (unsigned)pow(maxN(2, max+1), size - i - 2);
		}
	}
	else if ((str[0] == '0') && (str[1] == 'x' || str[1] == 'X'))
	{
		max = maxChar(str, 2);
		printf("0x-Number system base %d", maxN(16, max+1));
		for (i = 2; i <= size - 2; i++)
		{
			uNum += charToInt(str[i]) * (unsigned)pow(maxN(16, max+1), size - 2 - i);
		}
	}
	else if (str[0] == '0')
	{
		max = maxChar(str, 1);
		printf("0-Number system base %d", maxN(8, max+1));
		for (i = 1; i <= size - 2; i++)
		{
			uNum += charToInt(str[i]) * (unsigned)pow(maxN(8, max+1), size - 2 - i);
		}
	}
	else
	{
		max = maxChar(str, 0);
		printf("Number system base %d", max + 1);
		for (i = 0; i <= size - 2; i++)
		{
			uNum += charToInt(str[i]) * (unsigned)pow(max + 1, size - 2 - i);
		}
	}
	printf("\nNumber is %d", uNum);
	return 0;
}


unsigned charToInt(char a)
{
	if ('0' <= a && a <= '9')
	{
		return a = a - 48;
	}
	if ('A' <= a && a <= 'Z')
	{
		return a -= 55;
	}
	if ('a' <= a && a <= 'z')
	{
		return a -= 87;
	}
}


unsigned maxN(unsigned a, unsigned b)
{
	return a >= b ? a : b;
}


unsigned maxChar(char* cArr, int k)
{
	unsigned maxCh = charToInt(cArr[k]);
	while (cArr[k] != '\0')
	{
		if (charToInt(cArr[k]) > maxCh)
		{
			maxCh = charToInt(cArr[k]);
		}
		k++;
	}
	return maxCh;
}