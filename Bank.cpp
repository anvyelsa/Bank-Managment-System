#include "Bank.h"
#include <iostream>
#include<iomanip>
using namespace std;
int CBank::AdminMenuList()
{
	int nChoice = 0;

	//Admin Menu list
	cout << "\n\n\t\t\t" << setw(50) << setfill(' ') << "  BANK MANAGEMENT SYSTEM  "/* << setw(28) << setfill('*') << "*" */ << endl << endl << endl;
	cout << "\n\n\t\t\t" << setw(80) << setfill('*') << "*" << "\n";
	cout << "\t\t\t" << setw(45) << setfill(' ') << "ADMIN PORTAL ";
	cout << "\n\t\t\t" << setw(80) << setfill('*') << "*" << "\n\n";
	cout << setw(72) << setfill(' ') << "Account Holders \n";
	cout << "\t\t\t" << setw(80) << setfill('_') << "_" << "\n" << endl;
	cout << setw(72) << setfill(' ') << "1. ADD Account Holders List \n";
	cout << setw(72) << setfill(' ') << "2. View Account Holders List \n";
	cout << setw(72) << setfill(' ') << "3. Search Account Holder  \n";
	cout << setw(72) << setfill(' ') << "4. Modify Account Holder Details  \n";
	cout << setw(72) << setfill(' ') << "5. Close Account Holder  \n";
	cout << "\t\t\t" << setw(80) << setfill('_') << "_" << "\n\n";
	cout << setw(64) << setfill(' ') << "Employee\n";
	cout << "\t\t\t" << setw(80) << setfill('_') << "_" << "\n\n";
	cout << setw(72) << setfill(' ') << "6. Register Employee  \n";
	cout << setw(72) << setfill(' ') << "7. View Employee  \n";
	cout << setw(72) << setfill(' ') << "8. Search Employee  \n";
	cout << setw(72) << setfill(' ') << "9. Modify Employee Details \n";
	cout << setw(72) << setfill(' ') << "10. Delete Employee  \n";
	cout << setw(63) << setfill(' ') << "11. Logout \n";
	cout << "\n\n\t\t\t" << setw(80) << setfill('_') << "_" << "\n";

	//selecting menu list
	cout << "\n\t\t\t" << "Enter Your Choice : ";
	cin >> nChoice;

    return nChoice;
}

bool CBank::AdminLogin()
{
	string sUsername = " ";
	string sPassword = " ";

	system("cls");	//clear the screen

	//Display for login portal and enter login and password.
	cout << "\n\n\t\t\t" << setw(80) << setfill('*') << "*" << "\n\n";
	cout << "\t\t\t" << setw(45) << setfill(' ') << "LOGIN ";
	cout << "\n\n\t\t\t" << setw(80) << setfill('*') << "*" << "\n\n";

	//Enter username
	cout << "\t\t\t\t\tUser Name\t\t:\t\t";
	cin.ignore();
	getline(cin, sUsername);

	//Enter Password
	cout << "\t\t\t\t\tPassword \t\t:\t\t";
	//cin.ignore();
	getline(cin, sPassword);

	//checking Username and password is correct or not
	if (sUsername == stAdminLogin.sUsername && sPassword == stAdminLogin.sPassword)
	{
		return true;
	}
	else
	{
		return false;
	}

}

void CBank::CreateAccountHolder()
{
}

void CBank::DisplayAccountHolder()
{
}

void CBank::ModifyAccountHolder()
{
}

void CBank::Deposit(int nAmount)
{
}

void CBank::WithdrawAmount(int nAmount)
{
}

void CBank::Report()
{
}

int CBank::ReturnAccountNumber()
{
	return 0;
}

int CBank::ReturnDeposit()
{
	return 0;
}

int CBank::AccountHolderMenuList()
{
	return 0;
}

string CBank::ReturnUsername()
{
	return string();
}

string CBank::ReturnPassword()
{
	return string();
}

void CBank::AddEmployee()
{
}

void CBank::ViewEmployeeDetails()
{
}

void CBank::EditEmployeeDetails()
{
}
