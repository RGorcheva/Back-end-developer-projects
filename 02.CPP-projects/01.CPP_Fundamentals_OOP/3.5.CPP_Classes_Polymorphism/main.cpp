#include "funcManuManager.h"
#include <iostream>
#include "ProductManager.h"
#include "ProductBook.h"
#include "ProductBookSerie.h"
#include "ProductPen.h"

int main(void)
{
	ProductManager::GetInstance().deserializeProducts("Products.txt");
	ProductManager::GetInstance().fillSeriesInBooks();

	std::cout << "------------------------------------------------------" << std::endl;
	std::cout << "Welcome to Bookstore \"World of Books\"" << std::endl;
	std::cout << "------------------------------------------------------" << std::endl;

	std::cout << "Choose an option:\n" << std::endl;
	std::cout << "See all Products: Press 1" << std::endl;
	std::cout << "See all books: Press 2" << std::endl;
	std::cout << "See all book series: Press 3" << std::endl;
	std::cout << "See all pens: Press 4" << std::endl;
	int userChoice = 0;
	std::cin >> userChoice;
	if (userChoice == 1)
	{
		std::cout << "------------------------------------------------------" << std::endl;
		std::cout << "PRODUCT LIST" << std::endl;
		std::cout << "------------------------------------------------------" << std::endl;
		ProductManager::GetInstance().printProducts(std::cout);
	}
	else if (userChoice == 2)
	{
		std::cout << "------------------------------------------------------" << std::endl;
		std::cout << "BOOK LIST" << std::endl;
		std::cout << "------------------------------------------------------" << std::endl;
		ProductManager::GetInstance().printProductsByType(std::cout, E_productType_Book);
	}
	else if (userChoice == 3)
	{
		std::cout << "------------------------------------------------------" << std::endl;
		std::cout << "BOOK SERIE LIST" << std::endl;
		std::cout << "------------------------------------------------------" << std::endl;
		ProductManager::GetInstance().printProductsByType(std::cout, E_productType_Serie);
	}
	else if (userChoice == 4)
	{
		std::cout << "------------------------------------------------------" << std::endl;
		std::cout << "PEN LIST" << std::endl;
		std::cout << "------------------------------------------------------" << std::endl;
		ProductManager::GetInstance().printProductsByType(std::cout, E_productType_Pen);
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	std::cout << "------------------------------------------------------" << std::endl;
	std::cout << "BUY A PRODUCT" << std::endl;
	std::cout << "------------------------------------------------------" << std::endl;
	//Buy a product
	std::cout << "Please choose a product: " << std::endl;
	int chooseProductID = 0;
	std::cin >> chooseProductID;
	Product* product = ProductManager::GetInstance().getProduct(chooseProductID - 1);
	std::cout << "Your choice: " << std::endl;
	product->print(std::cout);
	static float iFinalPrice = 0;
	int quantity = 0;
	std::cout << "Choice quantity: ";
	std::cin >> quantity;
	if (quantity > product->getProductInStock())
	{
		std::cout << "Limited quantity!\n We have only " << product->getProductInStock() << "units\n";
		quantity = product->getProductInStock();
	}
	int newNumberInStock = product->getProductInStock() - quantity;
	product->setProductInStock(newNumberInStock);
	iFinalPrice += quantity * ProductManager::GetInstance().getProductContainer()[chooseProductID]->getProductPrice();
	std::cout << "Amount: " << iFinalPrice << " BGN" << std::endl;

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	std::cout << "------------------------------------------------------" << std::endl;
	std::cout << "VOTE A PRODUCT" << std::endl;
	std::cout << "------------------------------------------------------" << std::endl;

	//vote for book
	std::cout << "Book list: " << std::endl;
	ProductManager::GetInstance().printProductsByType(std::cout, E_productType_Book);

	std::cout << "Please choode a Book: " << std::endl;
	chooseProductID = 0;
	std::cin >> chooseProductID;
	ProductManager::GetInstance().getProduct(chooseProductID - 1)->print(std::cout);

	double newRate = 0.0;
	std::cout << "Please, rate for this book from 1.0 to 5.0: " << std::endl;
	std::cin >> newRate;
	Product* lastProduct = ProductManager::GetInstance().getProduct(chooseProductID - 1);
	ProductBook* book = static_cast<ProductBook*>(lastProduct);
	book->setAverageUserRating(newRate);
	std::cout << "New average user rating is " << book->getAverageUserRating() << std::endl;

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	std::cout << "------------------------------------------------------" << std::endl;
	std::cout << "ADD NEW PRODUCT" << std::endl;
	std::cout << "------------------------------------------------------" << std::endl;
	char menuChoice = '0';
	E_productType type = E_productType_NA;
	std::cout << "What type of product do you want to add?\nPlease, choose an option: " << std::endl;
	std::cout << "Press 1 for book" << std::endl;
	std::cout << "Press 2 for book serie" << std::endl;
	std::cout << "Press 3 for pen" << std::endl;
	do
	{
		std::cin >> menuChoice;
		if (menuChoice == '1')
		{
			type = E_productType_Book;
		}
		else if (menuChoice == '2')
		{
			type = E_productType_Serie;
		}
		else if (menuChoice == '3')
		{
			type = E_productType_Pen;
		}
		else
		{
			std::cout << "\nYour choice is not correct! Try again!" << std::endl;
		}
	} while (menuChoice != '1' && menuChoice != '2' && menuChoice != '3');

	Product* newProduct = ProductManager::GetInstance().addNewProduct(type);
	newProduct->print(std::cout);

	ProductManager::GetInstance().serializeProducts("Products2.txt");
	ProductManager::GetInstance().destroyAllProducts();

	//Operators << and >>///////////////////////////////////////////////////////////////////////////////////////////////////
	ProductBook* newBook = static_cast<ProductBook*>(ProductManager::GetInstance().addNewProduct(E_productType_Book));
	std::cin >> *newBook;
	std::cout << *newBook;

	return 0;
}