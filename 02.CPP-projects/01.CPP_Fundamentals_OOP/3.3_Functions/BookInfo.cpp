#include "BookInfo.h"
#include "BookSeries.h"
#include <fstream>

BookInfo::BookInfo()
	: m_productID(0)
	, m_edition(0)
	, m_countBooksInStock(0)
	, m_averageUserRating(0)
	, m_countUserRated(0)
	, m_productPrice(0.0f)
{};
BookInfo::BookInfo(int productID, const std::string& ISBN, const std::string& title, int edition,const AuthorContainer& authors,const GenreContainer&  genres
	, int countBooksInStock, double averageUserRating, unsigned countUserRated, float productPrice)
	: m_productID(productID)
	, m_ISBN(ISBN)
	, m_title(title)
	, m_edition(edition)
	, m_authors(authors)
	, m_genres(genres)
	, m_countBooksInStock(countBooksInStock)
	, m_averageUserRating(averageUserRating)
	, m_countUserRated(countUserRated)
	, m_productPrice(productPrice)
{};
const int BookInfo::getProductID() const
{
	return m_productID;
}
const std::string& BookInfo::getISBN() const
{
	return m_ISBN;
}
const std::string& BookInfo::getTitle() const
{
	return m_title;
}
const int BookInfo::getEdition() const
{
	return m_edition;
}
const BookInfo::AuthorContainer& BookInfo::getAuthors() const
{
	return m_authors;
}
const BookInfo::GenreContainer& BookInfo::getGenres() const
{
	return m_genres;
}
const int BookInfo::getBooksInStock() const
{
	return m_countBooksInStock;
}
const double BookInfo::getAverageUserRating() const
{
	return m_averageUserRating;
}
const unsigned BookInfo::getCountUserRated() const
{
	return m_countUserRated;
}
const float BookInfo::getProductPrice() const
{
	return m_productPrice;
}
const std::vector<BookSeries*>& BookInfo::getBookSeries() const
{
	return m_bookSeries;
}

//GETTERs
void BookInfo::setAverageUserRating(double newRate)
{
	m_averageUserRating = ((m_averageUserRating * m_countUserRated) + newRate) / (m_countUserRated + 1);
	m_countUserRated++;
}
void BookInfo::fillBookSeries(const BookSeriesManager::SerieContainer& alleries)
{
	for (int i = 0; i != alleries.size(); i++)
	{
		for (int j = 0; j != alleries[i].getSerie().size(); j++)
		{
			if (alleries[i].getSerie()[j] == m_productID)
			{
				BookSeries* bookSerie = const_cast<BookSeries*>(& alleries[i]) ;
				m_bookSeries.push_back(bookSerie);
			}
		}
	}
}

//OTHERs
void BookInfo::printAuthors(const AuthorContainer& authors) const
{
	std::cout << "Authors:";
	for (int i = 0; i != authors.size(); i++)
	{
		std::cout << authors[i] << ", ";
	}
	std::cout << std::endl;
}
void BookInfo::printGenres(const GenreContainer& genres) const
{
	std::cout << "Genre:";
	for (int i = 0; i != genres.size(); i++)
	{
		std::string strGenre = "NA";
		switch (genres[i])
		{
			case 0: strGenre = "Sci_Fi"; break;
			case 1: strGenre = "Fantasy"; break;
			case 2: strGenre = "Mystery"; break;
			case 3: strGenre = "Romance"; break;
			case 4: strGenre = "Adventure"; break;
			case 5: strGenre = "Horror"; break;
			case 6: strGenre = "Thriller"; break;
			default: ;
		}
		std::cout << strGenre << ", ";
	}
	std::cout << std::endl;
}
void BookInfo::printSeries() const
{
	for (int i = 0; i != m_bookSeries.size(); i++)
	{
		std::cout << "ID:" << m_bookSeries[i]->getProductID() << "\tPrice:" << m_bookSeries[i]->getProductPrice() << std::endl;
		std::cout << "Title:" << m_bookSeries[i]->getSerieTitle() << std::endl;
		std::cout << std::endl;
	}
}
void BookInfo::printBookInfo() const
{
	std::cout << "ID:" << getProductID() << "\tTitle:" << getTitle() << "\tISBN:" << getISBN() << std::endl;
	printAuthors(m_authors);
	printGenres(m_genres);
	std::cout << "User Rating:" << "\tPrice:" << getProductPrice() << "BGN" << std::endl;
	std::cout << "Contained in collections: " << std::endl;
	printSeries();
	std::cout << std::endl;
}

