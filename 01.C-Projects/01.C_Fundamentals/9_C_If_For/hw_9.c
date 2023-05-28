#include "hw_9.h"
#include <stdio.h>
#include <ctype.h>

void printLetter(char c, int iSymbolPerRow, int iRows)
{
	for (int i = 0; i < iRows; i++)
	{
		for (int j = 0; j < iSymbolPerRow; j++)
		{
			printf("%c", c);
		}
		printf("\n");
	}
}

void hw_9_1_rectangleArea(void) 
/*
Създайте програма, която показва на екран
обиколката и лицето на правоъгълник с височина 12.5
см и ширина 20.6 см.
*/
{
	printf("\n----------------task 9_1------------------\n");
	const float a = 12.5f;
	const float b = 20.5f;
	const float Area = a * b;
	const float Perimeter = 2 * (a + b);

	printf("\nArea = a * b = %.1f * %.1f = %.2f", a, b, Area);
	printf("\nPerimeter = 2 * (a + b) = 2 * (%.1f + %.1f) = %.1f", a, b, Perimeter);
}
void hw_9_2_winNumber(void)
/*
Създайте програма, която при въвеждане на число от
конзолата сравнява със зададена от вас константа и изписва
на конзолата „Печелите!“, ако въведеното число е равно или по
голямо и „Опитайте отново!“, ако е по-малко. Направете
примера използвайки единствено конструкцията if.
Какви променливи и от какъв тип ще имам?(2)
Какви са последователните операции, които трябва да изпълня?
Направете примера с конструкцията if-else.
*/
{
	printf("\n----------------task 9_2------------------\n");
	const int ciWinNumber = 13;
	int iChooseNumber = -1;
	printf("\nEnter a number: ");
	scanf_s("%d", &iChooseNumber);

	if (iChooseNumber >= ciWinNumber)
	{
		printf("\nYou winn!!!");
	}
	else
	{
		printf("\nTry again!!!");
	}
}
void hw_9_3_heightRange(void)
/*
Направете С програма, която да пита за ръста на човек и в
зависимост от въведеното число да ги квалифицира по
следния начин:
До 145 см включително - нисък ръст
От 146 до 180 - среден ръст;
Над 181 см до 205 см. – висок ръст
Извън тези граници – изключително висок ръст
*/
{
	printf("\n----------------task 9_3------------------\n");
	int iYourHeigh = -1;

	printf("\nEnter person height: ");
	scanf_s("%d", &iYourHeigh);

	if (iYourHeigh <= 145)
	{
		printf("\nYou are very short!");
	}
	else if (iYourHeigh <= 180)
	{
		printf("\nYou are of average height!");
	}
	else if (iYourHeigh <= 205)
	{
		printf("\nYou are of tall!");
	}
	else
	{
		printf("\nYou are of very tall!");
	}
}
void hw_9_4_0_ifAgeGender(void)
/*
За целите на научно изследване търсите хора, които отговарят на следните критерии
Жени на възраст от 25 до 35 години.
Мъже на възраст от 30 до 40 години.
Правите онлайн проучване, в което кандидатите въвеждат данните си и вие трябва да им кажете, дали
са подходящи или не. Ползвайте променливи за пол и възраст.
*/
{
	printf("\n----------------task 9_4_0------------------\n");
	int iGender = -1;
	int iAge = -1;

	printf("\nPlease, enter your gender: \nWoman - 1\nMan - 2");
	scanf_s("%d", &iGender);

	printf("\nPlease, enter your age: ");
	scanf_s("%d", &iAge);

	if (iGender == 1)
	{
		if (25 <= iAge && iAge <= 35)
		{
			printf("\nYou are eligible for the study!");
		}
		else
		{
			printf("\nYou are not eligible for the study!");
		}
	}
	if (iGender == 2)
	{
		if (30 <= iAge && iAge <= 40)
		{
			printf("\nYou are eligible for the study!");
		}
		else
		{
			printf("\nYou are not eligible for the study!");
		}
	}
}
void hw_9_4_1_ifAgeGender(void)
/*
Използвайте тернарен ( ? : ) оператор за едно от условията.
*/
{
	printf("\n----------------task 9_4_1------------------\n");
	int iGender = -1;
	int iAge = -1;

	printf("\nPlease, enter your gender: \nWoman - 1\nMan - 2");
	scanf_s("%d", &iGender);

	printf("\nPlease, enter your age: ");
	scanf_s("%d", &iAge);

	if (iGender == 1)
	{
		(25 <= iAge && iAge <= 35) ? printf("\nYou are eligible for the study!") : printf("\nYou are not eligible for the study!");
	}
	if (iGender == 2)
	{
		(30 <= iAge && iAge <= 40) ? printf("\nYou are eligible for the study!") : printf("\nYou are not eligible for the study!");
	}
}
void hw_9_4_2_switchAgeGender(void)
/*
Направете задачата за точна възраст - за жени 25 или 35 години;
За мъже 30 или 40 години.
*/
{
	printf("\n----------------task 9_4_2------------------\n");
	int iGender = -1;
	int iAge = -1;

	printf("\nPlease, enter your gender: \nWoman - 1\nMan - 2");
	scanf_s("%d", &iGender);

	printf("\nPlease, enter your age: ");
	scanf_s("%d", &iAge);

	if (iGender == 1)
	{
		switch (iAge)
		{
		case 25:
		case 35:
			printf("\nYou are eligible for the study!");
			break;
		default:
			printf("\nYou are not eligible for the study!");
			break;
		}
	}
	if (iGender == 2)
	{
		switch (iAge)
		{
		case 30:
		case 40:
			printf("\nYou are eligible for the study!");
			break;
		default:
			printf("\nYou are not eligible for the study!");
			break;
		}
	}
}
void hw_9_4_3_ifAgeGender(void)
/*
Направете го за два диапазона – жени от 25 до 30 включително или от 35 до 40
включително.
Мъже от 30-35 включително или от 40 до 45 г включително.
*/
{
	printf("\n----------------task 9_4_3------------------\n");
	int iGender = -1;
	int iAge = -1;

	printf("\nPlease, enter your gender: \nWoman - 1\nMan - 2");
	scanf_s("%d", &iGender);

	printf("\nPlease, enter your age: ");
	scanf_s("%d", &iAge);

	if (iGender == 1)
	{
		if ((25 <= iAge && iAge <= 30) || (35 <= iAge && iAge <= 40))
		{
			printf("\nYou are eligible for the study!");
		}
		else
		{
			printf("\nYou are not eligible for the study!");
		}
	}
	if (iGender == 2)
	{
		if ((30 <= iAge && iAge <= 35) || (40 <= iAge && iAge <= 45))
		{
			printf("\nYou are eligible for the study!");
		}
		else
		{
			printf("\nYou are not eligible for the study!");
		}
	}
}
void hw_9_5_switchAritmetic(void)
/*
Създайте програма, която подканя човека да въведе проста
аритметична операция с две числа от екрана - събиране, изваждане,
деление, умножение и отпечатва резултата.
*/
{
	printf("\n----------------task 9_5------------------\n");
	float fA = -1.0f;
	float fB = -1.0f;
	char cOperator = '0';

	printf("\nEnter float A:");
	scanf_s("%f", &fA);

	printf("\nEnter float B:");
	scanf_s("%f", &fB);

	printf("\nEnter operator:");
	scanf_s(" %c", &cOperator, 1);

	switch (cOperator)
	{
	case '+':
		printf("A + B = %.2f + %.2f = %.2f", fA, fB, fA + fB);
		break;
	case '-':
		printf("A - B = %.2f - %.2f = %.2f", fA, fB, fA - fB);
		break;
	case '*':
		printf("A * B = %.2f * %.2f = %.2f", fA, fB, fA * fB);
		break;
	case '/':
		printf("A / B = %.2f / %.2f= %.2f", fA, fB, fA / fB);
		break;
	}
}
void hw_9_6_switchMonthDays(void)
/*
Направете програма, която при въвеждане на месец от годината
като число извежда на екран колко дни има в месеца - “Посочения
месец има ... дни).
*/
{
	printf("\n----------------task 9_6------------------\n");
	int iMonth = -1;

	printf("\nPlease, enter a month from 1 to 12:");
	scanf_s("%d", &iMonth);

	switch (iMonth)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		printf("\nThe month has 31 days!");
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		printf("\nThe month has 30 days!");
		break;
	case 2:
		printf("\nThe month has 28 or 29 days!");
		break;
	default:
		printf("\nNo such month!");
		break;
	}
}
void hw_9_7_hotelInterface(void)
/*
Трябва да направите софтуер за заявки на хотел. Хотела има два
типа стаи - Луксозна, с цена 180 лв на нощ, Стандартна -120 лв на
нощ. Туристическият данък е 6%. Направете програма, която
калкулира очаквана себестойност за клиентите в зависимост от брой
нощувки и стаи, и я отпечатва на екрана. Валидността на офертата е
14 дни.
*/
{
	printf("\n----------------task 9_7------------------\n");
	int iTouristRoomChoice = -1;
	int iNumberOvernights = -1;
	int iPricePerNight = -1;
	int iCountNights = -1;
	int iTouristAccount = 0;
	int iCountTouristAccounts = 0;
	int iHotelProfit = 0;
	double dFinalHotelProfit = 0.0;
	char cContinue = '0';
	const double dTouristTax = 0.06;
	double dFinalHotelTouristTax = -1.0;

	do
	{
		printf("\nTypes of rooms:");
		printf("\n1.Standart room - 120 BGN per night");
		printf("\n2. Luxury room - 180 BGN per night");
		printf("\nPlease enter tourist chiose 1 or 2: ");
		scanf_s("%d", &iTouristRoomChoice);
		printf("\nPlease enter nubers of overnight stay: ");
		scanf_s("%d", &iNumberOvernights);

		switch (iTouristRoomChoice)
		{
		case 1:
			iPricePerNight = 120;
			break;
		case 2:
			iPricePerNight = 180;
			break;
		default:
			printf("\nNo such room!");
			break;
		};

		iTouristAccount = iNumberOvernights * iPricePerNight;
		printf("\nTourist account will be %d BGN.", iTouristAccount);
		printf("\nThe offer is valid for 14 days!");

		iHotelProfit += iTouristAccount;
		printf("\nWould you like to enter new offer? y/n");
		scanf_s(" %c", &cContinue, 1);

	} while (cContinue == 'y' || cContinue == 'Y');

	dFinalHotelTouristTax = iHotelProfit * dTouristTax;
	dFinalHotelProfit = iHotelProfit - dFinalHotelTouristTax;

	printf("\nProfit for the hotel: %d BGN", iHotelProfit);
	printf("\nTourist tax for the hotel 6 percent: %.2lf BGN", dFinalHotelTouristTax);
	printf("\nFinal profit for the hotel: %.2lf BGN", dFinalHotelProfit);
}
void hw_9_8_0_printNumbers(void)
/*
Направете програма, която ползва for за да отпечати числата от 1 до 10 всяко на
нов ред.
*/

