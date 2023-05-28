/*
#include <stdio.h>
int main() {
int nA = 40; /* използвайте scanf
int nB = 20;
int nX = 20;
int nY = 30;
if (nA > nB && nA != 0) {
	printf("&& Operator : Both conditions are true\n");
}
if (nX > nY || nY != 20) {
	printf("|| Operator : Only one condition is true\n");
}
if (!(nA > nB && nB != 0)) {
	printf(" ! Operator : Both conditions are true\n");
}
else {
	printf("Both conditions are true.\n");
}
}
опитайте различни комбинации
*/

#include <stdio.h>
int main() 
{
	int nA = 40;
	int nB = 20;
	int nX = 20;
	int nY = 30;

	printf("Enter A: ");
	scanf(" %d", &nA);
	printf("Enter B: ");
	scanf(" %d", &nB);
	printf("Enter x: ");
	scanf(" %d", &nX);
	printf("Enter y: ");
	scanf(" %d", &nY);

	if (nA > nB && nA != 0) 
	{
		printf("A>B && A!=0 - && Operator : Both conditions are true\n");
	}
	if (nX > nY || nY != 20) 
	{
		printf("X>Y || Y!=20 - || Operator : One or both conditions are true\n");
	}
	if (!(nA > nB && nB != 0)) 
	{
		printf("A>B && B!=0 - ! One or both conditions are false.\n");
	}
	else 
	{
		printf("A>B && B!=0 - Both conditions are true.\n");
	}
	if (nX == nY || nY == 10)
	{
		printf("X=Y || Y=10 - || Operator : One or both conditions are true\n");
	}
	if (0 < nA && nA < nB)
	{
		printf("0<A && A<B - && Operator : Both conditions are true\n");
	}
	return 0;
}