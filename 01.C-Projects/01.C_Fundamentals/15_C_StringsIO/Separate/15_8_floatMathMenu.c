/*
Напишете програма за смятане на float числа, която има следното главно меню, което дава възможност на потребителя да избере
аритметична операция или да излезе от програмата. Програмата трябва да работи правилно и с невалидни данни - да уведомява
потребителя ако въведе невалидни данни и да му даде възможност да ги въведе отново. Примери за невалидни данни:
несъществуващо меню, въведени букви вместо числа, въведено деление на 0.
*/

#include <stdio.h>
#define SRT_MENU "\nEnter the operation of your choice:\na.add\t\ts.subtract\nm.multiply\td.divide\nq.quit\n"
#define SRT_WRONG_CHOICE "\nWrong choice! Please, try again!\n"
#define SRT_WRONG_FLOAT "\nPlease enter a float number, such as 2.5, -1.78E8, or 3:\n"
#define SRT_ENTER_NOT_NULL "\nEnter a float number other than 0:"

char chooseOption(void);

int main(void)
{
	char cChoice = '0';
	float fA = -1.0f;
	float fB = -1.0f;
	//char input[10] = { 0 };

	do
	{
		printf(SRT_MENU);
		cChoice = chooseOption();

		if (cChoice == 'q')
		{
			return 0;
		}
		int isFloat = 0;
		do
		{
			setbuf(stdin, NULL);
			printf("\nEnter first float number:\t");
			isFloat = scanf_s("%f", &fA);
			if (isFloat !=1)
			{ 
				printf(SRT_WRONG_FLOAT);
			}
		} while (isFloat != 1);

		do
		{
			setbuf(stdin, NULL);
			printf("\nEnter second float number:\t");
			isFloat = scanf_s("%f", &fB);
			if (isFloat != 1)
			{
				printf(SRT_WRONG_FLOAT);
			}
		} while (isFloat != 1);

		if ((cChoice == 'd') && (fB == 0))
		{
			while (fB == 0)
			{
				setbuf(stdin, NULL);
				printf(SRT_ENTER_NOT_NULL);
				scanf_s("%f", &fB);
			}
		}

		switch (cChoice)
		{
		case 'a': printf("\n%.2f + %.2f = %.2f", fA, fB, fA + fB); break;
		case 's': printf("\n%.2f - %.2f = %.2f", fA, fB, fA - fB); break;
		case 'm': printf("\n%.2f * %.2f = %.2f", fA, fB, fA * fB); break;
		case 'd': printf("\n%.2f / %.2f = %.2f", fA, fB, fA / fB); break;
		}

	} while (cChoice = 'q');
	return 0;
}

char chooseOption(void)
{
	char cChoice = 0;
	do
	{
		setbuf(stdin, NULL);
		cChoice = getc(stdin);
		if (!((cChoice == 'a') || (cChoice == 's') || (cChoice == 'm') || (cChoice == 'd') || (cChoice == 'q')))
		{
			printf(SRT_WRONG_CHOICE);
		}

	} while (!((cChoice == 'a') || (cChoice == 's') || (cChoice == 'm') || (cChoice == 'd') || (cChoice == 'q')));
	return cChoice;
}