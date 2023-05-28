/*
Можем да измерим процесорното време, необходимо за изпълнението на част от кода, използвайки функцията clock() и константата CLOCKS_PER_SEC
от time.h, по следния начин:
clock_t begin = clock();
//time-consuming thing to measure duration of (in cpu time)
clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
Направете масив от указатели към функции, който е сортиран по бързина на изпълнение на функциите.
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE_3 3

int count1(void)
{
	for (int i = 0; i < 10; i++) {}
	return 1;
}
int count2(void)
{
	for (long long int i = 0; i < 10000000; i++) {}
	return 2;
}
int count3(void)
{
	for (long long int i = 0; i < 100000000; i++) {}
	return 3;
}

typedef int func(void);
typedef func* pfunc;

int compare_time(const void* a, const void* b)
{
	pfunc pf1 = *(pfunc*)a;
	pfunc pf2 = *(pfunc*)b;

	clock_t begin = clock();
	int m = pf1();
	clock_t end = clock();
	double time1_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	begin = clock();
	m = pf2();
	end = clock();
	double time2_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    if ((time1_spent - time2_spent) > 0) return 1;
	if ((time1_spent - time2_spent) < 0) return -1;
	return 0;
}

int main(void)
{
	pfunc p1 = count3;
	pfunc p2 = count2;
	pfunc p3 = count1;
	pfunc arrFunc[SIZE_3] = { p1, p2, p3 };

	qsort(arrFunc, SIZE_3, sizeof(pfunc), compare_time);
	for (int i = 0; i < SIZE_3; i++)
	{
		clock_t begin = clock();
		printf("\nStarting of the program, begin = %ld", begin);
		int m = arrFunc[i]();
		printf("\nm = %d", m);
		clock_t end = clock();
		printf("\nEnding of the program, end = %ld", end);
		double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		printf("\nTime spent = %lfs", time_spent);
		printf("\n");
	}
	return 0;
}


