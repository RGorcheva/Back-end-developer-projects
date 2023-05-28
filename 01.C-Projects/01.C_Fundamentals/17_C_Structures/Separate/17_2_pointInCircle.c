/*
Дефинирайте функция, която проверява дали точка е във вътрешността на кръг
*/

#include "../Library/math2d.h"
#include <math.h>
#include <stdio.h>

int main(void)
{
	struct point2DF point;
	struct point2DF* ptrPoint = &point;

	struct circle2DF circlek;
	struct circle2DF* ptrCircle = &circlek;

	math2d_enterPiont(ptrPoint);
	math2d_enterCircle(ptrCircle);
	if (math2d_isPointInCircle(ptrPoint, ptrCircle))
	{
		printf("The point is contained within the circle!");
	}
	else
	{
		printf("The point is NOT contained within the circle!");
	}

	return 0;
}