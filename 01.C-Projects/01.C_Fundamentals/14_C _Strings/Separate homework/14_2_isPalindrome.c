/*
Напишете функция, която проверява дали подаденият й стринг е палиндром
(редът на буквите от ляво надясно е същият като от дясно на ляво)
*/

#include "../Library/stringFunctions.h"

int main(void)
{
	char str[] = "rotator";
	if (string_isPalindrome(str))
	{
		printf("\n%s is palindrome!", str);
	}
	else
	{
		printf("\n%s is NOT palindrome!", str);
	}
	return 0;
}

