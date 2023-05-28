/*
Трябва да направите софтуер за заявки на хотел. Хотела има два 
типа стаи - Луксозна, с цена 180 лв на нощ, Стандартна -120 лв на 
нощ. Туристическият данък е 6%. Направете програма, която 
калкулира очаквана себестойност за клиентите в зависимост от брой 
нощувки и стаи, и я отпечатва на екрана. Валидността на офертата е 
14 дни.
*/

#include <stdio.h>

int main()
{
	int iTouristRoomChoice = -1;
	int iNumberOvernights = -1;
	int iPricePerNight = -1;
	int iCountNights = -1;
	int iTouristAccount = 0;
	int iCountTouristAccounts = 0;
	int iHotelProfit = 0;
	double dFinalHotelProfit = 0.0;
	char cContinue = '0';
	const double dTouristTax = 0.06;
	double dFinalHotelTouristTax = -1.0;

	do
	{
		printf("\nTypes of rooms:");
		printf("\n1.Standart room - 120 BGN per night");
		printf("\n2. Luxury room - 180 BGN per night");
		printf("\nPlease enter tourist chiose 1 or 2: ");
		scanf("%d", &iTouristRoomChoice);
		printf("\nPlease enter nubers of overnight stay: ");
		scanf("%d", &iNumberOvernights);

		switch(iTouristRoomChoice)
		{
		case 1:
			iPricePerNight = 120;
			break;
		case 2:
			iPricePerNight = 180;
			break;
		default:
			printf("\nNo such room!");
			break;
		};

		iTouristAccount = iNumberOvernights * iPricePerNight;
		printf("\nTourist account will be %d BGN.", iTouristAccount);
		printf("\nThe offer is valid for 14 days!");

		iHotelProfit += iTouristAccount;
		printf("\nWould you like to enter new offer? y/n");
		scanf(" %c", &cContinue);

	} while (cContinue == 'y' || cContinue == 'Y');

	dFinalHotelTouristTax = iHotelProfit * dTouristTax;
	dFinalHotelProfit = iHotelProfit - dFinalHotelTouristTax;

	printf("\nProfit for the hotel: %d BGN", iHotelProfit);
	printf("\nTourist tax for the hotel 6 percent: %.2lf BGN", dFinalHotelTouristTax);
	printf("\nFinal profit for the hotel: %.2lf BGN", dFinalHotelProfit);

	return 0;
}