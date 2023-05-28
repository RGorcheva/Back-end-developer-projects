/*
Напишете функция void circle_area_qna(void). Поискайте от
потребителя да въведе радиуса с помощта на функциите:
printf("Enter a radius\n");
scanf("%lf", &r);
Използвайте функцията от предходната задача за изчисляване на
площта на кръг, която написахме преди малко за да изчислите площта
на кръга с този радиус и върнете резултата
*/

#include <stdio.h>

#define CONST_PI (3.14)

double circleArea(double r)
{
	return r * r * CONST_PI;
}

void circleAreaQna(void)
{
	double dRadius = -1.0;
	double dArea = -1.0;

	printf("\nEnter a radius: ");
	scanf_s("%lf", &dRadius);

	dArea = circleArea(dRadius);
	printf("\nCircle area (R=%.2lf) = %.4lf", dRadius, dArea);
}

int main()
{
	circleAreaQna();
	return 0;
}