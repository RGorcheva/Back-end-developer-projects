/* 
Дефинирайте променливи със стойност 
24 212, 
-1 357 674, 
1 357 674, 
-1 357 674 000, 
3 657 895 000.
Изведете всяка променлива на екрана със printf(). 
*/

#include <stdio.h>

int main()
{
	short int i1 = 24212;
	int i2 = -1357674;
	int i3 = 1357674;
	long int i4 = -1357674000;
	long long int i5 = 3657895000;

	printf("\nshort int: %hd", i1);
	printf("\nint: %d", i2);
	printf("\nint: %d", i3);
	printf("\nlong int: %li", i4);
	printf("\nlong long int: %lli", i5);

	return 0;
}