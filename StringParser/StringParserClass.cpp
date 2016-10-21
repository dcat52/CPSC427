
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
	lastError = ERROR_NO_ERROR;
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
	if (strlen(this->pStartTag) == 0 || strlen(this->pEndTag) == 0) {
		this->lastError = ERROR_TAGS_NULL;
		return false;
	}
	// get length of tags for use in the for loop
	int lenOfTags = strlen(this->pStartTag) + strlen(this->pEndTag);
	int startOfData = UNINITIALIZED;
	int endOfData = UNINITIALIZED;

	cout << "lenOfTags: " << lenOfTags << endl;
	// iterate through the data, subtract length of tags to not go out of bounds

	bool foundStartTag = false;
	for (int i = 0; i <= strlen(pDataToSearchThru) - strlen(this->pEndTag); i++)
	{
		//cout << "pData: " << pDataToSearchThru[i] << endl;
		// check if current char is equal to pStartTag[0]
		if (pDataToSearchThru[i] == this->pStartTag[0])
		{

			// keep track of if tag was found
			bool foundPotentialStartTag = true;

			// parse through data for length of tag
			for (int j = 1; j < strlen(pStartTag); j++)
			{
				// if 1 val pt is not equal, then not a start tag
				if (pDataToSearchThru[i + j] != pStartTag[j])
				{
					foundPotentialStartTag = false;
				}
			}

			if (foundPotentialStartTag == true)
			{
				foundStartTag = true;
				// should be the 1st char of the data, or if no data, 1st char of pEndTag
				startOfData = i + strlen(pStartTag);

				cout << "Start of Data: " << startOfData << endl;
			}
		}

		//cout << "pData: " << pDataToSearchThru[i] << endl;
		// check if current char is equal to pEndTag[0]
		if (foundStartTag && pDataToSearchThru[i] == this->pEndTag[0])
		{
			// keep track of if tag was found
			bool foundEndTag = true;

			// parse through data for length of tag
			for (int j = 1; j < strlen(pEndTag); j++)
			{
				// if 1 val pt is not equal, then not a start tag
				if (pDataToSearchThru[i + j] != pEndTag[j])
				{
					foundEndTag = false;
				}
			}

			if (foundEndTag == true)
			{
				// should be the end of data
				endOfData = i;
				// get the string of data
				string data = &pDataToSearchThru[startOfData];
				data = data.substr(0, endOfData-startOfData);
				// if data is not null
				if (data.size() != 0)
					myVector.push_back(data);
				else
					this->lastError = ERROR_DATA_NULL;

				foundStartTag = false;
				foundEndTag = false;

				cout << "End of Data: " << endOfData << endl;
			}
		}

		// TODO: implement rest of error messages
	}

	if(myVector.size() != 0)
		return true;
	return false;
}

void StringParserClass::cleanup()
{
}

bool StringParserClass::findTag(char * pTagToLookFor, char *& pStart, char *& pEnd)
{
	return false;
}
