
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

	cout << "lenOfTags: " << lenOfTags << endl;
	// iterate through the data, subtract length of tags to not go out of bounds
	for (int i = 0; i <= strlen(pDataToSearchThru) - lenOfTags; i++)
	{
		//cout << "pData: " << pDataToSearchThru[i] << endl;
		// check if current char is equal to pStartTag[0]
		if (pDataToSearchThru[i] == this->pStartTag[0])
		{
			// keep track of if tag was found
			bool foundStartTag = true;

			// parse through data for length of tag
			for (int j = 1; j < strlen(pStartTag); j++)
			{
				// if 1 val pt is not equal, then not a start tag
				if (pDataToSearchThru[i + j] != pStartTag[j])
				{
					foundStartTag = false;
				}
			}

			if (foundStartTag == true)
			{
				// should be the 1st char of the data, or if no data, 1st char of pEndTag
				startOfData = i + strlen(pStartTag);
			}

			// TODO: Find pEndTag
			// TODO: implement error messages
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
