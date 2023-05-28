/* Създайте С програма, която калкулира стойността на покупки в магазин за хранителни
стоки. Клиентът може да закупи различна комбинация от продукти. В магазина има
следните налични продукти и цени:
Домати- 4.5 лв.за килограм,
Брашно 1.80 лв. за килограм,
Кисело мляко - 0.50 лв. за брой,
Сладолед на фунийки 0.60 лв. броя
Бонбони 1.50 лв. за килограм,
Близалки 0.15 лв. за брой. */

#include <stdio.h>

int main()
{
    int iChooseProduct = -1;
    float fProductPrice = -1;
    float fChooseQuantity = -1;
    float fPrice = -1;
    float fFinalPrice = 0;
    int iContinue = -1;

    printf("\n1. Tomato - 4.50 lv");
    printf("\n2. Flavour - 1.80 lv");
    printf("\n3. Yogurt - 0.50 lv");
    printf("\n4. Icecream - 0.60 lv");
    printf("\n5. Candies - 1.50 lv");
    printf("\n6. Lolypop - 0.15 lv");

    do
    {
        printf("\nChoose product 1-6?");
        scanf("%d", &iChooseProduct);
        printf("\nQuantity?");
        scanf("%f", &fChooseQuantity);

        switch (iChooseProduct)
        {
        case 1: {fProductPrice = 4.50; break; }
        case 2: {fProductPrice = 1.80; break; }
        case 3: {fProductPrice = 0.50; break; }
        case 4: {fProductPrice = 0.60; break; }
        case 5: {fProductPrice = 1.50; break; }
        case 6: {fProductPrice = 0.15; break; }
        default: {fProductPrice = 0.00; }
        }

        fPrice = fProductPrice * fChooseQuantity;
        fFinalPrice += fPrice;
        printf("\nDo you need something else? - Y=1/N=0");
        scanf("%d", &iContinue);
    } while (iContinue == 1);

    printf("\nYour bill is %02f", fFinalPrice);
    return 0;
}
