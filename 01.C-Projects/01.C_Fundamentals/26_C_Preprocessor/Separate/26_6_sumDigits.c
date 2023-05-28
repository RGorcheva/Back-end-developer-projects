/*
Дефинирайте макрос SUM_DIGITS(num, type), който връща сумата от цифрите на цяло число. Вторият
параметър указва типа и е нужен за дефиниция на променлива за сумата. Пример за извикване:
int num1 = 12345;
printf("The sum of the digits of %d is %d\n", num1, SUM_DIGITS(num1, int));
long num2 = 12345L;
printf("The sum of the digits of %ld is %ld\n", num1, SUM_DIGITS(num2, long));
*/

#include <stdio.h>

#define SUM_DIGITS(num,type) {\
	type num2=num;\
	sum = 0;\
	while(num2>0)\
	{\
		sum+=num2%10;\
		num2/=10;\
	}\
}

int main(void)
{
	int num = 12345;
	int sum = 0;
	SUM_DIGITS(num, int);
	printf("The sum of the digits of %d is %d\n", num, sum);

	long int numTwo = 123456L;
	SUM_DIGITS(numTwo, long int);
	printf("The sum of the digits of %ld is %d\n", numTwo, sum);

	return 0;
}
