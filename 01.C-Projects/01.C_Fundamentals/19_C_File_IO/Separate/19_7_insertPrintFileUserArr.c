/*
Дефинирайте функции за четене и писане на масив от UserData обекти във FILE*.
Тествайте четенето и писането на колекции от UserData в/от файлове.
*/

#include "..\Library\stringFunc.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef enum E_DrivingLicenseCategory { A1, A2, A, B, B1, C, D, BE, CE, DE, T } DrivingLicense;

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

void print_UserDataArr(FILE* in)
{
	for (int i = 0; i < 3; i++)
	{
		UserData userArr[3];
		fscanf(in, FORMAT_USERINFO_IN, &userArr[i].name, &userArr[i].middleName, &userArr[i].surname, &userArr[i].PIN, &userArr[i].driveCategory);
		char driveCat[3] = "0";
		switch (userArr[i].driveCategory)
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
		fprintf(stdout, FORMAT_USERINFO_OUT_STDOUT, userArr[i].name, userArr[i].middleName, userArr[i].surname, userArr[i].PIN, driveCat);
	}
}
void insert_UserDataArr(FILE* out)
{
	UserData userArr[3];
	for (int i = 0; i < 3; i++)
	{
		printf("\nEnter user name:");
		scanf_s(" %s", &(userArr[i].name), 20);
		printf("\nEnter user middleName:");
		scanf_s(" %s", &(userArr[i].middleName), 20);
		printf("\nEnter user surname:");
		scanf_s(" %s", &(userArr[i].surname), 20);
		printf("\nEnter user PIN:");
		scanf_s(" %s", &(userArr[i].PIN), 11);
		printf("\nEnter user drive category: \nA1\t0\nA2\t1\nB\t2\nB1\t3\nC\t4\nD\t5\nBE\t6\nCE\t7\nDE\t8\nT\t9\n");
		scanf_s("%d", &(userArr[i].driveCategory));
		fprintf(out, FORMAT_USERINFO_OUT_FILE, userArr[i].name, userArr[i].middleName, userArr[i].surname, userArr[i].PIN, userArr[i].driveCategory);
	}
}

int main(void)
{
	FILE* out = NULL;
	char filenameOUT[20];
	printf("\nEnter output file name:");
	io_strEnter(filenameOUT, 20);
	if ((out = fopen(filenameOUT, "w")) == NULL)
	{
		fprintf(stderr, "Can't create output file.\n");
		exit(EXIT_FAILURE);
	}
	insert_UserDataArr(out);
	if (fclose(out) != 0)
		fprintf(stderr, "Error in closing file\n");

	FILE* in = NULL;
	char filenameIN[20];
	printf("\nEnter input file name:");
	io_strEnter(filenameIN, 20);
	if ((in = fopen(filenameIN, "r")) == NULL)
	{
		fprintf(stderr, "Can't open input file.\n");
		exit(EXIT_FAILURE);
	}
	print_UserDataArr(in);
	if (fclose(in) != 0)
		fprintf(stderr, "Error in closing file\n");
	return 0;
}