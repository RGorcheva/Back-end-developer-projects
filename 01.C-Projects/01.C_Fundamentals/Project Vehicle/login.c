#include <stdio.h>
#include "users.h"

/*menu log in:
functions:
	log in - Проверява дали потрбителя съществува и валидира име и парола;
влиза в старт меню, според типа потребител;
	sign in for client - ако не съществува, може да се създаде, проверка за съществуващ акаунт
	*/

//enum E_APP_USER_FLAGS
//{
//	OWNER =		0b111,
//	ADMIN =		0b011,
//	CUSTOMER =	0b001
//};

int main_1(void)
{
	listUser* pfirstUser = NULL;
	pfirstUser = userList_deserilization(pfirstUser);
	char username[10];
	int userpass[10];
	enum UserAccount accountType;

	printf("Enter username:");
	int isScan = scanf_s("%s", 10);
	printf("Enter userpass:");
	
	



	userList_serilization(pfirstUser, userList_countUsers(pfirstUser));
	userList_empty(pfirstUser);
	return 0;
}