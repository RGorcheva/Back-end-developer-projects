#include "ProductPen.h"
#include <string>

//Constructors
ProductPen::ProductPen()
	:m_inkColor(E_Color_White),
	 m_penColor(E_Color_White){}

//Getters
const E_Color ProductPen::getInkColor() const
{
	return m_inkColor;
}
const E_Color ProductPen::getPenColor() const
{
	return m_penColor;
}
const std::string ProductPen::getBrand() const
{
	return m_brand;
}

//Setters
void ProductPen::setInkColor(const E_Color color)
{
	m_inkColor = color;
}
void ProductPen::setPenColor(const E_Color color)
{
	m_penColor = color;
}
void ProductPen::setBrand(const std::string& brand)
{
	m_brand = brand;
}

//Virtual
E_productType ProductPen::getType()
{
	return E_productType_Pen;
}
void ProductPen::serialize(std::ostream& out)
{
	Product::serialize(out);
	out << m_inkColor << "," << m_penColor << "," << m_brand << ")\n";
}
void ProductPen::deserialize(std::istream& in)
{
	int Color = -1;
	char ch = '0';
	Product::deserialize(in);
	in >> Color;
	in.get(ch);
	m_inkColor = static_cast<E_Color>(Color);
	in >> Color;
	in.get(ch);
	m_penColor = static_cast<E_Color>(Color);
	std::getline(in, m_brand, ')');
}
void ProductPen::print(std::ostream& out) const
{
	Product::print(out);
	std::string color;
	switch (m_inkColor)
	{
	case E_Color_Blue: color = "blue"; break;
	case E_Color_Red: color = "red"; break;
	case E_Color_Black: color = "black"; break;
	default: break;	
	}
	out << "Ink color: " << color << std::endl;
	switch (m_penColor)
	{
	case E_Color_White: color = "white"; break;
	case E_Color_Blue: color = "blue"; break;
	case E_Color_Red: color = "red"; break;
	case E_Color_Black: color = "black"; break;
	default: break;
	}
	out << "Pen color: " << color << std::endl;
	out << "Brand: " << m_brand  << std::endl;
} 
void ProductPen::addProduct()
{
	Product::addProduct();
	std::string color;
	std::cout << "Enter ink colour: ";
	std::cin >> color;
	if (color == "blue") { m_inkColor = E_Color_Blue; }
	if (color == "red") { m_inkColor = E_Color_Red; }
	if (color == "black") { m_inkColor = E_Color_Black; }
	std::cout << "Enter pen colour: ";
	std::cin >> color;
	if (color == "white") { m_penColor = E_Color_White; }
	if (color == "blue") { m_penColor = E_Color_Blue; }
	if (color == "red") { m_penColor = E_Color_Red; }
	if (color == "black") { m_penColor = E_Color_Black; }
	std::cout << "Enter brand: ";
	std::cin >> m_brand;
}