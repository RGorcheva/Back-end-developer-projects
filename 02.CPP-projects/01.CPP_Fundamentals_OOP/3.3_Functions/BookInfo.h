#ifndef BOOKINFO_H
#define BOOKINFO_H

#include <iostream>
#include <string>
#include <vector>
#include "BookSeries.h"
#include "E_BookGenre.h"
#include "BookSeriesManager.h"

class BookSeries;

class BookInfo
{
public:
	typedef std::vector<std::string>AuthorContainer;
	typedef std::vector<E_BookGenre> GenreContainer;

	//Constructors
	BookInfo();
	BookInfo(int productID
		, const std::string& ISBN
		, const std::string& title
		, int edition
		, const AuthorContainer& authors
		, const GenreContainer&  genres
		, int countBooksInStock
		, double averageUserRating
		, unsigned countUserRated
		, float productPrice
	 );

	//GETTERs
	const int getProductID() const;
	const std::string& getISBN() const;
	const std::string& getTitle() const;
	const int getEdition() const;
	const AuthorContainer& getAuthors() const;
	const GenreContainer& getGenres() const;
	const int getBooksInStock() const;
	const double getAverageUserRating() const;
	const unsigned getCountUserRated() const;
	const float getProductPrice() const;
	const std::vector<BookSeries*>& getBookSeries() const;


	//SETTERs
	void setAverageUserRating(double newRate);
	void fillBookSeries(const BookSeriesManager::SerieContainer& alleries);

	//OTHERs
	void printAuthors(const AuthorContainer& authors) const;
	void printGenres(const GenreContainer& genres) const;
	void printSeries() const;
	void printBookInfo() const;

private:
	int 			m_productID;
	std::string		m_ISBN;
	std::string		m_title;
	int				m_edition;
	AuthorContainer m_authors;
	GenreContainer  m_genres;
	int				m_countBooksInStock;
	double			m_averageUserRating;
	unsigned		m_countUserRated;
	float			m_productPrice;
	std::vector<BookSeries*> m_bookSeries;

};

#endif