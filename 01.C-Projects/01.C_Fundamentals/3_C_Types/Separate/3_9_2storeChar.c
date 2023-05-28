/*
Създайте С програма, която калкулира стойността на покупки в магазин за хранителни
стоки. Клиентът може да закупи различна комбинация от продукти. В магазина има
следните налични продукти и цени:
Домати- 4.5 лв.за килограм,
Брашно 1.80 лв. за килограм,
Кисело мляко - 0.50 лв. за брой,
Сладолед на фунийки 0.60 лв. броя
Бонбони 1.50 лв. за килограм,
Близалки 0.15 лв. за брой.
*/

#include <stdio.h>

int main()
{
    int iChooseProduct = -1;
    double dProductPrice = -1;
    double dChooseQuantity = -1;
    double dPrice = -1;
    double dFinalPrice = 0;
    char cContinue = '0';

    printf("\n1. Tomato - 4.50 lv");
    printf("\n2. Flavour - 1.80 lv");
    printf("\n3. Yogurt - 0.50 lv");
    printf("\n4. Icecream - 0.60 lv");
    printf("\n5. Candies - 1.50 lv");
    printf("\n6. Lolypop - 0.15 lv");

    do
    {
        printf("\nChoose product 1-6?");
        scanf_s("%d", &iChooseProduct);
        
        switch (iChooseProduct)
        {
        case 1: {dProductPrice = 4.50; break; }
        case 2: {dProductPrice = 1.80; break; }
        case 3: {dProductPrice = 0.50; break; }
        case 4: {dProductPrice = 0.60; break; }
        case 5: {dProductPrice = 1.50; break; }
        case 6: {dProductPrice = 0.15; break; }
        default: {dProductPrice = 0.00;
            printf("No such product!");}
        }

        printf("\nQuantity?");
        scanf_s("%lf", &dChooseQuantity);

        dPrice = dProductPrice * dChooseQuantity;
        dFinalPrice += dPrice;
        printf("\nDo you need something else? - Y/N");
        scanf_s(" %c", &cContinue);
    } while (cContinue == 'y' || cContinue == 'Y');

    printf("\nYour account is %02lf!", dFinalPrice);

    return 0;
}