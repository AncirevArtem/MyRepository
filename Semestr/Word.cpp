#include "stdafx.h"
#include "Word.h"


Word::Word(char *data){
	this->data = data;
}

Word::Word(){
}

char* Word::getData(){
	return this->data;
}
