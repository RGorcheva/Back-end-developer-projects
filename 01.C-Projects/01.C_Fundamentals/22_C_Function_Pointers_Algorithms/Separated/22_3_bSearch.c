/*
Използвайте стандартната функция bsearch от stdlib.h за да откриете някоя от стринговите литерали от сортирания лексикографски
масив от указатели към литерали
void *bsearch(const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *))
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\Library\inputOutputFunc.h"
#include "..\Library\stringFunc.h"

int compare_pointers(const void* a, const void* b)
{
    const char* pA = *(const char**)a;
    const char* pB = *(const char**)b;

    return  (strcmp(pA, pB));
}

int main(void)
{
    const char* arrPtr[4] = { "aaaa", "bbbb", "cccc", "dddd" };
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
    return 0;
}
