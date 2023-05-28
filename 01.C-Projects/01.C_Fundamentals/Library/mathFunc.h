#ifndef MATHFUNC_H
#define MATHFUNC_H


//int
int		math_iabs(int b);
int		math_maxInt(int a, int b);
int		math_minInt(int a, int b);

int		math_sumFromAToB(int a, int b);
int		math_sumFrom1ToN(int n);

int		math_multipleMinMax(const int min, const int max);
unsigned long long math_factoriel(int n);

void	math_swapInt(int* pa, int* pb);
void	math_swapPointerInt(int** ppa, int** ppb);

int		math_randToN(int max);
int		math_randRange(int min, int max);

void	math_itoa(int iNumber, char* str);

//float
float	math_fabs(float b);
int		math_fceil(float f);
int		math_ffloor(float f);
int		math_fround(float f);
float	math_fpow(float f, int i);
int		math_fequals(float a, float b);


//double

double	math_maxDouble(double a, double b);
double	math_minDouble(double a, double b);
double	math_dabs(double b);
int		math_dequals(double a, double b);

double	math_rectangleArea(double a, double b);
double	math_triangleArea(double a, double b);
double	math_circleArea(double R);
double	math_ellipseArea(double a, double b);

#endif