#define _CRT_SECURE_NO_WARNNINGS
#include "my_string.h"
#include <string>
#include <cstring>

const char ca::string::m_null_str = '\0';
#define STR_SIZE 20

const char* ca::string::c_str() const
{
	if (!m_str)
	{
		return &m_null_str;
	}
	return  m_str;
}
ca::string::string(const char* str)
	:m_str(0)
	,m_size(strlen(str))
{
	m_str = new char[m_size + 1];
	strcpy_s(m_str, m_size + 1, str);
}
ca::string::string()
	:m_str(NULL)
	,m_size(0)
{}
ca::string::~string()
{
	delete[] m_str;
}
ca::string::string(const string& other)
	:m_str(0)
	,m_size(other.m_size)
{
	m_str = new char[other.m_size + 1];
	strcpy_s(m_str, m_size + 1, other.m_str);
}
ca::string& ca::string::operator=(const string& other)
{
	if (this == &other) return *this;
	delete[] m_str;
	m_size = other.m_size;
	m_str = new char[m_size + 1];
	strcpy_s(m_str, m_size + 1, other.c_str());
	return *this;
}
inline size_t ca::string::size() const
{
	return m_size;
}
char ca::string::operator[](size_t index) 
{
	return m_str[index];
}
const char ca::string::operator[](size_t index) const
{
	return m_str[index];
}
ca::string& ca::string::operator+=(const ca::string& str)
{
	char* newStr = new char[m_size + 1];
	strcpy_s(newStr, m_size + 1,  m_str);
	delete[] m_str;
	m_size = m_size + str.size();
	m_str = new char[m_size + 1];
	strcpy_s(m_str, m_size + 1, newStr);
	strcat_s(m_str, m_size + 1, str.c_str());
	delete[] newStr;
	return *this;
}
//ca::string& ca::string::operator+=(const ca::string& str)
//{
//	char* newStr = new char[str.size() + m_size + 1];
//	strcpy_s(newStr, m_size + 1,  str.c_str());
//	strcpy_s(newStr, m_size + 1, m_str);
//	size_t new_size = m_size + str.size() + 1;
//	delete[] str.c_str();
//	str.m_str = newStr;
//	str.m_size = new_size;
//	return *this;
//}
ca::string operator+(const ca::string& str1, const ca::string& str2)
{
	ca::string result(str1);
	result += str2;
	return result;
}

bool operator==(const ca::string& str1, const ca::string& str2)
{
	return ((str1.size() == str2.size()) && (!strcmp(str1.c_str(), str2.c_str())));
}
bool operator!=(const ca::string& str1, const ca::string& str2)
{
	 return !((str1.size() == str2.size()) && (!strcmp(str1.c_str(), str2.c_str())));
}
bool operator<(const ca::string& str1, const ca::string& str2)
{
	return (strcmp(str1.c_str(), str2.c_str()) < 0);
}
bool operator>(const ca::string& str1, const ca::string& str2)
{
	return (strcmp(str1.c_str(), str2.c_str()) > 0);
}
bool operator<=(const ca::string& str1, const ca::string& str2)
{
	return (strcmp(str1.c_str(), str2.c_str()) <= 0);
}
bool operator>=(const ca::string& str1, const ca::string& str2)
{
	return (strcmp(str1.c_str(), str2.c_str()) >= 0);
}

std::ostream& operator<<(std::ostream& out, const ca::string& str)
{
	return out << str.c_str();
}
std::istream& operator>>(std::istream& in, ca::string& str)
{
	char ch = 0;
	std::string input;
	std::getline(in >> std::ws, input);
	ca::string newStr(input.c_str());
	str = newStr;
	return in;
}