#ifndef USERS_H
#define USERS_H

#include <stdio.h>
#include <stdbool.h>

enum DrivingLicense;
enum UserAccount;

typedef struct UserInfo {
	int userID;
	char username[10];
	int userpass[10];
	enum UserAccount accountType;
	char firstName[60];
	char middleName[60];
	char lastName[60];
	char PIN[11];
	enum DrivingLicense driveCategory;
} UserInfo;

typedef struct listUser
{
	UserInfo user;
	struct listUser* next;
} listUser;

FILE*		userInfoObject_Deserilization(FILE* in, UserInfo* pUser);
void		userInfoObject_Print(UserInfo* pUser);
void		userInfoObject_Initializatoin(UserInfo* pUser);
void		userInfoObject_Serilization(FILE* out, UserInfo* pUser);

void		userInfoArr_Deserilization(FILE* in, UserInfo* pUser, int size);
void		userInfoArr_Print(UserInfo* pUser, int size);
void		userInfoArr_Initializatoin(UserInfo* pUser, int size);
void		userInfoArr_Serilization(FILE* out, UserInfo* pUser, int size);

bool		userList_isEmpty(listUser* list);
void		userList_init(listUser* list);
int			userList_countUsers(listUser* list);
void		userList_print(listUser* list);
listUser*	userList_findIndexN(listUser* list, int indx);
listUser*	userList_findLast(listUser* list);
void		userList_copyStruct(listUser* list, UserInfo* pUserObject);
listUser*	userList_pushBack(listUser* list, UserInfo* pUserObject);
void		userList_insert(listUser* list, int indx);
listUser*	userList_empty(listUser* list);
listUser*	userList_delete(listUser* list, int indx);
listUser*	userList_deserilization(listUser* list);
void		userList_serilization(listUser* list, int* pCountUsers);

#endif