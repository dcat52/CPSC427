// Proj3.cpp
//
// Kim Jimenez
// Davis Catherman

#include "stdafx.h"
#include <string>
#include <algorithm>
#include <fstream>
#include "arrayStuff.h"
#include "common.h"

using namespace std;

entry* noDupsArray;
entry wordArray[10000];
int wordCount = 0;
int numberDeleted = 0;
void addTokenToArray(std::string token)
{
	wordArray[wordCount].word = token;
	wordArray[wordCount].number_occurences++;
	wordCount++;
}

void sortArray()
{
	for (int i = 0; i < 10000; i++)
	{
		sort(wordArray, wordArray + wordCount - numberDeleted, sortAscending);
		sort(wordArray, wordArray + wordCount - numberDeleted, sortDecending);
		sort(wordArray, wordArray + wordCount - numberDeleted, sortNumOccurrences);
	}
}

void printArrayAscending()
{
	sort(wordArray, wordArray + wordCount - numberDeleted, sortDecending);

	ofstream myfile;
	//creates output file
	myfile.open("Array.txt");

	for (int i = 0; i < wordCount - numberDeleted; i++)
	{
		//TODO: print to file
		entry temp = wordArray[i];
		myfile << temp.word << ": " << temp.number_occurences << endl;
	}

	//closes output file
	myfile.close();
}

void removeArrayDuplicates()
{

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

	sort(wordArray, wordArray + wordCount, sortDecending);
}