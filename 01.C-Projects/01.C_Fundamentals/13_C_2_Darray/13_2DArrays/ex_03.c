#include <stdio.h>

void f(int* pi, int arr[8])
{
   printf("pi:       %p\n", pi);
   printf("*pi:      %i\n", *pi);
   printf("&pi:      %p\n", &pi);

   printf("arr:      %p\n", arr);
   printf("*arr:     %i\n", *arr);
   printf("&arr:     %p\n", &arr);

   printf("&arr[0]:  %p\n", &arr[0]);
   printf("&arr[1]:  %p\n", &arr[1]);

   for (int* iter = arr; iter != arr + 8; ++iter)
   {
      *iter = 4;
      //arr[i] = 4;
      //*(arr + i) = 4;
   }

   for (size_t i = 0; i < 8; i++)
   {
      arr[i] = 4;
      *(arr + i) = 4;
   }
}

int main(void)
{
   int arr[8] = { 1 };
   int i = 9;
   int* pi = &i;
   int* pi2 = arr;

   int** ppi = &pi;

   pi = pi2;

   *pi = *pi2;

   pi[4] = 4;
   arr[4] = 4;

   ++pi;
   arr;



   arr[4] = 4;
   
   printf("pi:       %p\n", pi);
   printf("*pi:      %i\n", *pi);
   printf("&pi:      %p\n", &pi);

   printf("arr:      %p\n", arr);
   printf("*arr:     %i\n", *arr);
   printf("&arr:     %p\n", &arr);

   printf("&arr[0]:  %p\n", &arr[0]);
   printf("&arr[1]:  %p\n", &arr[1]);


   



   f(pi, arr);

   return 0;
}