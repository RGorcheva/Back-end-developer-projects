/*
Дефинирайте функции за въвеждане на всяка една от шестте геометрични фигури от потребителя.
Дефинирайте функции всяка за принтиране на всяка една от шестте геометрични фигури.
*/

#include "../Library/math2d.h"

int main(void)
{
	struct point2DF point;
	struct point2DF* ptrPoint = &point;

	struct triangle2DF triangle;
	struct triangle2DF* ptrTriangle = &triangle;

	struct circle2DF circlek;
	struct circle2DF* ptrCircle = &circlek;

	struct rectangle2DF rectangleabcd;
	struct rectangle2DF* ptrRectangle = &rectangleabcd;

	struct polygon2DF polygon;
	struct polygon2DF* ptrPolygon = &polygon;

	math2d_enterPiont(ptrPoint);
	math2d_printPoint(ptrPoint);

	math2d_enterTriangle(ptrTriangle);
	math2d_printTriangle(ptrTriangle);

	math2d_enterCircle(ptrCircle);
	math2d_printCircle(ptrCircle);

	math2d_enterRectangle(ptrRectangle);
	math2d_printRectangle(ptrRectangle);

	math2d_enterPolygon(ptrPolygon);
	math2d_printPolygon(ptrPolygon);

	return 0;
}




