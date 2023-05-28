/*
В C няма оператор за намиране на факториел (n!), но можем да си напишем функция:
int factorial(int)
// factorial(5) == 5 * 4 * 3 * 2 * 1
// factorial(n) == n * (n - 1) * .. * 2 * 1
Направете я по два начина:
● Итеративно - с цикъл
*/

#include <stdio.h>

unsigned long long myMath_factorial(int n);

int main()
{
	unsigned long long iN = 1;

	printf("\nEnter n: ");
	scanf("%d", &iN);

	printf("\n%d! = %llu", iN, myMath_factorial(iN));
	printf("\n%d! = %llu", 25, myMath_factorial(25llu));
	printf("\n%d! = %llu", 30, myMath_factorial(30llu));
	printf("\n%d! = %llu", 31, myMath_factorial(31));
	printf("\n%d! = %llu", 32, myMath_factorial(32));
	printf("\n%d! = %llu", 49, myMath_factorial(49));
	return 0;
}

unsigned long long myMath_factorial(unsigned long long n)
{
	unsigned long long fact = 1;
	for (int i = 1; i <= n; i++)
	{
		fact *= i;
	}
	return fact;
}