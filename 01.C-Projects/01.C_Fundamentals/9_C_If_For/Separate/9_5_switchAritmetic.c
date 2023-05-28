/*
Създайте програма, която подканя човека да въведе проста 
аритметична операция с две числа от екрана - събиране, изваждане, 
деление, умножение и отпечатва резултата.
*/

#include <stdio.h>

int main()
{
	float fA = -1.0f;
	float fB = -1.0f;
	char cOperator = '0';

	printf("\nEnter float A:");
	scanf("%f", &fA);

	printf("\nEnter float B:");
	scanf("%f", &fB);

	printf("\nEnter operator:");
	scanf(" %c", &cOperator);

	switch (cOperator)
	{
	case '+':
		printf("A + B = %.2f + %.2f = %.2f", fA, fB, fA + fB);
		break;
	case '-':
		printf("A - B = %.2f - %.2f = %.2f", fA, fB, fA - fB);
		break;
	case '*':
		printf("A * B = %.2f * %.2f = %.2f", fA, fB, fA * fB);
		break;
	case '/':
		printf("A / B = %.2f / %.2f= %.2f", fA, fB, fA / fB);
		break;
	}
	return 0;
}