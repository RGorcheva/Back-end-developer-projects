/*
Задача 2
Дефинирайте класове (които наследяват Product) за всеки вид продукт, който ще продава книжарницата (поне 2 вида).
Дефинирайте класове BookProduct и BookSeriesProduct - кнужарницата предлага както отделни книги, така и цяла колекция накуп
като отделен продукт (цялостта на колекцията не се нарушава - продава се цялата наведнъж)
*/

#pragma once
#include "Product.h"
#include "enums.h"

class ProductPen : public Product
{
public:
	//Getters
	const E_Color getInkColor() const;
	const E_Color getPenColor() const;
	const std::string getBrand() const;
	//Setters
	void setInkColor(const E_Color colour);
	void setPenColor(const E_Color colour);
	void setBrand(const std::string& brand);
	//Virtual
	virtual E_productType getType();
	virtual void serialize(std::ostream& in);
	virtual void deserialize(std::istream& out);
	virtual void print(std::ostream& out) const;
	virtual void addProduct();

	friend class ProductManager;

private:
	E_Color m_inkColor;
	E_Color m_penColor;
	std::string m_brand;

	//Constructors
	ProductPen();
};

