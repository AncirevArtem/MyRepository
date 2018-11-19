#include "stdafx.h"
#include "Text.h"
#include "WordNode.h"
#include <fstream>
#include <iostream>
using namespace std;

bool isLetter(char a) {
	return (a >= 'a') && (a <= 'z') || (a >= 'A') && (a <= 'Z');
}

bool isNotSpace(char a) {
	return (a != ' ');
}

bool isWord(Word *data) {
	char*word = data->getData();
	return isLetter(word[0]);
}

WordNode* delWordFromText(WordNode *deletedWord) {
	WordNode* hellper = deletedWord->getPrevious();
	hellper->setNext(deletedWord->getNext());
	hellper = hellper->getNext();
	hellper->setPrevious(deletedWord->getPrevious());
	delete deletedWord;
	return hellper->getPrevious();
}

char* wordCreating(char*word, int size) {
	char *newWord = new char[size+1];
	int i = 0;
	for (i = 0; i < size; ++i) {
		newWord[i] = word[i];
	}
	newWord[i] = '\0';
	return newWord;
}

char*wordCreating(char sign, int size) {
	char *newWord = new char[size + 1];
	newWord[0] = sign;
	newWord[1] = '\0';
	return newWord;
}

Text::Text(){
	this->head = NULL;
	this->tail = NULL;
}

void Text::push(char *data){
	WordNode *newWord = new WordNode(data);
	if (this->tail == NULL) {
		this->tail = newWord;
		this->head = newWord;
	}
	else {
		newWord->setPrevious(this->tail);
		this->tail->setNext(newWord);
		this->tail = newWord;
	}
}

void Text::ReadFromFile(ifstream &input){
	char letter;
	char hellperWord[30];
	int hellperSize = 0;
	while (!input.eof()) {
		input.get(letter);
		if (isLetter(letter)) {
			hellperWord[hellperSize] = letter;
			hellperSize++;
		}
		else if(isNotSpace(letter)){
			if (hellperSize != 0) {
				this->push(wordCreating(hellperWord,hellperSize));
				hellperSize = 0;
				this->push(wordCreating(letter, 1));
			}
			else {
				this->push(wordCreating(letter, 1));
			}
		}
		else {
			if (hellperSize != 0) {
				this->push(wordCreating(hellperWord, hellperSize));
				hellperSize = 0;
			}
		}
	}
	if (hellperSize != 0) {
		this->push(wordCreating(hellperWord, hellperSize));
		hellperSize = 0;
	}
	input.close();
}

void Text::normalize(){
	WordNode*current = this->head;
	WordNode*hellper = this->head;
	if (!isWord(this->head->getData())) {
		current = current->getNext();
		current->setPrevious(NULL);
		delete hellper;
		this->head = current;
		hellper = current;
	}
	while (current->getNext()) {
		if (!isWord(current->getData())) {
			current = delWordFromText(current);
		}
		current = current->getNext();
	}
	if (!isWord(this->tail->getData())) {
		current = tail->getPrevious();
		current->setNext(NULL);
		delete tail;
		this->tail = current;
	}
}

WordNode * Text::getHead(){
	return this->head;
}

