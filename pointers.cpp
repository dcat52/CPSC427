// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int a = 9;
	int *x = &a;
	cout << "a is set to 9" << endl;
	cout << "*x is set to &a" << endl << endl;
	cout << "a:\t" << a << endl;
	cout << "&a:\t" << &a << endl;
	cout << "x:\t" << x << endl;
	cout << "&x:\t" << &x << endl;
	cout << "*x:\t" << *x << endl << endl;

	int **y = &x;
	cout << "**y is set to &x" << endl << endl;
	cout << "y:\t" << y << endl;
	cout << "&y:\t" << &y << endl;
	cout << "*y:\t" << *y << endl;
	cout << "**y:\t" << **y << endl;
	return 0;
}

