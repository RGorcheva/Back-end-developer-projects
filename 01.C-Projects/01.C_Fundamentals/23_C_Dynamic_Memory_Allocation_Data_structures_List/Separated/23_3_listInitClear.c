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

int main(void)
{
	listStr* first = NULL;
	printf("\nIs list empty? - %d", listStr_isEmpty(&first));
	first = (listStr*)malloc(sizeof(listStr));
	if (first == NULL)
	{
		fprintf(stderr, "\nCannot alocate memory!");
		return -1;
	}
	listStr_init(&first);
	printf("\nIs list empty? - %d", listStr_isEmpty(&first));
	listStr_print(&first);
	listStr_clear(&first);
	return 0;
}