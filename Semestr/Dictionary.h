#pragma once
#include "WordNode.h"
#include "Text.h"
class Dictionary
{
private:
	void insertWord(WordNode*newWord);
	WordNode *tail;
	WordNode *head;
public:
	Dictionary();
	void addWordByRule(WordNode* word);
	void createDictionatyFromText(Text *Text);
};

