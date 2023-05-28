/*
Декларирайте и дефинирайте рекурсивна функция 
int sum_all(int n), 
която да връща сумата на всички цели числа от 0 до стойността на аргумента, 
който й е подаден.*/#include <stdio.h>

int sum_all(int n);

int main()
{
	int iN = -1;

	printf("N = ");
	scanf("%d", &iN);
	
	printf("\nSum 1 to %d = %d", iN, sum_all(iN));
	return 0;
}

int sum_all(int n)
{
	if (n > 0)
	{
		return n += sum_all(n - 1);
	}
	else
	{
		return n;
	}
}