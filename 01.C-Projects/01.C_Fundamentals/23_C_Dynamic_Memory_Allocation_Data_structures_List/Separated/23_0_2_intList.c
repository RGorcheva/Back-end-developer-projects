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

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node 
{
	int data;
	struct node* next;
} node;


bool list_isEmpty(node* list)
{
	return list == NULL;
}
void list_init(node* list)
{
	list = NULL;
}
int list_countElements(node* list)
{
	if (list == NULL)
		return 0;
	int count = 0;
	while (list != NULL)
	{
		++count;
		list = list->next;
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
	printf("\n");
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
node* list_findLast(node* plist)
{
	while (plist->next != NULL)
	{
		plist = plist->next;
	}
	return plist;
}
int list_getValue(node* list, int indx)
{
	node* pIndex =list_findIndexN(list, indx);
	return pIndex->data;
}
void list_pushBack(node* list, int data)
{
	node* pNode = (node*)malloc(sizeof(node));
	if (pNode == NULL)
	{
		fprintf(stderr, "Cannot alocate memory!");
		return;
	}
	pNode->data = data;
	pNode->next = NULL;
	node* plast = list_findLast(list);
	plast->next = pNode;
}
void list_insert(node* list, int indx, int data)
{
	node* new = (node*)malloc(sizeof(node));
	if (new == NULL)
	{
		fprintf(stderr, "Cannot alocate memory!");
		return;
	}
	new->data = data;
	node* prev = list_findIndexN(list, indx-1);
	new->next = prev->next;
	prev->next = new;
}
node* list_empty(node* list)
{
	if (list == NULL)
	{
		printf("\nlist is NULL pointer!!!");
		return NULL;
	}
	while (list != NULL)
	{
		node* temp = list->next;
		free(list);
		list = temp;
	}
	return NULL;
}
node* list_delete(node* list, int indx)
{
	if (list == NULL)
		return NULL;
	if (indx == 0)
	{
		node* first = list->next;
		free(list);
		return first;
	}
	node* first = list;
	int count = 0;
	while (count != indx-1)
	{
		++count;
		list = list->next;
	}
	node* prev = list;
	list = list->next;
	prev->next = list->next;
	free(list);
	return first;
}

int main(void)
{
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
	list_print(pfirst);
	list_insert(pfirst, 1, 4);
	list_print(pfirst);
	printf("nValue index 1 = %d\n", list_getValue(pfirst, 1));
	pfirst = list_delete(pfirst, 1);
	list_print(pfirst);
	int iCountElements = list_countElements(pfirst);
	printf("\nNumber of elements: %d\n", iCountElements);
	list_print(pfirst);
	node* nodeN0 = list_findIndexN(pfirst, 0);
	node* nodeN1 = list_findIndexN(pfirst, 1);
	node* nodeN2 = list_findIndexN(pfirst, 2);
	printf("\n Index 0 : %d", nodeN0->data);
	printf("\n Index 1 : %d", nodeN1->data);
	printf("\n Index 2 : %d", nodeN2->data);
	pfirst = list_empty(pfirst);
	list_print(pfirst);
	return 0;
}