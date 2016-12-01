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
	std::string line;
	std::ifstream myFile;
	myFile.open(myFileName);
	if (myFile.is_open())
	{
		while (getline(myFile, line))
		{
			//TODO decrypt if present
			decrypt(line);
			std::string data;
			int count;
			String_Data::parseData(line, data, count);
			String_Data *temp = new String_Data(data, count);
			myVector.push_back(*temp);
		}
	}
	myFile.close();
	return true;
}

bool DataStore_File::save(std::vector<String_Data>& myVector)
{
	std::string line;
	std::ofstream myFile;
	myFile.open(myFileName);
	if (myFile.is_open())
	{
		for (int i = 0; i < myVector.size(); i++) {
			line = myVector.at(i).serialize();
			// TODO encrypt if present
			encrypt(line);
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