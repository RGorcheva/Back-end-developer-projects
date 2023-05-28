/*
Задача 3
Дефинирайте мениджър клас ProductManager. Направете така, че да не може да се създават обекти от тип Product (или който и да
е тип от Product йерархията) от никъде освен от метод на ProductManager.
*/

#pragma once
#include "Product.h"
#include <vector>

class ProductManager
{
public:
	typedef std::vector<Product*> ProductContainer;


	static ProductManager& GetInstance();
	Product* addNewProduct(E_productType type);

	void destroyAllProducts();
	const unsigned getLastID() const;
	const ProductContainer& getProductContainer() const;
	ProductContainer& getProductContainer();
	const Product* getProduct(int index) const;
	Product* getProduct(int index);
	const Product* operator[](int index) const;
	Product* operator[](int index);
	void fillSeriesInBooks();

	void serializeProducts(const std::string& fileName);
	void deserializeProducts(const std::string& fileName);
	void printProducts(std::ostream& out);
	void printProductsByType(std::ostream& out, E_productType type);

private:
	ProductContainer m_productContainer;
	unsigned m_lastGivenID;
	static ProductManager* m_instance;

	ProductManager();
	ProductManager(const ProductManager& productManager);
	ProductManager& operator=(const ProductManager& productManager);
	Product* createProduct(E_productType type);
	void destroyProduct(Product* product);
};

