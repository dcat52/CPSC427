#pragma once

#include <string>
#include "common.h"

extern int wordCount;
extern entry wordArray[1000000];

void addTokenToArray(std::string token);
void sortArray();
void printArrayAscending();
void removeArrayDuplicates();