// Proj3.cpp
//
// Kim Jimenez
// Davis Catherman

#include "stdafx.h"
#include <cstdlib>
#include <string>
#include <algorithm>
#include <functional>
#include <fstream>
#include "common.h"
#include "vectorStuff.h"

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
	for (int i = 0; i < 10000; i++)
	{
		sort(wordVector.begin(), wordVector.end(), sortAscending);
		sort(wordVector.begin(), wordVector.end(), sortDecending);
		sort(wordVector.begin(), wordVector.end(), sortNumOccurrences);
	}
}

void printVectorAscending()
{
	sort(wordVector.begin(), wordVector.end(), sortDecending);
	
	ofstream myfile;
	//creates output file
	myfile.open("Vector.txt");

	for (entry x : wordVector)
	{
		//TODO: print to file
		myfile << x.word << ": " << x.number_occurences << endl;
	}

	//closes output file
	myfile.close();
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