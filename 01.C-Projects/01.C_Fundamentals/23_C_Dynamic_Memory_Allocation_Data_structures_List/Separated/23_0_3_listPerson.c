#include <stdio.h>
#include <stdlib.h>

#define MAX_PERSON_NAME_LEN 64

typedef struct Person
{
	char name[MAX_PERSON_NAME_LEN];
	int age;
} Person;

typedef Person ListData; //за да не се пише навсякъде Person, а да може да се използва с друг тип.

typedef struct ListNode  // Списък
{
	ListData data;
	struct ListNode* next;
} ListNode;

void printList(ListNode* list)
{
	const ListNode* it = list;
	while (it != NULL)
	{
		printf("%s, age %d\n", it->data.name, it->data.age);
		it = it->next;
	}
}
int main(void)
{
	printf("Enter elements count:");
	int count = 0;
	scanf_s("%d", &count);

	ListNode* head = NULL;
	ListNode* prevNode = NULL;

	for (int i = 0; i < count; i++)
	{
		ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
		printf("Enter person %d name: ", i);
		scanf_s(" %s", &(newNode->data.name), 20);
		printf("Enter person %d age: ", i);
		scanf_s("%d", &(newNode->data.age));
		newNode->next = NULL;

		if (head == NULL)
		{
			head = newNode;
		}
		else
		{
			prevNode->next = newNode;
		}
		prevNode = newNode;
	}
	printList(head);
	return 0;
}
