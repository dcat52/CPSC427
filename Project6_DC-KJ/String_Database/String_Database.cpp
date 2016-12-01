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
	// lock mutex
	mutex.lock();

	int count = 0;

	// go through string_data vector
	for (myStringsIter = myStrings.begin(); myStringsIter < myStrings.end(); myStringsIter++) {
		
		// if two datums are equal
		if (*myStringsIter == myString)
		{
			// get count of myStringIter
			count = myStringsIter->getCount();
		}
	}

	// unlock mutex
	mutex.unlock();

	return count;
}

void String_Database::clear()
{
	// lock mutex
	mutex.lock();

	// clear string_data vector
	myStrings.clear();

	// unlock mutex
	mutex.unlock();
}

bool String_Database::load(DataStore * myDataStore)
{
	// lock mutex
	mutex.lock();

	// load from file
	myDataStore->load(myStrings);

	// unlock mutex
	mutex.unlock();

	return true;
}

bool String_Database::save(DataStore * myDataStore)
{
	// lock mutex
	mutex.lock();

	// save to file
	myDataStore->save(myStrings);

	// unlock mutex
	mutex.unlock();


	return true;
}
