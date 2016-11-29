#include "..\includes\String_Database.h"

String_Database::String_Database(void)
{
}

String_Database::~String_Database(void)
{
}

void String_Database::add(std::string & myString)
{
	myStrings.push_back(myString);
}

int String_Database::getCount(std::string & myString)
{
	int count = 0;
	for (int i = 0; i < myStrings.size(); i++) {
		if (myStrings.at(i) == myString)
			count++;
	}
	return count;
}

void String_Database::clear()
{
}

bool String_Database::load(DataStore * myDataStore)
{
	return false;
}

bool String_Database::save(DataStore * myDataStore)
{
	return false;
}
