#include "ProductBook.h"
#include "ProductBookSerie.h"
#include "Product.h"
#include <fstream>
#include <sstream>
#include <string>

//Constructors
ProductBook::ProductBook()
	: m_edition(0)
	, m_averageUserRating(0.0)
	, m_countUserRated(0)
{}
ProductBook::ProductBook(const std::string& ISBN, const std::string& title, int edition,const AuthorContainer& authors,const GenreContainer&  genres, double averageUserRating, unsigned countUserRated)
	: m_ISBN(ISBN)
	, m_title(title)
	, m_edition(edition)
	, m_authors(authors)
	, m_genres(genres)
	, m_averageUserRating(averageUserRating)
	, m_countUserRated(countUserRated)
{};

//Getters
const std::string& ProductBook::getISBN() const
{
	return m_ISBN;
}
const std::string& ProductBook::getTitle() const
{
	return m_title;
}
const int ProductBook::getEdition() const
{
	return m_edition;
}
const ProductBook::AuthorContainer& ProductBook::getAuthors() const
{
	return m_authors;
}
const ProductBook::GenreContainer& ProductBook::getGenres() const
{
	return m_genres;
}
const double ProductBook::getAverageUserRating() const
{
	return m_averageUserRating;
}
const unsigned ProductBook::getCountUserRated() const
{
	return m_countUserRated;
}
const std::vector<ProductBookSerie*>& ProductBook::getBookSeries() const
{
	return m_bookSeries;
}
std::vector<ProductBookSerie*>& ProductBook::getBookSeries()
{
	return m_bookSeries;
}

//Setters
void ProductBook::setAverageUserRating(double newRate)
{
	m_averageUserRating = ((m_averageUserRating * m_countUserRated) + newRate) / (m_countUserRated + 1);
	m_countUserRated++;
}

//Virtual
E_productType ProductBook::getType()
{
	return E_productType_Book;
}
void ProductBook::deserialize(std::istream& in)
{
	char ch = '0';
	Product::deserialize(in);
	std::getline(in, m_ISBN, ',');
	std::getline(in, m_title, ',');
	in >> m_edition;
	in.get(ch);
	in.get(ch);

	std::string authors;
	std::string author;
	std::getline(in, authors, '}');
	std::stringstream s1(authors);
	std::string::difference_type n = std::count(authors.begin(), authors.end(), ',');
	for (int i = 0; i != n; i++)
	{
		std::getline(s1, author, ',');
		m_authors.push_back(author);
	}
	std::getline(s1, author);
	m_authors.push_back(author);
	in.get(ch);
	in.get(ch);

	std::string genres;
	int genre = 0;
	E_BookGenre genreType;
	std::getline(in, genres, '}');
	std::stringstream s2(genres);
	n = std::count(genres.begin(), genres.end(), ',');

	for (int i = 0; i != n; i++)
	{
		s2 >> genre;
		s2.get(ch);
		genreType = static_cast<E_BookGenre>(genre);
		m_genres.push_back(genreType);
	}
	s2 >> genre;
	genreType = static_cast<E_BookGenre>(genre);
	m_genres.push_back(genreType);
	in.get(ch);
	in >> m_averageUserRating;
	in.get(ch);
	in >> m_countUserRated;
	in.get(ch);
}
void ProductBook::serialize(std::ostream& out)
{
	Product::serialize(out);
	out << m_ISBN << ',' << m_title << ',' << m_edition << ",{";
	int i = 0;
	for (; i != m_authors.size() - 1; i++)
	{
		out << m_authors[i] << ",";
	}
	out << m_authors[i] << "},{";
	i = 0;
	for (; i != m_genres.size() - 1; i++)
	{
		out << m_genres[i] << ",";
	}
	out << m_genres[i] << "}," << m_averageUserRating << "," << m_countUserRated << ')' << std::endl;
}
void ProductBook::print(std::ostream& out) const
{
	Product::print(out);
	out << "ISBN: " << m_ISBN << "\nTitle: " << m_title << "\nEdition: " << m_edition << std::endl;
	out << "Authors: ";
	for (int i = 0; i != m_authors.size(); i++)
	{
		out << m_authors[i] << ", ";
	}
	out << std::endl;
	out << "Genre: ";
	for (int i = 0; i != m_genres.size(); i++)
	{
		std::string strGenre = "NA";
		switch (m_genres[i])
		{
		case E_BookGenre_Sci_Fi: strGenre = "Sci_Fi"; break;
		case E_BookGenre_Fantasy: strGenre = "Fantasy"; break;
		case E_BookGenre_Mystery: strGenre = "Mystery"; break;
		case E_BookGenre_Romance: strGenre = "Romance"; break;
		default:break;
		}
		out << strGenre << ", ";
	}
	out << std::endl;
	out << "User Rating: " << m_averageUserRating << " from " << m_countUserRated << " votes" << std::endl;
	out << "Contained in collections: " << std::endl;
	std::cout << "-------------------------" << std::endl;
	for (int i = 0; i != m_bookSeries.size(); i++)
	{
		out << "Serie ID:" << m_bookSeries[i]->getProductID();
		out << " Serie Title:" << m_bookSeries[i]->getBookSerieTitle() << std::endl;
	}
	out << std::endl;
}
void ProductBook::addProduct()
{
	Product::addProduct();
	std::cout << "Enter ISBN: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, m_ISBN);

	std::cout << "Enter title: ";
	std::getline(std::cin, m_title, '\n');

	std::cout << "Enter edition: ";
	std::cin >> m_edition;

	std::cout << "Enter Genres: \n";
	std::cout << "Press 1 for Sci_Fi: \n";
	std::cout << "Press 2 for Fantasy: \n";
	std::cout << "Press 3 for Mystery: \n";
	std::cout << "Press 4 for Romance: \n";
	int genre = 0;
	while (std::cin >> genre && (1 <= genre && genre <= 4))
	{
		switch (genre)
		{
		case 1: m_genres.push_back(E_BookGenre_Sci_Fi); break;
		case 2: m_genres.push_back(E_BookGenre_Fantasy); break;
		case 3: m_genres.push_back(E_BookGenre_Mystery); break;
		case 4: m_genres.push_back(E_BookGenre_Romance); break;
		default: break;
		}
	}

	std::cout << "Enter Authors: ";
	std::string author;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (std::getline(std::cin, author, '\n') && !author.empty())
	{
		m_authors.push_back(author);
	}

	m_averageUserRating = 0.0f;
	m_countUserRated = 0;
}

