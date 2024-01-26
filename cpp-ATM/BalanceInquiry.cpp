#include "BalanceInquiry.h"
#include <iostream>
#include <iomanip>
BalanceInquiry::BalanceInquiry(int userAccountNumber, vector< Account >& atmAccounts)
	:accountNumber(userAccountNumber), accounts(atmAccounts)
{
}

Account* BalanceInquiry::getAccount(int accountNumber, vector< Account >& accounts)
{
	// loop through accounts searching for matching account number
	for (size_t i = 0; i < accounts.size(); i++)
	{
		// return current account if match found
		if (accounts[i].getAccountNumber() == accountNumber)
			return &accounts[i];
	} // end for

	return NULL; // if no matching account was found, return NULL
}
void BalanceInquiry::execute()
{
	using namespace std;
	Account* m = getAccount(accountNumber, accounts);
	cout << "Balance Information:" << endl;
	cout << "- Avaliable balance: $" << setprecision(2) << fixed << m->getAvailableBalance() << endl;
	cout << "- Total balance:     $" << setprecision(2) << fixed << m->getTotalBalance() << endl;
	cout << endl;
}


