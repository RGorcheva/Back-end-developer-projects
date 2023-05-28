#include "math2dFunc.h"
#include <stdio.h>
#include <stdio.h>
#include <math.h>

void math2d_enterPiont(struct point2DF* ptrPoint)
{
	printf("\nEnter point coordinates:\nx=");
	scanf_s("%f", &ptrPoint->x);
	printf("\ny=");
	scanf_s("%f", &ptrPoint->y);
}
void math2d_printPoint(const struct point2DF* ptrPoint)
{
	printf("Point (x,y) = (%.2f, %.2f)", ptrPoint->x, ptrPoint->y);
}

void math2d_enterTriangle(struct triangle2DF* ptrTriangle)
{
	for (int i = 0; i < SIZE_3; i++)
	{
		printf("\nEnter coordinates of point %d:", i);
		printf("\nx%d=", i);
		scanf_s("%f", &(ptrTriangle->point[i].x));
		printf("\ny%d=", i);
		scanf_s("%f", &(ptrTriangle->point[i].y));
	}
}
void math2d_printTriangle(const struct triangle2DF* ptrTriangle)
{
	printf("\nTriangle:");
	for (int i = 0; i < SIZE_3; i++)
	{
		printf("\nPoint%d (x%d,y%d) = (%.2f, %.2f)", i, i, i, ptrTriangle->point[i].x, ptrTriangle->point[i].y);
	}
}

void math2d_enterCircle(struct circle2DF* ptrcircle)
{
	printf("\nEnter coordinates of circle center:\nx=");
	scanf_s("%f", &(ptrcircle->center.x));
	printf("\ny=");
	scanf_s("%f", &(ptrcircle->center.y));
	printf("\nEnter circle radius:\nr=");
	scanf_s("%f", &(ptrcircle->radius));
}
void math2d_printCircle(const struct circle2DF* ptrcircle)
{
	printf("\nCircle:");
	printf("\nCenter (%.2f, %.2f)", ptrcircle->center.x, ptrcircle->center.y);
	printf("\nRadius = %.2f", ptrcircle->radius);
}

void math2d_enterRectangle(struct rectangle2DF* ptrRectangle)
{
	printf("\nEnter coordinates of lower left point of rectangle:\nx=");
	scanf_s("%f", &(ptrRectangle->pointA.x));
	printf("\ny=");
	scanf_s("%f", &(ptrRectangle->pointA.y));
	printf("\nEnter dimensions of rectangle:\na=");
	scanf_s("%f", &(ptrRectangle->dims.x));
	printf("\nb=");
	scanf_s("%f", &(ptrRectangle->dims.y));
}
void math2d_printRectangle(const struct rectangle2DF* ptrRectangle)
{
	printf("\nRectangle:\nPointA (%.2f, %.2f)", ptrRectangle->pointA.x, ptrRectangle->pointA.y);
	printf("\nDimensions a = %.2f , b = %.2f", ptrRectangle->dims.x, ptrRectangle->dims.y);
}

void math2d_enterPolygon(struct polygon2DF* ptrPolygon)
{
	printf("\nEnter number of points:");
	scanf_s("%d", &(ptrPolygon->pointsCount));
	for (int i = 0; i < ptrPolygon->pointsCount; i++)
	{
		printf("\nEnter coordinates of point %d:", i);
		printf("\nx%d=", i);
		scanf_s("%f", &(ptrPolygon->point[i].x));
		printf("\ny%d=", i);
		scanf_s("%f", &(ptrPolygon->point[i].y));
	}
}
void math2d_printPolygon(const struct polygon2DF* ptrPolygon)
{
	printf("\nPolygon:");
		for (int i = 0; i < ptrPolygon->pointsCount; i++)
		{
			printf("\nPoint%d (x%d,y%d) = (%.2f, %.2f)", i, i, i, ptrPolygon->point[i].x, ptrPolygon->point[i].y);
		}
}

float math2d_distancePointToPoint(const struct point2DF* ptrPointA, const struct point2DF* ptrPointB)
{
	float dist = 0;
	float distX = ptrPointA->x - ptrPointB->x;
	float distY = ptrPointA->y - ptrPointB->y;
	return  sqrtf(powf(distX, 2.0f) + powf(distY, 2.0f));
}
int math2d_isPointInRectangle(const struct point2DF* ptrPoint, const struct rectangle2DF* ptrRectangle)
{
	if ((ptrRectangle->pointA.x <= ptrPoint->x) && (ptrPoint->x <= (ptrRectangle->pointA.x + ptrRectangle->dims.x)))
	{
		if ((ptrRectangle->pointA.y <= ptrPoint->y) && (ptrPoint->y <= (ptrRectangle->pointA.y + ptrRectangle->dims.y)))
		{
			return 1;
		}
	}
	return 0;
}
int math2d_isPointInCircle(const struct point2DF* ptrPoint, const struct circle2DF* ptrCircle)
{
	float dist = 0;
	dist = sqrtf(powf(ptrPoint->x - ptrCircle->center.x, 2.0f) + powf(ptrPoint->y - ptrCircle->center.y, 2.0f));
	return (dist <= ptrCircle->radius) ? 1 : 0;
}
int math2d_isCircleInCircle(const struct circle2DF* ptrCircle1, const struct circle2DF* ptrCircle2)
{
	float dist = 0;
	float distX = ptrCircle1->center.x - ptrCircle2->center.x;
	float distY = ptrCircle1->center.y - ptrCircle2->center.y;
	dist = sqrtf(powf(distX, 2.0f) + powf(distY, 2.0f));
	return (dist <= ptrCircle1->radius + ptrCircle2->radius) ? 1 : 0;
}


