/*
Дефинирайте макрос SORT, който сортира масив от целочислени стойности
*/

#include <stdio.h>

#define SORT(arr,size,type) {\
	int i=0;\
	for(; i<(size-1); i=(i+1))\
	{\
		int min=arr[i];\
		int p=i;\
		for(int j=(i+1); j<size; j=(j+1))\
		{\
			if(min>arr[j])\
			{\
				min=arr[j];\
				p=j;\
			}\
        }\
		arr[p]=arr[i]; arr[i]=min;\
	}\
}

int main(void)
{
	int arr[10] = { 3, 1, 5, 9, 4, 8, 7, 2, 6, 10 };
	int size = 10;
	SORT(arr, size, int);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

