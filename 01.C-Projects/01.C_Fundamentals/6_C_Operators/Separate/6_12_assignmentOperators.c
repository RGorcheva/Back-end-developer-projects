/*
# include <stdio.h>
int main() {
int nResult = 13; /* опитайте с други стойности
int nX = 4;
printf("Result = %d\n", nResult);
nResult += nX;
printf("Result += %d -> %d\n", nX, nResult);
nResult = 1;
nResult <<= nX;
printf("Result <<= %d -> %d\n", nX, nResult);
} /* използвайте и други оператори за присвояване */#include <stdio.h>
int main() 
{
	int nResult = 15;
	int nX = 5;

	printf("Result = %d\n", nResult);
	nResult += nX;
	printf("Result += %d -> %d\n", nX, nResult);
	nResult -= nX;
	printf("Result -= %d -> %d\n", nX, nResult);
	nResult *= nX;
	printf("Result *= %d -> %d\n", nX, nResult);
	nResult /= nX;
	printf("Result /= %d -> %d\n", nX, nResult);
	nResult++;
	printf("Result++ = %d\n", nResult);
	++nResult;
	printf("++Result = %d\n", nResult);
	nResult = 1;
	nResult <<= nX;
	printf("Result <<= %d -> %d\n", nX, nResult);
	return 0;
}