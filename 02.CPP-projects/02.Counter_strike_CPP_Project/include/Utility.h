#ifndef UTILITY_H
#define UTILITY_H

#include <fstream>
#include <string>

int min(int a, int b);
int max(int a, int b);

std::ifstream& openInputFile(std::ifstream& intFile, std::string fileName, std::ios::openmode mode);
std::ofstream& openOutputFile(std::ofstream& outFile, std::string fileName);

#endif /* UTILITY_H */