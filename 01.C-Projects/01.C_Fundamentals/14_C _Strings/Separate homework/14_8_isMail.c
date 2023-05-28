/*
Напишете функция, която връща дали даден стринг е валиден email адрес.
*/

#include <stdio.h>
#include "../Library/stringFunctions.h"

int main(void)
{
    char mail[50] = { 0 };

    printf("Enter email!\n");
    scanf_s("%s", mail, 50);
    printf("\n%d", string_isMail(mail));
    return 0; 
}