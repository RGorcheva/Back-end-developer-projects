/*
#include <stdio.h>
int main() {
 int nX = 33; /* homework, input with scanf
int nY = 20;
if (nX == nY) {
	printf("%d and %d are equal\n", nX, nY);
}
else {
	printf("%d and %d are not equal\n", nX, nY);
}
if (nX > nY) {
	printf("%d is greater than %d\n", nX, nY);
}
} /* използвайте и останалите оператори за сравнение 
*/

#include <stdio.h>

int main() 
{
	int nX = 33; 
	int nY = 20;

	printf("Enter x: ");
	scanf(" %d", &nX);
	printf("Enter y: ");
	scanf(" %d", &nY);

    if (nX == nY) 
	{
	   printf("%d and %d are equal\n", nX, nY);
    }
	if (nX != nY)
	{
	   printf("%d and %d are not equal\n", nX, nY);
    }
    if (nX > nY) 
	{
	   printf("%d is greater than %d\n", nX, nY);
    }
	if (nX < nY)
	{
		printf("%d is smaller than %d\n", nX, nY);
	}
	if (nX >= nY)
	{
		printf("%d is equal or greater than %d\n", nX, nY);
	}
	if (nX <= nY)
	{
		printf("%d is equal or smaller than %d\n", nX, nY);
	}
	return 0;
}