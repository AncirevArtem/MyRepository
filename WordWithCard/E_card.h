#pragma once
class E_card
{
protected:
	char usersFirstName[15];
	char usersSecondName[15];
	char usersPatronymic[15];
	int  requisites;
	int balance;
	void clearUserName(char*name);
	bool isCardOfSberbank(char*bankName);
	bool isCardOfAlfaBank(char*bankName);
	bool isCardOfVtb(char*bankName);
	void normalizeWord(char*bankName);
	void removalByPercent(const int total, int percent);
	void removalWithoutPercent(const int total);
public:
	E_card(char *usersFirstName);
	E_card(char *usersFirstName ,char *usersSecondName);
	E_card(char *usersFirstName ,char *usersSecondName, char *usersPatronymic);
	int getBalance();
	virtual void depositByAtm(const int total)=0;
	void showBalance();
};

