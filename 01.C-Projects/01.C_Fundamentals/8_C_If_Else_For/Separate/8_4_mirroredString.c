/*
Напишете функция, която обръща string наобратно
char str[] = "Hello\n";
reverseString(str); // "\nolleH"
Използвайте единствен for цикъл с две променливи за индексация:
for(i = 0, j = strLength - 1; i < j; i++, j--)
*/

#include <string.h>
#include <stdio.h>

void reverseString(char arr[])
{
	int sizeArr = strlen(arr);
	int i = 0;
	int j = sizeArr - 1;

	for (i = 0,j = sizeArr - 1; i < j; i++,j--)
	{
		arr[i] = arr[i] - arr[j];
		arr[j] = arr[j] + arr[i];
		arr[i] = arr[j] - arr[i];
	}
}

int main()
{
	char str[] = "Hello\\n";
	int sizeStr = strlen(str);

	reverseString(str);

	fputs(str, stdout);
	return 0;
}