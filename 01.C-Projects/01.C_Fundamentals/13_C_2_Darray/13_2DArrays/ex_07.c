#include <stdio.h>

int main(int argc, char *argv[])
{
   char matrix[3][4] = { 0 };

   printf("char matrix[3][4] = { 0 };\n\n");

   printf("sizeof(char*) == %i\n", sizeof(char*));
   printf("sizeof(matrix[0]) == %zu\n", sizeof(matrix[0]));
   printf("sizeof(&matrix[0]) == %zu\n", sizeof(&matrix[0]));
   printf("sizeof(matrix[0][0]) == %zu\n", sizeof(matrix[0][0]));
   printf("sizeof(&matrix[0][0]) == %zu\n", sizeof(&matrix[0][0]));
   printf("sizeof(matrix) == %zu\n", sizeof(matrix));
   printf("sizeof(*matrix) == %zu\n", sizeof(*matrix));
   printf("sizeof(**matrix) == %zu\n\n", sizeof(**matrix));

   if (matrix == &matrix[0])                       printf("matrix == &matrix[0] == %p == %p\n", matrix, &matrix[0]);
   if (matrix[0] == &matrix[0][0])                 printf("matrix[0] == &matrix[0][0] == %p == %p\n", matrix[0], &matrix[0][0]);
   if (matrix[1] == &matrix[1][0])                 printf("matrix[1] == &matrix[1][0] == %p == %p\n", matrix[1], &matrix[1][0]);
   if (*matrix == matrix[0])                       printf("*matrix == matrix[0] == %p == %p\n", *matrix, matrix[0]);
   if (*(matrix + 1) == matrix[1])                 printf("*(matrix + 1) == matrix[1] == %p == %p\n", *matrix, matrix[0]);
   if (*matrix == *&matrix[0])                     printf("*matrix == *&matrix[0] == %p == %p\n", *matrix, *&matrix[0]);
   if (*matrix == &matrix[0][0])                   printf("*matrix == &matrix[0][0] == %p == %p\n", *matrix, &matrix[0][0]);
   if (**matrix == *&matrix[0][0])                 printf("**matrix == *&matrix[0][0] == (char)%i == (char)%i\n", (int)(**matrix), (int)(*&matrix[0][0]));
   if (&matrix[2][1] == &(*(*(matrix + 2) + 1)))   printf("&matrix[2][1] == &(*(*(matrix + 2) + 1)) == %p == %p\n", &matrix[2][1], &(*(*(matrix + 2) + 1)));

   *(matrix + 2) = 3;
   (*matrix) + 2 = 3;

   return 0;
}