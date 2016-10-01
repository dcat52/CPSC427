#include "stdafx.h"
#include <cstdlib>
#include <string>
#include <algorithm>
#include <functional>
#include "common.h"
#include "vectorStuff.h"

using namespace std;

std::vector<entry> wordVector;
void addTokenToVector(string token)
{
	entry temp = entry();
	temp.word = token;
	temp.number_occurences = 1;
	wordVector.push_back(temp);

}

void sortVector()
{
	sort(wordVector.begin(), wordVector.end(), compareWords );
}

bool compareWords(const entry &a, const entry &b)
{
	return a.word < b.word;
}