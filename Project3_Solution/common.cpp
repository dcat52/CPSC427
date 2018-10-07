// Proj3.cpp
//
// Davis Catherman
// Kim Jimenez

#include "stdafx.h"
#include "common.h"

#define strcasecmp _stricmp

/*
	method compares the words between two entries
	returns true if first word comes before second word
		otherwise returns false
*/
bool sortAscending(const entry &a, const entry &b)
{
	if (strcasecmp(a.word.c_str(), b.word.c_str()) < 0)		//checks to see if word from entry a comes before word from entry b
		return true;
	return false;
}

/*
	method compares the words from two entries
	returns true if first word comes after second word
		otherwise returns false
*/
bool sortDescending(const entry &a, const entry &b)
{
	if (strcasecmp(a.word.c_str(), b.word.c_str()) > 0)		//checks to see if first word from entry a comes after word from entry b
		return true;
	return false;
}

/*
	method checks number of occurrences between two entries
	returns true if entry a has more occurrences than entry b
*/
bool sortNumOccurrences(const entry &a, const entry &b)
{
	return a.number_occurences < b.number_occurences;
}