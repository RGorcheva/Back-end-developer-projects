#include "hw_10.h"
#include "myMath_h/myMath.h"
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>

#define CONST_EPSILON 0.0001f
#define CONST_PI 3.14

int equals_f_eps(float a, float b, float eps)
{
	return eps >= myMath_fabs(a - b);
}
void circleAreaQna(void)
{
	double dRadius = -1.0;
	double dArea = -1.0;

	printf("\nEnter a radius: ");
	scanf_s("%lf", &dRadius);

	dArea = myMath_circleArea(dRadius);
	printf("\nCircle area (R=%.2lf) = %.4lf", dRadius, dArea);
}
unsigned long long factoriel_recurs(int n)
{
	if (n > 1)
	{
		return n * factoriel_recurs(n - 1);
	}
	else
	{
		return 1;
	}
}
int sum_all(int n)
{
	if (n > 0)
	{
		return n += sum_all(n - 1);
	}
	else
	{
		return n;
	}
}

void hw_10_0_1_arithmeticМeanInt(void)
/*
Напишете програма, която пресмята средната аритметична стойност на три променливи от тип int.
*/
{
	printf("\n----------------task 10_0_1------------------\n");
	int a = 10;
	int b = 11;
	int c = 12;
	double middle = -1.0f;

	middle = ((double)a + (double)b + (double)c) / 3.0;
	printf("%.3lf", middle);
}
void hw_10_0_2_arithmeticМeanDouble(void)
/*
Напишете програма, която пресмята средната аритметична стойност на три променливи,
които имат следните типове:
int
unsigned long
float
*/
{
	printf("\n----------------task 10_0_2------------------\n");
	int a = 10;
	unsigned long int b = 12;
	float c = 13.0f;
	double middle = -1.0;

	middle = ((double)a + (double)b + (double)c) / 3.0;
	printf("%.3lf", middle);
}
void hw_10_0_3_my_fabs(void)
/*
Декларирайте и дефинирайте функция float my_fabs(float),
която връща абсолютната стойност (|модул|) от аргумента си - неговата положителна
стойност ако е отрицателен и оригинална стойност ако е положителен или 0.
*/
{
	printf("\n----------------task 10_0_3------------------\n");
	float a = -1.0f;

	printf("\nEntr a number: ");
	scanf_s("%f", &a);
	printf("\nModul(%.2f) = %.2f", a, myMath_fabs(a));
}
void hw_10_0_4_fequals(void)
/*
Декларирайте и дефинирайте функция int fequals(float, float),
която сравнява двата си float аргумента дали са равни с определена точност, зависеща от
константа, която определя интервала за допустима грешка (разлика в стойностите на аргументите)
const float epsilon = 0.0001f;
Ползвайте my_fabs от предната задача за сравнението.
*/
{
	printf("\n----------------task 10_0_4------------------\n");
	float A = -1.0f;
	float B = -1.0f;
	printf("\nEntr a number: ");
	scanf_s("%f", &A);
	printf("\nEntr a number: ");
	scanf_s("%f", &B);
	if (myMath_fequals(A, B))
	{
		printf("\nEquals!");
	}
	else
	{
		printf("\nNot equals!");
	}
}
void hw_10_0_5_equals_f_eps(void)
/*
Декларирайте и дефинирайте функция
int equals_f_eps(float, float, float epsilon),
която да приема трети аргумент, който да дава възможност на клиента на функцията да
задава интервала за допустима грешка.
Променете equals_f така че да работи с помощта на equals_f_eps
*/
{
	printf("\n----------------task 10_0_5------------------\n");
	float A = -1.0f;
	float B = -1.0f;
	float eps = -1.0f;

	printf("\nEntr a number: ");
	scanf_s("%f", &A);
	printf("\nEntr a number: ");
	scanf_s("%f", &B);
	printf("Enter epsilon: ");
	scanf_s("%f", &eps);

	myMath_fequals(A, B) ? printf("\nEps = %f : Equals!", CONST_EPSILON) : printf("\nEps = %f : Not equals!", CONST_EPSILON);
	equals_f_eps(A, B, eps) ? printf("\nEps = %f : Equals!", eps) : printf("\nEps = %f : Not equals!", eps);
}
void hw_10_0_6_sumAll(void)
/*
Декларирайте и дефинирайте рекурсивна функция
int sum_all(int n),
която да връща сумата на всички цели числа от 0 до стойността на аргумента,
който й е подаден.
*/
{
	printf("\n----------------task 10_0_6------------------\n");
	int iN = -1;

	printf("N = ");
	scanf_s("%d", &iN);

	printf("\nSum 1 to %d = %d", iN, sum_all(iN));
}
void hw_10_1_circleArea(void)
/*
Напишете функция, която изчислява площта на кръг, на която като
параметър подаваме радиуса и връща площта на кръга.
Използвайте глобална константа pi = 3.14 за да извършите
изчисленията.
Извикайте функцията в main() и покажете резултата.
*/
{
	printf("\n----------------task 10_1------------------\n");
	double dRadius = -1.0;
	double dArea = -1.0;

	printf("\nEnter a radius: ");
	scanf_s("%lf", &dRadius);
	dArea = myMath_circleArea(dRadius);
	printf("\n Circle area (R=%.2lf) = %.4lf", dRadius, dArea);
}
void hw_10_2_circleAreaQna(void)
/*
Напишете функция void circle_area_qna(void). Поискайте от
потребителя да въведе радиуса с помощта на функциите:
printf("Enter a radius\n");
scanf("%lf", &r);
Използвайте функцията от предходната задача за изчисляване на
площта на кръг, която написахме преди малко за да изчислите площта
на кръга с този радиус и върнете резултата
*/
{
	printf("\n----------------task 10_2------------------\n");
	circleAreaQna();
}
void hw_10_3_triangleArea(void)
/*
Напишете програма на С, която съдържа 2 функции.
1. Първата смята лице на правоъгълен триъгълник.
2. Втората използва лицето на триъгълника, за да сметне лице на
четириъгълник със същите дължини на страните, като раменете на
триъгълника.
Напишете прототипите на функциите най-отгоре, а телата им под мейн
функцията.
*/
{
	printf("\n----------------task 10_3------------------\n");
	double dA = -1.0;
	double dB = -1.0;
	double trArea = -1;
	double rectArea = -1;

	printf("\nEnter A: ");
	scanf_s("%lf", &dA);
	printf("\nEnter B: ");
	scanf_s("%lf", &dB);

	trArea = myMath_triangleArea(dA, dB);
	rectArea = myMath_rectangleArea(dA, dB);
	printf("\nTriangle area (A=%.2lf, B=%.2lf) = %.4lf", dA, dB, trArea);
	printf("\nRectangle area (A=%.2lf, B=%.2lf) = %.4lf", dA, dB, rectArea);
}
void hw_10_4_myMath_main(void)
/*
Направете си собствена бибилиотека mymath.h(или друго име) с често-срещани
помощни математически функции.
Декларирайте функциите от предните задачи в .h файл (не забрявяйте header guards)
Дефинирайте ги в .c файл
Тествайте в отделен .c файл, който include-ва mymath.h и в който има main функция.
Не ползвайте съществуващата math.h библиотека освен за вдъхновение
*/
{
	printf("\n----------------task 10_4------------------\n");
	double lfA = -1.0;
	double lfB = -1.0;

	printf("\nEnter double A: ");
	scanf_s(" %lf", &lfA);
	printf("\nEnter double B: ");
	scanf_s(" %lf", &lfB);

	printf("\nRectangleArea = %.1lf * %.1lf = %.2lf", lfA, lfB, myMath_rectangleArea(lfA, lfB));
	printf("\nTriangleArea = %.1lf * %.1lf /2.0 = %.2lf", lfA, lfB, myMath_triangleArea(lfA, lfB));
	printf("\nCircleArea = %.1lf * %.1lf * PI = %.2lf", lfA, lfA, myMath_circleArea(lfA));
	printf("\nEllipseArea = %.1lf * %.1lf * PI = %.2lf", lfA, lfB, myMath_ellipseArea(lfA, lfB));
	printf("\nMIN(%.1lf, %.1lf) = %.2lf", lfA, lfB, myMath_minDouble(lfA, lfB));
	printf("\nMAX(%.1lf, %.1lf) = %.2lf", lfA, lfB, myMath_maxDouble(lfA, lfB));
	printf("\nFactoriel(%d) = %d", (int)lfA, (int)myMath_factoriel((int)lfA));
}
void hw_10_5_fRound(void)
/*
Добавете следните функции в персоналната си mymath.h бибилиотека:
int fceil(float);
int ffloor(float);
int fround(float);
float fpow(float, int);
първите три трябва да взимат число с плаваща запетая и да го закръглят в int:
● fceil - нагоре (fceil(0.1f) == 1)
● ffloor - надолу (fceil(0.9f) == 1)
● fround - математически (fceil(0.4f) == 0, fceil(0.6f) == 1)
fpow трябва да повдига число с плаваща запетая на степен цяло число.
● бонус : напишете рекурсивна версия на fpow
*/
{
	printf("\n----------------task 10_5------------------\n");
	float fC = -1.0f;
	int i = -1;

	printf("\nEnter float C: ");
	scanf_s("%f", &fC);
	printf("\nEnter int i: ");
	scanf_s(" %d", &i);

	printf("\nRound ceil(%.2f) = %d", fC, myMath_fceil(fC));
	printf("\nRound floor(%.2f) = %d", fC, myMath_ffloor(fC));
	printf("\nRound math(%.2f) = %d", fC, myMath_fround(fC));
	printf("\n%.2f power %d = %.2f", fC, i, myMath_fpow(fC, i));
}
void hw_10_6_1_factoriel_for(void)
/*
В C няма оператор за намиране на факториел (n!), но можем да си напишем функция:
int factorial(int)
// factorial(5) == 5 * 4 * 3 * 2 * 1
// factorial(n) == n * (n - 1) * .. * 2 * 1
Направете я по два начина:
● Итеративно - с цикъл
*/
{
	printf("\n----------------task 10_6_1------------------\n");
	int iN = 1;

	printf("\nEnter n: ");
	scanf_s("%d", &iN);

	printf("\n%d! = %llu", iN, myMath_factoriel(iN));
	printf("\n%d! = %llu", 25, myMath_factoriel(25));
	printf("\n%d! = %llu", 30, myMath_factoriel(30));
	printf("\n%d! = %llu", 31, myMath_factoriel(31));
}
void hw_10_6_2_factoriel_racurs(void)
/*
В C няма оператор за намиране на факториел (n!), но можем да си напишем функция:
int factorial(int)
// factorial(5) == 5 * 4 * 3 * 2 * 1
// factorial(n) == n * (n - 1) * .. * 2 * 1
Направете я по два начина:
● Рекурсивно - функцията сама да вика себе си с различни стойности на аргументите и да има
условие за излизане от безкрайна рекурсия
*/
{
	printf("\n----------------task 10_6_2------------------\n");
	int iN = -1;

	printf("\nEnter n: ");
	scanf_s("%d", &iN);

	printf("\n%d! = %llu", iN, factoriel_recurs(iN));
}
void hw_10_7_combinations(void)
/*
Използвайте factorial функцията за да пресметнете шанса да спечелите 6 от 49, по формулата за
комбинация (всяка топка има уникален номер и поредността на теглене няма значение):
*/
{
	printf("\n----------------task 10_7------------------\n");
	int allObjects = 49;
	int ChoosenObjects = 6;
	unsigned long long NumberCombinations = 0llu;
	unsigned long long sum = 1;

	for (int i = 1; i <= ChoosenObjects; i++)
	{
		sum *= allObjects - ChoosenObjects + i;
	}

	NumberCombinations = sum / (myMath_factoriel(ChoosenObjects));
	printf("\nNumber of combinations to win 6/49 is %llu", NumberCombinations);
}
void hw_10_8_intRand(void)
/*
Дефинирайте функциите
int randPositive(int max)
int randRange(int min, int max),
които връщат произволна стойност в зададен от потребителя на функцията интервал
За целта може да ползвате стандартните функции( от stdlib.h и time.h ):
● rand - за да генерирате произволно число на всяко извикване.
● srand - викнете я веднъж в началото на програмата за да seed-нете random генератора за да може
rand да връща различни числа на всяко различно пускане на програмата
● time - за да можем да seed-ваме с различно число на всяко стартиране на програмата
srand(time(NULL)); // init random number generator
int randomBooleanValue = rand() % 2 == 0; // use % to clamp large value from rand
*/
{
	printf("\n----------------task 10_8------------------\n");
	int A = -1;
	int B = -1;

	srand((int)time(NULL));

	printf("\nEntr a number A:");
	scanf_s("%d", &A);
	printf("\nEntr a number B:");
	scanf_s("%d", &B);

	printf("\nRandom number between 0 and %d: %d", A, myMath_randToN(A));
	printf("\nRandom number between %d and %d: %d", A, B, myMath_randRange(A, B));
}