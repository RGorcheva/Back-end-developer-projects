/*
Направете програма, която при въвеждане на месец от годината 
като число извежда на екран колко дни има в месеца - “Посочения 
месец има ... дни). 
*/

#include <stdio.h>

int main()
{
	int iMonth = -1;

	printf("\nPlease, enter a month from 1 to 12:");
	scanf("%d", &iMonth);

	switch (iMonth)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			printf("\nThe month has 31 days!");
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			printf("\nThe month has 30 days!");
			break;
		case 2:
			printf("\nThe month has 28 or 29 days!");
			break;
		default:
			printf("\nNo such month!");
			break;
	}
	return 0;
}