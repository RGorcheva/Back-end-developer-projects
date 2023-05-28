/*
Аритметични оператори
#include <stdio.h>
int main()
{
	int iX = 13;
	int iY = 44;
	int iResult = 0;
	iResult = iX - iY;
	printf("%d - %d = %d \n", iX, iY, iResult);
	iResult = iY / iX;
	printf("%d / %d = %d \n", iY, iX, iResult);
	iResult = iY % iX;
	printf("%d / %d Remainder: %d\n", iY, iX, iResult);
	return 0;
}
homework: examples for '*' и '+', float - използвайте вместо int
*/

#include <stdio.h>

int main()
{
	int iX = 13;
	int iY = 44;
	int iResult = 0;

	float fX = 13.0f;
	float fY = 44.0f;
	float fResult = 0.0f;

	iResult = iX - iY;
	printf("%d - %d = %d \n", iX, iY, iResult);
	iResult = iY + iX;
	printf("%d + %d = %d\n", iY, iX, iResult);
	iResult = iY * iX;
	printf("%d * %d = %d\n", iY, iX, iResult);
	iResult = iY / iX;
	printf("%d / %d = %d \n", iY, iX, iResult);
	iResult = iY % iX;
	printf("%d / %d Remainder: %d\n", iY, iX, iResult);

	fResult = fX - fY;
	printf("%f - %f = %f \n", fX, fY, fResult);
	fResult = fY + fX;
	printf("%f + %f = %f\n", fY, fX, fResult);
	fResult = fY * fX;
	printf("%f * %f = %f\n", fY, fX, fResult);
	fResult = fY / fX;
	printf("%f / %f = %f \n", fY, fX, fResult);
	fResult = (float)(iY % iX);
	printf("%f / %f Remainder: %f\n", fY, fX, fResult);

	return 0;
}