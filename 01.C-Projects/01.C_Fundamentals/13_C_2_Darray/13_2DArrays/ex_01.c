#include <stdio.h>

int main(void)
{
   int i = 1;
   int* pi = &i;

   printf("i:   %i\n", i);
   printf("&i:  %p\n", &i);
   printf("pi:  %p\n", pi);
   printf("*pi: %i\n", *pi);
   printf("&pi: %p\n", &pi);

   return 0;
}
