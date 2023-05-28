#include "mathFunc.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define PI_CONST (3.14)


//int
int	    math_iabs(int b)
{
	return b < 0 ? -b : b;
}
int		math_maxInt(int a, int b)
{
	return  a > b ? a : b;
}
int		math_minInt(int a, int b)
{
	return  a < b ? a : b;
}

int		math_sumFromAToB(int a, int b)
{
	int min = math_minInt(a, b);
	int max = math_maxInt(a, b);
	int sum = 0;
	while (min <= max)
	{
		sum += min;
		min++;
	}
	return sum;
}
int		math_sumFrom1ToN(int n)
{
	int iSum = 0;

	for (int i = 1; i <= n; i++)
	{
		iSum += i;
	}
	return iSum;
}

int		math_multipleMinMax(const int min, const int max)
{
	int product = 1;
	for (int i = min; i <= max; ++i)
	{
		product *= i;
	}
	return product;
}
unsigned long long math_factoriel(int n)
{
	int fact = 1;
	for (int i = 1; i <= n; i++)
	{
		fact *= i;
	}
	return fact;
}

void	math_swapInt(int* pa, int* pb)
{
	*pa = *pa - *pb;
	*pb = *pa + *pb;
	*pa = *pb - *pa;
}
void	math_swapPointerInt(int** ppa, int** ppb)
{
	int* c = *ppa;
	*ppa = *ppb;
	*ppb = c;
}

int		math_randToN(int max)
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
int		math_randRange(int min, int max)
{
	int Max = math_maxInt(max, min);
	int Min = math_minInt(max, min);

	int randomValue = math_randToN(Max - Min);

	return randomValue + Min;
}

void	math_itoa(int iNumber, char* str)
{
	//Turn integer into char string.
	int i = 0;
	do
	{
		str[i] = iNumber % 10 + '0';
		iNumber /= 10;
		i++;
	} while (iNumber > 0);
	str[i] = '\0';
}


//float
float	math_fabs(float b)
{
	return b < 0 ? -b : b;
}
int		math_fceil(float f)
{
	return (int)f + 1;
}
int		math_ffloor(float f)
{
	return (int)f;
}
int		math_fround(float f)
{
	return (int)(f + 0.5f);
}
float	math_fpow(float f, int i)
{
	float powf = f;
	if (i > 1)
	{
		powf *= math_fpow(f, i - 1);
	}
	return powf;
}
int		math_fequals(float a, float b)
{
	const float epsilon = 0.0001f;
	float minus = a - b;
	if (epsilon > math_fabs(minus))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


//double
double	math_maxDouble(double a, double b)
{
	return  a > b ? a : b;
}
double	math_minDouble(double a, double b)
{
	return  a < b ? a : b;
}
double	math_dabs(double b)
{
	return b < 0 ? -b : b;
}
int		math_dequals(double a, double b)
{
	const double epsilon = 0.0001;
	double minus = a - b;
	if (epsilon > math_dabs(minus))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

double	math_rectangleArea(double a, double b)
{
	return a * b;
}
double	math_triangleArea(double a, double b)
{
	return (a * b)/2;
}
double	math_circleArea(double R)
{
	return R * R * PI_CONST;
}
double	math_ellipseArea(double a, double b)
{
	return a * b * PI_CONST;
}




