#ifndef BOOKINFOMANAGER_H
#define BOOKINFOMANAGER_H
#include <string>
#include <vector>

class BookInfo;

class BookInfoManager
{
public:

	BookInfoManager();
	typedef std::vector<BookInfo> BookContainer;

	//GETTERs
	const BookContainer& getBookInfos() const;
	BookContainer& getBookInfos();
	const BookInfo& getBookInfoByIndex(size_t index) const;
	BookInfo& getBookInfoByIndex(size_t index);
	//OTHERs
	void bookInfoInitFromFile(const std::string& fileName = "books.txt");
	void bookInfoDeinitToFile(const std::string& fileName = "books.txt");

private:
	BookContainer	m_bookInfos;
};

#endif