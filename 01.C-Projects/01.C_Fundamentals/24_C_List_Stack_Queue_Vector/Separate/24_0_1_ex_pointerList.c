/*
Списък - поинтер към структура
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int node_data;
typedef struct list_node
{
	node_data data;
	struct list_node* next;
} list_node;

typedef list_node* list;

void list_init(list* list) //инициаализираме новосъздаден поинтер с NULL, list* = адрес към поинтера
{
	*list = NULL;
}
bool list_isEmpty(list* list) //Проверява дали списъка е празен. Ако поинтера сочи към NULL приемаме, че е празен.
{
	return *list == NULL;
}
list_node* list_first(list* list)//Връща първия елемент от списъка
{
	return *list;
}
list_node* list_last(list* list)//Връща последния елемент от списъка
{
	list_node* it = list_first(list);
	while (it->next != NULL)
	{
		it = it->next;
	}
	return it;
}
list_node* list_at(list* list, size_t idx)//Връща поинтер към елемент с индекс idx.
{
	list_node* result = list_first(list);
	for (size_t i = 0; i != idx; ++i)
	{
		result = result->next;
	}
	return result;
}
list_node* list_findIndxElem(list* list, size_t indx)//Връща поинтер към елемент с индекс idx.
{
	list_node* it = list_first(list);
	size_t count = 0;
	while (count != indx)
	{
		it = it->next;
		++count;
	}
	return it;
}
node_data list_get(list* list, size_t indx)//Връща стойността на елемент с индекс idx.
{
	list_node* it = list_findIndxElem(list, indx);
	return it->data;
}
void list_set(list* list, size_t idx, node_data value)//Присвоява стойност value на елемент с индекс idx.
{
	list_node* at = list_at(list, idx);
	at->data = value;
}
size_t list_size(list* list)
{
	list_node* it = list_first(list);
	size_t count = 0;
	while (it != NULL)
	{
		it = it->next;
		count++;
	}
	return count;
}
void list_insert(list* list, size_t idx, node_data dValue)
{
	list_node* prev = NULL;
	list_node* next = list_first(list);
	for (size_t i = 0; i != idx; ++i)
	{
		prev = next;
		next = next->next;
	}
	list_node* new = (list_node*)malloc(sizeof(list_node));
	if (new == NULL)
	{
		fprintf(stderr, "Cannot alocate memory!");
		return;
	}
	new->next = next;
	new->data = dValue;
	if (prev != NULL)
	{
		prev->next = new;
	}	
	else
	{
		*list = new;
	}
}
void list_pushback(list* list, node_data data)
{
	list_node* new = (list_node*)malloc(sizeof(list_node));
	if (new == NULL)
	{
		fprintf(stderr, "Cannot alocate memory!");
		return;
	}
	new->data = data;
	new->next = NULL;
	if (*list != NULL)
	{
		list_node* last = list_last(list);
		last->next = new;
	}
	else
	{
		*list = new;
	}
}
void list_delete(list* list, size_t idx)
{
	list_node* prev = NULL;
	list_node* at = list_first(list);
	for (size_t i = 0; i != idx; ++i)
	{
		prev = at;
		at = at->next;
	}
	list_node* next = at->next;
	free(at);
	if (prev != NULL)
		prev->next = next;
	else
		*list = next;
}
void list_empty(list* list)
{
	list_node* it = list_first(list);
	while (it != NULL)
	{
		list_node* next = it->next;
		free(it);
		it = next;
	}
	*list = NULL;
}
void list_print(list* list)
{
	list_node* it = list_first(list);
	while(it->next != NULL)
	{
		printf("%d ->", it->data);
	}
	printf("\n");
}
void list_iterate_ptr(list* list, void (*f)(node_data*))
{
	list_node* it = list_first(list);
	while (it != NULL)
	{
		f(&it->data);
		it = it->next;
	}
}
void list_iterate(list* list, void (*f)(node_data))
{
	list_node* it = list_first(list);
	while (it != NULL)
	{
		f(it->data);
		it = it->next;
	}
}

int main(void)
{
	list list;
	list_init(&list);
	list_pushback(&list, 1);
	list_pushback(&list, 2);
	list_pushback(&list, 3);
	list_print(&list);
	list_insert(&list, 1, 4);
	list_print(&list);

	printf("nValue index 1 = %d\n", list_get(&list, 1));
	list_delete(&list, 1);
	list_print(&list);
	size_t iCountElements = list_size(&list);
	printf("\nNumber of elements: %zu\n", iCountElements);
	list_print(&list);
	list_node* nodeN0 = list_findIndxElem(&list, 0);
	list_node* nodeN1 = list_findIndxElem(&list, 1);
	list_node* nodeN2 = list_findIndxElem(&list, 2);
	printf("\n Index 0 : %d", nodeN0->data);
	printf("\n Index 1 : %d", nodeN1->data);
	printf("\n Index 2 : %d", nodeN2->data);
	//pfirst = list_empty(pfirst);
	list_print(&list);
	return 0;
}

