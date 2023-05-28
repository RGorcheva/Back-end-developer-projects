#include <stdio.h>


void f(int i, int* pi, int arr[8]);

int main(void)
{
   int i = 3;
   int* pi = &i;
   int arr[8] = { 1 };

   printf(">> int i = 3;\n");
   printf(">> int* pi = &i;\n");
   printf(">> int arr[8] = { 1 };\n\n");

   
   printf("i:        %i\n", i);
   printf("&i:       %p\n", &i);

   printf("pi:       %p\n", pi);
   printf("*pi:      %i\n", *pi);
   printf("&pi:      %p\n", &pi);

   printf("\n>> pi = arr;\n\n");
   pi = arr;

   printf("arr:      %p\n", arr);
   printf("*arr:     %i\n", *arr);
   printf("&arr:     %p\n", &arr);

   printf("&arr[0]:  %p\n", &arr[0]);
   printf("&arr[1]:  %p\n", &arr[1]);

   printf("pi:       %p\n", pi);
   printf("*pi:      %i\n", *pi);
   printf("&pi:      %p\n", &pi);

   pi = &i;

   printf("\n>> f(i, pi, arr);\n\n");
   f(i, pi, arr);

   return 0;
}

void f(int i, int* pi, int arr[8])
{
   printf(">> void f(int i, int* pi, int arr[8])\n");
   printf("&i:       %p\n", &i);

   printf("pi:       %p\n", pi);
   printf("*pi:      %i\n", *pi);
   printf("&pi:      %p\n", &pi);

   printf("arr:      %p\n", arr);
   printf("*arr:     %i\n", *arr);
   printf("&arr:     %p\n", &arr);

   printf("&arr[0]:  %p\n", &arr[0]);
   printf("&arr[1]:  %p\n", &arr[1]);
}