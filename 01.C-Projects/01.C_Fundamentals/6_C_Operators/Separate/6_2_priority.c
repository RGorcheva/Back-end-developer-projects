/*
Какъв ще бъде резултатът в променливата t:
int x = 10;
int y = 10;
int z = 30;
int t = x==y + (z < y) != 20;
*/

#include <stdio.h>

int main()
{
	int x = 10;
	int y = 10;
	int z = 30;

	int t = x == y + (z < y) != 20;

	printf("\nt = %d", t);

	return 0;
}
