#include "ProductManager.h"
#include "ProductBook.h"
#include "ProductBookSerie.h"
#include "ProductPen.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

ProductManager* ProductManager::m_instance = NULL;

ProductManager::ProductManager()
:m_lastGivenID(0) {}

ProductManager& ProductManager::GetInstance()
{
	if (!m_instance)
	{
		m_instance = new ProductManager();
	}
	return *m_instance;
}
Product* ProductManager::createProduct(E_productType type)
{
	Product* result = NULL;
	switch (type)
	{
	case E_productType_Book: result = new ProductBook(); break;
	case E_productType_Serie: result = new ProductBookSerie(); break;
	case E_productType_Pen: result = new ProductPen(); break;
	default: break;
	};
	m_lastGivenID++;
	return result;
}
Product* ProductManager::addNewProduct(E_productType type)
{
	Product* result = ProductManager::GetInstance().createProduct(type);
	result->m_productType = type;
	result->m_productID = m_lastGivenID;
	result->addProduct();
	ProductManager::GetInstance().m_productContainer.push_back(result);
	return result;
}
void ProductManager::destroyProduct(Product* product)
{
	delete product;
}
void ProductManager::destroyAllProducts()
{
	for (int i = 0; i != ProductManager::GetInstance().getProductContainer().size(); i++)
	{
		destroyProduct(ProductManager::GetInstance().getProductContainer()[i]);
	}
}
void ProductManager::fillSeriesInBooks()
{
	for (int i = 0; i != m_productContainer.size(); i++)
	{
		if (m_productContainer[i]->getType() == E_productType_Book)
		{
			ProductBook* book = static_cast<ProductBook*>(m_productContainer[i]);
			for (int j = 0; j != m_productContainer.size(); j++)
			{
				if (m_productContainer[j]->getType() == E_productType_Serie)
				{
					ProductBookSerie* serie = static_cast<ProductBookSerie*>(m_productContainer[j]);
					for (int s = 0; s != serie->getBookSerie().size(); s++)
					{
						if (serie->getBookSerie()[s] == book->getProductID())
						{
							book->getBookSeries().push_back(serie);
						}
					}
				}
			}
		}
	}
}

const unsigned ProductManager::getLastID() const
{
	return m_lastGivenID;
}
const ProductManager::ProductContainer& ProductManager::getProductContainer() const
{
	return m_productContainer;
}
ProductManager::ProductContainer& ProductManager::getProductContainer()
{
	return m_productContainer;
}
const Product* ProductManager::getProduct(int index) const
{
	return m_productContainer[index];
}
Product* ProductManager::getProduct(int index)
{
	return m_productContainer[index];
}

/*
Тема 6: Задача 6
Дефинирайте subscript оператор за индексиране книга от колекция от книги
*/
const Product* ProductManager::operator[](int index) const
{
	return m_productContainer[index];
}
Product* ProductManager::operator[](int index)
{
	return m_productContainer[index];
}

void ProductManager::serializeProducts(const std::string& fileName)
{
	std::ofstream outputFile(fileName);
	if (!outputFile)
	{
		std::cout << "Error in openning file!\n" << std::endl;
		return;
	}

	for (int i = 0; i != m_productContainer.size(); i++)
	{
		m_productContainer[i]->serialize(outputFile);
	}
	outputFile.close();
}
void ProductManager::deserializeProducts(const std::string& fileName)
{
	std::ifstream inputFile(fileName);
	if (!inputFile)
	{
		std::cout << "Error in opening file!\n" << std::endl;
		return;
	}
	std::string line;
	while (std::getline(inputFile, line))
	{
		int prodType = 0;
		char ch = '0';
		E_productType type = E_productType_NA;
		std::istringstream s(line);

		s.get(ch);
		s >> prodType;
		s.get(ch);
		switch (prodType)
		{
		case 1: type = E_productType_Book; break;
		case 2: type = E_productType_Serie; break;
		case 3: type = E_productType_Pen; break;
		default: break;
		}
		Product* newProduct = createProduct(type);
		newProduct->m_productType = type;
		newProduct->deserialize(s);
		m_productContainer.push_back(newProduct);
	}
	inputFile.close();
}
void ProductManager::printProducts(std::ostream& out)
{
	for (int i = 0; i != m_productContainer.size(); i++)
	{
		E_productType prodType = m_productContainer[i]->getType();
		std::string type;
		switch (prodType)
		{
		case E_productType_Book: type = "Book"; break;
		case E_productType_Serie: type = "BookSerie"; break;
		case E_productType_Pen: type = "Pen"; break;
		default: break;
		}
		out << "Product type: " << type << std::endl;
		m_productContainer[i]->print(out);
		out << std::endl;
	}
}
void ProductManager::printProductsByType(std::ostream& out, E_productType Etype)
{
	for (int i = 0; i != m_productContainer.size(); i++)
	{
		if (Etype == m_productContainer[i]->getType())
		{
			std::string type;
			switch (m_productContainer[i]->getType())
			{
			case E_productType_Book: type = "Book"; break;
			case E_productType_Serie: type = "BookSerie"; break;
			case E_productType_Pen: type = "Pen"; break;
			default: break;
			}
			out << "Product type: " << type << std::endl;
			m_productContainer[i]->print(out);
			out << std::endl;
		}
	}
}

/*
Tema7: Задача 7
Разширете функционалността на програмата за книжарници, като добавите необходимия error handling.
Ползвайте стандартния изходен поток за грешки cerr за да уведомявате потребителя за грешки
*/