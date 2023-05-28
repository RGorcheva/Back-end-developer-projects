#include "../include/Utility.h"
#include <iostream>
#include <fstream>

int min(int a, int b)
{
	return (a <= b) ? a : b;
}

int max(int a, int b)
{
	return (a >= b) ? a : b;
}

std::ifstream& openInputFile(std::ifstream& intFile, std::string fileName, std::ios::openmode mode)
{
	if (!intFile.good())
	{
		intFile.clear();
	}
	intFile.open(fileName, mode);
	if (!intFile)
	{
		std::cerr << "File " << fileName << " could not be opened!" << std::endl;
	}
	return intFile;
}

std::ofstream& openOutputFile(std::ofstream& outFile, std::string fileName)
{
	if (!outFile.good())
	{
		outFile.clear();
	}
	outFile.open(fileName.c_str());
	if (!outFile)
	{
		std::cerr << "File " << fileName << " could not be opened!" << std::endl;
	}
	return outFile;
}