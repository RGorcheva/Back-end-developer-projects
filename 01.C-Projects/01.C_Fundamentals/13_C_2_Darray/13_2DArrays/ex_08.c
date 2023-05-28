#include <stdio.h>

void print_arr_4(int** arr, int rows, int cols)
{
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < cols; j++)
      {
         arr[i][j] = i * j;
      }
   }
}

void print_arr_3(const int* begin, int rows, int cols)
{
   for (int i = 0; i != rows; ++i, putchar('\n'))
      for (int j = 0; j != cols; ++j)
         printf("\t%d", begin[i * cols + j]);
}

#define ARR_COLS 4

void print_arr_1(const int arr[][ARR_COLS], int rows)
{
   for (int i = 0; i != rows; ++i, putchar('\n'))
      for (int j = 0; j != ARR_COLS; ++j)
         printf("\t%d", arr[i][j]);
}
void print_arr_2(const int(*arr)[ARR_COLS], int rows)
{
   for (int i = 0; i != rows; ++i, putchar('\n'))
      for (int j = 0; j != ARR_COLS; ++j)
         printf("\t%d", arr[i][j]);
}

#define ARR_ROWS 3

void print_arr_0(const int arr[ARR_ROWS][ARR_COLS])
{
   for (int i = 0; i != ARR_ROWS; ++i, putchar('\n'))
      for (int j = 0; j != ARR_COLS; ++j)
         printf("\t%d", arr[i][j]);
}

int main(void)
{
   int arr[ARR_ROWS][ARR_COLS] = { 
      { 1, 2, 3, 4 },
      { 5, 6, 7, 8 },
      { 9, 10, 11, 12 },
   };

   print_arr_0(arr);
   print_arr_1(arr, ARR_ROWS);
   print_arr_2(arr, ARR_ROWS);
   print_arr_3(*arr, ARR_ROWS, ARR_COLS);

   return 0;
}