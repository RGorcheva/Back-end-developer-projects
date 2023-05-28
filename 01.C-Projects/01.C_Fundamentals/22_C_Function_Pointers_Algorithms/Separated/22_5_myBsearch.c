/*
Напишете функция за претърсване на сортиран масив от указатели към стринг литерали. Функцията
трябва да работи с предикат, подобно на bsort. Използвайте binary search алгоритъм.
Използвайте функцията за да откриете някоя от стринг литералите от масив от предходната задача.
void *bsearch(const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *))
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "..\Library\inputOutputFunc.h"
#include "..\Library\stringFunc.h"

int compare_pointer_lexically(const void* a, const void* b)
{
	const char* pA = *(const char**)a;
	const char* pB = *(const char**)b;

	return  (strcmp(pA, pB));
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
	if (strcmp(*lo, *key)==0)
		return lo;
	else if (strcmp(*hi, *key)==0)
		return hi;
	return NULL;
}

int main(void)
{
	const char* arrPtr[4] = { "aaaa", "bbbb", "cccc", "dddd" };
	const char* pStr = "cccc";
	const char** pSearch = (const char**)bsearch(&pStr, arrPtr, 4, sizeof(char*), compare_pointer_lexically);
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
	pSearch = (const char**)my_bsearch(&pStr, arrPtr, 4, compare_pointer_lexically);
	if (pSearch != NULL)
	{
		printf("%s", *pSearch);
	}
	else
	{
		printf("The string is not found!");
	}
	return 0;
}