#include "stdafx.h"
#include "E_card_Vtb.h"
#include "E_card_AlfaBank.h"
#include "E_card_Sberbank.h"

int main()
{
	char*name = "Artem";
	E_card_Vtb Vtb(name);
	Vtb.showBalance();
	Vtb.depositByAtm(5000);
	Vtb.showBalance();
	system("pause");
    return 0;
}

