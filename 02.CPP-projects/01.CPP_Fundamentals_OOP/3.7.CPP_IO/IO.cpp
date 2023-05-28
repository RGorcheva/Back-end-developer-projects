#include "IO.h"
#include <iomanip>

/*
Задача 1
Дефинирайте функция за отваряне на файл за писане, която приема ifstream и го връща като референция.
Функцията трябва да може да работи и с потоци в невалидно състояние(трябва да се погрижи да направи
състоянието валидно в случай че не е)
*/
std::ofstream& fileOpenForWritting(std::ofstream& outFile, std::string fileName)
{
	if (!outFile.good())
	{
		outFile.clear();
	}
	outFile.open(fileName.c_str());
	if (!outFile)
	{
		std::cerr << "File could not be opened!" << std::endl;
	}
	return outFile;
}

/*
Задача 2
Дефинирайте функция за отваряне на файл за четене, която приема ofstream и го връща като референция. Функцията трябва
да приема и параметър за режима на отваряне на файла, който да има и подходяща default стойност.
*/
std::ifstream& fileOpenForReading(std::ifstream& intFile, std::string fileName, std::ios::openmode mode)
{
	if (!intFile.good())
	{
		intFile.clear();
	}
	intFile.open(fileName, mode);
	if (!intFile)
	{
		std::cerr << "File could not be opened!" << std::endl;
	}
	return intFile;
}

/*
Задача 3
Напишете функция, която приема име на файл, който да отвори и от който да чете.Функцията трябва да прочита всички думи
от файла и да ги записва в обратен ред във втори файл, който има името на първия, но с “_reverse” в името.
*/
void reverseFileContent(std::string fileName)
{
	std::ifstream inFile;
	fileOpenForReading(inFile, fileName.c_str(), std::ios::out);

	std::string reverseFileName("reverse_");
	reverseFileName += fileName;
	std::ofstream outFile;
	fileOpenForWritting(outFile, reverseFileName);
	std::string line;
	while (std::getline(inFile, line, '\n'))
	{
		for (size_t i = 1; i <= line.size(); i++)
		{
			outFile << line.c_str()[line.size() - i];
		}
		outFile << std::endl;
	}
}

/*
Задача 4
Напишете функция, която прави същото като функцията от предходната задача, но с множество файлове (функцията трябва
да приема контейнер с имена на файлове, от които да чете)
*/
void reverseFilesContent(const std::vector<std::string>& fileNames)
{
	for (int i = 0; i != fileNames.size(); i++)
	{
		reverseFileContent(fileNames[i]);
	}
}

/*
Задача 5
Напишете функция, която чете от istream цели числа и принтира най-голямото, най-малкото и средното
аритметично от/на всички прочетени числа
*/
void readNumbersInt(std::istream& in)
{
	int number = 0;
	std::vector<int>vec;
	while (in >> number)
	{
		vec.push_back(number);
	}
	int sum = 0;
	int min = vec[0];
	int max = vec[0];
	for (int i = 0; i != vec.size(); i++)
	{
		sum += vec[i];
		if (min > vec[i])
		{
			min = vec[i];
		}
		if (max < vec[i])
		{
			max = vec[i];
		}
	}
	float average = (float)sum / vec.size();
	std::cout << "Min: " << min << std::endl;
	std::cout << "Max: " << max << std::endl;
	std::cout << "Average: " << average << std::endl;
}

/*
Задача 6
Напишете функция, подобна на тази от предходната задача, но да работи с floating-point числа и да принтира
резултата в колони от по 8 символа, подравнени отдясно, с точност - до 3 цифри след десетичната запетая
*/
void readNumbersFloat(std::istream& in)
{
	float number = 0;
	std::vector<float>vec;
	while (in >> number)
	{
		vec.push_back(number);
	}
	float sum = 0;
	float min = vec[0];
	float max = vec[0];
	for (int i = 0; i != vec.size(); i++)
	{
		sum += vec[i];
		if (min > vec[i])
		{
			min = vec[i];
		}
		if (max < vec[i])
		{
			max = vec[i];
		}
	}
	float average = (float)sum / vec.size();
	std::cout << std::setw(10) << "Min: ";;
	std::cout << std::setw(8) << std::fixed << std::setprecision(3) << std::right << min << std::endl;
	std::cout << std::setw(10) << "Max: ";
	std::cout << std::setw(8) << std::fixed << std::setprecision(3) << std::right << max << std::endl;
	std::cout << std::setw(10) << "Average: ";
	std::cout << std::setw(8) << std::fixed << std::setprecision(3) << std::right << average << std::endl;
}

