#include "stdafx.h"
#include "common.h"

#define strcasecmp _stricmp

bool sortAscending(const entry &a, const entry &b)
{
	if (strcasecmp(a.word.c_str(), b.word.c_str()) < 0)
		return true;
	return false;
}

bool sortDecending(const entry &a, const entry &b)
{
	if (strcasecmp(a.word.c_str(), b.word.c_str()) > 0)
		return true;
	return false;
}

bool sortNumOccurrences(const entry &a, const entry &b)
{
	return a.number_occurences < b.number_occurences;
}
