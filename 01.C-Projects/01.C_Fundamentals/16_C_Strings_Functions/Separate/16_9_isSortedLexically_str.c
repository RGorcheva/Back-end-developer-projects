/*
Напишете функция, която проверява дали един масив от стрингове е сортиран
лексикографски.
*/

#include "../Library/stringFunctions.h"

int main(void) // todo: Check words in pointer array strings, not in only one word!!!
{
    const char str[5] = "abcd";
    puts(str);
    if (string_isSortedLexically(str))
    {
        printf("String is sorded lexically!");
    }
    else
    {
        printf("String is not sorded lexically!");
    }
    return 0;
}