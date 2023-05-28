/*
Използвайте стандартната функция qsort от stdlib.h за да сортирате:
● масив от int във възходящ ред
● масив от char във низходящ ред
● масив от константни указатели към стринг литерали лексикографски
● масив от unsigned long във низходящ ред, като четните стойности са преди нечетните, пример:
4, 2, 6, 1, 7, 5, 3, 9, 8, 0 след сортиране: 8, 6, 4, 2, 0, 9, 7, 5, 3, 1
void qsort(void *ptr, size_t count, size_t size, int (*comp)(const void *, const void *));
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\Library\inputOutputFunc.h"
#include "..\Library\stringFunc.h"

#define SIZE 10

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

    return (int)(cB) - (int)(cA);
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

int main(void)
{
    int arrInt[10] = { 4, 2, 6, 1, 7, 5, 3, 9, 8, 0 };
    qsort(arrInt, SIZE, sizeof(int), compare_ints);
    io_arrPrintSquareScopes("arrInt", arrInt, 10);
    printf("\n");

    //////////////////////

	char arrChar[10] = {'b','d','e','f','g','h','j','i','c','a'};
	qsort(arrChar, SIZE, sizeof(char), compare_chars);
    printf("\narrChar=");
    for (int i = 0; i < SIZE; i++)
    {
        printf("[%c]", arrChar[i]);
    }
    printf("\n\n");

    //////////////////////

    unsigned long arrUL[10] = { 4, 2, 6, 1, 7, 5, 3, 9, 8, 7 };
    qsort(arrUL, SIZE, sizeof(const unsigned long), compare_ulongs);
    printf("\narrUL=");
    for (int i = 0; i < SIZE; i++)
    {
        printf("[%u]", arrUL[i]);
    }
    printf("\n\n");

    ///////////////////////

    const char* arrPtr[4] = { "dddd", "cccc", "bbbb", "aaaa" };
   qsort(arrPtr, 4, sizeof(const char*), compare_pointers);
    for (int i = 0; i < 4; i++)
    {
            printf("[%s]", arrPtr[i]);
    }
	return 0;
}
