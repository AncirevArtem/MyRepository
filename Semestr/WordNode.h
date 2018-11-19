#pragma once
#include "Word.h"
class WordNode
{
private:
	WordNode *next;
	WordNode *previous;
	Word *data;
public:
	WordNode(char *data);
	WordNode(Word *data);
	void setNext(WordNode *next);
	void setPrevious(WordNode *previous);
	WordNode *getNext();
	WordNode *getPrevious();
	Word *getData();
	void normalizeWord();
};

