#include "..\includes\String_Database.h"

String_Database::String_Database(void)
{
}

String_Database::~String_Database(void)
{
}

void String_Database::add(std::string & myString)
{
	mutex.lock();
	myStrings.push_back(myString);
	mutex.unlock();
}

int String_Database::getCount(std::string & myString)
{
	mutex.lock();
	int count = 0;
	for(myStringsIter=myStrings.begin(); myStringsIter < myStrings.end(); myStringsIter++) {
		if (*myStringsIter == myString)
			count++;
	}
	mutex.unlock();
	return count;
}

void String_Database::clear()
{
	mutex.lock();
	myStrings.clear();
	mutex.unlock();
}

bool String_Database::load(DataStore * myDataStore)
{
	mutex.lock();
	mutex.unlock();
	return false;
}

bool String_Database::save(DataStore * myDataStore)
{
	mutex.lock();
	mutex.unlock();
	return false;
}
