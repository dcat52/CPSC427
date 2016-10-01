#pragma once

#include <string>
#include <vector>
#include "common.h"

extern std::vector<entry> wordVector;
void addTokenToVector(std::string token);
void sortVector();

bool compareWords(const entry &a, const entry &b);