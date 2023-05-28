/*
Напишете програма, която преобразува string в целочислено число(unsigned int). Низът
може да е число от всяка [2-10]-мерна бройна система(т.е. може да има само символи,
които са цифри)
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

unsigned charToInt(char a)
{
	if ('0' <= a && a <= '9')
	{
		return a - 48;
	}
}

int main()
{
	char str[] = { '0','0','0','0','0','1','8','\0' };
	unsigned uNum = 0;
	unsigned max = 0;
	int size = 0;
	int i = 0;

	max = charToInt(str[0]);
	while (str[i] != '\0')
	{
		if (charToInt(str[i]) > max)
		{
			max = charToInt(str[i]);
		}
		i++;
	}

	printf("Number system base %d", max + 1);

	size = (int)sizeof(str);
	for (int j = 0; j <= size - 2; j++)
	{
		uNum += charToInt(str[j]) * (unsigned)pow(max + 1, size - 2 - j);
	}
	printf("\nNumber is %d", uNum);
	return 0;
}