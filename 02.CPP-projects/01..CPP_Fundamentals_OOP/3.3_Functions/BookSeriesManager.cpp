#define _CRT_SECURE_NO_WARNINGS
#include "BookSeriesManager.h"
#include "BookSeries.h"
#include <iostream>
#include <fstream>
#include <sstream>

BookSeriesManager::BookSeriesManager()
{};
const BookSeriesManager::SerieContainer& BookSeriesManager::getBookSeries() const
{
	return m_bookSeries;
}
const BookSeries& BookSeriesManager::getBookSerieByIndex(size_t index) const
{
	return m_bookSeries[index];
}
BookSeries& BookSeriesManager::getBookSerieByIndex(size_t index)
{
	return m_bookSeries[index];
}
void BookSeriesManager::seriesInitFromFile(const std::string fileName)
{
	const char* strFile = fileName.c_str();
	FILE* in = fopen(strFile, "r");
	int countSeries = 0;
	char ch = 0;
	int isScan = fscanf(in, "(%d)\n", &countSeries);
	for (int i = 0; i != countSeries; i++)
	{
		int 			productID = 0;
		std::string		title;
		char cTitle[100] = "\0";
		float			productPrice = 0.0f;
		BookSeries::SerieContainer serie;
		int bookID = 0;

		isScan = fscanf(in, "(%d, %[^,], %ff, {", &productID, cTitle, &productPrice);
		title = cTitle;
		do
		{
			isScan = fscanf(in, "%d", &bookID);
			serie.push_back(bookID);
		} while ((isScan = fscanf(in, " %c", &ch)) && ch != '}');
		char buffer[20] = "\0";
		isScan = fscanf(in, "%[^\n]\n", &buffer);

		BookSeries serie1(productID, title, productPrice, serie);
		m_bookSeries.push_back(serie1);
	}
}
void BookSeriesManager::seriesDeinitToFile(const std::string fileName) const
{
	std::ofstream output_file(fileName);
	if (output_file.is_open())
	{
		output_file << '(' << m_bookSeries.size() << ")\n";
		for (int i = 0; i != m_bookSeries.size(); i++)
		{
			output_file << '(' << m_bookSeries[i].getProductID() << ", ";
			output_file << m_bookSeries[i].getSerieTitle() << ", ";
			output_file << m_bookSeries[i].getProductPrice() << ", {";
			int j = 0;
			for (; j != m_bookSeries[i].getSerie().size() - 1; j++)
			{
				output_file << m_bookSeries[i].getSerie()[j] << ", ";
			}
			output_file << m_bookSeries[i].getSerie()[j] << "})\n";
		}
		output_file.close();
	}
}