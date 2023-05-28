#include "hw_4.h"
#include <stdio.h>
#include <limits.h>
#include <string.h>

#define PI_CONST 3.14

int g_iVar = 0;

void print_bin31(unsigned n)
{
    unsigned i;
    for (i = 1U << 31; i > 0; i = i >> 1)
        (n & i) ? printf("1") : printf("0");
    printf("\n");
}
void print_bin63(unsigned long n)
{
    unsigned long long i;
    for (i = 1ULL << 63; i > 0; i = i >> 1)
        (n & i) ? printf("1") : printf("0");
    printf("\n");
}
void testGlobalVar(void)
{
    g_iVar += 1;
}
int testStaticVar(int iVar)
{
    static int sA = 0;
    sA++;
    return iVar += sA;
}
double circleArea(double R)
{
    return R * R * PI_CONST;
}
double ellipseArea(double a, double b)
{
    return a * b * PI_CONST;
}

void hw_4_0_1_binarry(void)
/*
Запишете в четири последователни байта в паметта със стойност
0xAA(10101010) и разпечатайте съдържанието на горните байтове, ако типът
е:
float,
signed int,
unsigned int
*/
{
    printf("\n----------------task 4_0_1------------------\n");
    float fVariable = 0xAA.p0f;
    signed int siVariable = 0xAA;
    unsigned int uiVariable = 0xAAu;

    print_bin31((unsigned)(fVariable));
    print_bin31((unsigned)(siVariable));
    print_bin31(uiVariable);
}
void hw_4_0_2_binarry(void)
/*
Запишете в осем последователни байта в паметта със стойност
0xBB(1011 1011) и разпечатайте съдържанието на горните
байтове, ако типът е:
double,
signed long long,
unsigned long long
*/
{
    printf("\n----------------task 4_0_2------------------\n");
    size_t sizeIntLongLong = sizeof(unsigned long long int);
    printf("Size of unsigned long long int %zu\n", sizeIntLongLong);
    double dVariable = 0xBB.p0;
    signed long long int slliVariable = 0xBBll;
    unsigned long long int ulliVariable = 0xBBull;

    print_bin63((unsigned long int)(dVariable));
    print_bin63((unsigned long)(slliVariable));
    print_bin63((unsigned long)(ulliVariable));
}
void hw_4_0_3_printString(void)
/*
Напишете програма, която пресмята колко символа има в един низ преди
края на низа, обозначен със символа ‘\0’. Как трябва да изглежда
програмата:
1. Декларираме и инициализираме един низ - char s[ ] = “Hi”;
2. Декларираме и инициализираме променлива i, която ще увеличаваме
всеки път, когато искаме да видим следващия символ от низа “Hi”.
3. Принтираме съответната буква от низа printf(“%c”, s[i]);
4. Принтирайте броя на буквите в низа.
*/
{
    printf("\n----------------task 4_0_3------------------\n");
    char s[] = "Hi";
    size_t sizeS = sizeof(s);
    int i = 0;

    for (i = 0; i < sizeS; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
    printf("String lenght is %d.\n", (int)sizeS - 1);
}
void hw_4_11_reverseString(void)
/*
Ако имаме символен низ от символа char str[] = “Hello”;
копирайте всеки един от неговите символи в низ, който да изглежда
огледален на него. Ето така char rts[] = “ollеH”; и принтирайте
резултата.
*/
{
    printf("\n----------------task 4_11------------------\n");
    char str[10] = "Hello";
    int sizeStr = (int)strlen(str);
    char rts[10];
    int i = 0;

    for (i = 0; i < sizeStr; i++)
    {
        rts[i] = str[sizeStr - 1 - i];
    }
    rts[sizeStr] = str[sizeStr];

    for (i = 0; i < sizeStr; i++)
    {
        printf("%c", rts[i]);
    }
    printf("\n%d", sizeStr);
}
void hw_4_12_changeSymbol(void)
/*
Ако имаме символен низ char str[] = “Hеllo”, заменете
буквите l с х на същия символен низ и отпечатайте резултата на
конзолата.
*/
{
    printf("\n----------------task 4_12------------------\n");
    char str[] = "Hello";
    int i = 0;
    size_t sizeStr = sizeof(str);

    for (i = 0; i < sizeStr; i++)
    {
        if (str[i] == 'l')
        {
            str[i] = 'x';
        }
    }

    for (i = 0; i < sizeStr; i++)
    {
        printf("%c", str[i]);
    }
}
void hw_4_13_changeToLower(void)
/*
Ако имаме символен низ char str[] = “HELLO”, заменете
всичките символи с главна буква със съответните символи с малка
буква.
*/
{
    printf("\n----------------task 4_13------------------\n");
    char str[] = "HELLO";
    int i = 0;
    size_t sizeStr = sizeof(str);

    for (i = 0; i < (sizeStr - 1); i++)
    {
        str[i] = str[i] + 32;
    }

    for (i = 0; i < sizeStr; i++)
    {
        printf("%c", str[i]);
    }
}
void hw_4_14_globalVariety(void)
/*
Напишете глобална променлива, която увеличаваме с 1 във
функция void test(). Извикайте функцията три пъти test() от main()
принтирайте стойността на глобалната променлива.
*/
{
    printf("\n----------------task 4_14------------------\n");
    printf("Enter x = ");
    scanf_s("%d", &g_iVar);

    testGlobalVar();
    printf("\nx = x + 1 = %d", g_iVar);

    testGlobalVar();
    printf("\nx = x + 1 = %d", g_iVar);

    testGlobalVar();
    printf("\nx = x + 1 = %d", g_iVar);
}
void hw_4_15_staticVariable(void)
/*
Използвайте статична локална променлива, за да постигнете
същото поведение, описано в задача 14.
*/
{
    printf("\n----------------task 4_15------------------\n");
    int iVar = 0;
    printf("Enter x = ");
    scanf_s("%d", &iVar);

    printf("\nx = x + 1 = %d", testStaticVar(iVar));
    printf("\nx = x + 1 = %d", testStaticVar(iVar));
    printf("\nx = x + 1 = %d", testStaticVar(iVar));
}
void hw_4_16_circleАреа(void)
/*
Да се дефинира константата Пи (3.14159...) и да се напише
функция, която изчислява лицето на кръг по даден радиус (Пи * R * R).
В main() да се извика горната функция с радиуси 1, 1.5, 13.
*/
{
    printf("\n----------------task 4_16------------------\n");
    double dR = 0.0;

    dR = 1.0;
    printf("\nS (R=1) = %.2lf", circleArea(dR));

    dR = 1.5;
    printf("\nS (R=1.5) = %.2lf", circleArea(dR));

    dR = 13.0;
    printf("\nS (R=13) = %.2lf", circleArea(dR));
}
void hw_4_17_ellipse(void)
/*
Към задача 16 да се добави втора функция, която изчислява
лицето на елипса по зададени два параметъра ( Пи * A * B)
*/
{
    printf("\n----------------task 4_17------------------\n");
    double dR = -1.0;
    double dA = -1.0;
    double dB = -1.0;

    dR = 1.0;
    printf("\nScircle (R=1) = %.2lf", circleArea(dR));

    dR = 1.5;
    printf("\nScircle (R=1.5) = %.2lf", circleArea(dR));

    dR = 13.0;
    printf("\nScircle (R=13) = %.2lf", circleArea(dR));

    printf("\n A = ");
    scanf_s("%lf", &dA);
    printf("\n B = ");
    scanf_s("%lf", &dB);

    printf("\nSellipse (A=%.2lf, B=%.2lf) = %.2lf", dA, dB, ellipseArea(dA, dB));
}
void hw_4_18_vehicleShop(void)
/*
Довършете задачата за кемперите от миналия път като добавите
променлива, в която да се събират парите, които клиента дължи на компанията.
Принтирайте резултата.Питайте клиента дали иска още налични продукти.
*/
{
    printf("\n----------------task 4_18------------------\n");
    int iCount = -1;
    int iCountCaravan = 0;
    int iCountCamper = 0;
    int iPricePerOne = -1;
    int iFinalPrice = 0;
    int iVehicleType = -1;
    char cContinue = '0';

    printf("\nHallo! We ofer:\n3 caravans per price of 90\n3 campers per price of 100");

    do
    {
        printf("\nWhat type of vehicle do you need?\nCaravan=1\nCamper=2 ");
        scanf_s("%d", &iVehicleType);

        printf("\nHow many vehicles do you need? - max 3:");
        scanf_s("%d", &iCount);

        switch (iVehicleType)
        {
        case 1: {iPricePerOne = 90;
            iCountCaravan += iCount; break; }
        case 2: {iPricePerOne = 100;
            iCountCamper += iCount; break; }
        default: printf("\nNo such vehicle!");
        }

        if (iCountCaravan > 3 || iCountCamper > 3)
        {
            printf("\nWe have only 3 vehicles!");
            break;
        }

        iFinalPrice = iFinalPrice + iPricePerOne * iCount;
        printf("\nYour account is: %d", iFinalPrice);

        printf("\nDo you need something else? - Y/N");
        scanf_s(" %c", &cContinue, 1);
    } while (cContinue == 'y' || cContinue == 'Y');
}