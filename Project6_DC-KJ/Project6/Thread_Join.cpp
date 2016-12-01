#include "stdafx.h"
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <sstream>
#include <fstream>
#include "..\includes\String_Database.h"
#include "..\includes\DataStore_File.h"
#include "..\includes\Crypto_AES.h"

const int TOTAL_ADDED_PER_THREAD	=20;
const int TOTAL_THREADS				=20;
const std::string ENCRYPT_FILE1 = "Encryptfile1.txt";
const std::string ENCRYPT_FILE2 = "Encryptfile2.txt";

const std::string NO_ENCRYPT_FILE1 = "noEncryptfile1.txt";
const std::string NO_ENCRYPT_FILE2 = "noEncryptfile2.txt";

const int NUMBER_TIMES_TO_ADD_STRING = 20;

//I've provided some hints in the form of comments and commented out code
//use them if you wish

////global database object 
String_Database myGlobalCache;
String_Database myGlobalCache2;

void cmpFiles(const std::string &MYFILE1, const std::string &MYFILE2) {
	std::fstream f1;
	std::fstream f2;
	std::string str1;
	std::string str2;

	vector<std::string> f1v;
	vector<std::string> f2v;

	f1.open(MYFILE1);
	if (f1.is_open())
	{
		while (getline(f1, str1)) {
			f1v.push_back(str1);
		}
	}
	f1.close();

	f2.open(MYFILE2);
	if (f2.is_open())
	{
		while (getline(f2, str2)) {
			f2v.push_back(str2);
		}
	}
	f2.close();
	
	bool same = true;

	if(f1v.size() != f2v.size())
		same = false;

	for(int i = 0; i < f1v.size() && i < f2v.size(); i++) {

		if (f1v.at(i) == f2v.at(i)) {
			same = false;
		}
	}
	
	std::cout << "files are same: ";
	if (same)
		std::cout << "true\n";
	else
		std::cout << "false\n";

}

//will add myString numbTimes to myGlobalCache
void ThreadFunc(int numbTimes, std::string myString) 
{
	for (int i = 0; i < numbTimes; i++)
	{
		myGlobalCache.add(myString);
	}
}
void ThreadFunc2(int numbTimes, std::string myString)
{
	for (int i = 0; i < numbTimes; i++)
	{
		myGlobalCache2.add(myString);
	}
}

void testSerialization(const std::string &MYFILE1, const std::string &MYFILE2, Crypto *pCrypto){
	DataStore_File myDataStore_File1(MYFILE1,pCrypto);
	myGlobalCache.save(&myDataStore_File1);

	//clear cache
	myGlobalCache.clear();

	//load it
	myGlobalCache.load(&myDataStore_File1);
	
	//save to a different file
	DataStore_File myDataStore_File2(MYFILE2,pCrypto);
	myGlobalCache.save(&myDataStore_File2);

	cmpFiles(MYFILE1, MYFILE2);
	//I use my own objects here to compare the files
}

// test code, yay
int main() 
{
	//I created and run a bunch(20) of threads that use ThreadFunc above 
	vector<string> tests;
	tests.push_back("testString");
	tests.push_back("abcxyz123");
	tests.push_back("Davis is cool");
	tests.push_back("PerkinsFBis lit");
	tests.push_back("more cool stuff");
	tests.push_back("fun stuff");
	tests.push_back("I Hate SArah");
	std::string rand = "randomNoExist";

	std::vector<std::thread> threads;

	int j = 0;
	for (int i = 0; i < tests.size(); i++) {
		threads.push_back(std::thread(ThreadFunc, j, tests.at(i)));
		threads.push_back(std::thread(ThreadFunc, 1, tests.at(3)));
		threads.push_back(std::thread(ThreadFunc, 10, tests.at(4)));
		threads.push_back(std::thread(ThreadFunc, 100, tests.at(5)));
		j += 1000;
	}

	for (int i = tests.size()-2; i < tests.size(); i++) {
		threads.push_back(std::thread(ThreadFunc2, j, tests.at(i)));
		j += 1000;
	}
	//make em all wait to do work

	//Then I wait for all of them to finish so my program does not crash
	for (auto& thread : threads) {
		thread.join();
	}
	
	//Then I go through myGlobalCache and make sure that it holds the correct data
	std::cout << "myGlobalCache:"<<endl;
	for (int i = 0; i < tests.size(); i++) {
		std::cout << tests.at(i) << "\t\t: count: " << myGlobalCache.getCount(tests.at(i)) << endl;
	}
	std::cout << endl << "myGlobalCache2:"<<endl;
	for (int i = tests.size()-2; i < tests.size(); i++) {
		std::cout << tests.at(i) << "\t\t: count: " << myGlobalCache2.getCount(tests.at(i)) << endl;
	}
	std::cout << endl << "none:"<<endl;
	std::cout << rand << "\t\t: count: " << myGlobalCache.getCount(rand) << endl;


	//then I test that serialization works correctly
	//first without encryption, 
	testSerialization(NO_ENCRYPT_FILE1, NO_ENCRYPT_FILE2, 0);

	//then with
	Crypto_AES myCrypto2("I Like Rollos   ");
	testSerialization(ENCRYPT_FILE1, ENCRYPT_FILE2, &myCrypto2);

}