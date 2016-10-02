// Proj3.cpp
//
// Davis Catherman
// Kim Jimenez

#pragma once

#include <string>
#include "common.h"

extern int wordCount;						//counts total number of words in file
extern entry wordArray[10000];				//array of entries with size of 10000

void addTokenToArray(std::string token);	//method that adds token to array
void sortArray();							//method that sorts array
void printArrayDecending();					//method prints array with words in ascending order
void removeArrayDuplicates();				//method removes duplicate words from array