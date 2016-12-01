#include "DataStore.h"

DataStore::DataStore(Crypto * pCrypt)
{
	myCrypto = pCrypt;
}

DataStore::~DataStore(void)
{
}

bool DataStore::decrypt(std::string & myString)
{
	return false;
}

bool DataStore::encrypt(std::string & myString)
{
	return false;
}
