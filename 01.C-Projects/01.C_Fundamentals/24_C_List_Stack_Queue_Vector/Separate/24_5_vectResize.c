/*
Дефинирайте функции за промяна на броя на елементите на динамичния масив:
void my_vector_resize(my_vector vec, size_t elementsCount);
void my_vector_resize_init(my_vector vec, size_t elementsCount,char *defaultValue);
Ако elementsCount е по-малък от текущия размер, съдържанието на динамичния
масив става първите elementsCount и останалите се унищожават.
Ако elementsCount е по-голямо от текущия размер, динамичният масив се разширява
до elementsCount брой елементи, като:
● my_vector_resize инициализира новите елементи на NULL
● my_vector_resize_init инициализира новите елементи на стойността на 3тия си
параметър: defaultValue
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

int main(void)
{
	vector vect;
	vectorStr_init(&vect);
	vector_data* it = vect.data;
	for (int i = 0; i < 5; i++)
	{
		it[i] = "old";
		vect.size++;
	}
	printf("\n%zu", vectorStr_size(&vect));
	printf("\n%zu", vectorStr_capacity(&vect));
	vectorStr_print(&vect);
	printf("\n---------");
	vectorStr_resize(&vect, 8);
	printf("\n%zu", vectorStr_size(&vect));
	printf("\n%zu", vectorStr_capacity(&vect));
	vectorStr_print(&vect);
	printf("\n---------");
	vectorStr_resize_init(&vect, 12, "new");
	printf("\n%zu", vectorStr_size(&vect));
	printf("\n%zu", vectorStr_capacity(&vect));
	vectorStr_print(&vect);
	printf("\n---------");
	vectorStr_resize(&vect, 8);
	printf("\n%zu", vectorStr_size(&vect));
	printf("\n%zu", vectorStr_capacity(&vect));
	vectorStr_print(&vect);
	printf("\n---------");
	vectorStr_resize_init(&vect, 4, "new");
	printf("\n%zu", vectorStr_size(&vect));
	printf("\n%zu", vectorStr_capacity(&vect));
	vectorStr_print(&vect);
	vectorStr_clear(&vect);
	return 0;
}

