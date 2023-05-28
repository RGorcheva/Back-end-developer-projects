#include "myMath.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define PI_CONST (3.14)

double	myMath_rectangleArea(double a, double b)
{
	return a * b;
}
double	myMath_triangleArea(double a, double b)
{
	return (a * b)/2;
}
double	myMath_circleArea(double R)
{
	return R * R * PI_CONST;
}
double	myMath_ellipseArea(double a, double b)
{
	return a * b * PI_CONST;
}
double	myMath_maxDouble(double a, double b)
{
	return  a > b ? a : b;
}
double	myMath_minDouble(double a, double b)
{
	return  a < b ? a : b;
}
int		myMath_maxIint(int a, int b)
{
	return  a > b ? a : b;
}
int		myMath_minInt(int a, int b)
{
	return  a < b ? a : b;
}
int		myMath_sumFromAToB(int a, int b)
{
	int min = myMath_minInt(a, b);
	int max = myMath_maxIint(a, b);
	int sum = 0;
	while (min <= max)
	{
		sum += min;
		min++;
	}
	return sum;
}
int		myMath_sumFrom1ToN(int n)
{
	int iSum = 0;

	for (int i = 1; i <= n; i++)
	{
		iSum += i;
	}
	return iSum;
}
double	myMath_modul(double b)
{
	return b < 0 ? -b : b;
}
unsigned long long myMath_factoriel(int n)
{
	int fact = 1;
	for (int i = 1; i <= n; i++)
	{
		fact *= i;
	}
	return fact;
}
float	myMath_fabs(float b)
{
	return b < 0 ? -b : b;
}
double	myMath_dabs(double b)
{
	return b < 0 ? -b : b;
}
int		myMath_fceil(float f)
{
	return (int)f + 1;
}
int		myMath_ffloor(float f)
{
	return (int)f;
}
int		myMath_fround(float f)
{
	return (int)(f+0.5f);
}
float	myMath_fpow(float f, int i)
{
	float powf = f;
	if (i > 1)
	{
		powf *= myMath_fpow(f, i - 1);
	}
	return powf;
}
int		myMath_fequals(float a, float b)
{
	const float epsilon = 0.0001f;
	float minus = a - b;
	if (epsilon > myMath_fabs(minus))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int		myMath_dequals(double a, double b)
{
	const double epsilon = 0.0001;
	double minus = a - b;
	if (epsilon > myMath_dabs(minus))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int		myMath_randToN(int max)
{
	int randomValue = rand() % (max + 1);
	if (max > 0)
	{
		return randomValue;
	}
	else
	{
		return -randomValue;
	}
}
int		myMath_randRange(int min, int max)
{
	int Max = myMath_maxIint(max, min);
	int Min = myMath_minInt(max, min);

	int randomValue = myMath_randToN(Max - Min);

	return randomValue + Min;
}
void	myMath_swapInt(int* pa, int* pb)
{
	*pa = *pa - *pb;
	*pb = *pa + *pb;
	*pa = *pb - *pa;
}
void	myMath_swapPointerInt(int** ppa, int** ppb)
{
	int* c = *ppa;
	*ppa = *ppb;
	*ppb = c;
}