{
	printf("\n----------------task 9_8_0------------------\n");
	for (int i = 1; i <= 10; i++)
	{
		printf("\n%d", i);
	}
}
void hw_9_8_1_printNumbersBreak(void)
/*
Модифицирайте, така че програмата да пропусне 5 и 7;
Продължение 2 Модифицирайте, така че програмата да спре на 9.
*/
{
	printf("\n----------------task 9_8_1------------------\n");
	for (int i = 1; i <= 10; i++)
	{
		if (i == 5 || i == 7)
		{
			continue;
		}
		if (i == 9)
		{
			break;
		}
		printf("\n%d", i);
	}
}
void hw_9_9_0_sumInt(void)
/*
Направете for цикъл, който показва сбора на първите 10 естествени
числа.
*/
{
	printf("\n----------------task 9_9_0------------------\n");
	int iSum = 0;

	for (int i = 1; i <= 10; i++)
	{
		iSum += i;
	}
	printf("\nSum 1 to 10 = %d", iSum);
}
void hw_9_9_1_sumInt(void)
/*
Наравете програмата да дава възможност да въведе броя на естествените числа,
чиито сбор показва.
*/
{
	printf("\n----------------task 9_9_1------------------\n");
	int iSum = 0;
	int iN = -1;

	printf("N = ");
	scanf_s("%d", &iN);

	for (int i = 1; i <= iN; i++)
	{
		iSum += i;
	}
	printf("\nSum 1 to %d = %d", iN, iSum);
}
void hw_9_10_sumInt(void)
/*
Направете С програма, която калкулира сбора на първите 10 числа, използвайки while.
*/
{
	printf("\n----------------task 9_10------------------\n");
	int iSum = 0;
	int i = 1;

	while (i <= 10)
	{
		iSum += i;
		i++;
	}
	printf("\nSum 1 to 10 = %d", iSum);
}
void hw_9_11_guessTheNumber(void)
/*
Игра „Познай числото“
Въведете в програмата си число от 0 до 20, което другите ще трябва да познаят
(константа).
Помолете играещият да направи предположение. Играещият има право на 5
опита.
Програмата трябва да сравни, дали числото е по-голямо или по-малко от
константата и да каже на потребителя.
Играещият да може да въведе само число от 0-20, проверете.
*/
{
	printf("\n----------------task 9_11------------------\n");
	int ciNumberToGuess = -1;
	int iChoosenNumber = -1;
	int i = 1;

	do
	{
		printf("\nEnter number to guess from 1 to 20:");
		scanf_s("%d", &ciNumberToGuess);
	} while (ciNumberToGuess < 1 || 20 < ciNumberToGuess);

	while (i <= 5)
	{
		i++;
		printf("Guess the number:");
		scanf_s("%d", &iChoosenNumber);

		if (iChoosenNumber == ciNumberToGuess)
		{
			printf("You win!!! The number is %d!", ciNumberToGuess);
			break;
		}
		else if (iChoosenNumber < ciNumberToGuess)
		{
			printf("Number to guess is bigger than yours!\n");
		}
		else
		{
			printf("Number to guess is smaller than yours!\n");
		}
		if (i == 5 && (iChoosenNumber != ciNumberToGuess))
		{
			printf("\nSorry, you loose!!! The number is %d!", ciNumberToGuess);
			break;
		}
	}
}
void ex_9_1_hourToMinutes(void)
/*
Write a program that converts time in minutes to time in hours and minutes.
Use #define or const to create a symbolic constant for 60.
Use a while loop to allow the user to enter values repeatedly and terminate the loop
if a value for the time of 0 or less is entered.
*/
{
	printf("\n----------------ex 9_1------------------\n");
	const int iHourToMinutes = 60;
	int iCustomerMinutes = -1;
	int iHours = -1;
	int iMinutes = -1;

	printf("\nEnter number of minutes: ");
	scanf_s("%d", &iCustomerMinutes);

	while (iCustomerMinutes > 0)
	{
		iHours = iCustomerMinutes / iHourToMinutes;
		iMinutes = iCustomerMinutes % iHourToMinutes;
		printf("In %d minutes has %d hours and %d minutes!", iCustomerMinutes, iHours, iMinutes);

		printf("\nEnter number of minutes: ");
		scanf_s("%d", &iCustomerMinutes);
	}
}
void ex_9_2_lowerCase(void)
/*
Write a program that creates an array with 26 elements
and stores the 26 lowercase letters in it.
Also have it show the array contents.
*/
{
	printf("\n----------------ex 9_2------------------\n");
	char cArr[27];
	int size = 27;
	char ch = '0';
	int i = 0;

	printf("\nEnter a lowercase letters:");
	while (i < size - 1)
	{
		scanf_s(" %c", &ch, 1);
		if ('a' <= ch && ch <= 'z')
		{
			cArr[i] = ch;
			i++;
		}
	}
	cArr[size - 1] = '\0';
	printf("\n%s", cArr);
	setbuf(stdin, NULL);
}
void ex_9_3_countLette(void)
/*
Write a function that takes three arguments : a character and two integers.
The character is to be printed. The first integer specifies the number of times
that the character is to be printed on a line, and the second integer specifies
the number of lines that are to be printed. Write a program that makes use of this
function.
*/
{
	printf("\n----------------ex 9_3------------------\n");
	char cSymbol = '0';
	int iNumberOfRows = -1;
	int iNumberOfSymbolsPerRow = -1;

	printf("\nEnter a symbol to be print:");
	scanf_s(" %c", &cSymbol, 1);
	printf("\nEnter number of symbols per row:");
	scanf_s("%d", &iNumberOfSymbolsPerRow);
	printf("\nEnter number of rows:");
	scanf_s(" %d", &iNumberOfRows);

	printLetter(cSymbol, iNumberOfSymbolsPerRow, iNumberOfRows);
}
void ex_9_4_interes(void)
/*
Daphne invests $100 at 10% simple interest.
(That is, every year, the investment earns an interest equal to 10% of the original investment.)
Deirdre invests $100 at 5% interest compounded annually.
(That is, interest is 5% of the current balance, including previous addition of interest.)
Write a program that finds how many years it takes for the value of Deirdre's investment to exceed
the value of Daphne's investment. Also show the two values at that time.
*/
{
	printf("\n----------------ex 9_4------------------\n");
	const double fDaphneSympleInterest = 0.1;
	const double fDeirdreCompaundInterest = 0.05;
	const double DaphneFirstInvestment = 100.0;
	double DaphneInvestment = 100.0;
	double DeirdreInvestment = 100.0f;
	int iYearCount = 0;

	do
	{
		DaphneInvestment += DaphneFirstInvestment * fDaphneSympleInterest;
		DeirdreInvestment += DeirdreInvestment * fDeirdreCompaundInterest;
		iYearCount++;
	} while (DaphneInvestment > DeirdreInvestment);

	printf("After %d years: ", iYearCount);
	printf("\nDaphne Investment id increased to %.2lf $", DaphneInvestment);
	printf("\nDeirdre Investment id increased to %.2lf $", DeirdreInvestment);
}
void ex_9_5_account(void)
/*
Chuckie Lucky won a million dollars, which he places in an account that earns 8% a year.
On the last day of each year, Chuckie withdraws $100,000. Write a program that finds out
how many years it takes for Chuckie to empty his account.
*/
{
	printf("\n----------------ex 9_5------------------\n");
	const float fFirstInvestment = 1000000.0f;
	float fInvestment = 1000000.0f;
	float fYearInterest = 0.08f;
	float fWiddraw = 100000.0f;
	int iYearCount = 0;

	do
	{
		fInvestment += fFirstInvestment * fYearInterest;
		fInvestment -= fWiddraw;
		iYearCount++;
	} while (fInvestment > 0);

	printf("After %d years Chuckie Lucky will empty his account!", iYearCount);
}
