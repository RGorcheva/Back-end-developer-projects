/*
Задача 2
Дефинирайте клас ca::string (клас с име string в namespace ca).
Дефинирайте private data member от тип char *, който сочи към динамично-алокирания на хийпа символен низ.
Дефинирайте интерфейсна (public) функция c_str, която връща низа като константен c-style string - const char *.
Задача 3
Дефинирайте конструктор, който взима като параметър const char * и прави копие на подадения аргумент - заделя памет на
хийпа с new, запазва началото й в char* data member’а си и копира съдържанието от аргумента в новосъздадената памет.
Задача 4
Дефинирайте default constructor и инициализирайте паметта с празен с-стринг.
Задача 5
Дефинирайте деструктор, който освобождава алокираната от класа памет.
Задача 6
Дефинирайте copy constructor за ca::string
Задача 7
Дефинирайте operator= за ca::string класа. Внимание: когато дефинираме operator= експлицитно, обикновено се налага да
проверим за “присвояване на себе си”:
*/

#ifndef _4_2_DEFINE_H
#define _4_2_DEFINE_H

#include <iostream>
#include <cstring>

namespace ca
{
	class string
	{
	public:
		//2
		inline const char* c_str() const;
		//3
		string(const char* str);
		//4
		string();
		//5
		~string();
		//6
		string(const string& other);
		//7
		string& operator=(const string& other);
		//getter
		inline size_t size() const;
	private:
		char* m_str;
		size_t m_size;
		static const char m_null_str;
	};
}

#endif