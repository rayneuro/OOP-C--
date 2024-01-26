#ifndef ATM_H_
#define ATM_H_

#include <iostream>

class member
{
public:
	member() {
	}
	member(int a, int pin, double ab, double tb) :
		account(a), PIN_num(pin), avaliable(ab), total(tb) {}
	int account;
	member& operator=(const member &right)
	{
		account = right.account;
		PIN_num = right.PIN_num;
		avaliable = right.avaliable;
		total = right.total;
		return *this;
	}
	int PIN_num;
	double avaliable;
	double total;
};


class ATM
{
public:
	int display(void)
	{
		using std::cin; using std::endl; using std::cout;
		cout << "Main menu: " << endl;
		cout << "1 - View my balance" << endl;
		cout << "2 - Withdraw cash" << endl;
		cout << "3 - Deposit funds" << endl;
		cout << "4 - Exit" << endl;
		cout << "Enter a choice: ";
		int choice;
		cin >> choice;
		cout << endl;
		return choice;
	}
	void balance_information(member &m)
	{
		using std::cin; using std::cout; using std::endl; using std::setprecision; using std::fixed;
		cout << "Balance Information: " << endl;
		cout << " - Available balance: $ " << setprecision(2) << fixed <<m.avaliable << endl;
		cout << " - Total balance:     $" << setprecision(2) << fixed << m.total << endl;
		cout << endl;
	}

	void withdraw_cash(member &m)
	{
		int choice = 0;

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
				if (m.avaliable < 20) {
					cout << "Money not enough ,choose a smaller amount" << endl;
					choice = 0;
				}
				else {
					m.avaliable -= 20;
					m.total -= 20;
					cout << "Please take your cash from the cash dispenser." << endl << endl;
				}
				break;
			case 2:
				if (m.avaliable < 40) {
					cout << "Money not enough ,choose a smaller amount" << endl;
					choice = 0;
				}
				else {
					m.avaliable -= 40;
					m.total -= 40;
					cout << "Please take your cash from the cash dispenser." << endl << endl;
				}
				break;
			case 3:
				if (m.avaliable < 60) {
					cout << "Money not enough ,choose a smaller amount" << endl;
					choice = 0;
				}
				else {
					m.avaliable -= 60;
					m.total -= 60;
					cout << "Please take your cash from the cash dispenser." << endl << endl;
				}
				break;
			case 4:
				if (m.avaliable < 100) {
					cout << "Money not enough ,choose a smaller amount" << endl;
					choice = 0;
				}
				else {
					m.avaliable -= 100;
					m.avaliable -= 100;
					cout << "Please take your cash from the cash dispenser." << endl << endl;
				}
				break;
			case 5:
				if (m.avaliable < 200) {
					cout << "Money not enough ,choose a smaller amount" << endl;
					choice = 0;
				}
				else {
					m.avaliable -= 200;
					m.total -= 200;
					cout << "Please take your cash from the cash dispenser." << endl << endl;
				}
				break;
			case 6:
				break;
			}
			
		}


	}
	void deposit_cash(member& m)
	{
		using std::cin; using std::cout; using std::endl; using std::setw; using std::setprecision; using std::fixed;
		cout << "Please enter a deposit amount in CENTS (or 0 to cancel):  " << endl;
		double enter;
		cin >> enter;
		enter /= 100;
		cout << "Please insert a deposit envelope containing $" <<setprecision(2) << fixed << enter <<"in the deposit slot." << endl;
		cout << "Your envelope has been received." << endl;
		m.total += enter;
		cout <<"NOTE: The money deposited will not be available until we" << endl;
		cout << "verify the amount of any enclosed cash, and any enclosed checks clear" << endl << endl;
	}
	bool verification(int a,int pin,member& m)
	{
		
		bool w = 0;
		
		if (m.account ==a)
		{
			if (m.PIN_num == pin) {
				w = true;
			}
		}
		return w;
		
	}
private:
	double cash = 10000.0;

};







#endif