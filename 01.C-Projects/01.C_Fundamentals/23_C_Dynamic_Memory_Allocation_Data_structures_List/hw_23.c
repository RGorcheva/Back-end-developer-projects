#include "hw_23.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "../Library/inputOutputFunc.h"
#include "..\Library\stringFunc.h"

#define MAX_PERSON_NAME_LEN 64
#define SIZE 7
#define SIZE_2 2

typedef struct node
{
	int data;
	struct node* next;
} node;

int list_countElements(node* plist)
{
	if (plist == NULL)
		return 0;
	int count = 0;
	while (plist != NULL)
	{
		++count;
		plist = plist->next;
	}
	return count;
}
void list_print(node* plist)
{
	if (plist == NULL)
		return;
	while (plist != NULL)
	{
		printf("%d -> ", plist->data);
		plist = plist->next;
	}
}
node* list_findLast(node* plist)
{
	while (plist->next != NULL)
	{
		plist = plist->next;
	}
	return plist;
}
void list_pushBack(node* plist, int dataN)
{
	node* pNode = (node*)malloc(sizeof(node));
	if (pNode == NULL)
	{
		fprintf(stderr, "Cannot alocate memory!");
		return;
	}
	pNode->data = dataN;
	pNode->next = NULL;
	node* plast = list_findLast(plist);
	plast->next = pNode;
}
node* list_findIndexN(node* plist, int n)
{
	int countIndex = 0;
	while (plist != NULL)
	{
		if (countIndex == n)
			return plist;
		countIndex++;
		plist = plist->next;
	}
	return NULL;
}
node* list_empty(node* plist)
{
	if (plist == NULL)
	{
		printf("\nlist is NULL pointer!!!");
		return NULL;
	}
	while (plist != NULL)
	{
		node* temp = plist->next;
		free(plist);
		plist = temp;
	}
	return NULL;
}

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

