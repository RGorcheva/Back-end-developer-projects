/*
● Декларирайте (без да дефинирате) следните функции:
● Функция avrg, която връща средното аритметично на две числа с плаваща запетая
● Функция char_to_int, която връща цялото число, на което отговаря подадения й символ
● Функция print_char_code, която принтира на екрана кода на символ
● Функция print_char, която от подаден код принтира отговарящия му char символ
● Напишете код, който извиква всяка една от горните четири функции с примерни аргументи
● Извиквайки avrg, без да ползвате променливи, напишете на един ред принтиране на средното
аритметично на следните числа:
● Число 1: средното аритметично на 0 и 100
● Число 2: средното аритметично на 100 и 200
*/

#include <stdio.h>

float avrg(float fA, float fB)
{
	return (fA + fB) / 2;
}
int char_to_int(char ch);
void print_char_code(char ch);
void print_char(int iCode);

int main(void)
{
	float fA = 1.0f;
	float fB = 1.0f;
	char ch = 'c';
	int iCode = 20;
	printf("\n%.2f",  avrg(avrg(0.0f, 100.0f),  avrg(100.0f, 200.0f)));
	printf("\n%f", avrg(fA, fB));
	printf("\n%d", char_to_int(ch));
	print_char_code(ch);
	print_code(iCode);
	return 0;
}
