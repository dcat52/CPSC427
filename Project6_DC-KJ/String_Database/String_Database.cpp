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
	bool exists = false;
	for (int i = 0; i < myStrings.size(); i++) {
		if (myStrings.at(i) == myString) {
			exists = true;
			myStrings.at(i).increment();
		}
	}
	if (!exists) {
		String_Data *temp = new String_Data(myString);
		myStrings.push_back(*temp);
	}
	mutex.unlock();
}

int String_Database::getCount(std::string & myString)
{
	mutex.lock();
	int count = 0;

	// Do We need to use iterators for looping through myString???
	// is it inefficient because creating new var? or is it just pointing to old var?

	for (myStringsIter = myStrings.begin(); myStringsIter < myStrings.end(); myStringsIter++) {
		if (*myStringsIter == myString)
		{
			String_Data temp = *myStringsIter;
			count = temp.getCount();
		}
	}
	for (int i = 0; i < myStrings.size(); i++) {
		if (myStrings.at(i) == myString) {
			count = myStrings.at(i).getCount();
		}

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
	myDataStore->load(myStrings);
	mutex.unlock();
	return false;
}

bool String_Database::save(DataStore * myDataStore)
{
	mutex.lock();
	myDataStore->save(myStrings);
	mutex.unlock();
	return false;
}
