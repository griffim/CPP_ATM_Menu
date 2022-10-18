#include <iostream>
#include <iomanip>
#include <dos.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

//
// CISC 192 Project 1: ATM
//
// 
// Assignment parameters
//
// Bank account with methods to deposit, withdraw, and check balance
//
// Contains 3 main variables; accountBalance, accountName, accountNum; with appropriate data types
// 
// Initialize the accountName with parameter specified
// accountBalance and accountNum are assigned random values
//
// Contains 3 member functions; menu, withdraw, deposit
//
// withdraw: Checks if balance able to withdraw and if so, decrements accountBalance by such. If not, prints appropriate error.
// 
// deposit: Adds deposit amount to accountBalance, and displays new accountBalance
// 
// menu: Contains following options; 1) Check balance, 2) Deposit amount, 3) Withdraw amount, 4) Exit
//
//
// By Griffin May
//


// Defines function to ignore incorrect inputs
void ignoreLine()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


// Defines ATM class
class atm {

	// Variables are defined and initialized
public:
	string accountName = "";
	long int accountNum = 0;
	float accountBalance = 25;
	float depositAmt = 0;
	float withdrawAmt = 0;

	// Defines menu function
	void menu()
	{
		cout << "\n________________________________________\n";
		cout << "\n\nWelcome to the ATM Menu!\n";
		cout << "\nPlease choose from the options below.\n\n\n";
		cout << "\t1.) Show account data\n";
		cout << "\t2.) Show account balance\n";
		cout << "\t3.) Deposit funds\n";
		cout << "\t4.) Withdraw funds\n";
		cout << "\t5.) Exit ATM\n\n";
		cout << "\nPlease make a selection: ";
	}

	// Initialize account
	void setData()
	{
		cout << "\nWelcome to the ATM!\nPlease enter the following information below.\n";
		cout << "\nPlease enter your name:\n";
		cin >> accountName;

		while (cin.fail())
		{
			ignoreLine();
			cout << "\nInvalid entry. Please enter valid account name below:\n\n";
			cin >> accountName;
		}


		cout << "\nPlease enter your account number:\n";
		cin >> accountNum;

		while (cin.fail())
		{
			ignoreLine();
			cout << "\nInvalid entry. Please enter valid account number below:\n\n";
			cin >> accountNum;
		}

		
	}

	// Show account information
	void showData()
	{
		cout << "\n\nBelow is your account information:\n";
		cout << "\nAccount Name: " << accountName << "\n";
		cout << "\nAccount Number: " << accountNum << "\n";

		// system("pause");
	}

	// Function to display current account balance. Defaults to 25.
	void showBalance()
	{
		cout << "\nCurrent account balance is: $" << accountBalance << endl;

		// system("pause");
	}

	// Function to deposit funds. Must be a positive value.
	void deposit()
	{
		cout << "\n\nPlease enter deposit amount:\n";
		cin >> depositAmt;
		if (depositAmt > 0)
		{
			accountBalance = accountBalance + depositAmt;
			cout << "\nDepositing $" << depositAmt << " into Account #" << accountNum << endl;
			cout << "\nNew account balance is: $" << accountBalance << endl;
		}
		else
		{
			cout << "\nInvalid response, deposit amount must be positive.\n";
		}

		// system("pause");
	}

	// Function to withdraw money. Final value must be positive.
	void withdraw()
	{
		cout << "\n\nPlease enter withdrawal amount:\n";
		cin >> withdrawAmt;
		if (accountBalance - withdrawAmt >= 0)
		{
			accountBalance = accountBalance - withdrawAmt;
			cout << "\nWithdrawing $" << withdrawAmt << " from Account #" << accountNum << endl;
			cout << "\nNew account balance is: $" << accountBalance << endl;
		}
		else
		{
			cout << "\nInsufficient funds, cannot withdraw more than account balance.\n";
		}

		// system("pause");
	}
};

int main(int argc, char const* argv[])
{
	// Initialize class and selection variable
	atm a;
	int choice = 0;

	a.setData();


	// Defaults to menu function
	while (1)
	{
		a.menu();
		cin >> choice;

		while (cin.fail())
		{
			ignoreLine();
			cout << "\n\n________________________________________\n";
			cout << "\nInvalid entry.\n";
			cout << "\nPlease choose from the options below.\n\n";
			cout << "1.) Show account data\n";
			cout << "2.) Show account balance\n";
			cout << "3.) Deposit funds\n";
			cout << "4.) Withdraw funds\n";
			cout << "5.) Exit ATM\n\n";
			cout << "\nPlease make a selection: ";
			cin >> choice;
		}

		switch (choice)
		{
			// Case 1; executes showData function
		case 1:
			a.showData();
			break;

			// Case 2; executes showBalance function
		case 2:
			a.showBalance();
			break;

			// Case 3; executes deposit function
		case 3:
			a.deposit();
			break;

			// Case 4; executes withdraw function
		case 4:
			a.withdraw();
			break;

			// Case 5; Exit code
		case 5:
			exit(4);
			break;

		default:
			cout << "\nInvalid response, unaccounted error. Please try again.\n";
			break;

		}
	}

	// Exit
	return 0;
};