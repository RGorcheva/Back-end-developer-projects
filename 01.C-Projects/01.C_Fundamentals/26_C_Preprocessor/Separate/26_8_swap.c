/*
Дефинирайте макрос SWAP, който сменя стойностите на две променливи
*/

#include <stdio.h>

#define SWAP(A,B,TYPE) { TYPE TMP; TMP=A; A=B; B=TMP; }

int main(void)
{
	int a = 5;
	int b = 10;
	printf("\na=%d, b=%d", a, b);

	SWAP(a, b, int);

	printf("\na=%d, b=%d", a, b);
	return 0;
}