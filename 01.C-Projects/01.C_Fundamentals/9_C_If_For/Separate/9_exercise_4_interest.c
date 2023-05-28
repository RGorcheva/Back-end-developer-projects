/*
Daphne invests $100 at 10% simple interest. 
(That is, every year, the investment earns an interest equal to 10% of the original investment.)
Deirdre invests $100 at 5% interest compounded annually. 
(That is, interest is 5% of the current balance, including previous addition of interest.) 
Write a program that finds how many years it takes for the value of Deirdre's investment to exceed 
the value of Daphne's investment. Also show the two values at that time.
*/

#include <stdio.h>
int main()
{
	const double fDaphneSympleInterest = 0.1;
	const double fDeirdreCompaundInterest = 0.05;
	const double DaphneFirstInvestment = 100.0;
	double DaphneInvestment = 100.0;
	double DeirdreInvestment = 100.0f;
	int iYearCount = 0;

	do
	{
		DaphneInvestment += DaphneFirstInvestment * fDaphneSympleInterest;
		DeirdreInvestment += DeirdreInvestment * fDeirdreCompaundInterest;
		iYearCount++;
	} while (DaphneInvestment > DeirdreInvestment);

	printf("After %d years: ", iYearCount);
	printf("\nDaphne Investment id increased to %.2lf $", DaphneInvestment);
	printf("\nDeirdre Investment id increased to %.2lf $", DeirdreInvestment);

	return 0; 
}