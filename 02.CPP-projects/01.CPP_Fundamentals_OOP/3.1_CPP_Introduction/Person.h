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

#ifndef _PERSON_H_
#define _PERSON_H_

#include <iostream>
#include <string>

class Address
{
public:
	std::string city;
	std::string county;
	std::string street;
	int streetNumber = 0;
	std::string quarter;
	int buildingNumber = 0;
};

class Person
{
public:
	std::string personal_ID;
	int heighCM = 0;
	float weightKG = 0;
	std::string eyesColor;
	std::string firstName;
	std::string lastName;
	Address address;
};

class Employee : public Person
{
protected:
	std::string  strInvoice;
public:
	void setInvoice(std::string newInvoice);
	std::string getInvoice();
	void printInvoice();
};

#endif
