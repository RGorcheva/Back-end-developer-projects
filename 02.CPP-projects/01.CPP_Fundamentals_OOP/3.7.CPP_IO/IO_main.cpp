#include "IO.h"
#include <iomanip>


int main()
{
	std::string filename("inputfile.txt");

	std::ofstream outfile;
	fileOpenForWritting(outfile, filename);
	outfile << "hello, world!" << std::endl;
	outfile.close();

	std::ifstream infile;
	fileOpenForReading(infile, filename, std::ios::out);
	std::string line;
	while (std::getline(infile, line))
	{
		std::cout << line << std::endl;
	}
	infile.close();

	std::string filename1("testfile1.txt");
	reverseFileContent(filename1);

	std::vector<std::string>filenames;
	std::string filename2("testfile2.txt");
	std::string filename3("testfile3.txt");
	filenames.push_back(filename1);
	filenames.push_back(filename2);
	filenames.push_back(filename3);
	reverseFilesContent(filenames);

	readNumbersInt(std::cin);

	readNumbersFloat(std::cin);
	return 0;
}
