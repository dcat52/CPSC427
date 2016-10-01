// Proj3.cpp
//
// Kim Jimenez
// Davis Catherman

#include "stdafx.h"
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include "constants.h"
#include "common.h"
#include "vectorStuff.h"
#include "arrayStuff.h"
using namespace std;

void extractTokensFromLine(std::string &myString);
void processToken(string token);

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream myFile;
	string fileName = "TestData.txt";

	// open default file
	myFile.open(fileName);

	// if file did not open, repeatedly prompt user for new file or to exit
	while (!myFile.is_open())
	{
		cout << "Could not find file, please enter a filename or an X to exit: ";
		cin >> fileName;
		if (fileName == "x" || fileName == "X")
		{
			return EXIT; // bye-bye
		}
		// try to open new file before re-looping through the while
		myFile.open(fileName);
	}

	// read lines from file, pass to extractTokens
	string line;	
							

	//reads each line of the file
	while (getline(myFile, line))
	{
		extractTokensFromLine(line);
	}
	myFile.close(); // done with input file

	removeVectorDuplicates();
	removeArrayDuplicates();

	std::chrono::high_resolution_clock::time_point startTime;
	std::chrono::high_resolution_clock::time_point endTime;
	std::chrono::duration<double> timeSpan;

	startTime = std::chrono::high_resolution_clock::now();
	sortVector();
	endTime = std::chrono::high_resolution_clock::now();
	timeSpan = std::chrono::duration_cast<std::chrono::duration<double>>(endTime - startTime);
	double vectorTime = timeSpan.count()/(3 * 1000);

	startTime = std::chrono::high_resolution_clock::now();
	sortArray();
	endTime = std::chrono::high_resolution_clock::now();
	timeSpan = std::chrono::duration_cast<std::chrono::duration<double>>(endTime - startTime);
	double arrayTime = timeSpan.count()/(3*1000);

	cout << "Avg. Vector runtime: " << vectorTime << endl;
	cout << "Avg. Array runtime: " << arrayTime << endl;

	double ratio = vectorTime / arrayTime;
	if (ratio < 1)
	{
		ratio = arrayTime / vectorTime;
		cout << setprecision(2) << "Vector sort is roughly " << ratio << " time(s) faster!" << endl;
	}
	else
	{
		cout << setprecision(2) << "Array sort is roughly " << ratio << " time(s) faster!" << endl;
	}

	printVectorAscending();
	printArrayAscending();

	

	return SUCCESS; // no problems!
}

void extractTokensFromLine(std::string &myString)
{
	const char CHAR_TO_SEARCH_FOR = ' ';
	stringstream ss(myString);
	string tempToken;
	//reads each line and each line will go through the processToken method
	while (getline(ss, tempToken, CHAR_TO_SEARCH_FOR))
	{
		processToken(tempToken);
	}
}

void processToken(string token)
{
	addTokenToVector(token);
	addTokenToArray(token);

}
