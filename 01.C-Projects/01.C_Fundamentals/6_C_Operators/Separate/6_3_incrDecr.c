#include <stdio.h>

int main()
{
	int i = 0;
	int j = i++;
	printf("\ni=%d, j=%d", i, j);
	j = ++i;
	printf("\ni=%d, j=%d", i, j);
	j = i--;
	printf("\ni=%d, j=%d", i, j);

	return 0;
}