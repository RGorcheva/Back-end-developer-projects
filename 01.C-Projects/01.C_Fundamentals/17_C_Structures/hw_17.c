#include "hw_17.h"
#include "../Library/math2dFunc.h"
#include "../Library/stringFunc.h"
#include "../Library/inputOutputFunc.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

const char* brand[] = { "FIAT", "MAZDA", "FORD", "TOYOTA" };
const char* model[] = { "Punto", "2", "Fiesta", "Yaris" };

struct VehicleShopInfo
{
	unsigned yearOfМanufacture;
	const char* brand;
	const char* model;
	char VIN[20];
	float pricePerDay;
};

struct Person
{
	char name[50];
	unsigned age;
} personArr[5], *ptrPerson;

struct PersonNode
{
	struct Person;
	struct PersonNode *ptrPNext;
} personNodeArr[5], *ptrPersonNode;

void print_vehicleInfo(struct VehicleShopInfo* pVehicle)
{
	printf("\nVehicle_1:\nyearOfManufacture - %u", pVehicle->yearOfМanufacture);
	printf("\nbrand - %s", pVehicle->brand);
	printf("\nmodel - %s", pVehicle->model);
	printf("\nVIN - %s", pVehicle->VIN);
	printf("\npricePerDay - %.2f BGN", pVehicle->pricePerDay);
}
void enter_vehicleInfo(struct VehicleShopInfo* pVehicle)
{
	int chooseBrand = 0;
	printf("\nyearOfManufacture: ");
	scanf_s("%u", &pVehicle->yearOfМanufacture);
	printf("\nChoose vehicle between: FIAT Punto-1, MAZDA 2-2, FORD Fiesta-3, TOYOTA Yaris-4");
	scanf_s("%d", &chooseBrand);
	if (chooseBrand == 1)
	{
		pVehicle->brand = brand[0];
		pVehicle->model = model[0];
	}
	else if (chooseBrand == 2)
	{
		pVehicle->brand = brand[1];
		pVehicle->model = model[1];
	}
	else if (chooseBrand == 3)
	{
		pVehicle->brand = brand[2];
		pVehicle->model = model[2];
	}
	else if (chooseBrand == 4)
	{
		pVehicle->brand = brand[3];
		pVehicle->model = model[3];
	}
	printf("\nVIN:");
	setbuf(stdin, NULL);
	fgets(pVehicle->VIN, 19, stdin);
	char* p = 0;
	p = string_strchrFindFirstChar(pVehicle->VIN, '\n');
	*p = '\0';
	setbuf(stdin, NULL);
	printf("\npricePerDay:");
	scanf_s("%f", &pVehicle->pricePerDay);
}
void print_vehicleInfoArr(struct VehicleShopInfo* pVehicle, int countElements)
{
	int i = 0;
	for (struct VehicleShopInfo* p = pVehicle; p < pVehicle + countElements; p++, i++)
	{
		printf("\nVehicle[%d]:\nyearOfManufacture - %u", i, p->yearOfМanufacture);
		printf("\nbrand - %s", p->brand);
		printf("\nmodel - %s", p->model);
		printf("\nVIN - %s", p->VIN);
		printf("\npricePerDay - %.2f BGN", p->pricePerDay);
		printf("\n");
	}
}
void enter_vehicleInfoArr(struct VehicleShopInfo* pVehicle, int countElements)
{
	int i = 0;
	for (struct VehicleShopInfo* ptr = pVehicle; ptr < pVehicle + countElements; ptr++, i++)
	{
		printf("\nEnter Info for vehicle %d:", i);
		printf("\nyearOfManufacture: ");
		scanf_s("%u", &ptr->yearOfМanufacture);
		int chooseBrand = 0;
		printf("\nChoose vehicle between: FIAT Punto-1, MAZDA 2-2, FORD Fiesta-3, TOYOTA Yaris-4");
		scanf_s("%d", &chooseBrand);
		if (chooseBrand == 1)
		{
			ptr->brand = brand[0];
			ptr->model = model[0];
		}
		else if (chooseBrand == 2)
		{
			ptr->brand = brand[1];
			ptr->model = model[1];
		}
		else if (chooseBrand == 3)
		{
			ptr->brand = brand[2];
			ptr->model = model[2];
		}
		else if (chooseBrand == 4)
		{
			ptr->brand = brand[3];
			ptr->model = model[3];
		}
		printf("\nVIN:");
		setbuf(stdin, NULL);
		fgets(ptr->VIN, 19, stdin);
		char* p = 0;
		p = string_strchrFindFirstChar(ptr->VIN, '\n');
		*p = '\0';
		setbuf(stdin, NULL);
		printf("\npricePerDay:");
		scanf_s("%f", &ptr->pricePerDay);
	}
}
void print_list(struct PersonNode* list)
{
	while (list != NULL)
	{
		printf("\n%s", list->name);
		printf("\n%u", list->age);
		printf("\n");
		list = list->ptrPNext;
	}
}


