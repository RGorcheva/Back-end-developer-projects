#include "4_1_define.h"
#include <iostream>

CA::CPP::Person::Person()
	:age(4)
	{
		int age = 5;
		std::cout << age << this->age << CA::CPP::age << CA::age << ::age << std::endl;
	};

int main()
{
	CA::CPP::Person person;
	return 0;
}