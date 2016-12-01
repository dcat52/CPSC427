#include "..\includes\DataStore_File.h"
#include <fstream>

// call the parent object and pass it crypto object
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

	// open myFileName
	myFile.open(myFileName);
	if (myFile.is_open())
	{
		while (getline(myFile, line))
		{
			// send to the decrypter
			decrypt(line);

			std::string data;
			int count;

			// parse the data from the decrypted line
			String_Data::parseData(line, data, count);

			// load it into a String_Data object
			String_Data *temp = new String_Data(data, count);

			// add it to the database vector
			myVector.push_back(*temp);
		}
	}
	// close the file
	myFile.close();
	return true;
}

bool DataStore_File::save(std::vector<String_Data>& myVector)
{
	std::string line;
	std::ofstream myFile;

	// open myFileName
	myFile.open(myFileName);
	if (myFile.is_open())
	{
		// go through database vector
		for (int i = 0; i < myVector.size(); i++) {

			// serialize the data and useCount into a string
			line = myVector.at(i).serialize();

			// send to the encrypter
			encrypt(line);

			// write to the file
			myFile << line << "\n";
		}

	}
	// close the file
	myFile.close();
	return true;
}