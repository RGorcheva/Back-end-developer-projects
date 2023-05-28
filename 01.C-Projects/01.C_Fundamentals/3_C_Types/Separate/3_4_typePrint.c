/* 
Дефинирайте променливи със стойности:
-127, 
255, 
63 498, 
4 294 967 292, 
-9 000 000 000 000 775 845.
Изведете всяка променлива на екрана със printf() 
*/

#include <stdio.h>

int main()
{
	char c1 = -127;
	unsigned char c2 = 255;
	int i1 = 63498;
	long long int i2 = 4294967292;
	signed long long int i3 = -9000000000000775845;

	printf("\nchar: %d", c1);
	printf("\nunsigned char: %d", c2);
	printf("\nint: %d", i1);
	printf("\nlong long int: %lli", i2);
	printf("\nsigned long long int: %lli", i3);

	return 0;
}


