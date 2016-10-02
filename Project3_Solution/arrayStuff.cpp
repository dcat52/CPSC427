// Proj3.cpp
//
// Davis Catherman
// Kim Jimenez

#include "stdafx.h"
#include <string>
#include <algorithm>
#include <fstream>
#include "arrayStuff.h"
#include "common.h"

using namespace std;

entry* noDupsArray;											//entry array with no duplicates
entry wordArray[10000];										//entry array of size 10000
int wordCount = 0;											//initial word count set to 0
int numberDeleted = 0;										//initial number of words deleted

//method takes in string and is added to wordArray
void addTokenToArray(std::string token)						
{
	wordArray[wordCount].word = token;						//word of entry at position indicated is set to token
	wordArray[wordCount].number_occurences++;				//number of occurrences is incremented
	wordCount++;											//wordCount is incremented
}

//method sorts array 
void sortArray()
{	//loops through the entire array 
	for (int i = 0; i < 10000; i++)
	{
		sort(wordArray, wordArray + wordCount - numberDeleted, sortAscending);				//sorts array in ascending order
		sort(wordArray, wordArray + wordCount - numberDeleted, sortDecending);				//sorts array in descending order
		sort(wordArray, wordArray + wordCount - numberDeleted, sortNumOccurrences);			//sorts array based on number of occurrences
	}
}

/*method sorts array in ascending order
  (i.e. ABC order regardless of case
*/
void printArrayAscending()
{
	sort(wordArray, wordArray + wordCount - numberDeleted, sortDecending);

	ofstream myfile;
	//creates output file
	myfile.open("Array.txt");

	//loops through the array from index 0 to wordCount-numberDeleted
	for (int i = 0; i < wordCount - numberDeleted; i++)
	{
		//TODO: print to file
		entry temp = wordArray[i];
		myfile << temp.word << ": " << temp.number_occurences << endl;
	}

	//closes output file
	myfile.close();
}

//method removes duplicate words
void removeArrayDuplicates()
{
	//loops through the array
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