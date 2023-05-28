#define _CRT_SECURE_NO_WARNNINGS
#include "my_string.h"

const char ca::string::m_null_str = '\0';

#define STR_SIZE 20
//ex 2
const char* ca::string::c_str() const
{
	if (!m_str)
	{
		return &m_null_str;
	}
	return  m_str;
}
//3
ca::string::string(const char* str)
	:m_str(0)
	,m_size(strlen(str))
{
	m_str = new char[m_size+1];
	strcpy_s(m_str, m_size+1, str);
}
//4
ca::string::string()
	:m_str(NULL)
	,m_size(0)
{}
//5
ca::string::~string()
{
	delete[] m_str;
}
//6
ca::string::string(const string& other)
	:m_str(0)
	,m_size(other.m_size)
{
	m_str = new char[other.m_size];
	strcpy_s(m_str, m_size, other.m_str);
}
//7
ca::string& ca::string::operator=(const string& other)
{
	if (this != &other) return *this;
	delete[] m_str;
	m_size = other.m_size;
	m_str = new char[m_size];
	strcpy_s(m_str, m_size, other.c_str());
	return *this;
}
inline size_t ca::string::size() const
{
	return m_size;
}



int main(void)
{
	ca::string a("hello");
	std::cout << a.size() << std::endl;
	std::cout << a.c_str() << std::endl;
	ca::string b;
	std::cout << b.c_str() << std::endl;
	ca::string d("");
	std::cout << d.c_str() << std::endl;

	return 0;
}
