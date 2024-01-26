#include "Deposit.h"
#include <iostream>
#include <iomanip>
Deposit::Deposit(int userAccountNumber, vector< Account >& atmAccounts)
	:accountNumber(userAccountNumber), accounts(atmAccounts)
{

}
Account* Deposit::getAccount(int accountNumber, vector< Account >& accounts)
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


void Deposit::execute()
{

	Account* const m = getAccount(accountNumber, accounts);
	using std::cin; using std::cout; using std::endl; using std::setw; using std::setprecision; using std::fixed;
	cout << "Please enter a deposit amount in CENTS (or 0 to cancel):  " << endl;
	double enter;
	cin >> enter;
	enter /= 100;
	cout << "Please insert a deposit envelope containing $" << setprecision(2) << fixed << enter << "in the deposit slot." << endl;
	cout << "Your envelope has been received." << endl;
	m->credit(enter);
	cout << "NOTE: The money deposited will not be available until we" << endl;
	cout << "verify the amount of any enclosed cash, and any enclosed checks clear" << endl << endl;
}