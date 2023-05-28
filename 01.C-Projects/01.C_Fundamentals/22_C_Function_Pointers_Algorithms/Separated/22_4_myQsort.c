/*
Напишете функция за сортиране на масив от указатели към стринг литерали, която работи с
предикатна функция, подобно на qsort (приемa като параметър указател към функция-предикат)
Напишете функции, които сортират масив:
● лексикографски, в обратен ред
● по брой символи в стринга
● по брой пунктуационни знаци в стринга
void qsort(void *ptr, size_t count, size_t size, int (*comp)(const void *, const void *));
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "..\Library\stringFunc.h"

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
			if (comp(p, p+1) > 0)
			{
				const char* temp = *p;
				*p = *(p + 1);
				*(p + 1) = temp;
			}
		}
	}
}
//void my_qsort(const void* ptr, size_t count, size_t size, int (*comp)(const void*, const void*))
//{
//
//	for (size_t i = 0; i < count - 1; i++)
//	{
//		const void* p = ptr;
//		for (; p < ptr + count*size - i - size; p+= size)
//		{
//			if (comp(p, p + size) > 0)
//			{
//				const void temp = *p;
//				*p = *(p + size);
//				*(p + size) = temp;
//			}
//		}
//	}
//}

int main(void)
{
	const char* arrPtr[4] = { "dd,.,.ddddd", "ccc,.,cc", "bb.,bbb", "aa.aa" };

	printf("\ncompare_pointer_lexically = \n");
	qsort(arrPtr, 4, sizeof(char*), compare_pointer_lexically);
	for (int i = 0; i < 4; i++)
	{
		printf("[%s]", arrPtr[i]);
	}
	printf("\n------------------------\n");
	my_qsort(arrPtr, 4, compare_pointer_lexically);
	for (int i = 0; i < 4; i++)
	{
			printf("[%s]", arrPtr[i]);
	}
	printf("\n");
//////////////////////////////////////////////
	printf("\ncompare_pointer_lexicallyBackwards =\n");
	qsort(arrPtr, 4, sizeof(char*), compare_pointer_lexicallyBackwards);
	for (int i = 0; i < 4; i++)
	{
		printf("[%s]", arrPtr[i]);
	}
	printf("\n------------------------\n");
	my_qsort(arrPtr, 4, compare_pointer_lexicallyBackwards);
	for (int i = 0; i < 4; i++)
	{
		printf("[%s]", arrPtr[i]);
	}
	printf("\n");
/////////////////////////////////////////////
	printf("\ncompare_pointer_countSymbols =\n");
	qsort(arrPtr, 4, sizeof(char*), compare_pointer_countSymbols);
	for (int i = 0; i < 4; i++)
	{
		printf("[%s]", arrPtr[i]);
	}
	printf("\n------------------------\n");
	my_qsort(arrPtr, 4, compare_pointer_countSymbols);
	for (int i = 0; i < 4; i++)
	{
		printf("[%s]", arrPtr[i]);
	}
	printf("\n");
////////////////////////////////////////////
	printf("\ncompare_pointer_countPunct = \n");
	qsort(arrPtr, 4, sizeof(char*), compare_pointer_countPunct);
	for (int i = 0; i < 4; i++)
	{
		printf("[%s]", arrPtr[i]);
	}
	printf("\n------------------------\n");
	my_qsort(arrPtr, 4, compare_pointer_countPunct);
	for (int i = 0; i < 4; i++)
	{
		printf("[%s]", arrPtr[i]);
	}
	printf("\n");
	return 0;
}