#include "..\Project Vehicle\userInfo.h"
#include "..\Library\stringFunc.h"
#include "..\Library\inputOutputFunc.h"
#include "..\Library\fileFunc.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

enum DrivingLicense { A1, A2, A, B, B1, C, D, BE, CE, DE, T };

//typedef struct UserInfo {
//	int userID;
//	char name[60];
//	char PIN[11];
//	enum DrivingLicense driveCategory;
//} UserInfo;
//
//typedef struct ListUsers
//{
//	UserInfo user;
//	struct ListUsers* next;
//} ListUsers;

bool userList_isEmpty(listUser* list)
{
	return list == NULL;
}
void userList_init(listUser* list)
{
	list = NULL;
}
int userList_countUsers(listUser* list)
{
	if (list == NULL)
		return 0;
	int count = 0;
	while (list != NULL)
	{
		++count;
		list = list->next;
	}
	return count;
}
void userList_print(listUser* list)
{
	if (list == NULL)
		return;
	while (list != NULL)
	{
		userInfoObject_Print(&list->user);
		list = list->next;
	}
	printf("\n------------------------------------\n");
}
listUser* userList_findIndexN(listUser* list, int indx)
{
	int countIndex = 0;
	while (list != NULL)
	{
		if (countIndex == indx)
			return list;
		countIndex++;
		list = list->next;
	}
	return NULL;
}
listUser* userList_findLast(listUser* list)
{
	while (list->next != NULL)
	{
		list = list->next;
	}
	return list;
}
void userList_copyStruct(listUser* list, UserInfo* pUserObject)
{
	list->user.userID = pUserObject->userID;
	strcpy(list->user.firstName, pUserObject->firstName);
	strcpy(list->user.middleName, pUserObject->middleName);
	strcpy(list->user.lastName, pUserObject->lastName);
	strcpy(list->user.PIN, pUserObject->PIN);
	list->user.driveCategory = pUserObject->driveCategory;
}
listUser* userList_pushBack(listUser* list, UserInfo* pUserObject)
{
	listUser* pNew = (listUser*)malloc(sizeof(listUser));
	if (pNew == NULL)
	{
		fprintf(stderr, "Cannot alocate memory!");
		return NULL;
	}
	userList_copyStruct(pNew, pUserObject);
	pNew->next = NULL;

	if (list == NULL)
	{
		list = pNew;
	}
	else
	{
		listUser* plast = userList_findLast(list);
		plast->next = pNew;
	}
	return list;
}
void userList_insert(listUser* list, int indx)
{
	UserInfo user;
	UserInfo* pUserObject = &user;
	userInfoObject_Initializatoin(pUserObject);

	listUser* pNew = (listUser*)malloc(sizeof(listUser));
	if (pNew == NULL)
	{
		fprintf(stderr, "Cannot alocate memory!");
		return;
	}
	userList_copyStruct(pNew, pUserObject);
	listUser* prev = userList_findIndexN(list, indx - 1);
	pNew->next = prev->next;
	prev->next = pNew;
}
listUser* userList_empty(listUser* list)
{
	if (list == NULL)
	{
		printf("\nlist is NULL pointer!!!");
		return NULL;
	}
	while (list != NULL)
	{
		listUser* temp = list->next;
		free(list);
		list = temp;
	}
	return NULL;
}
listUser* userList_delete(listUser* list, int indx)
{
	if (list == NULL)
		return NULL;
	if (indx == 0)
	{
		listUser* first = list->next;
		free(list);
		return first;
	}
	listUser* first = list;
	int count = 0;
	while (count != indx - 1)
	{
		++count;
		list = list->next;
	}
	listUser* prev = list;
	list = list->next;
	prev->next = list->next;
	free(list);
	return first;
}
listUser* userList_deserilization(listUser* list)
{
	FILE* in = NULL;
	char filename[20] = { 0 };
	printf("\nEnter input file name:");
	io_strEnter(filename, 20);
	in = file_open(in, filename, "r");

	int countUsers = 0;
	int* pCount = &countUsers;
	in = int_deserilization(in, pCount);
	printf("\nCount elem = %d", countUsers);

	listUser* pfirst = NULL;
	for (int i = 0; i < countUsers; i++)
	{
		UserInfo user;
		in = userInfoObject_Deserilization(in, &user);
		pfirst = userList_pushBack(pfirst, &user);
	}
	return pfirst;
}
void userList_serilization(listUser* list, int* pCountUsers)
{
	FILE* out = NULL;
	char filename[20] = { 0 };
	printf("\nEnter input file name:");// 
	io_strEnter(filename, 20);
	out = file_open(out, filename, "w");

	out = int_serilization(out, pCountUsers);

	while (list != NULL)
	{
		userInfoObject_Serilization(out, &list->user);
		list = list->next;
	}
	file_close(out);
}

int main(void)
{
	listUser* pfirst = NULL;
	pfirst = userList_deserilization(pfirst);
	userList_print(pfirst);

	userList_insert(pfirst, 2);
	userList_print(pfirst);
	pfirst = userList_delete(pfirst, 2);
	userList_print(pfirst);
	int iCountUsers = userList_countUsers(pfirst);
	printf("\nNumber of users: %d\n", iCountUsers);
	userList_serilization(pfirst, &iCountUsers);
	pfirst = userList_empty(pfirst);
	userList_print(pfirst);
	return 0;
}