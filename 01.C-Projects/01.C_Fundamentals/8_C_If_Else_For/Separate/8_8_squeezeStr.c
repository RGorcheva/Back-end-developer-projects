/*
Напишете алтернативна версия на функцията
void squeeze(char s1[], const char s2[]), която премахва всеки символ в
s1[], който съответства на някой от символите в s2.
char str[] = "Hello\n";
squeeze(str, "Hl");
printf("%s", str); // "eo\n"
*/

#include <stdio.h>
#include <string.h>

void squeezeStr(char *s1, size_t sizeS1, const char *s2, const size_t sizeS2);

int main()
{
	char s1[8] = "Hello\\n";
	const char s2[3] = "Hl";
	size_t sizeS1 = sizeof(s1);
	const size_t sizeS2 = sizeof(s2);

	printf("\nS1 Before=\t%s", s1);
	printf("\nS2 =\t\t%s", s2);

	squeezeStr(s1, sizeS1, s2, sizeS2);

	printf("\nS1 After=\t%s", s1);
	return 0;
}

void squeezeStr(char *s1, size_t sizeS1, const char *s2, const size_t sizeS2)
{
	char* k = s2;
	char* i = s1;
	for (k = s2; k < s2 + sizeS2 - 1; ++k)
	{
		char* j = s1;
		for (i = s1; i < s1 + sizeS1 - 1; ++i)
		{
			if (*k != *i)
			{
				*j = *i;
				j++;
			}
		}
		*j = '\0';
	}
}