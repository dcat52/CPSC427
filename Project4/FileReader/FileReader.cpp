/*
* FileReader.cpp
* Davis Catherman
* Kimberly Jimenez
*/
#include <iostream>
#include <fstream>
#include "string.h"
#include "..\Include\FileReader.h"
#include "..\Include\constants.h"
#include "..\Include\Debug_Help.h"
using namespace std;
using namespace KP_FileReaderClass;

//TODO Fill this in

//constructor 
FileReader::FileReader()
{
}

//destructor
FileReader::~FileReader()
{
}

//method will read in filename and contents within the file
int FileReader::getFileContents(const std::string filename, std::string & contents)
{
	ifstream myFile;
	//opens file
	myFile.open(filename);					

	//if file does not open then...
	while (!myFile.is_open()) {
		cout << ENTER_FN_OR_X << endl;
		string fileN;
		cin >> fileN;
		//filename = &fileN;

		//if the user enters an 'X' then return the following
		if (filename == EXITCHAR) {
			return USER_CHOSE_TO_EXIT;
		}

		//opens file once a proper filename is entered
		myFile.open(filename);
	}

	//reads lines from file, pass into contents using append method
	string line;

	//reads each line of the file and appends it to contents
	while (getline(myFile, line)) {
		contents.append(line);
	}
	
	//if c=the size of contents is 0 then nothing was read 
	if (contents.size() == 0) {
		myFile.close();
		return COULD_NOT_READ_FILE_INTO_CONTAINER;		
	}

	//closes the file
	myFile.close();

	//no problems!
	return SUCCEEDED;
}

int FileReader::ReadTheWholeFile(const std::string & filename)
{
	return 0;
}
