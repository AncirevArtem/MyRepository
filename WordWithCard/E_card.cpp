#include "stdafx.h"
#include "E_card.h"
#include <iostream>
using namespace std;

void E_card::clearUserName(char*name){
	for (int i = 0; i< 15; ++i) {
		name[i] = ' ';
	}
}

bool E_card::isCardOfSberbank(char * bankName)
{
	char *sberbank = "sberbank";
	int i = 0;
	for ( i = 0; sberbank[i] != '\0' || bankName[i] !='\0' ; ++i) {
		if (sberbank[i] != bankName[i]) {
			return false;
		}
	}
	if (sberbank[i] == bankName[i]) {
		return true;
	}
	else {
		return false;
	}
}

bool E_card::isCardOfAlfaBank(char * bankName)
{
	char *alfabank = "alfabank";
	int i = 0;
	for (i = 0; alfabank[i] != '\0' || bankName[i] != '\0'; ++i) {
		if (alfabank[i] != bankName[i]) {
			return false;
		}
	}
	if (alfabank[i] == bankName[i]) {
		return true;
	}
	else {
		return false;
	}
}

bool E_card::isCardOfVtb(char * bankName){
	char *vtb = "vtb";
	int i = 0;
	for (i = 0; vtb[i] != '\0' || bankName[i] != '\0'; ++i) {
		if (vtb[i] != bankName[i]) {
			return false;
		}
	}
	if (vtb[i] == bankName[i]) {
		return true;
	}
	else {
		return false;
	}
}

E_card::E_card(char * usersFirstName){
	int i = 0;
	for (i = 0; usersFirstName[i] != '\0'; ++i) {
		this->usersFirstName[i] = usersFirstName[i];
	}
	this->usersFirstName[i] = '\0';
	clearUserName(this->usersSecondName);
	clearUserName(this->usersPatronymic);
	this->balance = 0;
}

E_card::E_card(char * usersFirstName, char * usersSecondName){
	int i = 0;
	for (i = 0; usersFirstName[i] != '\0'; ++i) {
		this->usersFirstName[i] = usersFirstName[i];
	}
	this->usersFirstName[i] = '\0';
	for (i = 0; usersSecondName[i] != '\0'; ++i) {
		this->usersSecondName[i]=usersSecondName[i];
	}
	this->usersSecondName[i] = '\0';
	clearUserName(this->usersPatronymic);
	this->balance = 0;
}

E_card::E_card(char * usersFirstName, char * usersSecondName, char *usersPatronymic){
	int i = 0;
	for (i = 0; usersFirstName[i] != '\0'; ++i) {
		this->usersFirstName[i] = usersFirstName[i];
	}
	this->usersFirstName[i] = '\0';

	for (i = 0; usersSecondName[i] != '\0'; ++i) {
		this->usersSecondName[i] = usersSecondName[i];
	}
	this->usersSecondName[i] = '\0';

	for (i = 0; usersPatronymic[i] != '\0'; ++i) {
		this->usersPatronymic[i] = usersSecondName[i];
	}
	this->usersPatronymic[i] = '\0';

	this->balance = 0;
}

int E_card::getBalance(){
	return balance;
}

void E_card::showBalance(){
	cout << "You`re balance = " << this->getBalance() << endl;
}

void E_card::normalizeWord(char * bankName){
	for (int i = 0; bankName[i] != '\0'; ++ i) {
		if (bankName[i] >= 'A'&&bankName[i] <= 'Z') {
			bankName[i] += 32;
		}
	}
}

void E_card::removalByPercent(const int total, int percent){
	this->balance = total - (total/100*percent);
}

void E_card::removalWithoutPercent(const int total){
	this->balance = total;
}

