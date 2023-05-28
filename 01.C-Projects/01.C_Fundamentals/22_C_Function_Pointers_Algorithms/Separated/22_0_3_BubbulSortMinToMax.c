/*
Съставете функция, която сортира елементите на масив от най-малък към най-голям по метода на Балончето.
*/

#include <stdio.h>

void bubbleSortMinToMax(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main(void)
{
	int arr[10] = { 3, 1, 5, 9, 4, 8, 7, 2, 6, 10 };
	int size = 10;
	bubbleSortMinToMax(arr, size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}