/*
Направете бягаща светлина, като приемете, че всеки бит от
дадена променлива, е свързан с лампа (или светодиод). Когато битът е
нула, лампата не свети, когато е единица свети.
Примерно, ако генерирате последователност:
1, 2, 3, 4, се получава следното:
1 *....................
2 .*...................
4 ..*..................
8 ...*................. ...
За да генерирате закъснение, използвайте следната функция от C runtime:
#include <unistd.h>
unsigned int sleep(unsigned int seconds);
*/

#include <stdio.h>
#include <Windows.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>

void print_bin(unsigned n)
{
    unsigned i;
    for (i = 1 << 31; i > 0; i = i >> 1)
        (n & i) ? printf("*") : printf(" ");
    printf("\r");
}

int main()
{
    unsigned int uiNumber = 0;
    unsigned int pow2 = 0;

    for (int i = 32; i > 0; --i)
    {
        system("cls");
        uiNumber = (unsigned int)pow(2, i);
        print_bin(uiNumber);
        Sleep(10);
    }

    return 0;
}