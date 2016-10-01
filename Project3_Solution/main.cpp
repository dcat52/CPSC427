// Proj3.cpp : Defines the entry point for the console application.
//
// Kim Jimenez
// Davis Catherman

#include "stdafx.h"
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "common.h"
#include "vectorStuff.h"

using namespace std;

void extractTokensFromLine(std::string &myString);
void processToken(string token);

const int EXIT = -1;
const int SUCCESS = 0;
int wordCount = 0;
int countVar = 0;
int numberDeleted = 0;
entry* words;


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

	//TODO: implement timer wrapper
	sortVector();
	printVectorAscending();

	ofstream myfile;
	//creates output file
	myfile.open("outfile.txt");

	//closes output file
	myfile.close();



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

}
