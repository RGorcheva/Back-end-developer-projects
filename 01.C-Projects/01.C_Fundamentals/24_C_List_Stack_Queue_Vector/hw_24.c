#include "hw_24.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

int compare_pointers(void* a, void* b)
{
	const char* pA = *(const char**)a;
	const char* pB = *(const char**)b;

	int result = strcmp(pA, pB);
	if (result > 0)
	{
		return 1;
	}
	else if (result < 0)
	{
		return -1;
	}
	return 0;
}
void vectorStr_sort(vector* vec, size_t count, int (*comp)(void*, void*))
{
	for (size_t i = 0; i < vec->size - 1; i++)
	{
		for (size_t j = 0; j < vec->size - i - 1; j++)
		{
			if (comp(&vec->data[j], &vec->data[j + 1]) > 0)
			{
				char* temp = vec->data[j];
				vec->data[j] = vec->data[j + 1];
				vec->data[j + 1] = temp;
			}
		}
	}
}


void hw_24_1_vectInitClear(void)
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
{
	printf("\n-----------------task 24_1-----------------------\n");
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
}
void hw_24_2_vectPushBackInsert(void)
/*
 Дефинирайте функции за добавяне на елементи на последна и на конкретна
позиция в динамичния масив:
void my_vector_push_back(char *data, my_vector vec);
void my_vector_insert(char *data, my_vector vec, size_t pos);
*/
{
	printf("\n-----------------task 24_2-----------------------\n");
	vector vect;
	vectorStr_init(&vect);
	vector_data* it = vect.data;
	for (int i = 0; i < VECTOR_CAPACITY; i++)
	{
		it[i] = "old";
		vect.size++;
	}
	printf("\n%zu", vectorStr_size(&vect));
	printf("\n%zu", vectorStr_capacity(&vect));
	vectorStr_print(&vect);
	printf("\n---------");
	vectorStr_pushBack(&vect, "new");
	vectorStr_pushBack(&vect, "new");
	vectorStr_pushBack(&vect, "new");
	printf("\n%zu", vectorStr_size(&vect));
	printf("\n%zu", vectorStr_capacity(&vect));
	vectorStr_print(&vect);
	printf("\n---------");
	vectorStr_insert(&vect, "insert3", 3);
	vectorStr_print(&vect);
	vectorStr_clear(&vect);
}
void hw_24_3_eraseElements(void)
/*
Дефинирайте функции за изтриване на елементи на последна и на конкретна
позиция в списъка:
void my_vector_pop_back(my_vector vec);
void my_vector_erase(my_vector vec, size_t pos);
*/
{
	printf("\n-----------------task 24_3-----------------------\n");
	vector vect;
	vectorStr_init(&vect);
	vector_data* it = vect.data;
	for (int i = 0; i < 5; i++)
	{
		it[i] = "old";
		vect.size++;
	}
	vectorStr_insert(&vect, "insert3", 3);
	printf("\n%zu", vectorStr_size(&vect));
	printf("\n%zu", vectorStr_capacity(&vect));
	vectorStr_print(&vect);
	printf("\n---------");
	vectorStr_eraseLast(&vect);
	printf("\n%zu", vectorStr_size(&vect));
	printf("\n%zu", vectorStr_capacity(&vect));
	vectorStr_print(&vect);
	printf("\n---------");
	vectorStr_eraseIdx(&vect, 3);
	printf("\n%zu", vectorStr_size(&vect));
	printf("\n%zu", vectorStr_capacity(&vect));
	vectorStr_print(&vect);
	vectorStr_clear(&vect);
}
void hw_24_4_reserveCapacity(void)
/*
● Дефинирайте функция, която връща текущия капацитет на динамичния масив:
size_t my_vector_capacity(my_vector vec);
● Дефинирайте функция, която променя капацитета на динамичен масив.
void my_vector_reserve(my_vector vec, size_t minCapacity);
Ако новоподаденият капацитет е по-голям от текущия, функцията трябва да
реалокира достатъчно памет за minCapacity на брой елемента (може и повече).
Ако новоподаденият капацитет е по-малък от текущия - функцията не прави нищо
(текущият капацитет се запазва, не се намалява; не се алокира/деалокира/реалокира
памет)
*/
{
	printf("\n-----------------task 24_4-----------------------\n");
	vector vect;
	vectorStr_init(&vect);
	vector_data* it = vect.data;
	for (int i = 0; i < 5; i++)
	{
		it[i] = "old";
		vect.size++;
	}
	vectorStr_insert(&vect, "insert3", 3);
	printf("\n%zu", vectorStr_size(&vect));
	printf("\n%zu", vectorStr_capacity(&vect));
	vectorStr_print(&vect);
	printf("\n---------");
	vectorStr_eraseLast(&vect);
	printf("\n%zu", vectorStr_size(&vect));
	printf("\n%zu", vectorStr_capacity(&vect));
	vectorStr_print(&vect);
	printf("\n---------");
	vectorStr_eraseIdx(&vect, 3);
	printf("\n%zu", vectorStr_size(&vect));
	printf("\n%zu", vectorStr_capacity(&vect));
	vectorStr_print(&vect);
	vectorStr_reserve(&vect, VECTOR_MIN_CAPACITY);
	printf("\n%zu", vectorStr_size(&vect));
	printf("\n%zu", vectorStr_capacity(&vect));
	vectorStr_clear(&vect);
}
void hw_24_5_vectResize(void)
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
{
	printf("\n-----------------task 24_5-----------------------\n");
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
}
void hw_24_6_returnElement(void)
/*
 Дефинирайте функции за достъп до първия, последния и конкретен елемент от масива:
char* my_vector_front(my_vector vec);
char* my_vector_back(my_vector vec);
char* my_vector_at(my_vector vec, size_t index);
*/

{
	printf("\n-----------------task 24_6-----------------------\n");
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
	printf("\n%s", vectorStr_front(&vect));
	printf("\n%s", vectorStr_back(&vect));
	printf("\n%s", vectorStr_at(&vect, 2));
	vectorStr_clear(&vect);
}
void hw_24_7_vectIterate(void)
/*
Дефинирайте функция за итериране на елементите на масива, която приема указател към друга функция, подадена
от клиента, която извършва желаните операции на всеки отделен елемент от списъка.
void my_vector_iterate(my_vector vec, void (*iterFunc)(char*));
Функцията за итериране трябва да извиква подадената й като аргумент функция за всеки елемент на списъка
*/
{
	printf("\n-----------------task 24_7-----------------------\n");
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
}
void hw_24_8_vectSort(void)
/*
Дефинирайте функция за сортиране на елементите на масива по зададен предикат(параметър - указател към
функция, която сравнява два елемента и връща -1, 0 или 1.
void my_vector_sort(my_vector vec, //.
*/
{
	printf("\n-----------------task 24_8-----------------------\n");
	vector vect;
	vectorStr_init(&vect);
	vector_data* it = vect.data;
	vect.data[0] = "dddd";
	vect.size++;
	vect.data[1] = "cccc";
	vect.size++;
	vect.data[2] = "bbbb";
	vect.size++;
	vect.data[3] = "aaaa";
	vect.size++;
	vectorStr_print(&vect);
	printf("\n---------");
	vectorStr_sort(&vect, vect.size, compare_pointers);
	vectorStr_print(&vect);
	vectorStr_clear(&vect);
}
