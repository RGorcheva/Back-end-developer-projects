/*
Довършете задачата за кемперите от миналия път като добавите
променлива, в която да се събират парите, които клиента дължи на компанията.
Принтирайте резултата.Питайте клиента дали иска още налични продукти.
*/

#include <stdio.h>

int main()
{
	int iCount = -1;
	int iCountCaravan = 0;
	int iCountCamper = 0;
	int iPricePerOne = -1;
	int iFinalPrice = 0;
	int iVehicleType = -1;
	char cContinue = '0';
	
	printf("\nHallo! We ofer:\n3 caravans per price of 90\n3 campers per price of 100");

	do
	{
	printf("\nWhat type of vehicle do you need?\nCaravan=1\nCamper=2 ");
	scanf("%d", &iVehicleType);

	printf("\nHow many vehicles do you need? - max 3:");
	scanf("%d", &iCount);
	
	switch (iVehicleType)
	{
	case 1: {iPricePerOne = 90;
		iCountCaravan += iCount; break;}
	case 2: {iPricePerOne = 100;
		iCountCamper += iCount; break;}
	default: printf("\nNo such vehicle!");
	}

	if (iCountCaravan > 3 || iCountCamper > 3)
	{
		printf("\nWe have only 3 vehicles!");
		break;
	}

	iFinalPrice = iFinalPrice + iPricePerOne * iCount;
	printf("\nYour account is: %d", iFinalPrice);

	printf("\nDo you need something else? - Y/N");
	scanf(" %c", &cContinue);
	} while (cContinue == 'y' || cContinue == 'Y');

	return 0;
}