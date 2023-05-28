/*
Вектор
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define VECTOR_INIT_CAPACITY 2

typedef int vector_data;

typedef struct vector
{
	vector_data* data;
	size_t size;
	size_t capacity;
} vector;

void vector_init(vector* vec)
{
	vec->data = NULL;
	vec->size = 0;
	vec->capacity = VECTOR_INIT_CAPACITY;
	vec->data = (vector_data*)malloc(sizeof(vector_data) * vec->capacity);
}
_Bool vector_empty(vector* vec)
{
	return vec->size == 0;
}
size_t vector_size(vector* vec)
{
	return vec->size;
}
size_t vector_capacity(vector* vec)
{
	return vec->capacity;
}
vector_data* vector_at(vector* vec, size_t idx)
{
	return &vec->data[idx];
}
vector_data vector_get(vector* vec, size_t idx)
{
	return *vector_at(vec, idx);
}
void vector_set(vector* vec, size_t idx, vector_data value)
{
	*vector_at(vec, idx) = value;
}
void vector_double_capacity(vector* vec)
{
	if (vec->capacity <= 0)
	{
		vec->capacity = VECTOR_INIT_CAPACITY;
	}
	size_t newCapacity = vec->capacity * 2;
	vector_data* newArray = (vector_data*)malloc(sizeof(vector_data) * newCapacity);
	if (newArray == NULL)
	{
		fprintf(stderr, "Cannot alocate memory!");
		return;
	}
	for (size_t i = 0; i != vec->size; i++)
	{
		newArray[i] = vec->data[i];
	}
	free(vec->data);
	vec->data = newArray;
	vec->capacity = newCapacity;
}
void vector_half_capacity(vector* vec)
{
	if (vec->capacity <= VECTOR_INIT_CAPACITY)
		return;
	size_t newCapacity = vec->capacity / 2;
	vector_data* newArray = (vector_data*)malloc(sizeof(vector_data) * newCapacity);
	if (newArray == NULL)
	{
		fprintf(stderr, "Cannot alocate memory!");
		return;
	}
	size_t newSize = min(vec->size, newCapacity);
	for (size_t i = 0; i != newSize; i++)
		newArray[i] = vec->data[i];
	free(vec->data);
	vec->data = newArray;
	vec->capacity = newCapacity;
	vec->size = newSize;
}
void vector_push_back(vector* vec, vector_data value)
{
	if (vec->size >= vec->capacity)
		vector_double_capacity(vec);
	vec->data[vec->size++] = value;
}
void vector_clear(vector* vec)
{
	vec->size = 0;
	vec->capacity = VECTOR_INIT_CAPACITY;
	free(vec->data);
	vec->data = NULL;
	vector_init(vec);
}
void vector_print(vector* vec)
{
	vector_data* it = vec->data;
	for (int i = 0; i < vec->size; i++)
	{
		printf("%d ", *it);
		it++;
	}
}

int main(void)
{
	vector vect;
	vector_init(&vect);
	vector_push_back(&vect, 1);
	vector_print(&vect);
	vector_clear(&vect);
	return 0;
}
