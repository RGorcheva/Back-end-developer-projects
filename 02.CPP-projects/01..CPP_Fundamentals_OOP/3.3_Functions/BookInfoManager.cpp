#define _CRT_SECURE_NO_WARNINGS
#include "BookInfoManager.h"
#include "BookInfo.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include "E_BookGenre.h"


BookInfoManager::BookInfoManager()
{}

//GETTERs
const BookInfoManager::BookContainer& BookInfoManager::getBookInfos() const
{
	return m_bookInfos;
}
BookInfoManager::BookContainer& BookInfoManager::getBookInfos()
{
	return m_bookInfos;
}
const BookInfo& BookInfoManager::getBookInfoByIndex(size_t index) const
{
	return m_bookInfos[index];
}
BookInfo& BookInfoManager::getBookInfoByIndex(size_t index)
{
	return m_bookInfos[index];
}
//OTHERs
void BookInfoManager::bookInfoInitFromFile(const std::string& fileName)
{
	//std::ifstream input_file(fileName);
	//if (input_file.is_open())
	//{
	//	int countBooks = 0;
	//	std::string line;
	//	getline(input_file, line);
	//	std::istringstream ss(line);
	//	ss >> countBooks;
	//	for (int i = 0; i != countBooks; i++)
	//	{
	//		getline(input_file, line);
	////		char* pstr = line.c_str(line);
	//		std::istringstream ss(line); //pointer to string
	//		ss >> productID >> ISBN >> title >> edition;
	//		//...
	//		//Deserilization of  row in variables;
	//		
	//	}
	//	input_file.close();
	//}
	
	const char* strFile = fileName.c_str();
	FILE* in = fopen(strFile, "r");
	int countBooks = 0;
	char ch = 0;
	int isScan = fscanf(in, "(%d)\n", &countBooks);
	for (int i = 0; i != countBooks; i++)
	{
		int 			productID = 0;
		std::string		ISBN;
		char cISBN[14] = "\0";
		std::string		title;
		char cTitle[100] = "\0";
		int				edition = 0;
		BookInfo::AuthorContainer authors;
		char strAuthor[50] = "\0";
		BookInfo::GenreContainer  genres;
		int Genre;
		int				countBooksInStock = 0;
		double			averageUserRating = 0.0;
		unsigned		countUserRated = 0;
		float			productPrice = 0.0f;

		isScan = fscanf(in, "(%d, %[^,], %[^,], %d, {", &productID, cISBN, cTitle, &edition);
		ISBN = cISBN;
		title = cTitle;
		do
		{
			isScan = fscanf(in, "%[^,}]", &strAuthor);
			std::string cstrAuthor = strAuthor;
			authors.push_back(cstrAuthor);
		} while ((isScan = fscanf(in, " %c", &ch)) && ch != '}');
		char buffer[20] = "\0";
		isScan = fscanf(in, "%[^{]{", &buffer);
		E_BookGenre enum_g;
		do
		{
			isScan = fscanf(in, "%d", &Genre);
			switch (Genre)
			{
			case 0: enum_g = E_BookGenre_Sci_Fi; break;
			case 1: enum_g = E_BookGenre_Fantasy; break;
			case 2: enum_g = E_BookGenre_Mystery; break;
			case 3: enum_g = E_BookGenre_Romance; break;
			case 4: enum_g = E_BookGenre_Adventure; break;
			case 5: enum_g = E_BookGenre_Horror; break;
			default: enum_g = E_BookGenre_Thriller; break;
			}
			genres.push_back(enum_g);
		} while ((isScan = fscanf(in, " %c", &ch)) && ch != '}');
		isScan = fscanf(in, ", %d, %lf, %d, %f)\n", &countBooksInStock, &averageUserRating, &countUserRated, &productPrice);
		BookInfo book(productID, ISBN, title, edition, authors, genres, countBooksInStock, averageUserRating, countUserRated, productPrice);
		m_bookInfos.push_back(book);
	}
}
void BookInfoManager::bookInfoDeinitToFile(const std::string& fileName)
{
	std::ofstream output_file(fileName);
	if (output_file.is_open())
	{
		output_file << '(' << m_bookInfos.size() << ")\n";
		for (int i = 0; i != m_bookInfos.size(); i++)
		{
			output_file << '(' << m_bookInfos[i].getProductID() << ", ";
			output_file  << m_bookInfos[i].getISBN() << ", ";
			output_file << m_bookInfos[i].getTitle() << ", ";
			output_file << m_bookInfos[i].getEdition() << ", {";
			int j = 0;
			for (; j != m_bookInfos[i].getAuthors().size() - 1; j++)
			{
				output_file << m_bookInfos[i].getAuthors()[j] << ", ";
			}
			output_file << m_bookInfos[i].getAuthors()[j] << "}, {";
			j = 0;
			for (; j != m_bookInfos[i].getGenres().size() - 1; j++)
			{
				output_file << m_bookInfos[i].getGenres()[j] << ", ";
			}
			output_file << m_bookInfos[i].getGenres()[j] << "}, ";
			output_file << m_bookInfos[i].getBooksInStock() << ", ";
			output_file << m_bookInfos[i].getAverageUserRating() << ", ";
			output_file << m_bookInfos[i].getCountUserRated() << ", ";
			output_file << m_bookInfos[i].getProductPrice() << ")\n";
		}
		output_file.close();
	}
}
