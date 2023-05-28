/*
Направете клас Adress със следните членове:
● Град
● Държава
● Улица
● Номер
● Квартал
● Блок номер
С++ упражнение

Направете клас Person със следните членове:
● ЕГН
● Височина
● Тегло
● Цвят на очите
● Първо име
● Фамилия
● Адрес от класа адрес

Направете клас Employee, които наследява protected клас
Person със следните допълнителни членове:
Сметка;
Функция за добавяне в сметката;
Функция за изваждане от сметката;
Функция за принтиране на сметката;
*/



#include "Person.h"

int main()
{
	Employee employee1;
	employee1.personal_ID = "1234567890";
	employee1.heighCM = 178;
	employee1.weightKG = 80;
	employee1.eyesColor = "green";
	employee1.firstName = "Ivan";
	employee1.lastName = "Ivanov";
	employee1.address.city = "Vrna";
	employee1.address.county = "Bulgaria";
	employee1.setInvoice("FN0012345");
	std::cout << employee1.firstName << " " << employee1.lastName << std::endl;
	std::cout << employee1.getInvoice() << std::endl;
	employee1.printInvoice();
	return 0;
}