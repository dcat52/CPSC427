#include "DataStore.h"

DataStore::DataStore(Crypto * pCrypt)
{
	// setup myCrypto on object creations
	myCrypto = pCrypt;
}

DataStore::~DataStore(void)
{
}

bool DataStore::decrypt(std::string & myString)
{
	// if crypto is not null, decrypt it
	if (myCrypto != NULL)
	{
		myCrypto->decrypt(myString);
		return true;
	}
	return false;
}

bool DataStore::encrypt(std::string & myString)
{
	// if crypto is not null, encrypt it
	if (myCrypto != NULL)
	{
		myCrypto->encrypt(myString);
		return true;
	}
	return false;
}
