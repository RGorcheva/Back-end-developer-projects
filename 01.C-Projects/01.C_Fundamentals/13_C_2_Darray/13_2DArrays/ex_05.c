#include <stdio.h>

int main(void)
{
   //int* iptr = { 1, 2, 3 };   // error
   int iarr[] = { 1, 2, 3 };  // ok

   char* chPtr = "123"; // compile-time error in c++ (pointer should be const)
   const char* c_chPtr = "123";
   const char c_chArr[] = "123";

   printf("sizeof(char)   : %i\n", (int)sizeof(char));
   printf("sizeof c_chArr : %i\n", (int)sizeof c_chArr);

   printf("sizeof(char*)  : %i\n", (int)sizeof(char*));
   printf("sizeof c_chPtr : %i\n", (int)sizeof c_chPtr);

   return 0;
}