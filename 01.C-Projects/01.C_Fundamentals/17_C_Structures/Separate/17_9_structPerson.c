/*
- Дефинирайте тип Person с име и възраст.
- Дефинирайте масив от Person и го инициализирайте.
- Дефинирайте тип PersonNode с 2 member-а: Person и PersonNode* - информация за Person и указател към PersonNode, който
може да сочи към друг обект от тип PersonNode.
- Дефинирайте масив от тип PersonNode. Обходете масива и копирайте информацията за всеки елемент от съответстващия му по
индекс елемент от първия масив (от тип Person). В същия цикъл пренасочете всеки member указател към PersonNode към
следващия елемент от масива, който обхождаме (към 0 за последния елемент)
● Принтирайте съдържанието на създадения от нас свързан списък, използвайки само PersonNode обекти и техните members (без
да използвате името на масивите). Дефинирайте отделна функция за тази цел.
- Обходете масива отново и пренасочете member указателите на всеки PersonNode, чиито Person обект е с възраст над 18 год,
така че да сочат към следващия обект от масива от тип PersonNode, чиито Person member е с възраст над 18 год. (ако обектите с
индекс 0 и 1 и 4 са над 18, обектите с индекс 2 и 3 са под 18, member указателят на обект с индекс 1 трябва да почне да сочи не
към обект с индекс 2, ами да “пропусне всички следващи елементи под 18” и да се пренасочи към обект с индекс 4)
● Принтирайте съдържанието на масива (всички хора) и на списъка (само над 18)
*/

#include "../Library/stringFunctions.h"
#include <stdio.h>

void print_list(struct PersonNode* list);

struct Person
{
	char name[50];
	unsigned age;
} personArr[5], *ptrPerson;

struct PersonNode
{
	struct Person;
	struct PersonNode* ptrPNext;
} personNodeArr[5], *ptrPersonNode;

int main(void)
{
	struct Person* ptrPerson = personArr;
	struct PersonNode* ptrPersonNode = personNodeArr;

	for (int i = 0; i < 5; i++, ptrPerson++)
	{
		printf("\nEnter name of person %d:", i + 1);
		io_strEnter(ptrPerson->name, 50);
		printf("\nAge:");
		scanf_s("%u", &(ptrPerson->age));
		printf("\n");
	}
	for (int i = 0; i < 5; i++)
	{
		string_strcopy(personNodeArr[i].name, personArr[i].name);
		personNodeArr[i].age = personArr[i].age;
		personNodeArr[i].ptrPNext = &(personNodeArr[i+1]);
	}
	personNodeArr[4].ptrPNext = NULL;
	print_list(personNodeArr);

	printf("\nAdult persons with age >=18:");
	struct PersonNode* ptr18 = 0;
	int i = 0;
	for (; i < 5; i++) //find first aaray element >=18.
	{
		if (personNodeArr[i].age >= 18)
		{
			ptr18 = &(personNodeArr[i]);
			break;
		}
	}
	for (int next = i+1; next < 5; next++)
	{
		if (personNodeArr[next].age >= 18)
		{
			personNodeArr[i].ptrPNext = &(personNodeArr[next]);
			i = next;
		}
	}
	personNodeArr[i].ptrPNext = NULL;
	print_list(ptr18);
	return 0;
}

void print_list(struct PersonNode* list)
{
	while (list != NULL)
	{
		printf("\n%s", list->name);
		printf("\n%u", list->age);
		printf("\n");
		list = list->ptrPNext;
	}
}