#include <iostream>
#include <fstream>
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
		cout << "Could not find file, please enter a filename or an X to exit: ";

		if (filename == EXITCHAR) {
			return USER_CHOSE_TO_EXIT;
		}

		myFile.open(filename);
	}

	myFile.close();
	return 0;
}

int FileReader::ReadTheWholeFile(const std::string & filename)
{
	return 0;
}
