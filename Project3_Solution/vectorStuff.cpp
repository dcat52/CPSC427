#include "stdafx.h"
#include <cstdlib>
#include <string>
#include <algorithm>
#include <functional>
#include <iostream>
#include "common.h"
#include "vectorStuff.h"

#define strcasecmp _stricmp

using namespace std;

vector<entry> wordVector;
void addTokenToVector(string token)
{
	entry temp = entry();
	temp.word = token;
	temp.number_occurences = 1;
	wordVector.push_back(temp);

}

void sortVector()
{
	sort(wordVector.begin(), wordVector.end(), sortAscending);
	sort(wordVector.begin(), wordVector.end(), sortDecending);
	sort(wordVector.begin(), wordVector.end(), sortNumOccurences);
}

void printVectorAscending()
{
	sort(wordVector.begin(), wordVector.end(), sortAscending);
	for (entry x : wordVector)
	{
		//TODO: print to file
		cout << x.word << ":\t" << x.number_occurences << "\n";
	}
}

void removeVectorDuplicates()
{
	for (int i = 0; i < wordVector.size() - 1; i++)
	{
		for (int j = i + 1; j < wordVector.size(); j++)
		{
			string &wordI = wordVector.at(i).word;
			string &wordJ = wordVector.at(j).word;
			if (wordI != "" && strcasecmp(wordI.c_str(),wordJ.c_str()) == 0)
			{
				wordJ = "";
				wordVector.at(i).number_occurences++;
			}
		}
	}
	sort(wordVector.begin(), wordVector.end(), sortDecending);

	while (wordVector.at(wordVector.size()-1).word == "")
	{
		wordVector.pop_back();
	}
	
}