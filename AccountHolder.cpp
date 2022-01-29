#include "AccountHolder.h"
#include <iostream>
#include<iomanip>
#include<string>
#include<vector>
void CAccountHolder::CreateAccountHolder()
{
	system("CLS");
	cout << "\n\t\t\tEnter the Account No. \t\t\t: ";
	cin >> m_nAccountNumber;
	cout << "\n\t\t\tEnter the Name of the Account holder : ";
	cin.ignore();
	getline(cin, m_sAccountHolderName);
	cout << "\t\t\tEnter Type of the Account  \t\t: ";
	//cin.ignore();
	getline(cin, m_sAccountType);
	//type = toupper(type);
	cout << "\t\t\tEnter The Initial amount : ";
	cin >> m_nDeposit;
	cout << "\t\t\tEnter the username \t\t: ";
	cin.ignore();
	getline(cin, m_sAccountHolderUsername);
	cout << "\t\t\tEnter the Password \t\t: ";
	cin.ignore();
	getline(cin, m_sAccountHolderPassword);
	cout << "\n\t\t\tAccount Created..";
}

void CAccountHolder::DisplayAccountHolder()
{
	cout << "\n\t\t\tAccount No. : " << m_nAccountNumber;
	cout << "\n\t\t\tAccount Holder Name : " << m_sAccountHolderName;
	cout << "\n\t\t\tType of Account : " << m_sAccountType;
	cout << "\n\t\t\tBalance amount : " << m_nDeposit;
}

void CAccountHolder::ModifyAccountHolder()
{
	cout << "\n\t\t\tAccount No. : " << m_nAccountNumber;
	cout << "\n\t\t\tModify Account Holder Name : ";
	cin.ignore();
	getline(cin, m_sAccountHolderName);
	cout << "\n\t\t\tModify Type of Account : ";
	//cin.ignore();
	getline(cin, m_sAccountType);
	cout << "\n\t\t\tModify Balance amount : ";
	cin >> m_nDeposit;
}

int CAccountHolder::Deposit()
{
	int nAmount = 0;
	cout << "Enter the Amount you want to Deposit : ";
	cin >> nAmount;
	m_nDeposit += nAmount;
	return m_nDeposit;
}

int CAccountHolder::WithdrawAmount()
{
	int nAmount;
	cout << "Enter the Amount you want to Withdraw : ";
	cin >> nAmount;
	if (m_nDeposit >= nAmount)
	{
		m_nDeposit -= nAmount;
		return m_nDeposit;
	}
	else
	{
		cout << "\n Insufficent Balance";
		return 0;
	}

}

void CAccountHolder::Report()
{
	cout << endl << m_nAccountNumber << setw(10) << " " << m_sAccountHolderName;
	cout << setw(10) << " " << m_sAccountType << setw(6) << m_nDeposit << endl;
}

int CAccountHolder::ReturnAccountNumber()
{
	return m_nAccountNumber;
}

int CAccountHolder::ReturnDeposit()
{
	return m_nDeposit;
}

string CAccountHolder::ReturnUsername()
{
	return m_sAccountHolderUsername;
}

string CAccountHolder::ReturnPassword()
{
	return m_sAccountHolderPassword;
}

int CAccountHolder::AccountHolderMenuList()
{
	int nChoice = 0;
	cout << "\n\n\t\t\t" << setw(50) << setfill(' ') << "  BANK MANAGEMENT SYSTEM  "/* << setw(28) << setfill('*') << "*" */ << endl;
	cout << "\n\n\t\t\t" << setw(80) << setfill('*') << "*" << "\n";
	cout << "\t\t\t" << setw(45) << setfill(' ') << "CUSTOMER PORTAL ";
	cout << "\n\t\t\t" << setw(80) << setfill('*') << "*" << "\n\n";
	cout << setw(66) << setfill(' ') << "1.Registration \n";
	cout << setw(59) << setfill(' ') << "2.Login \n";
	cout << "\t\t\t" << setw(80) << setfill('_') << "_" << "\n" << endl;

	//selecting menu list
	cout << "\n\t\t\t" << "Enter Your Choice : ";
	cin >> nChoice;

	return nChoice;
}
