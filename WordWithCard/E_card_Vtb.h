#pragma once
#include"E_card.h"
#include<iostream>
using namespace std;

class E_card_Vtb : public E_card{
private:
	const int percentForSberbank = 2;
	const int percentForAlfaBank = 1;
public:
	E_card_Vtb(char *usersFirstName) : E_card(usersFirstName) {};
	E_card_Vtb(char *usersFirstName, char *usersSecondName) : E_card(usersFirstName, usersSecondName) {};
	E_card_Vtb(char *usersFirstName, char *usersSecondName, char *usersPatronymic) : E_card(usersFirstName, usersSecondName, usersPatronymic) {};
	void depositByAtm(const int total) {
		char bankName[20];
		bool depositSuccess = false;
		while (!depositSuccess) {
			cout << "Plese enter the banks name of ATM" << endl;
			cin.getline(bankName, 20);
			this->normalizeWord(bankName);
			if (this->isCardOfAlfaBank(bankName)) {
				this->removalByPercent(total,this->percentForAlfaBank);
				depositSuccess = true;
				cout << "Successful completion" << endl;
			}
			else if (this->isCardOfSberbank(bankName)) {
				this->removalByPercent(total, this->percentForSberbank);
				depositSuccess = true;
				cout << "Successful completion" << endl;
			}
			else if (this->isCardOfVtb(bankName)) {
				this->removalWithoutPercent(total);
				depositSuccess = true;
				cout << "Successful completion" << endl;
			}
		}
	}


};

