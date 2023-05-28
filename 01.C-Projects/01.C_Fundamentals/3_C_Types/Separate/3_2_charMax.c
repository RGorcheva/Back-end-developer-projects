/*
Използвайте израз който да направи така че unsigned char да прехвърли
максималната си стойност.Изведете резултата преди и след това.
Направете същото със signed char.
*/

#include <stdio.h>
#include <limits.h>

int main()
{
	printf("%d\n", (unsigned char)UCHAR_MAX);
	printf("%d\n", (unsigned char)(UCHAR_MAX + 1));

	printf("%d\n", (signed char)SCHAR_MAX);
	printf("%d\n", (signed char)(SCHAR_MAX + 1));

	return 0;
}