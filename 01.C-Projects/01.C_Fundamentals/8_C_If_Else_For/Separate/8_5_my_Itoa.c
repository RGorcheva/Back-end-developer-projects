/*
Използвайте do-while цикъл, за да напишете функцията void itoa(int n, char
s[]), която преобразува число в символен низ (обратната функция на atoi).
do-while цикълът e необходим, тъй като в масива ще трябва да се постави
поне един символ, дори ако n е нула. Ако n = 123, за да вземем последната
цифра, трябва да разделим n по модул(%) на основата на бройната
система 10. За да получите чаръктър число, трябва да съберете резултата
с '0'. За да вземете следващото число, трябва да разделите n на 10. Това
продължава докато n е различно от нула. Това генерира низа в обратен ред
– 321, затова използваме reverse функцията от предходната задача.
*/


#include <stdio.h>
#include <string.h>

void itoa(int iNumber, char str[]);
void reverseString(char arr[]);

int main()
{
	int iNumberToEnter = 1;
	char arrSymbols[10];

	printf("\nEnter a number:");
	scanf("%d", &iNumberToEnter);

	itoa(iNumberToEnter, arrSymbols);
	reverseString(arrSymbols);

	fputs(arrSymbols, stdout);
	return 0;
}

void itoa(int iNumber, char str[])
{
	int i = 0;
	do
	{
		str[i] = iNumber % 10 + '0';
		iNumber /= 10;
		i++;
	} while (iNumber > 0);
	str[i] = '\0';
}

void reverseString(char arr[])
{
	int sizeArr = strlen(arr);
	int i = 0;
	int j = sizeArr - 1;

	for (i = 0, j = sizeArr - 1; i < j; i++, j--)
	{
		arr[i] = arr[i] - arr[j];
		arr[j] = arr[j] + arr[i];
		arr[i] = arr[j] - arr[i];
	}
}