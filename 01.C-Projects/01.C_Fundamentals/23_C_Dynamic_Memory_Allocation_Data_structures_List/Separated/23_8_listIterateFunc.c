/*
Дефинирайте функция за итериране на елементите на списъка, която приема указател към друга
функция, подадена от клиента, която извършва желаните операции на всеки отделен елемент от списъка.
void my_list_iterate(my_list ls, void (*iterFunc)(char*));
Функцията за итериране трябва да извиква подадената й като аргумент функция за всеки елемент на
списъка
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

void element_print(const char* str)
{
	printf("\n%s", str);
	return;
}
void listStr_iterate(list* list, void (*iterFunc)(const char*))
{
	listStr* it = *list;
	while (it != NULL)
	{
		iterFunc(it->str);
		it = it->next;
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
	listStr_iterate(&first, element_print);
	listStr_clear(&first);
	return 0;
}