// Proj3.cpp
//
// Kim Jimenez
// Davis Catherman

#pragma once

#include <string>
#include "common.h"

extern int wordCount;
extern entry wordArray[10000];

void addTokenToArray(std::string token);
void sortArray();
void printArrayAscending();
void removeArrayDuplicates();