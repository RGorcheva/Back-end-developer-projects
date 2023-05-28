/*
Напишете глобална променлива, която увеличаваме с 1 във
функция void test(). Извикайте функцията три пъти test() от main() 
принтирайте стойността на глобалната променлива.
*/

#include <stdio.h>

int g_iVar = 0;

void testGlobalVar(void)
{
	g_iVar += 1;
}

int main(void)
{ 
	printf("Enter x = ");
	scanf_s("%d", &g_iVar);

	testGlobalVar();
	printf("\nx = x + 1 = %d", g_iVar);

	testGlobalVar();
	printf("\nx = x + 1 = %d", g_iVar);

	testGlobalVar();
	printf("\nx = x + 1 = %d", g_iVar);
	
	return 0;
}