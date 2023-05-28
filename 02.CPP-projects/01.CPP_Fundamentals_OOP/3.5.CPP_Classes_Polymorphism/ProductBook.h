#ifndef BOOKINFO_H
#define BOOKINFO_H

#include <iostream>
#include <string>
#include <vector>
#include "Product.h"
#include "enums.h"

class ProductBookSerie;

class ProductBook : public Product
{
public:
	typedef std::vector<std::string>AuthorContainer;
	typedef std::vector<E_BookGenre> GenreContainer;
	typedef std::vector<ProductBookSerie*> SeriesContainer;

	//GETTERs
	const std::string& getISBN() const;
	const std::string& getTitle() const;
	const int getEdition() const;
	const AuthorContainer& getAuthors() const;
	const GenreContainer& getGenres() const;
	const double getAverageUserRating() const;
	const unsigned getCountUserRated() const;
	const SeriesContainer& getBookSeries() const;
	SeriesContainer& getBookSeries();

	//SETTERs
	void setAverageUserRating(double newRate);

	//Virtual
	virtual E_productType getType();
	virtual void deserialize(std::istream& in);
	virtual void serialize(std::ostream& out);
	virtual void print(std::ostream& out) const;
	virtual void addProduct();

	friend class ProductManager;
	friend std::ostream& operator<<(std::ostream& out, const ProductBook& book);
	friend std::istream& operator>>(std::istream& in, ProductBook& book);

private:
	std::string		m_ISBN;
	std::string		m_title;
	int				m_edition;
	AuthorContainer m_authors;
	GenreContainer  m_genres;
	double			m_averageUserRating;
	unsigned		m_countUserRated;
	SeriesContainer m_bookSeries;

	//Constructors
	ProductBook();
	ProductBook(
		const std::string& ISBN
		, const std::string& title
		, int edition
		, const AuthorContainer& authors
		, const GenreContainer& genres
		, double averageUserRating
		, unsigned countUserRated
	);
};

#endif