#include "..\includes\String_Database.h"

String_Database::String_Database(void)
{
}

String_Database::~String_Database(void)
{
}

void String_Database::add(std::string & myString)
{
	// lock the mutex
	mutex.lock();

	// keep track if data already exists
	bool exists = false;

	// go through the string_data vector
	for (int i = 0; i < myStrings.size(); i++) {

		// if data already exists, increment count
		if (myStrings.at(i) == myString) {
			exists = true;
			myStrings.at(i).increment();
		}
	}

	// if does not exist, add a new entry
	if (!exists) {
		String_Data *temp = new String_Data(myString);
		myStrings.push_back(*temp);
	}

	// unlock the mutex
	mutex.unlock();
}

int String_Database::getCount(std::string & myString)
{
	mutex.lock();
	int count = 0;

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
