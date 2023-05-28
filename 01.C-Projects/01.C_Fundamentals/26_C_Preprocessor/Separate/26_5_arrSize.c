/*
Дефинирайте макрос ARRAY_SIZE, който връща броя на елементи на масив
*/

#include <stdio.h>

#define ARRAY_SIZE(ARR) (sizeof(ARR) / sizeof((ARR)[0]))

int main(void)
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	printf("\nARRAY_SIZE(arr) = %ld", ARRAY_SIZE(arr));
	return 0;
}

