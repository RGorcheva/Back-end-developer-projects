/*
Напишете собствена версия на стандартната функция strcpy от string.h със
същия интерфейс и функционалност.
char* my_strcpy(char* dest, const char* src);
Връща адреса на главния стринг, в който се копира друг стринг.
*/

#include "../Library/stringFunctions.h"
#include <string.h>

int main(void) 
{
	const char strFrom[20] = "ab";
	char strTo[20] = "abcde";
	string_strcopy(strTo, strFrom);	
	puts(strTo);
	printf("------------------\n");
	const char strFrom1[20] = "ab";
	char strTo1[20] = "abcde";
	strcpy(strTo1, strFrom1);
	puts(strTo1);

	return 0;
}