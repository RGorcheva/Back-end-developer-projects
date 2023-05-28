#include "sequential.h"
#include <vector>
#include <list>
#include <deque>
#include <string>
#include <iostream>
#include <algorithm>


/*
Задача 1
Напишете програма, която моли потребителя да въвежда в обратен ред цели числа във vector.
Принтирайте съдържанието на контейнера.
*/

void task1(void)
{
	std::vector<int>vec;
	int number = 0;
	std::cout << "Please, enter integer numbers in reverse order " << std::endl;
	while (std::cin >> number)
	{
		vec.insert(vec.begin(), number);
	}
	std::vector<int>::const_iterator iter = vec.begin();
	std::vector<int>::const_iterator end = vec.end();
	for (; iter != end; iter++)
	{
		std::cout << *iter << "\t";
	}
}

/*
Задача 2
Напишете функция, която приема deque от int числа и премахва всички нечетни числа от контейнера.
*/
void task2(void)
{
	std::deque<int>deq;
	int number = 0;
	std::cout << "Please, enter integer numbers " << std::endl;
	while (std::cin >> number)
	{
		deq.push_back(number);
	}
	for (std::deque<int>::iterator iter = deq.begin(); iter != deq.end(); )
	{
		if (*iter % 2 == 1)
		{
			iter = deq.erase(iter);
		}
		else
		{
			iter++;
		}
	}
	for (std::deque<int>::iterator iter = deq.begin(); iter != deq.end(); iter++)
	{
		std::cout << *iter << "\t";
	}
}

/*
Задача 3
Напишете програма, която моли потребителя да въведе цели числа във vector, след което принтира всички уникални
елементи на контейнера
*/
void task3(void)
{
	std::vector<int>vec;
	int number = 0;
	std::cout << "Please, enter integer numbers" << std::endl;
	while (std::cin >> number)
	{
		vec.push_back(number);
	}
	for (std::vector<int>::const_iterator iter = vec.begin(); iter != vec.end() - 1; iter++)
	{
		bool isUnique = true;
		for (std::vector<int>::const_iterator iter2 = vec.begin(); iter2 != vec.end(); iter2++)
		{
			if (iter == iter2)
			{
				continue;
			}
			if (*iter == *iter2)
			{
				isUnique = false;
				break;
			}
		}
		if (isUnique == true)
		{
			std::cout << *iter << " ";
		}
	}
}

/*
Задача 4
Напишете програма, която моли потребителя да въведе цели числа във list, след което, премахва всички дублиращи се
елементи и го принтира в обратен ред.
*/
void task4(void)
{
	std::list<int>lis;
	int number = 0;
	std::cout << "Please, enter integer numbers" << std::endl;
	while (std::cin >> number)
	{
		lis.push_back(number);
	}
	for (std::list<int>::const_iterator iter = lis.begin(); iter != lis.end();)
	{
		bool isUnique = true;
		for (std::list<int>::const_iterator iter2 = lis.begin(); iter2 != lis.end(); iter2++)
		{
			if (iter == iter2)
			{
				continue;
			}
			if (*iter == *iter2)
			{
				isUnique = false;
				break;
			}
		}
		if (isUnique == false)
		{
			iter = lis.erase(iter);
		}
		else
		{
			iter++;
		}
	}
	std::reverse(lis.begin(), lis.end());
	for (std::list<int>::const_iterator iter = lis.begin(); iter != lis.end(); iter++)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';
}

/*
Задача 5
Напишете програма, която моли потребителя да въведе текст на няколко реда(до прочитане на EOF), след което прави
всички думи от текста да започват с главна буква и принтира текста отзад - напред(целия текст отзад - напред, не по редове)
Задачи за самподготовка
*/
void task5(void)
{
	std::vector<std::string>vec;
	std::string word;
	std::cout << "Please, enter words in multiple rows" << std::endl;
	while (std::cin >> word)
	{
		word[0] = toupper(word[0]);
		vec.push_back(word);
	}
	std::reverse(vec.begin(), vec.end());
	for (std::vector<std::string>::iterator iter = vec.begin(); iter != vec.end(); iter++)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';
}
