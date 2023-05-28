/*
Write a program that converts time in minutes to time in hours and minutes.
Use #define or const to create a symbolic constant for 60.
Use a while loop to allow the user to enter values repeatedly and terminate the loop
if a value for the time of 0 or less is entered.
*/

#include <stdio.h>

int main()
{
	const int iHourToMinutes = 60;
	int iCustomerMinutes = -1;
	int iHours = -1;
	int iMinutes = -1;

	printf("\nEnter number of minutes: ");
	scanf("%d", &iCustomerMinutes);

	while (iCustomerMinutes > 0)
	{
		iHours = iCustomerMinutes / iHourToMinutes;
		iMinutes = iCustomerMinutes % iHourToMinutes;
		printf("In %d minutes has %d hours and %d minutes!", iCustomerMinutes, iHours, iMinutes);

		printf("\nEnter number of minutes: ");
		scanf("%d", &iCustomerMinutes);
	}
	return 0;
}