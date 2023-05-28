#pragma once

#include "Product.h"
#include <string>
#include <vector>
#include "enums.h"

class ProductBook;

class ProductBookSerie : public Product
{
public:
	typedef std::vector<int> BookIDContainer;

	//Getters
	const std::string& getBookSerieTitle() const;
	const BookIDContainer& getBookSerie() const;
	int getBookInfoByIndex(size_t index);

	//void printBookSeries(const BookInfoManager& bookInfoM) const;

	//Virtual
	virtual E_productType getType();
	virtual void serialize(std::ostream& out);
	virtual void deserialize(std::istream& in);
	virtual void print(std::ostream& out) const;
	virtual void addProduct();

	friend class ProductManager;

private:
	std::string m_bookSerieTitle;
	BookIDContainer m_bookIDs;

	//Constructors
	ProductBookSerie();
	ProductBookSerie(std::string& title, BookIDContainer& serie);
};

