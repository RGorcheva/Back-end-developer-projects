#include "hw_21.h"
#include "../Library/bitsFunc.h"
#include "../Library/fileFunc.h"
#include "../Library/inputOutputFunc.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

union base_type
{
	float f;
	char c;
	int i;
	double d;
} a;

struct base_val
{
	enum { val_type_f, val_type_c, val_type_i, val_type_d } value_type;
	union base_type value;
} base_val[10];

void hw_21_0_1_randomUnion(void)
/*
Да се създаде Union с елементи float, char, int и double.
Да се създаде масив и да се мапълни с елементи от горния union с произволни стойности.
*/
{
	printf("\n-----------------task 21_0_1-----------------------\n");
	srand((int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		if (i % 4 == 0)
		{
			base_val[i].value.f = (float)(rand() % 10);
			base_val[i].value_type = val_type_f;
		}
		if (i % 4 == 1)
		{
			base_val[i].value.c = (char)(rand() % 10) + 'c';
			base_val[i].value_type = val_type_c;
		}
		if (i % 4 == 2)
		{
			base_val[i].value.i = (int)(rand() % 10);
			base_val[i].value_type = val_type_i;
		}
		if (i % 4 == 3)
		{
			base_val[i].value.d = (double)(rand() % 10);
			base_val[i].value_type = val_type_d;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (base_val[i].value_type == val_type_f)
		{
			printf("\n%0.4ff", base_val[i].value.f);
		}
		else if (base_val[i].value_type == val_type_c)
		{
			printf("\n%c", base_val[i].value.c);
		}
		else if (base_val[i].value_type == val_type_i)
		{
			printf("\n%d", base_val[i].value.i);
		}
		else
		{
			printf("\n%0.6lf", base_val[i].value.d);
		}
	}
}
void hw_21_1_bits(void)
/*
*Нека направим малка помощна библиотека за high-level побитови манипулации с 8-битови положителни числа
(например u8.h, bits.h, ..). Ползвайте имена по ваш избор за задачите за библиотеката.

Библиотеката трябва да ползва unsigned char за типа на числата и за позициите на отделните битове, _Bool за стойността на бит.
Използвайте typedef за да не се налага да променяме кода на функциите на библиотеката ако решим да ползваме други типове.
Можем и да ползваме conditional compilation макроси за да потвърдим, че компилираме за архитектура с 8-битов байт по следния
начин:
#include <limits.h>
#if (CHAR_BIT != 8)
#error Error CHAR_BIT is not 8!
#else
typedef unsigned char u8;
typedef u8 u8bitpos; // used for specifying bit positions
typedef _Bool u8bit; // value of a bit
#endif
*/
{
	printf("\n-----------------task 21_1-----------------------\n");
	printf("\nLook at ../Library/bitFunc.h and bitFunc.c !\n");
}
void hw_21_2_bitValue(void)
/*
Дефинирайте функция:
u8bit u8_get_bit(u8 num, u8bitpos pos);,
която връща стойността на бит от число num на дадена позиция pos*
*/
{
	printf("\n-----------------task 21_2-----------------------\n");
	u8 num = 0b00001000;
	printf("\nnum = 0b");
	u8_print_bits(stdout, num);
	unsigned char pos = 3;
	printf("\npos = %d", pos);
	u8bit bitValie = u8_get_bit(num, pos);
	(bitValie) ? printf("\n1") : printf("\n0");
}
void hw_21_3_bitChangeOn(void)
/*
Дефинирайте функция:
u8 u8_set_bit_on(u8 num, u8bitpos pos);,
която променя стойността на бит от число num на дадена позиция pos на 1.
*/
{
	printf("\n-----------------task 21_3-----------------------\n");
	u8 num = 0b00000000;
	printf("\nnum = 0b");
	u8_print_bits(stdout, num);
	unsigned char pos = 3;
	printf("\npos = %d", pos);
	u8 numChange = u8_set_bit_on(num, pos);
	printf("\nnumChange = 0b");
	u8_print_bits(stdout, numChange);
}
void hw_21_4_bitChangeOff(void)
/*
 Дефинирайте функция:
u8 u8_set_bit_off(u8 num, u8bitpos pos);,
която променя стойността на бит от число num на дадена позиция pos на 0
*/
{
	printf("\n-----------------task 21_4-----------------------\n");
	u8 num = 0b11111111;
	printf("\nnum = 0b");
	u8_print_bits(stdout, num);
	unsigned char pos = 3;
	printf("\npos = %d", pos);
	u8 numChange = u8_set_bit_off(num, pos);
	printf("\nnumChange = 0b");
	u8_print_bits(stdout, numChange);
}
void hw_21_5_bitChangeOnOff(void)
/*
Дефинирайте функция:
u8 u8_set_bit(u8 num, u8bitpos pos, u8bit val);,
която връща стойността на бит от число num на дадена позиция pos на val
*/
{
	printf("\n-----------------task 21_5-----------------------\n");
	u8 num = 0b11111111;
	printf("\nnum = 0b");
	u8_print_bits(stdout, num);
	u8bit val = 0;
	printf("\nval = %d", val);
	unsigned char pos = 3;
	printf("\npos = %d", pos);

	u8 numChange = u8_set_bit(num, pos, val);
	printf("\nnumChange = 0b");
	u8_print_bits(stdout, numChange);

	num = 0b00000000;
	printf("\nnum = 0b");
	u8_print_bits(stdout, num);
	val = 1;
	printf("\nval = %d", val);
	pos = 3;
	printf("\npos = %d", pos);

	numChange = u8_set_bit(num, pos, val);
	printf("\nnumChange = 0b");
	u8_print_bits(stdout, numChange);
}
void hw_21_6_toggleSingleBit(void)
/*
Дефинирайте функция:
u8 u8_toggle_bit(u8 num, u8bitpos pos);,
която променя стойността на бит от число num на дадена позиция pos на обратната й.
*/
{
	printf("\n-----------------task 21_6-----------------------\n");
	u8 num = 0b11111111;
	printf("\nnum = 0b");
	u8_print_bits(stdout, num);
	unsigned char pos = 3;
	printf("\npos = %d", pos);
	u8 numChange = u8_toggle_bit(num, pos);
	printf("\nnumChange = 0b");
	u8_print_bits(stdout, numChange);

	num = 0b00000000;
	printf("\nnum = 0b");
	u8_print_bits(stdout, num);
	pos = 3;
	printf("\npos = %d", pos);
	numChange = u8_toggle_bit(num, pos);
	printf("\nnumChange = 0b");
	u8_print_bits(stdout, numChange);
}
void hw_21_7_toggleAllBits(void)
/*
Дефинирайте функция:
u8 u8_toggle_bits(u8 num);,
която променя всичките битове от число num на обратните, така че да са равни на обратните им стойности.
*/
{
	printf("\n-----------------task 21_7-----------------------\n");
	u8 num = 0b11111111;
	printf("\nnum = 0b");
	u8_print_bits(stdout, num);
	unsigned char pos = 3;
	printf("\npos = %d", pos);
	u8 numChange = u8_toggle_bits(num);
	printf("\nnumChange = 0b");
	u8_print_bits(stdout, numChange);

	num = 0b00000000;
	printf("\nnum = 0b");
	u8_print_bits(stdout, num);
	pos = 3;
	printf("\npos = %d", pos);
	numChange = u8_toggle_bits(num);
	printf("\nnumChange = 0b");
	u8_print_bits(stdout, numChange);
}
void hw_21_8_reverseBits(void)
/*
Дефинирайте функция:
u8 u8_reverse_bits(u8 num);,
която обръща стойностите на битовете на число num в обратен ред
*/
{
	printf("\n-----------------task 21_8-----------------------\n");
	u8 num = 0b11110000;
	printf("\nnum = 0b");
	u8_print_bits(stdout, num);
	u8 numChange = u8_reverse_bits(num);
	printf("\nnumChange = 0b");
	u8_print_bits(stdout, numChange);
}
void hw_21_9_bitsPrint(void)
/*
Дефинирайте функция:
void u8_print_bits(FILE* f, u8 num);,
която принтира битовете на число num на подадения й файлов поток
*/
{
	printf("\n-----------------task 21_9-----------------------\n");
	u8 num = 0b00001000;
	printf("\nnum = 0b");
	u8_print_bits(stdout, num);
}
void hw_21_10_scanBitsFromFile(void)
/*
Дефинирайте функция:
u8 u8_scan_bits(FILE* f);,
която парсва число на побитов принцип от следващите осем символа в подадения й файлов поток.
*/
{
	printf("\n-----------------task 21_10-----------------------\n");
	FILE* in = NULL;
	FILE* out = NULL;
	char filename[20];
	printf("\nEnter input file name:");
	io_strEnter(filename, 20);
	in = file_open(in, filename, "r");


	u8 num = 0b00000000;
	num = u8_scan_bits(in);
	printf("\nnum = 0b");
	u8_print_bits(stdout, num);

	file_close(in);
}
void hw_21_11_timeBitFields(void)
/*
Променете структурата, която ползваме за репрезентация на календарна дата
да ползва bitfields за годината,месеца и деня от месеца. Оставете
коментар за допустимите стойности за година при декларацията на побитовото
поле за година в дефиницията на структурата за календарна дата
*/
{
	printf("\n-----------------task 21_11-----------------------\n");
	typedef struct dateTime {
		unsigned year : 11; // 0 <= year <= 2048 (2^11 = 2048)
		unsigned month : 4;  // 0 <= month <= 11 (2^4 = 16)
		unsigned day : 5;   // 0 <= day <= 31 (2^5 = 32)
	} dateTime;
}
void hw_21_12(void)
/*
Да променим програмата така че да поддържа различни менюта и опции за различните видове потребители:
● Потребител от тип Owner ще може всичко
● Потребител от тип Admin ще може всичко като Owner, без да може да добавя/премахва фирмени ПС,
както и да редактира информация замарка/модел
● Потребител от тип User ще може само да резервира и да отлага резервация.
Дефинирайте enum константи за различните възможности, които ще предлага приложението, в зависимост
от типа на потредбителя
enum E_APP_PERMISSION_FLAGS
{
 E_BOOK_VEHICLE = //..
 E_UNBOOK_VEHICLE = //..,
 E_EDIT_VEHICLE_INFO = //..,
 E_ADD_REMOVE_VEHICLE = //..,
 E_EDIT_BRAND_INFO = //..
};
Използвайте такива стойности за константите, че да можем да ги ползваме като маски/флагове - всяка константа
трябва да има 0 на всяка позиция,освен на позиция, която е уникална за константата ( пример побитов запис
на четири различни константи: 0001, 0010, 0100, 1000 )
За да напишете стойностите на константите използвайте или оператор <<, или целочислени бинарни литерали
*/
{
	printf("\n-----------------task 21_12-----------------------\n");
	printf("\nLook at Project Vehicle!");
}
void hw_21_13(void)
/*
Дефинирайте enum константи за различните видове потребители на приложението - Owner, Admin, User
enum Е_APP_USER {
 Е_OWNER = //...
 Е_ADMIN = //...
 Е_USER = //...
};
Използвайте стойностите от E_APP_PERMISSION_FLAGS и други стойности от Е_APP_USER (по-горни) за да дефинирате
комбинации от различни опции за всеки потребител.
Използвайте оператор | за комбиниране на опции и оператори & и ~ за изключване на опция. Примери:
E_EDIT_BRAND_INFO | E_EDIT_VEHICLE_INFO // E_EDIT_BRAND_INFO И E_EDIT_VEHICLE_INFO
Е_ADMIN &~EDIT_BRAND_INFO // каквото имаме за Е_ADMIN без EDIT_BRAND_INFO
0xff &~EDIT_BRAND_INFO // всичко без EDIT_BRAND_INFO
Стартирайте приложението/main menu по подобен начин:
start_app(Е_APP_USER_PERMISSION_LEVEL_USER );
(На по-късен етап ще направим login меню, от което ще идва информацията за типа на потребителя)
*/
{
	printf("\n-----------------task 21_13-----------------------\n");
	printf("\nLook at Project Vehicle!");
}