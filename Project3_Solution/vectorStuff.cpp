// Proj3.cpp
//
// Davis Catherman
// Kim Jimenez

#include "stdafx.h"
#include <cstdlib>							//c-string library
#include <string>							//string library
#include <algorithm>						//algorithm library
#include <functional>						//functional library 
#include <fstream>							//f-stream library
#include "common.h"							
#include "vectorStuff.h"

using namespace std;

vector<entry> wordVector;					//vector of entries

//method will add token into wordVector
void addTokenToVector(string token)
{
	entry temp = entry();					//temporary entry
	temp.word = token;						//word is set to token
	temp.number_occurences = 1;				//number of occurrences is set to 1
	wordVector.push_back(temp);				//entry is added to wordVector

}

//method will sort vector of entries
void sortVector()
{
	for (int i = 0; i < 10000; i++)
	{
		sort(wordVector.begin(), wordVector.end(), sortAscending);			//sorts vector in ascending order
		sort(wordVector.begin(), wordVector.end(), sortDecending);			//sorts vector in decending order
		sort(wordVector.begin(), wordVector.end(), sortNumOccurrences);		//sorts vector based on number of occurrences
	}
}

//method will print vector in Decending order
void printVectorDecending()
{
	sort(wordVector.begin(), wordVector.end(), sortDecending);			//sorts vector in decending order
	
	ofstream myfile;
	//creates output file
	myfile.open("Vector.txt");

	for (entry x : wordVector)
	{
		myfile << x.word << ": " << x.number_occurences << endl;
	}

	//closes output file
	myfile.close();
}

//method will remove duplicate entries
void removeVectorDuplicates()
{	//loops through the vector
	for (int i = 0; i < wordVector.size() - 1; i++)
	{
		for (int j = i + 1; j < wordVector.size(); j++)
		{
			string &wordI = wordVector.at(i).word;								//holds word from vector at index i
			string &wordJ = wordVector.at(j).word;								//holds word from vector at index j
			if (wordI != "" && strcasecmp(wordI.c_str(),wordJ.c_str()) == 0)	//compares both words regardless of case
			{
				wordJ = "";														//sets word at index j to ""
				wordVector.at(i).number_occurences++;							//number of occurrences at index i is incremented
			}
		}
	}
	sort(wordVector.begin(), wordVector.end(), sortDecending);		//vector is sorted in descending order

	while (wordVector.at(wordVector.size()-1).word == "")
	{
		wordVector.pop_back();										//entry is removed
	}
	
}