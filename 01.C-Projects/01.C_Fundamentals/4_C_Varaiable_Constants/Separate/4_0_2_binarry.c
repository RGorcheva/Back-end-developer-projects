/*
Запишете в осем последователни байта в паметта със стойност 
0xBB(1011 1011) и разпечатайте съдържанието на горните 
байтове, ако типът е: 
double, 
signed long long, 
unsigned long long
*/

#include <stdio.h>
#include <limits.h>

void print_bin63(unsigned long n)
{
    unsigned long long i;
    for (i = 1ULL << 63; i > 0; i = i >> 1)
        (n & i) ? printf("1") : printf("0");
    printf("\n");
}

int main()
{
    size_t sizeIntLongLong = sizeof(unsigned long long int);
    printf("Size of unsigned long long int %zu\n", sizeIntLongLong);
    double dVariable = 0xBB.p0;
    signed long long int slliVariable = 0xBBll;
    unsigned long long int ulliVariable = 0xBBull;

    print_bin63((unsigned long int)(dVariable));
    print_bin63((unsigned long)(slliVariable));
    print_bin63((unsigned long)(ulliVariable));

    return 0;
}