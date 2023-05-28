/*
Двойно свързан писък - отделна структура.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int node_data; //тип на данните

typedef struct list_node //структура с данни и двойно свързан списък
{
	node_data data;
	struct list_node* prev;
	struct list_node* next;
}list_node;

typedef struct list //структура за улеснение ма двойно свързаноия списък, пази информация за списъка
{
	list_node* first;
	list_node* last;
	size_t size;
}list;

void list_init(list* plist)
{
	plist->first = NULL;
	plist->last = NULL;
	plist->size = 0;
}
bool list_isEmpty(list* plist)
{
	return plist->first == NULL;
}
list_node* list_first(list* list)
{
	return list->first;
}
list_node* list_last(list* list)
{
	return list->last;
}

int main(void)
{
	list plist;
	list_init(&plist);

}

