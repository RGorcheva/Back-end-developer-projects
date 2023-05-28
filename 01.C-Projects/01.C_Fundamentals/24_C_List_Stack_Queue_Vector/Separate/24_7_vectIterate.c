/*
Дефинирайте функция за итериране на елементите на масива, която приема указател към друга функция, подадена
от клиента, която извършва желаните операции на всеки отделен елемент от списъка.
void my_vector_iterate(my_vector vec, void (*iterFunc)(char*));
Функцията за итериране трябва да извиква подадената й като аргумент функция за всеки елемент на списъка
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define VECTOR_CAPACITY 10
#define VECTOR_MIN_CAPACITY 7

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
	vec->data = (vector_data*)malloc(sizeof(vector_data) * vec->capacity);
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

void vectorStr_double_capacity(vector* vec)
{
	size_t newCapacity = vec->capacity * 2;
	vector_data* newData = (vector_data*)malloc(sizeof(vector_data) * newCapacity);
	if (newData == NULL)
	{
		fprintf(stderr, "Cannot alocate memory!");
		return;
	}
	for (size_t i = 0; i < vec->size; i++)
	{
		newData[i] = vec->data[i];
	}

	free(vec->data);
	vec->data = newData;
	vec->capacity = newCapacity;
}
void vectorStr_pushBack(vector* vec, char* str)
{
	if (vec->size + 1 > vec->capacity)
	{
		vectorStr_double_capacity(vec);
	}
	vec->data[vec->size++] = str;
}
void vectorStr_insert(vector* vec, char* str, size_t idx)
{
	if (vec->size + 1 > vec->capacity)
	{
		vectorStr_double_capacity(vec);
	}
	for (size_t i = vec->size; i > idx; i--)
	{
		vec->data[i] = vec->data[i - 1];
	}
	vec->data[idx] = str;
	vec->size++;
}

void vectorStr_half_capacity(vector* vec)
{
	size_t newCapacity = vec->capacity / 2;
	vector_data* newData = (vector_data*)malloc(sizeof(vector_data) * newCapacity);
	if (newData == NULL)
	{
		fprintf(stderr, "Cannot alocate memory!");
		return;
	}
	for (size_t i = 0; i < vec->size; i++)
	{
		newData[i] = vec->data[i];
	}
	free(vec->data);
	vec->data = newData;
	vec->capacity = newCapacity;
}
void vectorStr_eraseLast(vector* vec)
{
	vec->size--;
	if (vec->size <= vec->capacity / 2)
	{
		vectorStr_half_capacity(vec);
	}
}
void vectorStr_eraseIdx(vector* vec, size_t idx)
{
	vector_data* it = vec->data;
	for (size_t i = idx; i < vec->size - 1; i++)
	{
		it[i] = it[i + 1];
	}
	vectorStr_eraseLast(vec);
}

size_t vectorStr_capacity(vector* vec)
{
	return vec->capacity;
}
void vectorStr_reserve(vector* vec, size_t minCapacity)
{
	if (vec->capacity < minCapacity)
	{
		vector_data* newData = (vector_data*)malloc(sizeof(vector_data) * minCapacity);
		if (newData == NULL)
		{
			fprintf(stderr, "Cannot alocate memory!");
			return;
		}
		for (size_t i = 0; i != vec->size; i++)
		{
			newData[i] = vec->data[i];
		}
		free(vec->data);
		vec->data = newData;
		vec->capacity = minCapacity;
	}
}

void vectorStr_resize(vector* vec, size_t elementsCount)
{
	int minus = (int)vec->size - (int)elementsCount;
	if (minus > 0)
	{
		vec->size = elementsCount;
		if (vec->size <= vec->capacity / 2)
		{
			vectorStr_half_capacity(vec);
		}
	}
	else if (minus < 0)
	{
		for (int i = 0; i < abs(minus); i++)
		{
			if (vec->size + 1 > vec->capacity)
			{
				vectorStr_double_capacity(vec);
			}
			vec->size++;
			vec->data[vec->size - 1] = NULL;
		}
	}
}
void vectorStr_resize_init(vector* vec, size_t elementsCount, char* defaultValue)
{
	int minus = (int)vec->size - (int)elementsCount;
	if (minus > 0)
	{
		vec->size = elementsCount;
		if (vec->size <= vec->capacity / 2)
		{
			vectorStr_half_capacity(vec);
		}
	}
	else if (minus < 0)
	{
		for (int i = 0; i < abs(minus); i++)
		{
			if (vec->size + 1 > vec->capacity)
			{
				vectorStr_double_capacity(vec);
			}
			vec->size++;
			vec->data[vec->size - 1] = defaultValue;
		}
	}
}

char* vectorStr_front(vector* vec)
{
	return vec->data[0];
}
char* vectorStr_back(vector* vec)
{
	return vec->data[vec->size - 1];
}
char* vectorStr_at(vector* vec, size_t idx)
{
	return vec->data[idx];
}

void element_print(const char* str)
{
	printf("\n%s", str);
	return;
}
void vectorStr_iterate(vector* vec, void (*iterFunc)(char*))
{
	if (vec == NULL)
	{
		printf("\nVector is NULL pointer!!!");
		return;
	}
	for (int i = 0; i < vec->size; i++)
	{
		iterFunc(vec->data[i]);
	}
}

int main(void)
{
	vector vect;
	vectorStr_init(&vect);
	vector_data* it = vect.data;
	vect.data[0] = "zero";
	vect.size++;
	vect.data[1] = "one";
	vect.size++;
	vect.data[2] = "two";
	vect.size++;
	vect.data[3] = "three";
	vect.size++;
	vectorStr_print(&vect);
	printf("\n---------");
	vectorStr_iterate(&vect, element_print);
	vectorStr_clear(&vect);
	return 0;
}
