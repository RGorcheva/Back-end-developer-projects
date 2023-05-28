/*
Използвайте typedef за да дефинирате алтернативни имена на следните типове:
● масив с 8 int елемента: arr8_i
● указател към arr8_i: arr8_i_ptr
● масив с 8 елемента от тип arr8_i: arr2d8_i
● указател към arr2d8_i: arr2d8_i_ptr
Използвайте enum константа за размера - 8
Дефинирайте функции за принтиране на arr8_i и на arr2d8_i.
Създайте променливи от четирите типа, като ги инициализирате(при дефиницията).
Инициализирайте arr8_i_ptr и arr2d8_i_ptr променливите с адреси на compound literalи(при дефиницията).
*/
#include <stdio.h>

#define ARR_SIZE_8 8

typedef int arr8_i[ARR_SIZE_8];
typedef arr8_i* arr8_i_ptr;
typedef arr8_i arr2d8_i[ARR_SIZE_8];
typedef arr2d8_i* arr2d8_i_ptr;

void print_arr8_i(arr8_i_ptr pArr, int elementCount);
void print_arr2d8_i(arr2d8_i_ptr pArr2d, int rows, int cols);

int main(void)
{
	arr8_i arr = { 1, 2, 3, 4, 5, 6, 7, 8 };
	arr8_i_ptr pArr = &(int[ARR_SIZE_8]){ 0 };
	arr2d8_i arr2d = { { 1, 2, 3, 4, 5, 6, 7, 8 },
					   { 9, 2, 3, 4, 5, 6, 7, 8 },
					   { 10, 3, 3, 4, 5, 6, 7, 8 },
					   { 11, 4, 4, 4, 5, 6, 7, 8 },
				   	   { 12, 5, 5, 5, 5, 6, 7, 8 },
					   { 13, 6, 6, 6, 6, 6, 7, 8 },
					   { 14, 7, 7, 7, 7, 7, 7, 8 },
					   { 15, 8, 8, 8, 8, 8, 8, 8 }
	};
	arr2d8_i_ptr pArr2d = &(int[ARR_SIZE_8][ARR_SIZE_8]) { 0 };
	pArr = &arr;
	print_arr8_i(pArr, ARR_SIZE_8);
	pArr2d = &arr2d;
	print_arr2d8_i(pArr2d, ARR_SIZE_8, ARR_SIZE_8);
	return 0;
}
void print_arr8_i(arr8_i_ptr pArr, int elementCount)
{
	for (int i = 0; i< elementCount; i++)
	{
		printf("%d\t", *(*pArr+i));
	}
	printf("\n\n");
}
void print_arr2d8_i(arr2d8_i_ptr pArr2d, int ROWS, int COLS)
{
	for (int row= 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; col++)
		{
			printf("%d\t", *(*(*pArr2d + row) + col));
		}
		printf("\n");
	}
}
