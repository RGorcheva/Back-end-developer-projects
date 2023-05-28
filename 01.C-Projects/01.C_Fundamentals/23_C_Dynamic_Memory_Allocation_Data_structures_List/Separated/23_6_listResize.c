/*
Дефинирайте функции за промяна на броя на елементите на списъка:
void my_list_resize(my_list ls, size_t elementsCount);
void my_list_resize_init(my_list ls, size_t elementsCount,char *defaultValue );
Ако elementsCount е по-малък от текущия размер, съдържанието на списъка става първите
elementsCount и останалите се унищожават.
Ако elementsCount е по-голямо от текущия размер, списъкът се разширява до elementsCount
брой елементи, като:
● my_list_resize инициализира новите елементи на NULL
● my_list_resize_init инициализира новите елементи на стойността на 3тия си параметър:
defaultValue
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 7

const char* arrPtr[7] = { "Sunday", "Monday", "Tuesday", "Wednsday", "Thursday", "Friday", "Satyrday" };

typedef struct listStr {
	const char* str;
	struct listStr* next;
}listStr;

typedef listStr* list;

bool listStr_isEmpty(list* list)
{
	return *list == NULL;
}
void listStr_init(list* list)
{
	printf("\nChoose string between:");
	int i = 0;
	for (int i = 0; i < SIZE; i++)
	{
		printf("\nPress %d to choose '%s'", i, arrPtr[i]);
	}
	int chooseI = -1;
	scanf_s("%d", &chooseI);
	(*list)->str = arrPtr[chooseI];
	(*list)->next = NULL;
}
void listStr_print(list* list)
{
	if (*list == NULL)
		return;
	listStr* it = *list;
	while (it != NULL)
	{
		printf("\n%s", it->str);
		it = it->next;
	}
}
void listStr_clear(list* list)
{
	if (*list == NULL)
	{
		printf("\nlist is NULL pointer!!!");
		return;
	}
	listStr* it = *list;
	while (it != NULL)
	{
		listStr* temp = it->next;
		free(it);
		it = temp;
	}
}

void listStr_pushBack(list* list, const char* pStr)
{
	listStr* it = *list;
	listStr* pNew = (listStr*)malloc(sizeof(listStr));
	if (pNew == NULL)
	{
		fprintf(stderr, "\nCannot alocate memory!");
		return;
	}
	pNew->str = pStr;
	pNew->next = NULL;
	if (*list == NULL)
	{
		*list = pNew;
	}
	else
	{
		while (it->next != NULL)
		{
			it = it->next;
		}
		it->next = pNew;
	}
}
void listStr_pushFront(list* list, const char* pStr)
{
	listStr* it = *list;
	listStr* pNew = (listStr*)malloc(sizeof(listStr));
	if (pNew == NULL)
	{
		fprintf(stderr, "\nCannot alocate memory!");
		return;
	}
	pNew->str = pStr;

	if (*list == NULL)
	{
		pNew->next = NULL;
	}
	else
	{
		pNew->next = it;
	}
	*list = pNew;
}
void listStr_insert(list* list, const char* pStr, size_t pos)
{
	listStr* it = *list;
	if (pos == 0)
	{
		listStr_pushFront(&it, pStr);
	}
	else
	{
		listStr* pNew = (listStr*)malloc(sizeof(listStr));
		if (pNew == NULL)
		{
			fprintf(stderr, "\nCannot alocate memory!");
			return;
		}
		pNew->str = pStr;
		size_t count = 1;
		while (count != pos)
		{
			it = it->next;
			count++;
		}
		listStr* temp = it->next;
		it->next = pNew;
		pNew->next = temp;
	}
}

size_t listStr_countElem(list* list)
{
	listStr* it = *list;
	size_t count = 0;
	while (it != NULL)
	{
		it = it->next;
		count++;
	}
	return count;
}
void listStr_erase_back(list* list)
{
	listStr* it = *list;
	size_t count = listStr_countElem(&it);
	size_t prev = 1;
	while (prev != count - 1)
	{
		it = it->next;
		prev++;
	}
	listStr* temp = it->next;
	it->next = NULL;
	free(temp);
}
void listStr_erase_front(list* list)
{
	listStr* it = *list;
	listStr* temp = it->next;
	free(it);
	*list = temp;
}
void listStr_erase(list* list, size_t pos)
{
	listStr* it = *list;
	if (pos == 0)
	{
		listStr_erase_front(&it);
		*list = it;
		return;
	}
	size_t count = 0;
	while (count != pos - 1)
	{
		it = it->next;
		count++;
	}
	listStr* prev = it;
	it = it->next;
	prev->next = it->next;
	free(it);
}

void listStr_resize(list* list, size_t elementsCount)
{
	listStr* it = *list;
	if (*list == NULL)
	{
		return;
	}
	size_t oldSize = listStr_countElem(&it);
	int minus = (int)elementsCount - (int)oldSize;
	if (minus > 0)
	{
		while (it->next != NULL)
		{
			it = it->next;
		}
		for (size_t i = 0; i < elementsCount - oldSize; i++)
		{
			listStr* pNew = (listStr*)malloc(sizeof(listStr));
			if (pNew == NULL)
			{
				fprintf(stderr, "\nCannot alocate memory!");
				return;
			}
			pNew->str = NULL;
			pNew->next = NULL;
			it->next = pNew;
			it = it->next;
		}
	}
	else if (minus  < 0)
	{
		size_t count = 1;
		while (count != elementsCount)
		{
			it = it->next;
			count++;
		}
		listStr* toErase = it->next;
		it->next = NULL;
		listStr_clear(&toErase);
	}
}
void listStr_resize_init(list* list, size_t elementsCount, char* defaultValue)
{
	listStr* it = *list;
	if (*list == NULL)
	{
		return;
	}
	size_t oldSize = listStr_countElem(&it);
	int minus = (int)elementsCount - (int)oldSize;
	if (minus > 0)
	{
		while (it->next != NULL)
		{
			it = it->next;
		}
		for (size_t i = 0; i < elementsCount - oldSize; i++)
		{
			listStr* pNew = (listStr*)malloc(sizeof(listStr));
			if (pNew == NULL)
			{
				fprintf(stderr, "\nCannot alocate memory!");
				return;
			}
			pNew->str = defaultValue;
			pNew->next = NULL;
			it->next = pNew;
			it = it->next;
		}
	}
	else if (minus < 0)
	{
		size_t count = 1;
		while (count != elementsCount)
		{
			it = it->next;
			count++;
		}
		listStr* toErase = it->next;
		it->next = NULL;
		listStr_clear(&toErase);
	}
}

int main(void)
{
	listStr* first = NULL;
	listStr_pushBack(&first, arrPtr[2]);
	listStr_pushFront(&first, arrPtr[0]);
	listStr_pushBack(&first, arrPtr[3]);
	listStr_insert(&first, arrPtr[1], 2);
	listStr_print(&first);
	printf("\n--------------------------");
	listStr_resize(&first, 8);
	listStr_print(&first);
	printf("\n--------------------------");
	listStr_resize_init(&first, 12, "new");
	listStr_print(&first);
	printf("\n--------------------------");
	listStr_resize(&first, 8);
	listStr_print(&first);
	printf("\n--------------------------");
	listStr_resize_init(&first, 4, "new");
	listStr_print(&first);
	listStr_clear(&first);
	return 0;
}