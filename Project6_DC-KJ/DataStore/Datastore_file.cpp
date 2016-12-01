#include "..\includes\DataStore_File.h"

DataStore_File::DataStore_File(std::string fileName, Crypto * crypto)
{
}

DataStore_File::~DataStore_File(void)
{
}

bool DataStore_File::load(std::vector<String_Data>& myVector)
{
	return false;
}

bool DataStore_File::save(std::vector<String_Data>& myVector)
{
	return false;
}

bool DataStore_File::openFile(std::fstream & myfile, const std::string & myFileName, std::ios_base::openmode mode)
{
	return false;
}

void DataStore_File::closeFile(std::fstream & myfile)
{
}