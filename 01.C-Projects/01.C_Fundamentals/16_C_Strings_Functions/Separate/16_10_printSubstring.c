/*
Напишете функция, която принтира на отделни редове всички подстрингове в подаден стринг,
разделени от символите, подадени във втори стринг.
void print_str_tokens(const char* str, const char * delimiters);
Пример:
print_str_tokens(“hello,hi, bye byee_12-3”, “”);
Резултат:
hello
hi
bye
byee
12-3
*/

#include "../Library/stringFunc.h"
#include <string.h>


void print_str_tokens(const char* str, const char* delimiters);

int main(void)
{
	const char str[] = ",,,hello, hi, bye byee_12-3";
	const char delimiters[] = "_ ,";
	const char* p = str;
	print_str_tokens(p, delimiters);
	return 0;
}

void print_str_tokens(const char* str, const char* delimiters)
{
	const char* subStrStart[20] = { 0 };   // to do: Without pointer arrays!!!
	const char* subStrEnd[20] = { 0 };
	const char* pStr = str;
	int i = 0;
	for (; pStr != '\0'; ++i)
	{
		pStr = string_findSubstringStart(pStr, delimiters);   
		subStrStart[i] = pStr; 
		if (pStr != '\0')
		{
			pStr = string_findSubstringEnd(pStr, delimiters);
			subStrEnd[i] = pStr;
		}
	}
	subStrStart[i] = '\0';
	subStrEnd[i] = '\0';
	int countSubstrings = i - 1;
	for (int j = 0; j < countSubstrings; ++j)
	{
		for (int subSymbol = 0; subStrStart[j] + subSymbol < subStrEnd[j]; ++subSymbol)
		{
			printf("%c", *(subStrStart[j] + subSymbol));
		}
		printf("\n");
	}
}