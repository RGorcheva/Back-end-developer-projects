#ifndef MYMATH_H
#define MYMATH_H

double	myMath_rectangleArea(double a, double b);
double	myMath_triangleArea(double a, double b);
double	myMath_circleArea(double R);
double	myMath_ellipseArea(double a, double b);
double	myMath_maxDouble(double a, double b);
double	myMath_minDouble(double a, double b);
int		myMath_maxIint(int a, int b);
int		myMath_minInt(int a, int b);
int		myMath_sumFromAToB(int a, int b);
int		myMath_sumFrom1ToN(int n);
double	myMath_modul(double b);
unsigned long long myMath_factoriel(int n);
float	myMath_fabs(float b);
double	myMath_dabs(double b);
int		myMath_fceil(float f);
int		myMath_ffloor(float f);
int		myMath_fround(float f);
float	myMath_fpow(float f, int i);
int		myMath_fequals(float a, float b);
int		myMath_dequals(double a, double b);
int		myMath_randPositive(int max);
int		myMath_randToN(int max);
int		myMath_randRange(int min, int max);
void	myMath_swapInt(int* pa, int* pb);
void	myMath_swapPointerInt(int** ppa, int** ppb);

#endif