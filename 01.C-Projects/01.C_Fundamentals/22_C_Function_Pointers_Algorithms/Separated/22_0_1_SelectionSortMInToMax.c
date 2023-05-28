/*
Съставете функция, която сортира елементите на масив от най-малък към най-голям по метода на Селекциите
*/

#include <stdio.h>

void sortArrSelectionMinToMax(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int min = arr[i];
		int p = i;
		for (int j = i+1; j < size; j++)
		{
			if (min > arr[j])
			{
				min = arr[j];
				p = j;
			}
		}
		arr[p] = arr[i];
		arr[i] = min;
	}
}

int main(void)
{
	int arr[10] = { 3, 1, 5, 9, 4, 8, 7, 2, 6, 10 };
	int size = 10;
	sortArrSelectionMinToMax(arr, size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}