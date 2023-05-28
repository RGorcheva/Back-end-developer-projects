/*
Задача 1
Дефинирайте subscript оператор за индексиране на отделните символи от ca::string.
Задача 2
Дефинирайте бинарен + оператор за ca::string, който дa конкатенира аргументите си
Задача 3
Дефинирайте оператор += за ca::string, който конкатенира лявата операнда към дясната
Задача 4
Дефинирайте операторите за сравняване на стрингове : лексикографски, според ANSI таблицата. (== , != , > , >= , < , <= )
Задача 5
Дефинирайте оператори за вход и изход на ca::string с istream и ostream
*/

#ifndef _6_STRING_H
#define _6_STRING_H

#include <iostream>
#include <cstring>

namespace ca
{
	class string
	{
	public:
		string();
		string(const char* str);
		~string();
		string(const string& other);
		inline const char* c_str() const;

		string& operator=(const string& other);

		//getter
		inline size_t size() const;

		ca::string& operator+=(const ca::string& str);
		char operator[](size_t index);
		const char operator[](size_t index) const;

		//friend ca::string operator+(const ca::string& str1, const ca::string& str2);
		//friend bool operator==(const ca::string& str1, const ca::string& str2);
		//friend bool operator!=(const ca::string& str1, const ca::string& str2);
		//friend bool operator<(const ca::string & str1, const ca::string & str2);
		//friend bool operator>(const ca::string& str1, const ca::string& str2);
		//friend bool operator<=(const ca::string& str1, const ca::string& str2);
		//friend bool operator>=(const ca::string& str1, const ca::string& str2);

	private:
		char* m_str;
		size_t m_size;
		static const char m_null_str;
	};
}

ca::string operator+(const ca::string& str1, const ca::string& str2);
bool operator==(const ca::string& str1, const ca::string& str2);
bool operator!=(const ca::string& str1, const ca::string& str2);
bool operator<(const ca::string& str1, const ca::string& str2);
bool operator>(const ca::string& str1, const ca::string& str2);
bool operator<=(const ca::string& str1, const ca::string& str2);
bool operator>=(const ca::string& str1, const ca::string& str2);

std::ostream& operator<<(std::ostream& out, const ca::string& str);
std::istream& operator>>(std::istream& in, ca::string& str);

#endif