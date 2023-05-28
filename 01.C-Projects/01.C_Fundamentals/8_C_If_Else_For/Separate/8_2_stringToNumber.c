/*
Разширете възможностите на програмата от Задача 1:
Нека низът да може да е число от всяка [2-36]-мерна бройна система(т.е. може да има само
символи, които са цифри и букви)
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

unsigned charToInt2(char a)
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

int main()
{
	char str[]={'0','0','0','0','0','1','z','\0'};
	unsigned uNum = 0;
	unsigned max = 0;
	int size = 0;
	int i = 0;

	max = charToInt2(str[0]);
	while (str[i] != '\0')
	{
		if (charToInt2(str[i]) > max)
		{
			max = charToInt2(str[i]);
		}
		i++;
	}
	
	printf("Number system base %d", max+1);

	size = (int)sizeof(str);
	for (int j = 0; j <= size - 2; j++)
	{
		uNum += charToInt2(str[j]) * (unsigned)pow(max + 1, size - 2 - j);
	}
	printf("\nNumber is %d", uNum);
	return 0;
}