#include <stdlib.h>

#include "../include/BattleField.h"
#include "../include/Utility.h"
#include <string>

int main() 
{
	const std::string fileFolder("E:\\Programming\\Counter_Strike_C++\\1.Counter_Strike_Code_C++\\Counter_strike_Cpp\\Tests\\");
	//const std::string infileName("Sample\\test.000.001.in.txt");
	const std::string infileName("TestInput\\test.000.001.in.txt");
	std::ifstream inFile;
	openInputFile(inFile, fileFolder + infileName, std::ios::out);

	std::ofstream outFile;
	const std::string outfileName("MineResults\\mine_test.000.001.out.txt");
	openOutputFile(outFile, fileFolder + outfileName);

	BattleField bf;
	bf.createPlayers(inFile);
	bf.buyPistols(inFile);
	bf.startBattle(outFile);

	return EXIT_SUCCESS;
}
