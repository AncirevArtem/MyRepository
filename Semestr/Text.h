#pragma once
#include "WordNode.h"
#include <fstream>
using namespace std;
class Text
{
private:
	WordNode *tail;
	WordNode *head;
public:
	Text();
	void push(char *data);
	void ReadFromFile(ifstream &input);
	void normalize();
	WordNode* getHead();
};

