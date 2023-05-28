#include "my_string.h"

int main(void)
{
	ca::string a("hello");
	std::cout << a[0] << std::endl;
	std::cout << a.size() << std::endl;

	ca::string b(" world!");
	std::cout << b.c_str() << std::endl;
	ca::string d("");
	d = a;
	std::cout << d.c_str() << std::endl;
	d += b;
	std::cout << d.c_str() << std::endl;
	ca::string c("");
	c = a + b;
	std::cout << c.c_str() << std::endl;
	(a == b) ? printf("a == b\n") : printf("a != b\n");
	(a < b) ? printf("a < b\n") : printf("a > b\n");
	(a <= b) ? printf("a <= b\n") : printf("a >= b\n");
	std::cout << c << std::endl;
	char ch = c[0];
	std::cout << ch << std::endl;
	std::cin >> a;
	std::cout << a << std::endl;
	return 0;
}