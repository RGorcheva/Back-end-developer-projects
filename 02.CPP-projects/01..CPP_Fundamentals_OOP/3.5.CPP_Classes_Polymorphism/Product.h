/*
Задача 1
Дефинирайте базов абстрактен клас Product със всички данни, които са общи за всеки вид продукт(например: всеки продукт има
	цена - правим protected data member за целта в базовия клас + метод(и) за достъп)
	Дефинирайте enum E_ProductType за всички видове продукти в scope - a на класа Product.
	Дефинирайте pure virtual метод в базовия клас Product, който връща вида на продукта E_ProductType.
	Всеки клас, който репрезентира конкретен продукт(не е абстрактен) трябва да override - не този pure virtual method от базовия клас и
	да връща константата, отговаряща на вида продукт, който репрезентира.
*/
#pragma once
#include "enums.h"
#include <iostream>
#include <string>

typedef float moneyType;

class Product
{
public:
	virtual ~Product();
	//Getters
	const int getProductID() const;
	const float getProductPrice() const;
	const int getProductInStock() const;
	//Setters
	void setProductPrice(const float newProdPrice);
	void setProductInStock(const int newProdInStock);
	virtual void print(std::ostream& out) const;
	virtual E_productType getType() = 0;

	friend class ProductManager;

protected:
	//Data
	E_productType	m_productType;
	int 			m_productID;
	moneyType		m_productPrice;
	int				m_productInStock;

	//Virtual
	virtual void serialize(std::ostream& out);
	virtual void deserialize(std::istream& in);
	virtual void addProduct();

	//Constructors
	Product();
	Product(E_productType type, int id, moneyType price, int inStock);

private:

};


