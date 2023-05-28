/*
Ако искате функциите да имат различни прототипи, може да ги “обвиете”(да ги wrap - нете) в структура, която има 2 members: указател към void(void*),
който сочи към въпросната функция(ползвайте експлицитен cast за преобразуването от void* към типа на указателя към функцията и обратно) и
целочислена променлива, отговаряща на enum константа, която указва типа на функцията.Пример :
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define ARR_SZ 3

int fast_func(void) 
{
	for (int i = 0; i < 10; i++) {}
	return 1;
}
int middle_func(int i) 
{
	for (long long int i = 0; i < 10000000; i++) {}
	return 2;
}
int slow_func(double d) 
{
	for (long long int i = 0; i < 100000000; i++) {}
	return 3;
}

typedef int (*FUNC_PTR_I_V)(void);
typedef int (*FUNC_PTR_I_I)(int);
typedef int (*FUNC_PTR_I_D)(double);

enum EFunctionType { EFunctionType_i_v, EFunctionType_i_i, EFunctionType_i_d };

struct FunctionInfo
{
	 enum EFunctionType type;
	 void* funcPtr;
};
struct FunctionInfo funcInfoArr[ARR_SZ] = {
	{
		.type = EFunctionType_i_d,
		.funcPtr = slow_func
	},
	{
		.type = EFunctionType_i_i,
		.funcPtr = middle_func,
	},
	{
		.type = EFunctionType_i_v,
		.funcPtr = fast_func,
	}
 };
struct FunctionInfo* pArr = funcInfoArr;

int compare_time(const void* a, const void* b)
{
	struct FunctionInfo pf1 = *(struct FunctionInfo*)a;

	struct FunctionInfo pf2 = *(struct FunctionInfo*)b;

	clock_t begin = clock();
	switch (pf1.type) {
	case EFunctionType_i_v: {
		int m = ((FUNC_PTR_I_V)pf1.funcPtr)(); }; break;
	case EFunctionType_i_i: {
		int m = ((FUNC_PTR_I_I)pf1.funcPtr)(0); }; break;
	case EFunctionType_i_d: {
		int m = ((FUNC_PTR_I_D)pf1.funcPtr)(0.0); }; break;
	default:break;
	}
	clock_t end = clock();
	double time1_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	begin = clock();
	switch (pf2.type) {
	case EFunctionType_i_v: {
		int m = ((FUNC_PTR_I_V)pf2.funcPtr)(); }; break;
	case EFunctionType_i_i: {
		int m = ((FUNC_PTR_I_I)pf2.funcPtr)(0); }; break;
	case EFunctionType_i_d: {
		int m = ((FUNC_PTR_I_D)pf2.funcPtr)(0.0); }; break;
	default:break;
	}
	end = clock();
	double time2_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	if ((time1_spent - time2_spent) > 0) return 1;
	if ((time1_spent - time2_spent) < 0) return -1;
	return 0;
}

int main(void)
{
	qsort(funcInfoArr, ARR_SZ, sizeof(struct FunctionInfo), compare_time);

	for (int i = 0; i < ARR_SZ; i++)
	{
		clock_t begin = clock();
		printf("\nStarting of the program, begin = %ld", begin);
		switch (funcInfoArr[i].type)
		{
		case EFunctionType_i_v:
		{
			int m = ((FUNC_PTR_I_V)funcInfoArr[i].funcPtr)();
			printf("\nm = %d", m);
		}; break;
		case EFunctionType_i_i:
		{
			int m = ((FUNC_PTR_I_I)funcInfoArr[i].funcPtr)(0);
			printf("\nm = %d", m);
		}; break;
		case EFunctionType_i_d:
		{
			int m = ((FUNC_PTR_I_D)funcInfoArr[i].funcPtr)(0.0);
			printf("\nm = %d", m);
		}; break;
		default: break;
		}
		clock_t end = clock();
		printf("\nEnding of the program, end = %ld", end);
		double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		printf("\nTime spent = %lfs", time_spent);
		printf("\n");
	}
	return 0;
}
