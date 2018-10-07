// Proj3.cpp
//
// Davis Catherman
// Kim Jimenez


#pragma once

#include <string>				//string library
#include <vector>				//vector library
#include "common.h"

extern std::vector<entry> wordVector;		//vector of entries
void addTokenToVector(std::string token);	//method will add token to vector
void sortVector();							//method will sort vector
void printVectorDescending();				//method will print out vector in Descending order
void removeVectorDuplicates();				//method will remove duplicate words