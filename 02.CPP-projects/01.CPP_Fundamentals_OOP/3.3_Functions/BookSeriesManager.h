#ifndef BOOKSERIESMANAGER_H
#define BOOKSERIESMANAGER_H

#include <vector>
#include <string>

class BookSeries;

class BookSeriesManager
{
public:
	BookSeriesManager();
	typedef std::vector<BookSeries> SerieContainer;

	const SerieContainer& getBookSeries() const;
	const BookSeries& getBookSerieByIndex(size_t index) const;
	BookSeries& getBookSerieByIndex(size_t index);
	void seriesInitFromFile(const std::string fileName = "series.txt");
	void seriesDeinitToFile(const std::string fileName = "series.txt") const; 
private:
	SerieContainer	m_bookSeries;
};

#endif