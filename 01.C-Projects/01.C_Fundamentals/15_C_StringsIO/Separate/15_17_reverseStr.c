/*
 Напишете функция void reverse(char s[]), която обръща
низа char s[].
*/

#include "../Library/stringFunctions.h"

int main(void)
{
	char s[] = "That's what!";
	string_reverse(s);
	printf("\nReversed:\n%s", s);
	return 0;
}