#include "Person.h"

void Employee::setInvoice(std::string  newInvoice)
{
	strInvoice = newInvoice;
}

std::string  Employee::getInvoice()
{
	return strInvoice;
}

void Employee::printInvoice()
{
	std::cout << strInvoice << std::endl;
}