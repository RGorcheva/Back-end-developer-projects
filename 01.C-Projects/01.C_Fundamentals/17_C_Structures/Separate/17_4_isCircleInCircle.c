/*
Дефинирайте функция, която проверява дали два кръга имат допирни точки (не се пресичат и нито единия не е
изцяло във вътрешността на другия)
*/

#include "../Library/math2d.h"
#include <stdio.h>

int main(void)
{
	struct circle2DF circle1;
	struct circle2DF* ptrCircle1 = &circle1;

	struct circle2DF circle2;
	struct circle2DF* ptrCircle2 = &circle2;

	math2d_enterCircle(ptrCircle1);
	math2d_enterCircle(ptrCircle2);

	if (math2d_isCircleInCircle(ptrCircle1, ptrCircle2))
	{
		printf("The circles have points in common!");
	}
	else
	{
		printf("The circles have NOT points in common!");
	}

	return 0;
}