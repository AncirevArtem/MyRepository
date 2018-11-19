#include "stdafx.h"
#include "Dictionary.h"


Dictionary::Dictionary(){
	this->head = NULL;
	this->tail = NULL;
}

bool FirstLetterBeforeSecondLetter(char letterFirst, char letterSecond) {
	return letterFirst < letterSecond;
}

bool NewWordBeforeDictionaryWord(Word*newWord,Word* DictionaryWord) {
	char* dataNewWord = newWord->getData();
	char* dataDictionaryWord = DictionaryWord->getData();
	int count = 0;
	while (dataNewWord[count]!='\0' || dataDictionaryWord[count]!='\0') {
		if (FirstLetterBeforeSecondLetter(dataNewWord[count], dataDictionaryWord[count])) {
			return true;
		}
		else if (FirstLetterBeforeSecondLetter(dataDictionaryWord[count], dataNewWord[count])) {
			return false;
		}
		count++;
	}
	if (dataNewWord[count] == '\0' && dataDictionaryWord[count] == '\0') {
		return false;
	}
	else if (dataNewWord[count] == '\0') {
		return true;
	}
	else {
		return false;
	}
}

bool equallWords(Word*newWord, Word* DictionaryWord) {
	char* dataNewWord = newWord->getData();
	char* dataDictionaryWord = DictionaryWord->getData();
	int count = 0;
	while (dataNewWord[count] != '\0' || dataDictionaryWord[count] != '\0') {
		if (FirstLetterBeforeSecondLetter(dataNewWord[count], dataDictionaryWord[count])) {
			return false;
		}
		else if (FirstLetterBeforeSecondLetter(dataDictionaryWord[count], dataNewWord[count])) {
			return false;
		}
		count++;
	}
	if (dataNewWord[count] == '\0' && dataDictionaryWord[count] == '\0') {
		return true;
	}
	else if (dataNewWord[count] == '\0') {
		return false;
	}
	else {
		return false;
	}
}

void addWord(WordNode* newWord, WordNode* headDictionary) {
	WordNode*hellper = headDictionary->getPrevious();
	hellper->setNext(newWord);
	newWord->setPrevious(hellper);
	newWord->setNext(headDictionary);
	headDictionary->setPrevious(newWord);
}

void Dictionary::insertWord(WordNode* newWord){
	WordNode*current = this->head;
	bool wordIndictionary = false;
	if (NewWordBeforeDictionaryWord(newWord->getData(), current->getData())) {
		newWord->setNext(this->head);
		this->head->setPrevious(newWord);
		this->head = newWord;
	}
	else {
		while (current && !wordIndictionary) {
			if(equallWords(newWord->getData(), current->getData())){
				wordIndictionary = true;
			}
			if (NewWordBeforeDictionaryWord(newWord->getData(), current->getData())) {
				addWord(newWord, current);
				wordIndictionary = true;
			}
			current = current->getNext();
		}
		if (!wordIndictionary) {
			this->tail->setNext(newWord);
			newWord->setPrevious(this->tail);
			this->tail = newWord;
		}
	}
}

void Dictionary::addWordByRule(WordNode *word) {
	word->normalizeWord();
	WordNode* newWord = new WordNode(word->getData());
	if (head == NULL) {
		this->head = newWord;
		this->tail = newWord;
	}
	else {
		this->insertWord(newWord);
	}
}

void Dictionary::createDictionatyFromText(Text *Text){
	Text->normalize();
	WordNode*hellper = Text->getHead();
	while (hellper) {
		this->addWordByRule(hellper);
		hellper = hellper->getNext();
	}
}