void hw_17_0_1_defineStruct(void)
/*
● Дефинирайте нов тип VehicleShopInfo, който можем да ползваме за да държим
информация, свързана с отдаването на превозни средства под наем.
● Дефинирайте members за следната информация:
○ Година на производство
○ Име на марката
○ Име на модела
○ Уникален идентификатор на превозното средство (VIN)
○ Цена на ден
● Дефинирайте две променливи от тип VehicleShopInfo и ги инициализирайте.
● Принтирайте информацията за двете превозни средства.
*/
{
	printf("\n-----------task 17_0_1-----------------");
	struct VehicleShopInfo vehicle_1 = {
		.yearOfМanufacture = 2017u,
		.brand = brand[3],
		.model = model[3],
		.VIN = "67LU280957863CH56",
		.pricePerDay = 120.0f
	};

	struct VehicleShopInfo vehicle_2 = {
		.yearOfМanufacture = 2010u,
		.brand = brand[1],
		.model = model[1],
		.VIN = "8363GKY0387864RD3",
		.pricePerDay = 100.0f
	};

	printf("\nVehicle_1:\t%u,\t%s,\t%s,\t%s,\t%.2f", vehicle_1.yearOfМanufacture, vehicle_1.brand, vehicle_1.model, vehicle_1.VIN, vehicle_1.pricePerDay);
	printf("\nVehicle_2:\t%u,\t%s,\t%s,\t%s,\t%.2f", vehicle_2.yearOfМanufacture, vehicle_2.brand, vehicle_2.model, vehicle_2.VIN, vehicle_2.pricePerDay);
}
void hw_17_0_2_structArr(void)
/*
Дефинирайте масив от VehicleShopInfo обекти и го инициализирайте.
Обходете масива и принтирайте информацията за всяко превозно средство от
масива.
*/
{
	printf("\n-----------task 17_0_2-----------------");
	struct VehicleShopInfo vehicles[2] = {
	{
		.yearOfМanufacture = 2017u,
		.brand = brand[3],
		.model = model[3],
		.VIN = "67LU280957863CH56",
		.pricePerDay = 120.0f
	},
	{
		.yearOfМanufacture = 2010u,
		.brand = brand[1],
		.model = model[1],
		.VIN = "8363GKY0387864RD3",
		.pricePerDay = 100.0f
	}
	};

	printf("\nVehicle[0]:\t%u,\t%s,\t%s,\t%s,\t%.2f", vehicles[0].yearOfМanufacture, vehicles[0].brand, vehicles[0].model, vehicles[0].VIN, vehicles[0].pricePerDay);
	printf("\nVehicle[1]:\t%u,\t%s,\t%s,\t%s,\t%.2f", vehicles[1].yearOfМanufacture, vehicles[1].brand, vehicles[1].model, vehicles[1].VIN, vehicles[1].pricePerDay);
}
void hw_17_0_3_pointerToStruct(void)
/*
● Дефинирайте и инициализирайте променлива от тип VehicleShopInfo и друга
променлива, от тип - указател към VehicleShopInfo.
● Използвайте scanf_s и указателя към VehicleShopInfo за да дадете възможност на
потребителя да промени годината на производство.
● Принтирайте информацията за превозното средство чрез указателя.
*/
{
	printf("\n-----------task 17_0_3----------------");
	struct VehicleShopInfo vehicle_1 = {
	.yearOfМanufacture = 2017u,
	.brand = brand[3],
	.model = model[3],
	.VIN = "67LU280957863CH56",
	.pricePerDay = 120.0f
	};

	struct VehicleShopInfo* pVehicle = &vehicle_1;

	printf("\nVehicle_1:\t%u,\t%s,\t%s,\t%s,\t%.2f", pVehicle->yearOfМanufacture, pVehicle->brand, pVehicle->model, pVehicle->VIN, pVehicle->pricePerDay);
	printf("\nChange year of manufacture:");
	scanf_s("%u", &(pVehicle->yearOfМanufacture));
	printf("\nVehicle_1:\t%u,\t%s,\t%s,\t%s,\t%.2f", pVehicle->yearOfМanufacture, pVehicle->brand, pVehicle->model, pVehicle->VIN, pVehicle->pricePerDay);
}
void hw_17_0_4_inputOutputFunc(void)
/*
Напишете функция за принтиране на данните на VehicleShopInfo обект.
Напишете функция за въвеждането на данните за VehicleShopInfo от потребителя.
Напишете програма, която ползва функциите.
*/
{
	printf("\n-----------task 17_0_4-----------------");
	struct VehicleShopInfo vehicle_1;
	struct VehicleShopInfo* pVehicle = &vehicle_1;
	enter_vehicleInfo(pVehicle);
	print_vehicleInfo(pVehicle);
}
void hw_17_0_5_inputOutputArrFunc(void)
/*
● Напишете функция за принтиране на масив от VehicleShopInfo обекти
● Напишете функция за въвеждането на масив от VehicleShopInfo обекти от
потребителя
● Напишете програма, която извиква функциите.
*/
{
	printf("\n-----------task 17_0_5-----------------");
	struct VehicleShopInfo vehicles[2];
	int countElements = 2;
	enter_vehicleInfoArr(vehicles, countElements);
	print_vehicleInfoArr(vehicles, countElements);
}
void hw_17_1_math_structDefinitions(void)
/*
Да положим основите на библиотека за 2D геометрични функции, полезни в редица
приложения, свързани с компютърна графика, например.
math2d.h
Нека ползваме float за всички типове и функции от библиотеката.
...
Дефинирайте следните типове, изполвайки struct:
● точка в равнината(2D), примерни имена: point2f, point2, vec2f, vec2, vec2df, ..
● триъгълник в равнината
● кръг
● правоъгълник (axis-aligned - без ротация, винаги с перпендикулярни страни на абцисната и
ординатна оси - на страните на екрана), примерни имена : rect2df, aabb2, ..
● полигон (с от 3 до 8 върха - vertices)
*/ 
{
	printf("\n-----------task 17_1-----------------");
}
void hw_17_2_pointInCircle(void)
/*
Дефинирайте функция, която проверява дали точка е във вътрешността на кръг
*/
{
	printf("\n-----------task 17_2-----------------");
	struct point2DF point = {0.0f, 0.0f};
	struct point2DF* ptrPoint = &point;

	struct circle2DF circlek = { { 0.0f, 0.0f }, 0.0f };
	struct circle2DF* ptrCircle = &circlek;

	math2d_enterPiont(ptrPoint);
	math2d_enterCircle(ptrCircle);
	if (math2d_isPointInCircle(ptrPoint, ptrCircle))
	{
		printf("The point is contained within the circle!");
	}
	else
	{
		printf("The point is NOT contained within the circle!");
	}
}
void hw_17_3_pointInRectangle(void)
/*
Дефинирайте функция, която проверява дали точка е във вътрешността на правоъгълник (aabb)
*/
{
	printf("\n-----------task 17_3-----------------");
	struct point2DF point;
	struct point2DF* ptrPoint = &point;

	struct rectangle2DF rectangle;
	struct rectangle2DF* ptrRectangle = &rectangle;

	math2d_enterPiont(ptrPoint);
	math2d_enterRectangle(ptrRectangle);
	if (math2d_isPointInRectangle(ptrPoint, ptrRectangle))
	{
		printf("The point is contained within the rectangle!");
	}
	else
	{
		printf("The point is NOT contained within the rectangle!");
	}
}
void hw_17_4_isCircleInCircle(void)
/*
Дефинирайте функция, която проверява дали два кръга имат допирни точки (не се пресичат и нито единия не е
изцяло във вътрешността на другия)
*/
{
	printf("\n-----------task 17_4-----------------");
	struct circle2DF circle1;
	struct circle2DF* ptrCircle1 = &circle1;

	struct circle2DF circle2;
	struct circle2DF* ptrCircle2 = &circle2;

	math2d_enterCircle(ptrCircle1);
	math2d_enterCircle(ptrCircle2);

	if (math2d_isCircleInCircle(ptrCircle1, ptrCircle2))
	{
		printf("The circles have points in common!");
	}
	else
	{
		printf("The circles have NOT points in common!");
	}
}
void hw_17_5_distPointToPoint(void)
/*
Дефинирайте функция за пресмятането на разстоянието между две точки в равнината.
*/
{
	printf("\n-----------task 17_5-----------------");
	float distAB = 0;

	struct point2DF pointA;
	struct point2DF* ptrPointA = &pointA;

	struct point2DF pointB;
	struct point2DF* ptrPointB = &pointB;

	math2d_enterPiont(ptrPointA);
	math2d_enterPiont(ptrPointB);

	distAB = math2d_distancePointToPoint(ptrPointA, ptrPointB);
	printf("\nDistAB = %.2f", distAB);
}
void hw_17_6_and_7_enterPrintStruct(void)
/*
Дефинирайте функции за въвеждане на всяка една от шестте геометрични фигури от потребителя.
Дефинирайте функции всяка за принтиране на всяка една от шестте геометрични фигури.
*/
{
	printf("\n-----------task 17_6 and task 17_7-----------");
	struct point2DF point;
	struct point2DF* ptrPoint = &point;

	struct triangle2DF triangle;
	struct triangle2DF* ptrTriangle = &triangle;

	struct circle2DF circlek;
	struct circle2DF* ptrCircle = &circlek;

	struct rectangle2DF rectangleabcd;
	struct rectangle2DF* ptrRectangle = &rectangleabcd;

	struct polygon2DF polygon;
	struct polygon2DF* ptrPolygon = &polygon;

	math2d_enterPiont(ptrPoint);
	math2d_printPoint(ptrPoint);

	math2d_enterTriangle(ptrTriangle);
	math2d_printTriangle(ptrTriangle);

	math2d_enterCircle(ptrCircle);
	math2d_printCircle(ptrCircle);

	math2d_enterRectangle(ptrRectangle);
	math2d_printRectangle(ptrRectangle);

	math2d_enterPolygon(ptrPolygon);
	math2d_printPolygon(ptrPolygon);
}
void hw_17_8_1_(void)
/*
Направете нова версия на програмата за отдаване на превозни средства под наем. В бъдеще ще разширим функционалността на
програмата да работи с файлове и дати, засега ще четем хард-коднати свободни превозни средства(ПС) и ще ги отдаваме едно по едно
докато не свършат или не излезем от програмата.
● Програмата трябва да има следните менюта:
○ Main Menu, със следните опции:
■ Press 1 to choose vehicle (води до Choose Vehicle Menu с всички свободни ПС)
■ Press 2 to choose vehicle by brand(води до Choose Brand Menu с всички марки от които има налични ПС, след което до
Choose Vehicle Menu с всички свободни ПС от избраната марка)
■ Press q to quit.
○ Choose Vehicle Menu - списък с множество свободни ПС(в зависимост от контекста, някой път всички, друг път - от дадена
марка), с опция за избор на ПС(водеща до Vehicle Details Menu) + опция за връщане в Main Menu (“Press b to go back to
Main Menu”)
○ Choose Brand Menu - списък с марки ПС, за които има налично свободно ПС. Дава възможност за избор на марка(при
което води до Choose Vehicle Menu със свободни ПС от избраната марка) или връщане в Main Menu
○ Vehicle Details Menu, със следното съдържание:
■ <Детайли за марката - име и кратка информация>
■ <Детайли за модела - име и кратка информация>
■ <Брой свободни ПС от тази марка и модел>
■ <Цена за наемане за едно денонощие>
■ Опции за наемане на ПС (за текущото изпълнение на програмата) и за връщане в предходното меню - Choose Vehicle
Menu (с последните филтри за менюто)
*/
{
	printf("\n-----------task 17_8_1-----------------");
}
void hw_17_8_2_(void)
/*
● Направете отделен модул (в отделни .h и .c файлове) за съхранение на информацията, свързана с различните марки
и модели на превозни средства. За всяка марка, както и за всеки модел от дадена марка трябва да пазим име и
кратко описание на марката/модела. В бъдеще модулът ще има функции за четене на информацията от файл(ове)
или от мрежата, засега можем да хард-коднем примерни данни.
● Направете отделен модул за съхранение и достъп до информацията за всичките ПС на компанията, с цена за
денонощие и наличност (дали е наличен за текущото изпълнение на програмата засега)
● Напревете трети, основен модул на програмата, който да чете избора на потребителя и да контролира потока на
изпълнение на програмата, на базата на направения от потребителя избор.
● Дефинирайте и използвайте отделни типове за различните видове данни:
○ Информация за марка(име и кратко описание засега)
○ Информация за модел от марка(име и кратко описание засега)
○ Информация за превозните средства с които разполага компанията(марка, модел, наличност, цена за всяко ПС)
*/
{
	printf("\n-----------task 17_8_2-----------------");
}
void hw_17_9_structPerson(void)
/*
● Дефинирайте тип Person с име и възраст.
● Дефинирайте масив от Person и го инициализирайте.
● Дефинирайте тип PersonNode с 2 member-а: Person и PersonNode* - информация за Person и указател към PersonNode, който
може да сочи към друг обект от тип PersonNode.
● Дефинирайте масив от тип PersonNode. Обходете масива и копирайте информацията за всеки елемент от съответстващия му по
индекс елемент от първия масив (от тип Person). В същия цикъл пренасочете всеки member указател към PersonNode към
следващия елемент от масива, който обхождаме (към 0 за последния елемент)
● Принтирайте съдържанието на създадения от нас свързан списък, използвайки само PersonNode обекти и техните members (без
да използвате името на масивите). Дефинирайте отделна функция за тази цел.
● Обходете масива отново и пренасочете member указателите на всеки PersonNode, чиито Person обект е с възраст над 18 год,
така че да сочат към следващия обект от масива от тип PersonNode, чиито Person member е с възраст над 18 год. (ако обектите с
индекс 0 и 1 и 4 са над 18, обектите с индекс 2 и 3 са под 18, member указателят на обект с индекс 1 трябва да почне да сочи не
към обект с индекс 2, ами да “пропусне всички следващи елементи под 18” и да се пренасочи към обект с индекс 4)
● Принтирайте съдържанието на масива (всички хора) и на списъка (само над 18)
*/
{
	printf("\n-----------task 17_9-----------------");
	struct Person* ptrPerson = personArr;
	struct PersonNode* ptrPersonNode = personNodeArr;

	for (int i = 0; i < 5; i++, ptrPerson++)
	{
		printf("\nEnter name of person %d:", i + 1);
		io_strEnter(ptrPerson->name, 50);
		printf("\nAge:");
		scanf_s("%u", &(ptrPerson->age));
		printf("\n");
	}
	for (int i = 0; i < 5; i++)
	{
		string_strcopy(personNodeArr[i].name, personArr[i].name);
		personNodeArr[i].age = personArr[i].age;
		personNodeArr[i].ptrPNext = &(personNodeArr[i + 1]);
	}
	personNodeArr[4].ptrPNext = NULL;
	print_list(personNodeArr);

	printf("\nAdult persons with age >=18:");
	struct PersonNode* ptr18 = 0;
	int i = 0;
	for (; i < 5; i++) //find first aaray element >=18.
	{
		if (personNodeArr[i].age >= 18)
		{
			ptr18 = &(personNodeArr[i]);
			break;
		}
	}
	for (int next = i + 1; next < 5; next++)
	{
		if (personNodeArr[next].age >= 18)
		{
			personNodeArr[i].ptrPNext = &(personNodeArr[next]);
			i = next;
		}
	}
	personNodeArr[i].ptrPNext = NULL;
	print_list(ptr18);
}