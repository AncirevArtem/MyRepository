#include "stdafx.h"
#include "Dictionary.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream input1("text1.txt");
	Text *text1 = new Text();
	text1->ReadFromFile(input1);
	text1->normalize();
	Dictionary*FirtsDictionary = new Dictionary();
	FirtsDictionary->createDictionatyFromText(text1);
	system("pause");
    return 0;
}

