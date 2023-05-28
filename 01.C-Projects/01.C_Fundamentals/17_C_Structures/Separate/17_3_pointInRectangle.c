/*
Дефинирайте функция, която проверява дали точка е във вътрешността на правоъгълник (aabb)
*/

#include "../Library/math2d.h"
#include <math.h>
#include <stdio.h>


int main(void)
{
	struct point2DF point;
	struct point2DF* ptrPoint = &point;

	struct rectangle2DF rectangle;
	struct rectangle2DF* ptrRectangle = &rectangle;

	math2d_enterPiont(ptrPoint);
	math2d_enterRectangle(ptrRectangle);
	if (math2d_isPointInRectangle(ptrPoint, ptrRectangle))
	{
		printf("The point is contained within the rectangle!");
	}
	else
	{
		printf("The point is NOT contained within the rectangle!");
	}
	return 0;
}

