/*
Дефинирайте функция за пресмятането на разстоянието между две точки в равнината.
*/

#include "../Library/math2d.h"
#include <stdio.h>

int main(void)
{
	float distAB = 0;

	struct point2DF pointA;
	struct point2DF* ptrPointA = &pointA;

	struct point2DF pointB;
	struct point2DF* ptrPointB = &pointB;

	math2d_enterPiont(ptrPointA);
	math2d_enterPiont(ptrPointB);

	distAB = math2d_distancePointToPoint(ptrPointA, ptrPointB);
	printf("\nDistAB = %.2f", distAB);
	return 0;
}