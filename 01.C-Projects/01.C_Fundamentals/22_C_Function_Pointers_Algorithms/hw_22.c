#include "hw_22.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\Library\inputOutputFunc.h"
#include "..\Library\stringFunc.h"
#include <time.h>


#define SIZE_10 10
#define SIZE_4 4
#define SIZE_3 3
#define ARR_SZ 3

void sortArrSelectionMinToMax(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int min = arr[i];
		int p = i;
		for (int j = i + 1; j < size; j++)
		{
			if (min > arr[j])
			{
				min = arr[j];
				p = j;
			}
		}
		arr[p] = arr[i];
		arr[i] = min;
	}
}
void sortArrSelectionMaxToMin(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int max = arr[i];
		int p = i;
		for (int j = i + 1; j < size; j++)
		{
			if (max < arr[j])
			{
				max = arr[j];
				p = j;
			}
		}
		arr[p] = arr[i];
		arr[i] = max;
	}
}
void bubbleSortMinToMax(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void bubbleSortMaxToMin(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int compare_ints(const void* a, const void* b)
{
	int iA = *(const int*)a;
	int iB = *(const int*)b;

	return iA - iB;
}
int compare_chars(const void* a, const void* b)
{
	char cA = *(const char*)a;
	char cB = *(const char*)b;

	return (int)(cB)-(int)(cA);
	return 0;
}
int compare_pointers(const void* a, const void* b)
{
	const char* pA = *(const char**)a;
	const char* pB = *(const char**)b;

	return  (strcmp(pA, pB));
}
int compare_ulongs(const void* a, const void* b)
{
	const unsigned long ulA = *(const unsigned long*)a;
	const unsigned long ulB = *(const unsigned long*)b;

	if ((ulA > ulB) && (ulA % 2 > ulB % 2)) return 1;
	if ((ulA > ulB) && !(ulA % 2 > ulB % 2)) return -1;
	if ((ulA < ulB) && (ulA % 2 < ulB % 2)) return -1;
	if ((ulA < ulB) && !(ulA % 2 < ulB % 2))  return 1;
	return 0;
}

int compare_pointer_lexically(const void* a, const void* b)
{
	const char* pA = *(const char**)a;
	const char* pB = *(const char**)b;

	return  (strcmp(pA, pB));
}
int compare_pointer_lexicallyBackwards(const void* a, const void* b)
{
	const char* pA = *(const char**)a;
	const char* pB = *(const char**)b;

	return  -(strcmp(pA, pB));
}
int compare_pointer_countSymbols(const void* a, const void* b)
{
	const char* pA = *(const char**)a;
	const char* pB = *(const char**)b;

	return  (int)strlen(pA) - (int)strlen(pB);
}
int compare_pointer_countPunct(const void* a, const void* b)
{
	const char* pA = *(const char**)a;
	const char* pB = *(const char**)b;

	return  string_countPunct(pA) - string_countPunct(pB);
}

void my_qsort(const char** ptr, size_t count, int (*comp)(const void*, const void*))
{

	for (size_t i = 0; i < count - 1; i++)
	{
		const char** p = ptr;
		for (; p < ptr + count - i - 1; p++)
		{
			if (comp(p, p + 1) > 0)
			{
				const char* temp = *p;
				*p = *(p + 1);
				*(p + 1) = temp;
			}
		}
	}
}
const char** my_bsearch(const char** key, const char** base, size_t count, int (*comp)(const void*, const void*))
{
	const char** lo = base;
	const char** hi = base + count - 1;
	size_t step = (count - 1) / 2;
	while (step != 0)
	{
		const char** mid = base + step;
		if (comp(key, mid) > 0)
		{
			*lo = *(mid + 1);
		}
		else if (comp(key, mid) < 0)
		{
			*hi = *mid;
		}
		else
		{
			return mid;
		}
		step = step / 2;
	}
	if (strcmp(*lo, *key) == 0)
		return lo;
	else if (strcmp(*hi, *key) == 0)
		return hi;
	return NULL;
}

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

void hw_22_0_1_SelectionSortMInToMax(void)
/*
Съставете функция, която сортира елементите на масив от най-малък към най-голям по метода на Селекциите
*/
{
	printf("\n-----------------task 22_0_1-----------------------\n");
	int arr[10] = { 3, 1, 5, 9, 4, 8, 7, 2, 6, 10 };
	int size = 10;
	sortArrSelectionMinToMax(arr, size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}
void hw_22_0_2_SelectionSortMaxToMin(void)
/*
Съставете функция, която сортира елементите на масив от най-голям към най-малък по метода на Селекциите.
*/
{
	printf("\n-----------------task 22_0_2-----------------------\n");
	int arr[10] = { 3, 1, 5, 9, 4, 8, 7, 2, 6, 10 };
	int size = 10;
	sortArrSelectionMaxToMin(arr, size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}
void hw_22_0_3_BubbulSortMinToMax(void)
/*
Съставете функция, която сортира елементите на масив от най-малък към най-голям по метода на Балончето.
*/
{
	printf("\n-----------------task 22_0_3-----------------------\n");
	int arr[10] = { 3, 1, 5, 9, 4, 8, 7, 2, 6, 10 };
	int size = 10;
	bubbleSortMinToMax(arr, size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}
void hw_22_0_4_BubbleSortMaxToMin(void)
/*
Съставете функция, която сортира елементите на масив от най-голям към най-малък по метода на Балончето.
*/
{
	printf("\n-----------------task 22_0_4-----------------------\n");
	int arr[10] = { 3, 1, 5, 9, 4, 8, 7, 2, 6, 10 };
	int size = 10;
	bubbleSortMaxToMin(arr, size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}
void hw_22_1_typedefFunc(void)
/*
Използвайте typedef за да дефинирате алтернативни имена на следните типове:
● Функция, която не приема параметри и връща double
● Функция, която приема два double параметъра и не връща нищо
● Функция, която приема един int параметър и връща указател към функция, която не приема параметри и връща int
● Функция, която взима три указателя към три различни типа функции - същите типове като на по-горните три типа функции (за
които вече имаме алтернативни имена)
*/
{
	printf("\n-----------------task 22_1-----------------------\n");
	typedef double typef1(void);
	double (*pf1)(void);
	typedef void typef2(double a, double b);
	void (*pf2)(double, double);
	typedef int (*pf3)(void);
	typedef pf3 typef4(int a);
	pf3(*pf4)(int);
	typedef void typef5(typef1* pf1, typef2* pf2, typef4* pf4);
}
void hw_22_2_qSort(void)
/*
Използвайте стандартната функция qsort от stdlib.h за да сортирате:
● масив от int във възходящ ред
● масив от char във низходящ ред
● масив от константни указатели към стринг литерали лексикографски
● масив от unsigned long във низходящ ред, като четните стойности са преди нечетните, пример:
4, 2, 6, 1, 7, 5, 3, 9, 8, 0 след сортиране: 8, 6, 4, 2, 0, 9, 7, 5, 3, 1
void qsort(void *ptr, size_t count, size_t size, int (*comp)(const void *, const void *));
*/
{
	printf("\n-----------------task 22_2-----------------------\n");
	int arrInt[SIZE_10] = { 4, 2, 6, 1, 7, 5, 3, 9, 8, 0 };
	qsort(arrInt, SIZE_10, sizeof(int), compare_ints);
	io_arrPrintSquareScopes("arrInt", arrInt, 10);
	printf("\n");

	//////////////////////

	char arrChar[SIZE_10] = { 'b','d','e','f','g','h','j','i','c','a' };
	qsort(arrChar, SIZE_10, sizeof(char), compare_chars);
	printf("\narrChar=");
	for (int i = 0; i < SIZE_10; i++)
	{
		printf("[%c]", arrChar[i]);
	}
	printf("\n\n");

	//////////////////////

	unsigned long arrUL[SIZE_10] = { 4, 2, 6, 1, 7, 5, 3, 9, 8, 7 };
	qsort(arrUL, SIZE_10, sizeof(const unsigned long), compare_ulongs);
	printf("\narrUL=");
	for (int i = 0; i < SIZE_10; i++)
	{
		printf("[%u]", arrUL[i]);
	}
	printf("\n\n");

	///////////////////////

	const char* arrPtr[SIZE_4] = { "dddd", "cccc", "bbbb", "aaaa" };
	qsort(arrPtr, SIZE_4, sizeof(const char*), compare_pointers);
	for (int i = 0; i < SIZE_4; i++)
	{
		printf("[%s]", arrPtr[i]);
	}
}
void hw_22_3_bSearch(void)
/*
Използвайте стандартната функция bsearch от stdlib.h за да откриете някоя от стринговите литерали от сортирания лексикографски
масив от указатели към литерали
void *bsearch(const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *))
*/
{
	printf("\n-----------------task 22_3-----------------------\n");
	const char* arrPtr[SIZE_4] = { "aaaa", "bbbb", "cccc", "dddd" };
	const char* pStr = "cccc";
	const char** pSearch = (const char**)bsearch(&pStr, arrPtr, 4, sizeof(char*), compare_pointers);
	if (pSearch != NULL)
	{
		printf("%s", *pSearch);
	}
	else
	{
		printf("The string is not found!");
	}
}
void hw_22_4_myQsort(void)
/*
Напишете функция за сортиране на масив от указатели към стринг литерали, която работи с
предикатна функция, подобно на qsort (приемa като параметър указател към функция-предикат)
Напишете функции, които сортират масив:
● лексикографски, в обратен ред
● по брой символи в стринга
● по брой пунктуационни знаци в стринга
void qsort(void *ptr, size_t count, size_t size, int (*comp)(const void *, const void *));
*/
{
	printf("\n-----------------task 22_4-----------------------\n");
	const char* arrPtr[SIZE_4] = { "dd,.,.ddddd", "ccc,.,cc", "bb.,bbb", "aa.aa" };

	printf("\ncompare_pointer_lexically = \n");
	qsort(arrPtr, SIZE_4, sizeof(char*), compare_pointer_lexically);
	for (int i = 0; i < SIZE_4; i++)
	{
		printf("[%s]", arrPtr[i]);
	}
	printf("\n------------------------\n");
	my_qsort(arrPtr, 4, compare_pointer_lexically);
	for (int i = 0; i < SIZE_4; i++)
	{
		printf("[%s]", arrPtr[i]);
	}
	printf("\n");
	//////////////////////////////////////////////
	printf("\ncompare_pointer_lexicallyBackwards =\n");
	qsort(arrPtr, SIZE_4, sizeof(char*), compare_pointer_lexicallyBackwards);
	for (int i = 0; i < SIZE_4; i++)
	{
		printf("[%s]", arrPtr[i]);
	}
	printf("\n------------------------\n");
	my_qsort(arrPtr, SIZE_4, compare_pointer_lexicallyBackwards);
	for (int i = 0; i < SIZE_4; i++)
	{
		printf("[%s]", arrPtr[i]);
	}
	printf("\n");
	/////////////////////////////////////////////
	printf("\ncompare_pointer_countSymbols =\n");
	qsort(arrPtr, 4, sizeof(char*), compare_pointer_countSymbols);
	for (int i = 0; i < SIZE_4; i++)
	{
		printf("[%s]", arrPtr[i]);
	}
	printf("\n------------------------\n");
	my_qsort(arrPtr, SIZE_4, compare_pointer_countSymbols);
	for (int i = 0; i < SIZE_4; i++)
	{
		printf("[%s]", arrPtr[i]);
	}
	printf("\n");
	////////////////////////////////////////////
	printf("\ncompare_pointer_countPunct = \n");
	qsort(arrPtr, SIZE_4, sizeof(char*), compare_pointer_countPunct);
	for (int i = 0; i < SIZE_4; i++)
	{
		printf("[%s]", arrPtr[i]);
	}
	printf("\n------------------------\n");
	my_qsort(arrPtr, SIZE_4, compare_pointer_countPunct);
	for (int i = 0; i < SIZE_4; i++)
	{
		printf("[%s]", arrPtr[i]);
	}
	printf("\n");
}
void hw_22_5_myBsearch(void)
/*
Напишете функция за претърсване на сортиран масив от указатели към стринг литерали. Функцията
трябва да работи с предикат, подобно на bsort. Използвайте binary search алгоритъм.
Използвайте функцията за да откриете някоя от стринг литералите от масив от предходната задача.
void *bsearch(const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *))
*/
{
	printf("\n-----------------task 22_5-----------------------\n");
	const char* arrPtr[SIZE_4] = { "aaaa", "bbbb", "cccc", "dddd" };
	const char* pStr = "cccc";
	const char** pSearch = (const char**)bsearch(&pStr, arrPtr, SIZE_4, sizeof(char*), compare_pointer_lexically);
	if (pSearch != NULL)
	{
		printf("%s", *pSearch);
	}
	else
	{
		printf("The string is not found!");
	}
	///////////////////////////////////////////
	printf("\n------------------------\n");
	pSearch = (const char**)my_bsearch(&pStr, arrPtr, SIZE_4, compare_pointer_lexically);
	if (pSearch != NULL)
	{
		printf("%s", *pSearch);
	}
	else
	{
		printf("The string is not found!");
	}
}
void hw_22_6_sortCPUTime(void)
/*
Можем да измерим процесорното време, необходимо за изпълнението на част от кода, използвайки функцията clock()
и константата CLOCKS_PER_SEC от time.h, по следния начин:
clock_t begin = clock();
//time-consuming thing to measure duration of (in cpu time)
clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
Направете масив от указатели към функции, който е сортиран по бързина на изпълнение на функциите.
Ако искате функциите да имат различни прототипи, може да ги “обвиете”(да ги wrap - нете) в структура, която има 2 members: указател към void(void*),
който сочи към въпросната функция(ползвайте експлицитен cast за преобразуването от void* към типа на указателя към функцията и обратно) и
целочислена променлива, отговаряща на enum константа, която указва типа на функцията.Пример :
*/
{
	printf("\n-----------------task 22_6-----------------------\n");
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
}