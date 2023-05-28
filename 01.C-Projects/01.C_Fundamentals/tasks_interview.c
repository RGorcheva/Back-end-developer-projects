//1.Write a function to swap two integers without using a temporary variable.
//2.Write a program to reverse a given string.
//3.Write a function that takes an array of integers and its size as input, and returns the sum of all the elements.
//4.Write a program to find the maximum and minimum values in an array of integers.
//5.Write a function that takes two arrays of integers and their sizes as input, and returns a new array that 
//contains the elements that are common to both arrays.
//6.Write a function that takes a string as input and counts the number of vowels in it.
//7.Write a program that reads in a list of integers from the user and prints them out in reverse order..2

#define SIZE_MAX 100
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void swap_ints(int* a, int* b)
{
	*a = *a - *b;
	*b = *a + *b;
	*a = *b - *a;
}
void reverse_string(char* string)
{
	size_t len = strlen(string);
	for (size_t i = 0; i < len/2; i++)
	{
		char temp = string[i];
		string[i] = string[len - 1 - i];
		string[len - 1 - i] = temp;
	}
}
int sum_arr(int* arr, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum;
}
int arr_min(int* arr, int size)
{
	int min = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < min)
		{
			int temp = min;
			min = arr[i];
			arr[i] = temp;
		}
	}
	return min;
}
int arr_max(int* arr, int size)
{
	int max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			int temp = max;
			max = arr[i];
			arr[i] = temp;
		}
	}
	return max;
}
int* arr_common_elements(int* arr1, int* arr2, int* arr3, size_t size1, size_t size2, size_t* size3)
{
	for (size_t i = 0; i < size1; i++)
	{
		for (size_t j = 0; j < size2; j++)
		{
			if (arr1[i] == arr2[j])
			{
				int unique = 1;
				for (int s = 0; s < *size3; s++)
				{
					if (arr1[i] == arr3[s])
					{
						unique = 0;
						break;
					}
				}
				if (unique == 1)
				{
					arr3[*size3] = arr1[i];
					*size3 = *size3 + 1;
				}
			}
		}
	}
	return arr3;
}
int count_vowels(char* str)
{
	int count = 0;
	char* it = str;
	for (it; *it != '\0'; it++)
	{
		if (*it == 'a' || *it == 'A' || *it == 'o' || *it == 'O' || *it == 'u' || *it == 'U' ||
			*it == 'i' || *it == 'I' || *it == 'e' || *it == 'E')
		{
			count++;
		}
	}
	return count;
}
void print_arr(int* arr, size_t size)
{
	printf("arr = ");
	for (int i = 0; i < size; i++)
	{
		printf("%d, ", arr[i]);
	}
	printf("\n");
}

typedef struct list
{
	int data;
	struct list* next;
}list;

void list_pushBack(list** lis, int data)
{
	list* new = (list*)malloc(sizeof(list));
	if (new == NULL)
	{
		printf("Cannot alocate memory!\n");
	}
	else
	{
		new->data = data;
		new->next = NULL;
	}
	if (*lis == NULL)
	{
		*lis = new;
		return;
	}
	list* it = *lis;
	while (it->next != NULL)
	{
		it = it->next;
	}
	it->next = new;
}

void list_printReverse(list** lis)
{
	if (*lis == NULL)
	{
		printf("List is empty!\n");
		return;
	}
	list_printReverse(&((*lis)->next));
	printf("%d ", (*lis)->data);
}

int main(void)
{
	int a = 4;
	int b = 5;
	swap_ints(&a, &b);
	printf("a = %d\n", a);
	printf("b = %d\n", b);

	char string[] = "Hello, world!";
	reverse_string(string);
	printf("%s\n", string);
	int countVowels = count_vowels(string);
	printf("Number of vowels: %d\n", countVowels);
	int arr[5] = { 7, 1, 2, 3, 4 };
	int size = 5;
	int sum = sum_arr(arr, size);
	int min = arr_min(arr, size);
	int max = arr_max(arr, size);
	printf("sum = %d\n", sum);
	printf("min = %d\n", min);
	printf("max = %d\n", max);

	int arr1[SIZE_MAX] = { 7, 1, 1, 3, 4 };
	size_t size1 = 5;
	print_arr(arr1, size1);
	int arr2[SIZE_MAX] = { 8, 1, 3, 8, 4 };
	size_t size2 = 5;
	print_arr(arr2, size2);
	int arr3[SIZE_MAX] = { 0 };
	size_t size3 = 0;
	arr_common_elements(arr1, arr2, arr3, size1, size2, &size3);
	print_arr(arr3, size3);

	//list

	list* head = NULL;
	int data = 0;
	int elementsCount = 0;
	printf("Enter number of elements: ");
	int isScan = scanf("%d", &elementsCount);
	for (int i = 0; i < elementsCount; i++)
	{
		printf("Enter element: ");
		isScan = scanf("%d", &data);
		list_pushBack(&head, data);
	}
	list_printReverse(&head);
	return 0;
}