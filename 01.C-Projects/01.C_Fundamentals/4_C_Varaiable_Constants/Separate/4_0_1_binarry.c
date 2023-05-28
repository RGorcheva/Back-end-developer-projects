/*
Запишете в четири последователни байта в паметта със стойност 
0xAA(10101010) и разпечатайте съдържанието на горните байтове, ако типът 
е:
float, 
signed int, 
unsigned int
*/

#include <stdio.h>
#include <limits.h>

void print_bin31(unsigned n)
{
    unsigned i;
    for (i = 1U << 31; i > 0; i = i >> 1)
        (n & i) ? printf("1") : printf("0");
    printf("\n");
}

int main()
{
    float fVariable = 0xAA.p0f;
    signed int siVariable = 0xAA;
    unsigned int uiVariable = 0xAAu;

    print_bin31((unsigned)(fVariable));
    print_bin31((unsigned)(siVariable));
    print_bin31(uiVariable);

    return 0;
}