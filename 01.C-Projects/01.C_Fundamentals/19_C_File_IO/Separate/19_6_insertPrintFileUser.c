/*
Дефинирайте структура UserData със следните members:
● c-string масиви от char за име, презиме и фамилия
● PIN (ЕГН)
● enum E_DrivingLicenseCategory - категория за водач на МПС
Дефинирайте функции за четене и писане на UserData дата обекти в/от подаден
FILE* като аргумент(форматирайте текстовите данни както намерите за добре)
Прочетете UserData обект от текстов файл.
Запишете UserData обект в текстов файл.
*/

#include "..\Library\stringFunc.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef enum E_DrivingLicenseCategory {A1, A2, A, B, B1, C, D, BE, CE, DE, T} DrivingLicense;

static const char* FORMAT_USERINFO_IN = "(%[^,], %[^,], %[^,], %[^,], %d)\n";
static const char* FORMAT_USERINFO_OUT_FILE = "(%s, %s, %s, %s, %d)\n";
static const char* FORMAT_USERINFO_OUT_STDOUT = "(%s, %s, %s, %s, %s)\n";

typedef struct UserData {
	char name[20];
	char middleName[20];
	char surname[20];
	char PIN[11];
	DrivingLicense driveCategory;
} UserData;

void print_UserData(FILE* in)
{
	UserData user;
	fscanf(in, FORMAT_USERINFO_IN, &user.name, &user.middleName, &user.surname, &user.PIN, &user.driveCategory);
	char driveCat[3] = "0";
	switch (user.driveCategory)
	{
	case A1: string_strcopy(driveCat, "A1"); break;
	case A2: string_strcopy(driveCat, "A2"); break;
	case A: string_strcopy(driveCat, "A"); break;
	case B: string_strcopy(driveCat, "B"); break;
	case B1: string_strcopy(driveCat, "B1"); break;
	case C: string_strcopy(driveCat, "C"); break;
	case D: string_strcopy(driveCat, "D"); break;
	case BE: string_strcopy(driveCat, "BE"); break;
	case CE: string_strcopy(driveCat, "CE"); break;
	case DE: string_strcopy(driveCat, "DE"); break;
	case T: string_strcopy(driveCat, "T"); break;
	default: string_strcopy(driveCat, "");
	}
	fprintf(stdout, FORMAT_USERINFO_OUT_STDOUT, user.name, user.middleName, user.surname, user.PIN, driveCat);
}

void insert_UserData(FILE* out)
{
	UserData user;
	printf("\nEnter user name:");
	scanf_s(" %s", &(user.name), 20);
	printf("\nEnter user middleName:");
	scanf_s(" %s", &(user.middleName), 20);
	printf("\nEnter user surname:");
	scanf_s(" %s", &(user.surname), 20);
	printf("\nEnter user PIN:");
	scanf_s(" %s", &(user.PIN), 11);
	printf("\nEnter user drive category: \nA1\t0\nA2\t1\nA\t2\nB\t3\nB1\t4\nC\t5\nD\t6\nBE\t7\nCE\t8\nDE\t9\nT\t10\n");
	scanf_s("%d", &(user.driveCategory));
	fprintf(out, FORMAT_USERINFO_OUT_FILE, user.name, user.middleName, user.surname, user.PIN, user.driveCategory);
}

int main(void)
{
	FILE* in = NULL;
	FILE* out = NULL;
	char filenameOUT[20];
	printf("\nEnter output file name:");
	io_strEnter(filenameOUT, 20);
	if ((out = fopen(filenameOUT, "w")) == NULL)
	{
		fprintf(stderr, "Can't create output file.\n");
		exit(EXIT_FAILURE);
	}
	insert_UserData(out);
	if (fclose(out) != 0)
		fprintf(stderr, "Error in closing file\n");

	char filenameIN[20];
	printf("\nEnter input file name:");
	io_strEnter(filenameIN, 20);
	if ((in = fopen(filenameIN, "r")) == NULL)
	{
		fprintf(stderr, "Can't open input file.\n");
		exit(EXIT_FAILURE);
	}
	print_UserData(in);
	if (fclose(in) != 0)
		fprintf(stderr, "Error in closing file\n");
	return 0;
}