#include "users.h"
#include "..\Library\stringFunc.h"
#include "..\Library\inputOutputFunc.h"
#include "..\Library\fileFunc.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

enum DrivingLicense { A1, A2, A, B, B1, C, D, BE, CE, DE, T };
enum UserAccount { Customer, Admin, Owner };

static const char* FORMAT_USERINFO_DESERILIZATOIN = "(%d, %[^,], %[^,], %[^,], %[^,], %d)\n";
static const char* FORMAT_USERINFO_SERILIZATION = "(%d, %s, %s, %s, %s, %d)\n";
static const char* FORMAT_USERINFO_PRINT = "\n-----------------------"
"\nuser ID: %d\nfirst name: %s\nmiddle name: %s\nlast name: %s\nPIN: %s\nDriving license category: %s\n";

FILE* userInfoObject_Deserilization(FILE* in, UserInfo* pUser)
{
	int ifscan = fscanf(in, FORMAT_USERINFO_DESERILIZATOIN, &pUser->userID, &pUser->firstName, &pUser->middleName, &pUser->lastName, &pUser->PIN, &pUser->driveCategory);
	return in;
}
void userInfoObject_Print(UserInfo* pUser)
{
	char* driveCat = NULL;
	switch (pUser->driveCategory)
	{
	case A1: driveCat = "A1"; break;
	case A2: driveCat = "A2"; break;
	case A: driveCat = "A"; break;
	case B: driveCat = "B"; break;
	case B1: driveCat = "B1"; break;
	case C: driveCat = "C"; break;
	case D: driveCat = "D"; break;
	case BE: driveCat = "BE"; break;
	case CE: driveCat = "CE"; break;
	case DE: driveCat = "DE"; break;
	case T: driveCat = "T"; break;
	default: driveCat = "NA";
	}
	fprintf(stdout, FORMAT_USERINFO_PRINT, pUser->userID, pUser->firstName, pUser->middleName, pUser->lastName, pUser->PIN, driveCat);
}
void userInfoObject_Initializatoin(UserInfo* pUser)
{
	printf("\nEnter user ID:");
	scanf_s("%d", &(pUser->userID));
	setbuf(stdin, NULL);
	printf("\nEnter user first name:");
	char ch = '0';
	int i = 0;
	while ((pUser->firstName[i] = getc(stdin)) != '\n')
	{
		i++;
	}
	pUser->firstName[i] = '\0';
	setbuf(stdin, NULL);
	printf("\nEnter user middle name:");
	i = 0;
	while ((pUser->middleName[i] = getc(stdin)) != '\n')
	{
		i++;
	}
	pUser->middleName[i] = '\0';
	setbuf(stdin, NULL);
	printf("\nEnter user last name:");
	i = 0;
	while ((pUser->lastName[i] = getc(stdin)) != '\n')
	{
		i++;
	}
	pUser->lastName[i] = '\0';
	setbuf(stdin, NULL);
	printf("\nEnter user PIN:");
	scanf_s(" %s", &(pUser->PIN), 11);
	printf("\nEnter user drive category: \nA1\t0\nA2\t1\nA\t2\nB\t3\nB1\t4\nC\t5\nD\t6\nBE\t7\nCE\t8\nDE\t9\nT\t10\n");
	scanf_s("%d", &(pUser->driveCategory));
}
void userInfoObject_Serilization(FILE* out, UserInfo* pUser)
{
	fprintf(out, FORMAT_USERINFO_SERILIZATION, pUser->userID, pUser->firstName, pUser->middleName, pUser->lastName, pUser->PIN, pUser->driveCategory);
}

