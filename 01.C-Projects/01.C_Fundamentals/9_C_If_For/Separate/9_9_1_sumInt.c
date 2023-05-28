/*
Наравете програмата да дава възможност да въведе броя на естествените числа,
чиито сбор показва.
*/

#include <stdio.h>

int main()
{
	int iSum = 0;
	int iN = -1;

	printf("N = ");
	scanf("%d", &iN);

	for (int i = 1; i <= iN; i++)
	{
		iSum += i;
	}
	printf("\nSum 1 to %d = %d", iN, iSum);
	return 0;
}