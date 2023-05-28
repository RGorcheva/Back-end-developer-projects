/*
Ако имаме символен низ от символа char str[] = “Hello”; 
копирайте всеки един от неговите символи в низ, който да изглежда
огледален на него. Ето така char rts[] = “ollеH”; и принтирайте
резултата.
*/

#include <stdio.h>
#include <string.h>

int main()
{
	char str[10] = "Hello";
	int sizeStr = strlen(str);
	char rts[10];
	int i = 0;

	for (i = 0; i < sizeStr; i++)
	{
		rts[i] = str[sizeStr - 1 - i];
	}
	rts[sizeStr] = str[sizeStr];

	for (i = 0; i < sizeStr; i++)
	{
		printf("%c", rts[i]);
	}
	printf("\n%d", sizeStr);

	return 0;
}