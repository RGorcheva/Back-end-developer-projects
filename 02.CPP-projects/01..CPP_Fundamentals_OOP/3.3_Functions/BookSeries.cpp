#include "BookSeries.h"
#include "BookInfo.h"
#include "BookInfoManager.h"
#include <iostream>


BookSeries::BookSeries()
	:m_productID(0)
	,m_productPrice(0.0f)
{}
BookSeries::BookSeries(int id, std::string& title, float price, SerieContainer& serie)
	: m_productID(id)
	, m_serieTitle(title)
	, m_productPrice(price)
	, m_serie(serie)
{}

const int BookSeries::getProductID() const
{
	return m_productID;
}
const std::string& BookSeries::getSerieTitle() const
{
	return m_serieTitle;
}
const  BookSeries::SerieContainer& BookSeries::getSerie() const
{
	return m_serie;
}
const float BookSeries::getProductPrice() const
{
	return m_productPrice;
}
void BookSeries::printSeries(const BookInfoManager& bookInfoM) const
{
	std::cout << "ID:" << getProductID() << "\tPrice:" << getProductPrice() << std::endl; 
	std::cout << "Title:" << getSerieTitle() << std::endl;
	std::cout << "Contains books:" << std::endl;
	std::cout << "-------------------------" << std::endl;
	for (int i = 0; i != m_serie.size(); i++)
	{
		int j = 0;
		for (; j != bookInfoM.getBookInfos().size(); j++)
		{
			if (bookInfoM.getBookInfos()[j].getProductID() == m_serie[i])
			{
				bookInfoM.getBookInfos()[j].printBookInfo();
				break;
			}
		}
	}
	std::cout << std::endl;
}