bool searchSymbolA(const char* str)
{
	if (str == NULL)
	{
		return 0;
	}
	if (string_strchrFindFirstChar(str, 'a'))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void listStr_eraseIf(list* list, bool (*predicateFunc)(const char*))
{
	listStr* it = *list;
	int indx = 0;
	while (it != NULL)
	{
		if (predicateFunc(it->str))
		{
			if (it == *list)
			{
				listStr_erase(&it, indx);
				*list = it;
			}
			else
			{
				listStr_erase(&it, indx);
			}
		}
		else
		{
			indx++;
			it = it->next;
		}
	}
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

void hw_23_0_1_dynamicMemoryInt(void)
/*
Напишете програма, която иска от потребителя да въведе брой на елементите
на колекция от цели числа (int).
Заделете динамично точно толкова памет, колкото трябва за да се поберат
въведения брой цели числа. Използвайте malloc.
Напишете цикъл, в който искаме от потребителя да въведе стойност за всяко
число.
Използвайте функция, която принтира масив от int за да принтирате
въведените числа.
Освободете заделената динамична памет с free
*/
{
	printf("\n-----------------task 23_0_1-----------------------\n");
	int iNumberElements = 0;
	printf("Enter number of elements:");
	scanf_s("%d", &iNumberElements);
	int* ptr = NULL;
	ptr = (int*)malloc(iNumberElements * sizeof(int));
	int* it = ptr;
	for (; it < ptr + iNumberElements; it++)
	{
		printf("Enter number:");
		scanf_s("%d", it);
	}
	io_arrPrint(ptr, iNumberElements);
	free(ptr);
}
void hw_23_0_2_intList(void)
/*
Реализирайте списък от int.
За целта използвайте следната структура за елементите на списъка:
typedef struct node {
 int data;
 struct node * next;
} node;
Дефинирайте следните интерфейсни функции:
● Функция, която връща броя на елементите на списък
● Функция за добавяне на нов елемент в края на списъка
● Функция за достъп до елемент по подаден индекс
● Функция за премахване на всички елементи на списъка
*/
{
	printf("\n-----------------task 23_0_2-----------------------\n");
	node* pfirst = (node*)malloc(sizeof(node));
	if (pfirst == NULL)
	{
		fprintf(stderr, "\nCannot alocate memory!");
		return;
	}
	pfirst->data = 1;
	pfirst->next = NULL;
	list_pushBack(pfirst, 2);
	list_pushBack(pfirst, 3);
	int iCountElements = list_countElements(pfirst);
	printf("Number of elements: %d\n", iCountElements);
	list_print(pfirst);
	node* nodeN0 = list_findIndexN(pfirst, 0);
	node* nodeN1 = list_findIndexN(pfirst, 1);
	node* nodeN2 = list_findIndexN(pfirst, 2);
	printf("\n Index 0 : %d", nodeN0->data);
	printf("\n Index 1 : %d", nodeN1->data);
	printf("\n Index 2 : %d", nodeN2->data);
	pfirst = list_empty(pfirst);
	list_print(pfirst);
}
void hw_23_1_dynamicPrintSum(void)
/*
Да се направи програма, която заделя динамичен масив с брой елементи зададени от
потребителя. За всеки елемент от масива се очаква потребителят да въведе цяло число и
след това се изчислява сумата на всички елементи от масива.
*/
{
	printf("\n-----------------task 23_1-----------------------\n");
	int iNumberElements = 0;
	printf("Enter number of elements:");
	scanf_s("%d", &iNumberElements);
	int* ptr = NULL;
	ptr = (int*)malloc(iNumberElements * sizeof(int));
	if (ptr == NULL)
	{
		printf("\nCannot alocate memory!");
		return;
	}
	int* it = ptr;
	int sum = 0;
	for (; it < ptr + iNumberElements; it++)
	{
		printf("\nEnter number:");
		scanf_s("%d", it);
		sum += *it;
		printf("sum = %d", sum);
	}
	printf("\n");
	io_arrPrintSquareScopes("arr", ptr, iNumberElements);
	free(ptr);
}
void hw_23_2_reallocBuffer(void) 
/*
Заделете динамично памет за char* buffer с размер size = 2.
Използвайте getchar за въвеждане на текст от стандартния вход до достигане на EOF.
Реалокирайте динамично паметта при нужда (при въвеждане на все по-дълъг текст).
Принтирайте буфера и освободете паметта.
*/
{
	printf("\n-----------------task 23_2-----------------------\n");
	int size = SIZE_2;
	char* buffer = (char*)malloc(sizeof(char) * size);
	if (buffer == NULL)
	{
		printf("\nCannot alocate memory!");
		return;
	}
	char ch = '0';
	int i = 0;
	while ((ch = getchar()) != EOF)
	{
		buffer[i++] = ch;
		if (i >= size)
		{
			size = size * 2;
			char* new = (char*)realloc(buffer, sizeof(char) * size);
			if (new == NULL)
			{
				printf("\nCannot alocate memory!");
				return;
			}
			buffer = new;
		}
	}
	buffer[i] = '\0';
	printf("\n%s", buffer);
	free(buffer);
}
void hw_23_3_listInitClear(void)
/*
Дефинирайте нов тип - списък с указатели към стрингове (към началото им - char*).
Дефинирайте следните интерфейсни функции (”my_” e примерно име на библиотека. Би могло и да е “str”, тъй
като е списък с char* елементи):
● Функция за инициализация на членовете на списъка: void my_list_init(my_list ls);
● Приемлив интерфейс е и : void my_list_init(my_list *ls);
● Същото важи и за останалите функции.
● Функция за проверка на това дали списъкът е празен: _Bool my_list_empty(my_list ls);
● Функция за премахването на всички елементи на списъка: void my_list_clear(my_list ls);
*/
{
	printf("\n-----------------task 23_3-----------------------\n");
	listStr* first = NULL;
	printf("\nIs list empty? - %d", listStr_isEmpty(&first));
	first = (listStr*)malloc(sizeof(listStr));
	if (first == NULL)
	{
		fprintf(stderr, "\nCannot alocate memory!");
		return;
	}
	listStr_init(&first);
	printf("\nIs list empty? - %d", listStr_isEmpty(&first));
	listStr_print(&first);
	listStr_clear(&first);
}
void hw_23_4_listInsert(void)
/*
Дефинирайте функции за добавяне на елементи на начална, крайна и конкретна позиция
в списъка:
void my_list_push_back(char *data, my_list ls);
void my_list_push_front(char *data, my_list ls);
void my_list_insert(char *data, my_list ls, size_t pos);
*/
{
	printf("\n-----------------task 23_4-----------------------\n");
	listStr* first = NULL;
	listStr_pushBack(&first, arrPtr[2]);
	listStr_pushFront(&first, arrPtr[0]);
	listStr_pushBack(&first, arrPtr[3]);
	listStr_insert(&first, arrPtr[1], 2);
	listStr_print(&first);
	listStr_clear(&first);
}
void hw_23_5_listErase(void)
/*
Дефинирайте функции за изтриване на елементи на начална, крайна и конкретна
позиция в списъка :
void my_list_pop_back(my_list ls);
void my_list_pop_front(my_list ls);
void my_list_erase(my_list ls, size_t pos);
*/
{
	printf("\n-----------------task 23_5-----------------------\n");
	listStr* first = NULL;
	listStr_pushBack(&first, arrPtr[2]);
	listStr_pushFront(&first, arrPtr[0]);
	listStr_pushBack(&first, arrPtr[3]);
	listStr_insert(&first, arrPtr[1], 2);
	listStr_print(&first);
	printf("\n--------------------------");
	listStr_erase_back(&first);
	listStr_print(&first);
	printf("\n--------------------------");
	listStr_erase_front(&first);
	listStr_print(&first);
	printf("\n--------------------------");
	listStr_erase(&first, 1);
	listStr_print(&first);
	listStr_clear(&first);
}
void hw_23_6_listResize(void)
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
{
	printf("\n-----------------task 23_6-----------------------\n");
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
}
void hw_23_7_predicatErase(void)
/*
Дефинирайте функции за изтриване на елемент от списъка по зададен предикат - условие, дефинирано от
клиента, при което трием елемент:
size_t my_list_erase_if(my_list ls, _Bool (*predicateFunc)(char*));
Функцията, подадена от клиента като аргумент трябва да бъде извикана за всеки елемент от списъка.
Трием тези елементи, за които връща 1
*/
{
	printf("\n-----------------task 23_7-----------------------\n");
	listStr* first = NULL;
	listStr_pushBack(&first, arrPtr[2]);
	listStr_pushFront(&first, arrPtr[0]);
	listStr_pushBack(&first, arrPtr[3]);
	listStr_insert(&first, arrPtr[1], 2);
	listStr_print(&first);
	printf("\n--------------------------");
	listStr_resize_init(&first, 8, "new");
	listStr_print(&first);
	printf("\n--------------------------");
	listStr_eraseIf(&first, searchSymbolA);
	listStr_print(&first);
	listStr_clear(&first);
}
void hw_23_8_listIterateFunc(void)
/*
Дефинирайте функция за итериране на елементите на списъка, която приема указател към друга
функция, подадена от клиента, която извършва желаните операции на всеки отделен елемент от списъка.
void my_list_iterate(my_list ls, void (*iterFunc)(char*));
Функцията за итериране трябва да извиква подадената й като аргумент функция за всеки елемент на
списъка
*/
{
	printf("\n-----------------task 23_8-----------------------\n");
	listStr* first = NULL;
	listStr_pushBack(&first, arrPtr[2]);
	listStr_pushFront(&first, arrPtr[0]);
	listStr_pushBack(&first, arrPtr[3]);
	listStr_insert(&first, arrPtr[1], 2);
	listStr_print(&first);
	printf("\n--------------------------");
	listStr_iterate(&first, element_print);
	listStr_clear(&first);
}

