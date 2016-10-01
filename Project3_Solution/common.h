#pragma once

#include <string>

#define strcasecmp _stricmp

struct entry
{
	std::string word;				//word in the file
	int number_occurences;		//number of times word appears in the file
}; // REMEMBER the last semi-colon

bool sortAscending(const entry &a, const entry &b);
bool sortDecending(const entry &a, const entry &b);
bool sortNumOccurrences(const entry &a, const entry &b);