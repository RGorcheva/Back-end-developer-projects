#include "Product.h"

Product::~Product() {}

//Getters
const int Product::getProductID() const 
{
	return m_productID;
}
const float Product::getProductPrice() const
{
	return m_productPrice;
}
const int Product::getProductInStock() const
{
	return m_productInStock;
}

//Setters
void Product::setProductPrice(const float newProdPrice) 
{
	m_productPrice = newProdPrice;
}
void Product::setProductInStock(const int newProdInStock) 
{
	m_productInStock = newProdInStock;
}

//Virtual
void Product::deserialize(std::istream& in)
{
	char ch = '0';
	in >> m_productID;
	in.get(ch);
	in >> m_productPrice;
	in.get(ch);
	in >> m_productInStock;
	in.get(ch);
}
void Product::serialize(std::ostream& out)
{
	out << '(' << m_productType << "," << m_productID << "," << m_productPrice << "," << m_productInStock << ",";
}
void Product::print(std::ostream& out) const
{
	out << "ProductID: " << m_productID << "\nProducts in stock: " << m_productInStock << "\nPrice: " << m_productPrice << std::endl;
}
void Product::addProduct()
{
	std::cout << "Enter product price: ";
	std::cin >> m_productPrice;
	std::cout << "Enter products in stock: ";
	std::cin >> m_productInStock;
}

//Constructors
Product::Product()
	:m_productType(E_productType_NA),
	m_productID(0),
	m_productPrice(0.0f),
	m_productInStock(0)
{}
Product::Product(E_productType type, int id, moneyType price, int inStock)
	:m_productType(type),
	m_productID(id),
	m_productPrice(price),
	m_productInStock(inStock)
{}