/*
Използвайте статична локална променлива, за да постигнете
същото поведение, описано в задача 14.
*/

#include <stdio.h>

int testStaticVar(int iVar)
{
	static int sA = 0;
	sA++;
	return iVar += sA;
}

int main()
{
	int iVar = 0;
	printf("Enter x = ");
	scanf_s("%d", &iVar); 

	printf("\nx = x + 1 = %d", testStaticVar(iVar));
	printf("\nx = x + 1 = %d", testStaticVar(iVar));
	printf("\nx = x + 1 = %d", testStaticVar(iVar));

	return 0;
}