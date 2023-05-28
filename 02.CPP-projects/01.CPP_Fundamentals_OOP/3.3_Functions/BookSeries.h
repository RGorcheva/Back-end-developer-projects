#ifndef BOOKSERIES_H
#define BOOKSERIES_H

#include <vector>
#include <string>

class BookInfo;
class BookInfoManager;

class BookSeries
{
public:

	typedef std::vector<int> SerieContainer;
	BookSeries();
	BookSeries(int id, std::string& title, float price, SerieContainer& serie);

	const int getProductID() const;
	const std::string& getSerieTitle() const;
	const  SerieContainer& getSerie() const;
	const float getProductPrice() const;

	void printSeries(const BookInfoManager& bookInfoM) const;
	void printSeries() const;

private:
	int m_productID;
	std::string m_serieTitle;
	SerieContainer m_serie;
	float m_productPrice;
};

#endif
