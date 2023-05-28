/*
В C няма оператор за намиране на факториел (n!), но можем да си напишем функция:
int factorial(int)
// factorial(5) == 5 * 4 * 3 * 2 * 1
// factorial(n) == n * (n - 1) * .. * 2 * 1
Направете я по два начина:
● Рекурсивно - функцията сама да вика себе си с различни стойности на аргументите и да има
условие за излизане от безкрайна рекурсия
*/

#include <stdio.h>

long long int factoriel_recurs(int n);

int main()
{
	long long int iN = -1;

	printf("\nEnter n: ");
	scanf_s("%d", &iN);

	printf("\n%d! = %d", iN, factoriel_recurs(iN));
	return 0;
}

long long int factoriel_recurs(int n)
{
	if (n > 1)
	{
		return n * factorial(n - 1);
	}
	else
	{
		return 1;
	}
}