/*
Напишете функцията int find_any(const char s1[], const char s2[]), която
връща първата позиция в низа s1, където се появява някой от
символите в низа s2, или -1 ако не е намерен нито един символ.
// returns 1, as "Hello"[1] == 'e', which is found in "oe"
int index = find_any("Hello", "oe");
if (index >= 0)
//..
*/

#include <stdio.h>
#include <string.h>

int find_any(const char* s1, const size_t sizeS1, const char* s2, const size_t sizeS2);

int main()
{
	const char s1[6] = "Hello";
	const char s2[3] = "oe";
	const size_t sizeS1 = sizeof(s1);
	const size_t sizeS2 = sizeof(s2);

	printf("\nS1 = %s", s1);
	printf("\nS2 = %s", s2);

	printf("\nFirst position of meeting element from 'oe' is %d", find_any(s1, sizeS1, s2, sizeS2));
	return 0;
}

int find_any(const char* s1, const size_t sizeS1, const char* s2, const size_t sizeS2)
{
	char* i = s1;
	char* k = s2;
	for (i = s1; i < s1 + sizeS1 - 1; ++i)
	{
		for (k = s2; k < s2 + sizeS2 - 1; ++k)
		{
			if (*k == *i)
			{
				return (i - s1);
			}
		}
	}
	return -1;
}