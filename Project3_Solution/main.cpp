// Proj3.cpp
//
// Davis Catherman
// Kim Jimenez

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

	removeVectorDuplicates();												//removes duplicates from Vector
	removeArrayDuplicates();												//removes duplicates from Array

	std::chrono::high_resolution_clock::time_point startTime;				//start time for timer
	std::chrono::high_resolution_clock::time_point endTime;					//end time for timer
	std::chrono::duration<double> timeSpan;									//records amount of time it takes to sort with each method (Vector and Array)

	startTime = std::chrono::high_resolution_clock::now();					//timer starts
	sortVector();															//sorts Vector
	endTime = std::chrono::high_resolution_clock::now();					//timer ends
	timeSpan = std::chrono::duration_cast<std::chrono::duration<double>>(endTime - startTime);	//records amount of time it took Vector approach to sort
	double vectorTime = timeSpan.count() / (3 * 1000);											//records amount of time it took Vector approach to sort

	startTime = std::chrono::high_resolution_clock::now();										//timer starts
	sortArray();																				//sorts Array
	endTime = std::chrono::high_resolution_clock::now();										//timers ends
	timeSpan = std::chrono::duration_cast<std::chrono::duration<double>>(endTime - startTime);	//records amount of time it took Array approach to sort
	double arrayTime = timeSpan.count() / (3 * 1000);											//records amount of time it took Array approach to sort

	cout << "Avg. Vector runtime: " << vectorTime << endl;				//prints amount of time to took Vector to sort
	cout << "Avg. Array runtime: " << arrayTime << endl;				//prints amount of time it took Array to sort

	double ratio = vectorTime / arrayTime;								//calculates the amount of vectorTime divided by arrayTime
	if (ratio < 1)														//if ratio is less than 1 then Vector sort is faster
	{
		ratio = arrayTime / vectorTime;
		cout << setprecision(2) << "Vector sort is roughly " << ratio << " time(s) faster!" << endl;
	}
	else                                                               //else than Array sort is faster
	{
		cout << setprecision(2) << "Array sort is roughly " << ratio << " time(s) faster!" << endl;
	}

	printVectorDescending();					//prints Vector in descending order
	printArrayDescending();					//prints Array in descending order



	return SUCCESS; // no problems!
}

void extractTokensFromLine(std::string &myString)
{
	const char CHAR_TO_SEARCH_FOR = ' ';		//searched if any character is ' '
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
	addTokenToVector(token);			//adds token to Vector
	addTokenToArray(token);				//adds token to Array

}