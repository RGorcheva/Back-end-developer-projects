/*
Chuckie Lucky won a million dollars, which he places in an account that earns 8% a year.
On the last day of each year, Chuckie withdraws $100,000. Write a program that finds out
how many years it takes for Chuckie to empty his account.
*/

#include <stdio.h>

int main()
{
	const float fFirstInvestment = 1000000.0f;
	float fInvestment = 1000000.0f;
	float fYearInterest = 0.08f;
	float fWiddraw = 100000.0f;
	int iYearCount = 0;

	do
	{
		fInvestment += fFirstInvestment * fYearInterest;
		fInvestment -= fWiddraw;
		iYearCount++;
	} while (fInvestment > 0);

	printf("After %d years Chuckie Lucky will empty his account!", iYearCount);

	return 0;
}