void userInfoArr_Deserilization(FILE* in, UserInfo* pUser, int size)
{
	for (int i = 0; i < size; i++)
	{
		int ifscan = fscanf(in, FORMAT_USERINFO_DESERILIZATOIN, &pUser[i].userID, &pUser[i].firstName, &pUser[i].middleName, &pUser[i].lastName, &pUser[i].PIN, &pUser[i].driveCategory);
	}
}
void userInfoArr_Print(UserInfo* pUser, int size)
{
	for (int i = 0; i < size; i++)
	{
		char* driveCat = NULL;
		switch (pUser[i].driveCategory)
		{
		case A1: driveCat = "A1"; break;
		case A2: driveCat = "A2"; break;
		case A: driveCat = "A"; break;
		case B: driveCat = "B"; break;
		case B1: driveCat = "B1"; break;
		case C: driveCat = "C"; break;
		case D: driveCat = "D"; break;
		case BE: driveCat = "BE"; break;
		case CE: driveCat = "CE"; break;
		case DE: driveCat = "DE"; break;
		case T: driveCat = "T"; break;
		default: driveCat = "NA";
		}
		fprintf(stdout, FORMAT_USERINFO_PRINT, pUser[i].userID, pUser[i].firstName, pUser[i].middleName, pUser[i].lastName, pUser[i].PIN, driveCat);
	}
}
void userInfoArr_Initializatoin(UserInfo* pUser, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("\nEnter user ID:");
		scanf_s("%d", &(pUser->userID));
		printf("\nEnter user first name:");
		char ch = '0';
		int i = 0;
		while ((pUser->firstName[i] = getc(stdin)) != '\n')
		{
			i++;
		}
		pUser->firstName[i] = '\0';
		setbuf(stdin, NULL);
		printf("\nEnter user middle name:");
		i = 0;
		while ((pUser->middleName[i] = getc(stdin)) != '\n')
		{
			i++;
		}
		pUser->middleName[i] = '\0';
		setbuf(stdin, NULL);
		printf("\nEnter user last name:");
		i = 0;
		while ((pUser->lastName[i] = getc(stdin)) != '\n')
		{
			i++;
		}
		pUser->lastName[i] = '\0';
		setbuf(stdin, NULL);
		printf("\nEnter user PIN:");
		scanf_s(" %s", &(pUser[i].PIN), 11);
		printf("\nEnter user drive category: \nA1\t0\nA2\t1\nA\t2\nB\t3\nB1\t4\nC\t5\nD\t6\nBE\t7\nCE\t8\nDE\t9\nT\t10\n");
		scanf_s("%d", &(pUser[i].driveCategory));
	}
}
void userInfoArr_Serilization(FILE* out, UserInfo* pUser, int size)
{
	for (int i = 0; i < size; i++)
	{
		fprintf(out, FORMAT_USERINFO_SERILIZATION, pUser[i].userID, pUser[i].firstName, pUser[i].middleName, pUser[i].lastName, pUser[i].PIN, pUser[i].driveCategory);
	}
}

bool		userList_isEmpty(listUser* list)
{
	return list == NULL;
}
void		userList_init(listUser* list)
{
	list = NULL;
}
int			userList_countUsers(listUser* list)
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
void		userList_print(listUser* list)
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
listUser*	userList_findIndexN(listUser* list, int indx)
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
listUser*	userList_findLast(listUser* list)
{
	while (list->next != NULL)
	{
		list = list->next;
	}
	return list;
}
void		userList_copyStruct(listUser* list, UserInfo* pUserObject)
{
	list->user.userID = pUserObject->userID;
	strcpy(list->user.firstName, pUserObject->firstName);
	strcpy(list->user.middleName, pUserObject->middleName);
	strcpy(list->user.lastName, pUserObject->lastName);
	strcpy(list->user.PIN, pUserObject->PIN);
	list->user.driveCategory = pUserObject->driveCategory;
}
listUser*	userList_pushBack(listUser* list, UserInfo* pUserObject)
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
void		userList_insert(listUser* list, int indx)
{
	UserInfo userObject;
	userInfoObject_Initializatoin(&userObject);

	listUser* pNew = (listUser*)malloc(sizeof(listUser));
	if (pNew == NULL)
	{
		fprintf(stderr, "Cannot alocate memory!");
		return;
	}
	userList_copyStruct(pNew, &userObject);
	listUser* prev = userList_findIndexN(list, indx - 1);
	pNew->next = prev->next;
	prev->next = pNew;
}
listUser*	userList_empty(listUser* list)
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
listUser*	userList_delete(listUser* list, int indx)
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
listUser*	userList_deserilization(listUser* list)
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
		UserInfo UserObject;
		in = userInfoObject_Deserilization(in, &UserObject);
		pfirst = userList_pushBack(pfirst, &UserObject);
	}
	return pfirst;
}
void		userList_serilization(listUser* list, int* pCountUsers)
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