
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
	//be safe
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

bool StringParserClass::getDataBetweenTags(char * pDataToSearchThru, vector<string>& myVector)
{
	for (int i = 0; i < strlen(pDataToSearchThru); i++)
	{
		//findTag(this->pStartTag, pDataToSearchThru, pDataToSearchThru);
		//if (pDataToSearchThru[i] == 
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
