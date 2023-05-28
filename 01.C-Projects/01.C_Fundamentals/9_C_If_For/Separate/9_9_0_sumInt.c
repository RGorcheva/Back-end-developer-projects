/*
Направете for цикъл, който показва сбора на първите 10 естествени 
числа.
*/

#include <stdio.h>

int main()
{
	int iSum = 0;

	for (int i = 1; i <= 10; i++)
	{
		iSum += i;
	}
	printf("\nSum 1 to 10 = %d", iSum);
	return 0;
}