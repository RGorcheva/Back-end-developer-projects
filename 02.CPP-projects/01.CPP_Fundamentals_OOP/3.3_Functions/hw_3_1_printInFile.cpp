/*
Задача 1
Напишете функция, която взима std::string и го принтрира на подаден като аргумент файлов поток.
Overload-нете горната функция, така че да работи и със С strings.
*/

#include <iostream>
#include <fstream>
#include <string>

void print_string(const std::string &str, std::ostream& file)
{
	file << str << std::endl;
}

void print_string(const char* str, std::ostream& file)
{
	file << str << std::endl;
}

int main()
{
	const char* cStr = "Hello, world C!";
	std::string cppStr("Hello, world CPP!");

	std::string fileName("test_file.txt");
	std::ofstream output_file(fileName);
	if (output_file.is_open())
	{
		print_string(cStr, output_file);
		print_string(cStr, std::cout);
		print_string(cppStr, output_file);
		print_string(cppStr, std::cout);
		output_file.close();
	}
	return 0;
}