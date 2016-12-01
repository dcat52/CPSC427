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
	if (myCrypto != NULL)
	{
		myCrypto->decrypt(myString);
		return true;
	}
	return false;
}

bool DataStore::encrypt(std::string & myString)
{
	if (myCrypto != NULL)
	{
		myCrypto->encrypt(myString);
		return true;
	}
	return false;
}
