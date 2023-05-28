﻿/* --------------------17_8_1
Направете нова версия на програмата за отдаване на превозни средства под наем. В бъдеще ще разширим функционалността на
програмата да работи с файлове и дати, засега ще четем хард-коднати свободни превозни средства(ПС) и ще ги отдаваме едно по едно
докато не свършат или не излезем от програмата.
● Програмата трябва да има следните менюта:
- Main Menu, със следните опции:
- Press 1 to choose vehicle (води до Choose Vehicle Menu с всички свободни ПС)
- Press 2 to choose vehicle by brand(води до Choose Brand Menu с всички марки от които има налични ПС, след което до
Choose Vehicle Menu с всички свободни ПС от избраната марка)
- Press q to quit.
- Choose Vehicle Menu - списък с множество свободни ПС(в зависимост от контекста, някой път всички, друг път - от дадена
марка), с опция за избор на ПС(водеща до Vehicle Details Menu) + опция за връщане в Main Menu (“Press b to go back to
Main Menu”)й9и1
- Choose Brand Menu - списък с марки ПС, за които има налично свободно ПС. Дава възможност за избор на марка(при
което води до Choose Vehicle Menu със свободни ПС от избраната марка) или връщане в Main Menu
○ Vehicle Details Menu, със следното съдържание:
-<Детайли за марката - име и кратка информация>
- <Детайли за модела - име и кратка информация>
- <Брой свободни ПС от тази марка и модел>
- <Цена за наемане за едно денонощие>
- Опции за наемане на ПС (за текущото изпълнение на програмата) и за връщане в предходното меню - Choose Vehicle
Menu (с последните филтри за менюто)
 --------------------17_8_2
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


#include "functionsMenu.h"

int main(void)
{
	int menuChoice = 0;
	mainMenu: menuChoice = f_main_menu();
	if (menuChoice == e_allVehicleList)
	{
		allVehicleList: menuChoice = f_allVehicleList();
		if (menuChoice == e_rentVehicle)
		{
			menuChoice = f_rentVehicle();
			if (menuChoice == e_main_menu)
			{
				goto mainMenu;
			}
		}
		else if (menuChoice == e_brandDetails)
		{
			menuChoice = f_brandDetails();
			goto allVehicleList;
		} 
		else goto mainMenu;
	}
	else if (menuChoice == e_vehicleBrandList)
	{
		vehicleBrandList: menuChoice = f_vehicleBrandList();
		if (menuChoice == e_rentVehicle)
		{	
			menuChoice = f_rentVehicle();
			if (menuChoice == e_main_menu)
			{
				goto mainMenu;
			}
		}
		else if (menuChoice == e_brandDetails)
		{
			menuChoice = f_brandDetails();
			goto vehicleBrandList;
		}
		else goto mainMenu; 
	}
	else if (menuChoice == e_quit)
	{
		return 0;
	}
	return 0;
}