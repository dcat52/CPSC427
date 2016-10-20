
#include <string>
#include "..\Include\stringparserClass.h"
#include "..\Include\FileReader.h"
#include "..\Include\constants.h"
#include "..\Include\Debug_Help.h"

using namespace std;
using namespace KP_StringParserClass;

StringParserClass::StringParserClass(void)
{
	setTags(START_TAG, END_TAG);
	areTagsSet = false;
	lastError = UNINITIALIZED;
}

StringParserClass::~StringParserClass(void)
{
	// be safe
	cleanup();
}

int StringParserClass::getLastError()
{
	return lastError;
}

bool StringParserClass::setTags(const char * pStartTag, const char * pEndTag)
{
	this->pStartTag = (char*)pStartTag;
	this->pEndTag = (char*)pEndTag;
	return true;
}

// TODO: Test This Method
bool StringParserClass::getDataBetweenTags(char * pDataToSearchThru, vector<string>& myVector)
{
	// get length of tags for use in the for loop
	int lenOfTags = strlen(this->pStartTag) + strlen(this->pEndTag);
	int startOfData = UNINITIALIZED;
	int endOfData = UNINITIALIZED;

	// iterate through the data, subtract length of string to not go out of bounds
	for (int i = 0; i < strlen(pDataToSearchThru) - lenOfTags; i++)
	{
		// check if current char and beyond is equal to pStartTag
		if (pDataToSearchThru[i] == *this->pStartTag)
		{
			// should be the 1st char of the data, or if no data, 1st char of pEndTag
			startOfData = i + strlen(pStartTag);
		}
	}

	return false;
}

void StringParserClass::cleanup()
{
}

bool StringParserClass::findTag(char * pTagToLookFor, char *& pStart, char *& pEnd)
{
	return false;
}
