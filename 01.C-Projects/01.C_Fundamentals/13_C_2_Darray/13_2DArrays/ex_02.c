#include <stdio.h>

void f(int i, int* pi)
{
   printf("&i:       %p\n", &i);
   printf("pi:       %p\n", pi);
   printf("&pi:      %p\n", &pi);
}

int main(void)
{
   int i = 1;
   int* pi = &i;

   printf("&i:       %p\n", &i);
   printf("pi:       %p\n", pi);
   printf("&pi:      %p\n", &pi);

   f(i, pi);

   return 0;
}

