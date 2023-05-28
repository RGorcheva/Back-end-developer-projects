/* 
Представете си, че имате фирма за отдаване на каравани и кемпери под наем, за 
която трябва да разработите софтуер. 
Имате общо 3 каравани на цена 90 лв. на ден и 3 кемпера на цена 100 лв. на ден. 
Декларирайте променливи за броя на караваните, цената на караваните, броя на 
кемперите и цената им. 
Направете меню, което пита клиента каравана или кемпер ще иска. 
Направете променлива, в която да се събират парите, които клиента дължи на 
компанията. 
Принтирайте резултата. 
*/

#include <stdio.h>

int main()
{
	int iCount = -1;
	int iPrice = -1;
	int iFinalPrice = -1;
	int iVehicle = -1;

	printf("\nHallo! What type of vehicle do you need? - Caravan=1/Camper=2");
	scanf("%d", &iVehicle);

	if (iVehicle == 1) 
	{ 
		iPrice = 90;
	}
	else 
	{ 
		iPrice = 100; 
	}

	printf("\nHow many vehicles do you need? - max 3:");
	scanf("%d", &iCount);

	iFinalPrice = iPrice * iCount;

	printf("\nYour account is: %d", iFinalPrice);

	return 0;
}