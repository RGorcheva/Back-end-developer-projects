#include <stdio.h>

int main(void)
{
   int matrix[3][4] = { 0 };
   //matrix == &matrix[0];
   //*matrix == matrix[0];
   //*matrix == *&matrix[0];
   //*matrix == matrix[0];
   //**matrix = matrix[0][0];
   //*(matrix + 1) == *&matrix[1];
   //*(matrix + 1) == matrix[1];

   printf("matrix:               %p\n", matrix);
   printf("*matrix:              %p\n", *matrix);
   printf("&**matrix:            %p\n", &**matrix);
   printf("&matrix[0]:           %p\n", &matrix[0]);
   printf("&matrix[0][0]:        %p\n", &matrix[0][0]);
   printf("sizeof(matrix):       %i\n", (int)sizeof(matrix));
   printf("sizeof(matrix[0]):    %i\n", (int)sizeof(matrix[0]));
   printf("sizeof(matrix[0][0]): %i\n", (int)sizeof(matrix[0][0]));

   return 0;
}