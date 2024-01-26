#include "Withdrawal.h"

#include <iostream>
#include <iomanip>

Withdrawal::Withdrawal(int userAccountNumber, vector< Account >& atmAccounts, int& atmRemainingBills)
	:accountNumber(userAccountNumber), accounts(atmAccounts), remainingBills(atmRemainingBills)
{
}

Account* Withdrawal::getAccount(int accountNumber, vector< Account >& accounts)
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

void Withdrawal::execute()
{
	int choice = 0;
	Account* const m = getAccount(accountNumber, accounts);
	while (choice == 0) {
		using std::cin; using std::cout; using std::endl; using std::setw;
		cout << "Withdrawal options:" << endl;
		cout << "1 - $20" << endl;
		cout << "2 - $40" << endl;
		cout << "3 - $60" << endl;
		cout << "4 - $100" << endl;
		cout << "5 - $200" << endl;
		cout << "6 - Cancel transaction" << endl << endl;
		cout << "Choose a withdrawal option (1-6): ";
		cin >> choice;
		switch (choice) {
		case 1:
			if (m->getAvailableBalance() < 20.0) {
				cout << "Money not enough ,choose a smaller amount" << endl;
				choice = 0;
			}
			else {
				m->debit(20);
				remainingBills -= 20;
				cout << "Please take your cash from the cash dispenser." << endl << endl;
			}
			break;
		case 2:
			if ((int)m->getAvailableBalance() < 40.0) {
				cout << "Money not enough ,choose a smaller amount" << endl;
				choice = 0;
			}
			else {
				m->debit(40);
				cout << "Please take your cash from the cash dispenser." << endl << endl;
				remainingBills -= 40;
			}
			break;
		case 3:
			if ((int)m->getAvailableBalance() < 60.0) {
				cout << "Money not enough ,choose a smaller amount" << endl;
				choice = 0;
			}
			else {
				m->debit(60);
				remainingBills -= 60;
				cout << "Please take your cash from the cash dispenser." << endl << endl;
			}
			break;
		case 4:
			if (m->getAvailableBalance() < 100.0) {
				cout << "Money not enough ,choose a smaller amount" << endl;
				choice = 0;
			}
			else {
				m->debit(100);
				remainingBills -= 100;
				cout << "Please take your cash from the cash dispenser." << endl << endl;
			}
			break;
		case 5:
			if (m->getAvailableBalance() < 200.0) {
				cout << "Money not enough ,choose a smaller amount" << endl;
				choice = 0;
			}
			else {
				m->debit(200);
				remainingBills -= 200;
				cout << "Please take your cash from the cash dispenser." << endl << endl;
			}
			break;
		case 6:
			break;
		}
		

	}

}






