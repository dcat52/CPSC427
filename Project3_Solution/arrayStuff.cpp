#include "stdafx.h"
#include <string>
#include <algorithm>
#include <iostream>
#include "arrayStuff.h"
#include "common.h"

using namespace std;

entry* noDupsArray;
entry wordArray[1000000];
int wordCount = 0;
void addTokenToArray(std::string token)
{
	entry temp = entry();
	temp.word = token;
	temp.number_occurences = 1;
	wordArray[wordCount] = temp;
	wordCount++;
}

void sortArray()
{
	cout << "sort Array" << endl;
	for (int i = 0; i < 100; i++)
	{
		sort(noDupsArray.begin(), end(noDupsArray), sortAscending);
		sort(noDupsArray, noDupsArray + sizeof(noDupsArray), sortDecending);
		sort(noDupsArray, noDupsArray + sizeof(noDupsArray), sortNumOccurrences);
	}
	cout << "sort Array v2" << endl;
}

void printArrayAscending()
{
	cout << "print array ascending" << endl;
	sort(noDupsArray, noDupsArray + sizeof(noDupsArray), sortAscending);
	for (int i = 0; i < sizeof(noDupsArray); i++)
	{
		//TODO: print to file
		entry temp = noDupsArray[i];
		cout << temp.word << ": " << temp.number_occurences << "\n";
	}
}

void removeArrayDuplicates()
{
	int numberDeleted = 0;

	for (int i = 0; i < wordCount - 1; i++)
	{
		for (int j = i + 1; j < wordCount; j++)
		{
			//if the current index's word and the next word are exactly the same then...
			if (wordArray[i].word != "" && strcasecmp(wordArray[i].word.c_str(), wordArray[j].word.c_str()) == 0)
			{
				wordArray[j].word = "";					//empty string
				wordArray[i].number_occurences++;		//the number of times the word appears will increment
				numberDeleted++;				    //the number of words that is deleted will increment
			}
		}
	}

	sort(wordArray, wordArray + wordCount, sortAscending);
	noDupsArray = new entry[wordCount - numberDeleted+1];
	int j = 0;
	for (int i = numberDeleted; i < wordCount; i++)
	{
		noDupsArray[j] = wordArray[i];
		j++;
	}
}