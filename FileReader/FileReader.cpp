#include <iostream>
#include <fstream>
#include "string.h"
#include "..\Include\FileReader.h"
#include "..\Include\constants.h"
#include "..\Include\Debug_Help.h"
using namespace std;
using namespace KP_FileReaderClass;

//TODO Fill this in

FileReader::FileReader()
{
}

FileReader::~FileReader()
{
}

int FileReader::getFileContents(const std::string filename, std::string & contents)
{
	ifstream myFile;
	//opens file
	myFile.open(filename);					

	//if file does not open then...
	while (!myFile.is_open()) {
		cout << ENTER_FN_OR_X;
		string fileN;
		cin >> fileN;
		//filename = &fileN;


		if (filename == EXITCHAR) {
			return USER_CHOSE_TO_EXIT;
		}

		myFile.open(filename);
	}

	

	string line;

	while (getline(myFile, line)) {
		contents.append(line);
	}
	
	if (contents.size() == 0) {
		myFile.close();
		return COULD_NOT_READ_FILE_INTO_CONTAINER;		
	}

	myFile.close();

	return SUCCEEDED;
}

int FileReader::ReadTheWholeFile(const std::string & filename)
{
	return 0;
}
