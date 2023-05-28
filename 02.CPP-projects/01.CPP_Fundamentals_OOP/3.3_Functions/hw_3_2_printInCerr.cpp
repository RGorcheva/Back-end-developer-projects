/*
Задача 2
Напишете функция, която взима std::string (by reference) и го принтира в stderr.
Добавете default аргумент за std::string параметъра, така че ако се извика без аргумент да принтира default съобщение
(стойността на default параметъра)
*/

#include <iostream>
#include <string>

void print_string_err(const std::string& str = "Default")
{
	std::cerr << str << std::endl;
}

int main()
{
	std::string cppStr("Hello, CPP!");

	print_string_err(cppStr);
	print_string_err();

	return 0;
}