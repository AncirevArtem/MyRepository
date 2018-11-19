#include "stdafx.h"
#include "WordNode.h"
#include "Word.h"


WordNode::WordNode(char *data){
	Word *newWord = new Word(data);
	this->next = NULL;
	this->previous = NULL;
	this->data = newWord;
}

WordNode::WordNode(Word * data){
	this->data = data;
	this->next = NULL;
	this->previous = NULL;
}

void WordNode::setNext(WordNode * next){
	this->next = next;
}

void WordNode::setPrevious(WordNode * previous){
	this->previous = previous;
}

WordNode * WordNode::getNext(){
	return this->next;
}

WordNode * WordNode::getPrevious(){
	return this->previous;
}

Word * WordNode::getData(){
	return this->data;
}

void WordNode::normalizeWord() {
	char *hellper = this->data->getData();
	for (int i = 0; hellper[i] != '\0'; ++i) {
		if (hellper[i] >= 'A'&&hellper[i] <= 'Z') {
			hellper[i] +=32;
		}
	}
}

