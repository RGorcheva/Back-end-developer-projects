/*
Задача 3
За програма за менажиране на книгите в библиотека, дефинирайте клас BookInfo с private член данни за следната
информация:
● ISBN (International Standard Book Number) - уникален идентификатор на заглавието
● Заглавие
● Номер на издание
● Автор(и)
● Жанр(ове)
● Потребителски рейтинг - число от 0 до 5
● .. (каквото друго е необходимо в следващите задачи)

Задача 4
Дефинирайте getter методи за достъп за четене до всички член данни от предходната задача.
Дефинирайте setter метод само за потребителския рейтинг (тъй като само той се очаква да се променя - останалите членове,
веднъж инициализирани, запазват стойността си непроменена до затваряне на програмата, поне такова очакване имаме до
момента)

Задача 5
Дефинирайте клас, който репрезентира колекция(поредица) от книги. Една книга би могла да е част от различни поредици.
Дефинирайте член данни за това от кои книги се състои колекцията, метод за инициализация на колекцията и интерфейс за
достъп до информацията - клиентите на класа трябва да могат да имат достъп за четене на това кои книги са част от
поредицата.

Задача 6
Добавете член данна в BookInfo, която репрезентира колекцията от поредици, в които присъства всяка книга. Дефинирайте
интерфейс за достъп за четене до поредиците, в които присъства всяка книга.
Правим тази двойна връзка (хем колекцията пази от кои книги се състои, хем всяка книга пази колекциите, в които е) за да
можем да имаме бърз достъп до:
● Поредиците, в които присъства дадена книга, без да трябва да обхождаме всички поредици и книгите в тях
● Книгите, които присъстват в дадена поредица, без да трябва да обхождаме

Задача 7
Къде ще “живеят” обектите с информацията за книгите и поредиците от книги? Кой ще се грижи за тяхната памет, за инициализацията и
достъпа до информацията? Отговор: “мениджър” клас(ове), например:
● BookManager за книгите и поредиците от книги
● BookInfoManager за книгите и BookSeriesInfoManager за поредиците от книги.
Дефинирайте класа(класовете) и техните член данни.

Задача 8
Добавете функционалност за еднократно гласуване за книга от потребител (рейтинг от 0 до 5).
Добавете функционалност, която следи общия средноаритметичен рейтинг на всички книги в библиотеката. Добавете интефрейс за
обновяването му при всяко еднократно гласуване и интерфейс за бърз достъп до него. За да бъде бърз този достъп за четене, не би
следвало на всяко негово извикване да се обхожда и изчислява - по-скоро можем да върнем кеширана стойност, която се обновява
много по-рядко, само при нужда - при единично гласуване от потребител.
Къде ще живее тази кеширана променлива?
Би могла да е член данна на manager class(тепърва ще видим как да ограничим броя обекти от даден тип на един и не повече).
Би могла и да е член данна на BookInfo класа. С цел упражнение, нека изберем второто за момента

Задача 9
Тествайте си кода (с друг, временен код) - било с hardcode-нати стойности и инициализация, било с четене от файлове (без валидация)
*/

#include "BookInfo.h"
#include "BookInfoManager.h"
#include "BookSeries.h"
#include "BookSeriesManager.h"

int main()
{
	//Deserilization
	BookInfoManager BookList;
	BookList.bookInfoInitFromFile();
	BookSeriesManager Serielist;
	Serielist.seriesInitFromFile();

	//fill array with collections in bookInfo:
	for (int i = 0; i != BookList.getBookInfos().size(); i++)
	{
		BookList.getBookInfoByIndex(i).fillBookSeries(Serielist.getBookSeries());
	}

	//Print all books;
	std::cout << "Book list:" << std::endl;
	for (size_t i = 0; i != BookList.getBookInfos().size(); i++)
	{
		BookList.getBookInfoByIndex(i).printBookInfo();
	}
	std::cout << "Series list:" << std::endl;

	//Print all series;
	for (size_t i = 0; i != Serielist.getBookSeries().size(); i++)
	{
		Serielist.getBookSerieByIndex(i).printSeries(BookList);
	}

	//Choose product
 	std::cout << "Please choode a product: " << std::endl;
	int chooseProductID = 0;
	std::cin >> chooseProductID;
	std::cout << "You choose the book: "<< std::endl;
	int i = 0;
	for (; i != BookList.getBookInfos().size(); i++)
	{
		if (BookList.getBookInfos()[i].getProductID() == chooseProductID)
		{
			BookList.getBookInfos()[i].printBookInfo();
			break;
		}
	}

	//Rate the product
	double newRate = 0.0;
	std::cout << "Please, rate for this book from 1.0 to 5.0: " << std::endl;
	std::cin >> newRate;
	BookList.getBookInfos()[i].setAverageUserRating(newRate);
	std::cout << "New average user rating is " << BookList.getBookInfos()[i].getAverageUserRating() << std::endl;

	//Serilization
	BookList.bookInfoDeinitToFile("testBook.txt");
	Serielist.seriesDeinitToFile("testSerie.txt");
	return 0;
}