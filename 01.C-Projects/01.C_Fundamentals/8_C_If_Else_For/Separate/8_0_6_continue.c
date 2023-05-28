/*
Ползвайки continue, oбходете масив от числа и изведете:
● броя на положителните числа
● броя на положителните четни числа
● всяко четно число по-голямо от 100
*/

#include <stdio.h>

int main()
{
	int arr[10];
	int size = 10;
	int i = 0;
	int iCountPozitive = 0;
	int iCountPozitiveEnum = 0;
	int iCountPozitiveEnum100 = 0;

	for (i = 0; i < size; i++)
	{
		printf("\narr[%d]=", i);
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < size; i++)
	{
		if (arr[i] > 0 && arr[i] % 2 == 0 && arr[i] > 100)
		{
			iCountPozitive += 1;
			continue;
		}
		if (arr[i] > 0 && arr[i] % 2 == 0)
		{
			iCountPozitiveEnum += 1;
			continue;
		}
		if (arr[i] > 0)
		{
			iCountPozitiveEnum100 += 1;
		}

	}		
		printf("\nPozitive\t\t  %d", iCountPozitive);
		printf("\nPozitive Enum\t\t  %d", iCountPozitiveEnum);
		printf("\nPozitive Enum > 100\t  %d", iCountPozitiveEnum100);

	return 0;
}
