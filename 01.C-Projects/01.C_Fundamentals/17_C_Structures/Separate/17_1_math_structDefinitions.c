/*
Да положим основите на библиотека за 2D геометрични функции, полезни в редица
приложения, свързани с компютърна графика, например.
math2d.h
Нека ползваме float за всички типове и функции от библиотеката.
...
Дефинирайте следните типове, изполвайки struct:
● точка в равнината(2D), примерни имена: point2f, point2, vec2f, vec2, vec2df, ..
● триъгълник в равнината
● кръг
● правоъгълник (axis-aligned - без ротация, винаги с перпендикулярни страни на абцисната и
ординатна оси - на страните на екрана), примерни имена : rect2df, aabb2, ..
● полигон (с от 3 до 8 върха - vertices)
*/

struct point2DF
{
	float x;
	float y;
};

struct triangle2DF
{
	struct point2DF pointA;
	struct point2DF pointB;
	struct point2DF pointC;
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

struct polygon6_2DF
{
	struct point2DF pointA;
	struct point2DF pointB;
	struct point2DF pointC;
	struct point2DF pointD;
	struct point2DF pointE;
	struct point2DF pointF;
};