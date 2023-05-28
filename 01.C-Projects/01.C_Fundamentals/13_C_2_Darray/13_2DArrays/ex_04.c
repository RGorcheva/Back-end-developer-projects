#include <stdio.h>


void f(char arr[])
{
   printf("f: %i\n", (int)sizeof arr);
}

void g(char arr[10])
{
   printf("g: %i\n", (int)sizeof arr);
}

void h(char * ptr)
{
   printf("h: %i\n", (int)sizeof ptr);
}

int main(void)
{
   char arr[32] = { 0 };

   printf("sizeof(char): %d\n", (int)sizeof(char));
   printf("sizeof(char*): %d\n", (int)sizeof(char*));

   f(arr);
   g(arr);

   return 0;
}
