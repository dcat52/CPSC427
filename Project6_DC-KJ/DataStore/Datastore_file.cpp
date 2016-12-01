#include "..\includes\DataStore_File.h"
#include <fstream>

DataStore_File::DataStore_File(std::string fileName, Crypto * crypto) :DataStore(crypto)
{
	myFileName = fileName;
}

DataStore_File::~DataStore_File(void)
{
}

bool DataStore_File::load(std::vector<String_Data>& myVector)
{
	// Do we need to clear myVector before loading???
	std::string line;
	std::ifstream myFile(myFileName);
	myFile.open(myFileName);
	if (myFile.is_open())
	{
		while (getline(myFile, line))
		{
			//TODO decrypt if present
			add(myVector, line);
		}
	}
	myFile.close();
	return true;
}

bool DataStore_File::save(std::vector<String_Data>& myVector)
{
	std::string line;
	std::ofstream myFile(myFileName);
	myFile.open(myFileName);
	if (myFile.is_open())
	{
		for (int i = 0; i < myVector.size(); i++) {
			// TODO encrypt if present
			myFile << line << "\n";
		}

	}
	myFile.close();
	return true;
}

bool DataStore_File::openFile(std::fstream & myfile, const std::string & myFileName, std::ios_base::openmode mode)
{
	// DO we need to implement these???
	return false;
}

void DataStore_File::closeFile(std::fstream & myfile)
{
	// DO we need to implement these???
}

void DataStore_File::add(std::vector<String_Data>& myVector, std::string line)
{
	bool exists = false;
	for (int i = 0; i < myVector.size(); i++) {
		if (myVector.at(i) == line) {
			exists = true;
			myVector.at(i).increment();
		}
	}
	if (!exists) {
		String_Data *temp = new String_Data(line);
		myVector.push_back(*temp);
	}
}