/*
Тема 6: Задача 7
Дефинирайте оператори за вход и изход на книга и на колекция от книги
*/
std::ostream& operator<<(std::ostream& out, const ProductBook& book)
{
	out << "ISBN: " << book.m_ISBN << "\nTitle: " << book.m_title << "\nEdition: " << book.m_edition << std::endl;
	out << "Authors: ";
	for (int i = 0; i != book.m_authors.size(); i++)
	{
		out << book.m_authors[i] << ", ";
	}
	out << std::endl;
	out << "Genre: ";
	for (int i = 0; i != book.m_genres.size(); i++)
	{
		std::string strGenre = "NA";
		switch (book.m_genres[i])
		{
		case E_BookGenre_Sci_Fi: strGenre = "Sci_Fi"; break;
		case E_BookGenre_Fantasy: strGenre = "Fantasy"; break;
		case E_BookGenre_Mystery: strGenre = "Mystery"; break;
		case E_BookGenre_Romance: strGenre = "Romance"; break;
		default:break;
		}
		out << strGenre << ", ";
	}
	out << std::endl;
	out << "User Rating: " << book.m_averageUserRating << " from " << book.m_countUserRated << " votes" << std::endl;
	out << "Contained in collections: " << std::endl;
	for (int i = 0; i != book.m_bookSeries.size(); i++)
	{
		out << "Title:" << book.m_bookSeries[i]->getBookSerieTitle() << std::endl;
		out << std::endl;
	}
	out << std::endl;
	return out;
}
std::istream& operator>>(std::istream& in, ProductBook& book)
{
	std::cout << "\nEnter ISBN: ";
	std::getline(in, book.m_ISBN, '\n');
	std::cout << "\nEnter title: ";
	std::getline(in, book.m_title, '\n');
	std::cout << "\nEnter edition: ";
	in >> book.m_edition;
	std::cout << "\nEnter Genres: ";
	int genre = 0;
	while (in >> genre && (1 <= genre && genre <= 4))
	{
		switch (genre)
		{
		case 1: book.m_genres.push_back(E_BookGenre_Sci_Fi); break;
		case 2: book.m_genres.push_back(E_BookGenre_Fantasy); break;
		case 3: book.m_genres.push_back(E_BookGenre_Mystery); break;
		case 4: book.m_genres.push_back(E_BookGenre_Romance); break;
		default: break;
		}
	}

	std::cout << "\nEnter Authors: ";
	std::string author;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (std::getline(in, author, '\n') && !author.empty())
	{
		book.m_authors.push_back(author);
	}

	book.m_averageUserRating = 0.0f;
	book.m_countUserRated = 0;
	return in;
}