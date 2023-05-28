#include "ProductBookSerie.h"
#include "Product.h"
#include "ProductManager.h"
#include "ProductBook.h"
#include <iostream>
#include <fstream>
#include <sstream>

//Constructors
ProductBookSerie::ProductBookSerie()
{}
ProductBookSerie::ProductBookSerie(std::string& title, BookIDContainer& serie)
	: m_bookSerieTitle(title)
	, m_bookIDs(serie)
{}

//Getters
const std::string& ProductBookSerie::getBookSerieTitle() const
{
	return m_bookSerieTitle;
}
const  ProductBookSerie::BookIDContainer& ProductBookSerie::getBookSerie() const
{
	return m_bookIDs;
}
int ProductBookSerie::getBookInfoByIndex(size_t index)
{
	return m_bookIDs[index];
}

//Virtual
E_productType ProductBookSerie::getType() 
{
	return E_productType_Serie;
}
void ProductBookSerie::deserialize(std::istream& in)
{
	char ch = '0';
	Product::deserialize(in);
	std::getline(in, m_bookSerieTitle, ',');
	in.get(ch);

	std::string books;
	int book = 0;
	std::getline(in, books, '}');
	std::stringstream s(books);
	std::string::difference_type n = std::count(books.begin(), books.end(), ',');

	for (int i = 0; i != n; i++)
	{
		s >> book;
		s.get(ch);
		m_bookIDs.push_back(book);
	}
	s >> book;
	m_bookIDs.push_back(book);
	in.get(ch);
}
void ProductBookSerie::serialize(std::ostream& out)
{
	Product::serialize(out);
	out << m_bookSerieTitle << ",{";
	int i = 0;
	for (; i != m_bookIDs.size() - 1; i++)
	{
		out << m_bookIDs[i] << ",";
	}
	out << m_bookIDs[i] << "})" << std::endl;
}
void ProductBookSerie::print(std::ostream& out) const
{
	Product::print(out);
	out << "Title: " << m_bookSerieTitle << std::endl;
	std::cout << "Contains books:" << std::endl;
	std::cout << "-------------------------" << std::endl;
	for (int i = 0; i != m_bookIDs.size(); i++)
	{
		for (int j = 0; j != ProductManager::GetInstance().getProductContainer().size(); j++)
		{
			if (ProductManager::GetInstance().getProductContainer()[j]->getProductID() == m_bookIDs[i])
			{
				ProductBook* book = dynamic_cast<ProductBook*>(ProductManager::GetInstance().getProductContainer()[j]);
				out << "Book ID:" << book->getProductID();
				out << " Book title: " << book->getTitle() << std::endl;
			}
		}
	}
	std::cout << std::endl;
}
void ProductBookSerie::addProduct()
{
	Product::addProduct();

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Enter book serie title: ";
	std::getline(std::cin, m_bookSerieTitle);

	int bookID = 0;
	int genre = 0;
	std::cout << "Enter contains book IDs: ";
	while (std::cin >> bookID && genre != 0)
	{
		m_bookIDs.push_back(bookID);
	}
}