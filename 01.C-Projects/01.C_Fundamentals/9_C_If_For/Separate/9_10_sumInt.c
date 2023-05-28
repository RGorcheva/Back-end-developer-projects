/*
Направете С програма, която калкулира сбора на първите 10 числа, използвайки while.
*/

#include <stdio.h>

int main()
{
	int iSum = 0;
	int i = 1;

	while (i<=10)
	{
		iSum += i; 
		i++;
	}
	printf("\nSum 1 to 10 = %d", iSum);
	return 0;
}