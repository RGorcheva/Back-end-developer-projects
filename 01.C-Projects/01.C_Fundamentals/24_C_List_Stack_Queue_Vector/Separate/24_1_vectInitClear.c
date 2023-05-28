/*
Дефинирайте нов тип - динамичен масив(vector) с указатели към стрингове (към началото им - char*).
Дефинирайте следните интерфейсни функции (”my_” e примерно име на библиотека. Би могло и да е “str”,
тъй като е списък с char* елементи):
● Функция за инициализация на членовете на масива:
void my_vector_init(my_vector v);
Приемлив интерфейс е и : void my_vector_init(my_vector *v);
Същото важи и за останалите функции.
● Функция за проверка на това дали масивът е празен:
_Bool my_vector_empty(my_vector v);
● Функция за премахване на всички елементи от масива:
void my_vector_clear(my_vector v);
● Функция, която връща броя на елементите на масива:
size_t my_vector_size(my_vector v);
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define VECTOR_CAPACITY 10

typedef char* vector_data;

typedef struct vector
{
	vector_data* data;
	size_t size;
	size_t capacity;
} vector;

bool vectorStr_isEmpty(vector* vec)
{
	return vec->size == 0;
}
void vectorStr_init(vector* vec)
{
	vec->data = NULL;
	vec->size = 0;
	vec->capacity = VECTOR_CAPACITY;
	vec->data = (vector_data*)malloc(sizeof(vector_data)*vec->capacity);
}
size_t vectorStr_size(vector* vec)
{
	return vec->size;
}
void vectorStr_clear(vector* vec)
{
	vec->size = 0;
	vec->capacity = 0;
	free(vec->data);
	vec->data = NULL;
}
void vectorStr_print(vector* vec)
{
	vector_data* it = vec->data;
	for (int i = 0; i < vec->size; i++)
	{
		printf("\nvec %d - %s", i, *it);
		it++;
	}
}

int main(void)
{
	vector vect;
	vectorStr_init(&vect);
	printf("\n%d", vectorStr_isEmpty(&vect));
	vector_data* it = vect.data;
	for (int i = 0; i < VECTOR_CAPACITY; i++)
	{
		it[i] = "new";
		vect.size++;
	}
	printf("\n%d", vectorStr_isEmpty(&vect));
	vectorStr_print(&vect);
	vectorStr_clear(&vect);
	return 0;
}

