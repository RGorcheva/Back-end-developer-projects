#ifndef MATH2DFUNC_H
#define MATH2DFUNC_H

enum { SIZE_3 = 3, MAX_SIZE_8 = 8 };

struct point2DF
{
	float x;
	float y;
};

struct triangle2DF
{
	struct point2DF point[SIZE_3];
};

struct circle2DF
{
	struct point2DF center;
	float radius;
};

struct rectangle2DF
{ 
	struct point2DF pointA;
	struct point2DF dims;
};

struct polygon2DF
{
	struct point2DF point[MAX_SIZE_8];
	int pointsCount;
};

void math2d_enterPiont(struct point2DF* ptrPoint);
void math2d_printPoint(const struct point2DF* ptrPoint);

void math2d_enterTriangle(struct triangle2DF* ptrTriangle);
void math2d_printTriangle(const struct triangle2DF* ptrTriangle);

void math2d_enterCircle(struct circle2DF* ptrCircle);
void math2d_printCircle(const struct circle2DF* ptrCircle);

void math2d_enterRectangle(struct rectangle2DF* ptrRectangle);
void math2d_printRectangle(const struct rectangle2DF* ptrRectangle);

void math2d_enterPolygon(struct polygon2DF* ptrPolygon);
void math2d_printPolygon(const struct polygon2DF* ptrPolygon);

float math2d_distancePointToPoint(const struct point2DF* ptrPointA, const struct point2DF* ptrPointB);
int math2d_isPointInRectangle(const struct point2DF* ptrPoint, const struct rectangle2DF* ptrRectangl);
int math2d_isPointInCircle(const struct point2DF* ptrPoint, const struct circle2DF* ptrCircle);
int math2d_isCircleInCircle(const struct circle2DF* ptrCircle1, const struct circle2DF* ptrCircle2);

#endif