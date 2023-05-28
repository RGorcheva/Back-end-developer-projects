/*
Дефинирайте макрос IS_PALINDROME(num, type), който проверява дали дадено цяло число е палиндром
(първата цифра е равна на последната, втората - на предпоследната и т.н.)
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define IS_PALINDROME(num,type) {\
	char str[10]={'\0'};\
	_itoa(num,str,10);\
	size_t len=strlen(str);\
	int i=0;\
	int count=0;\
	for(; i<(len/2); i=(i+1))\
	{\
		if(str[i]!=str[len-1-i])\
		{\
			count=(count+1);\
			break;\
		}\
	}\
	if(count == 0)\
	{\
		isPalindrome = 1;\
	}\
	else\
	{\
		isPalindrome = 0;\
	}\
}

int main(void)
{
	int a = 12321;
	bool isPalindrome = 0;
	char str[10] = {'\0'};

	IS_PALINDROME(a, int);
	printf("Is %d palindrom: %d", a, isPalindrome);
	return 0;
}