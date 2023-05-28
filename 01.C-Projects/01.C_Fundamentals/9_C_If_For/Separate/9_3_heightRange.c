/*
Направете С програма, която да пита за ръста на човек и в 
зависимост от въведеното число да ги квалифицира по 
следния начин:
До 145 см включително - нисък ръст
От 146 до 180 - среден ръст;
Над 181 см до 205 см. – висок ръст
Извън тези граници – изключително висок ръст
*/

#include <stdio.h>

int main()
{
	int iYourHeigh = -1;

	printf("\nEnterheight: ");
	scanf_s("%d", &iYourHeigh);

	if (iYourHeigh <= 145)
	{
		printf("\nYou are very short!!!");
	}
	else if (iYourHeigh <= 180)
	{
		printf("\nYou are of average height!!!");
	}
	else if (iYourHeigh <= 205)
	{
		printf("\nYоu are tall!!!");
	}
	else
	{
		printf("\nYоu are very tall!!!");
	}
	return 0;
}