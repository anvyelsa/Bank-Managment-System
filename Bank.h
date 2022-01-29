#pragma once
#include<string>
using namespace std;
class CBank
{
private:
	//admin username and password
	struct
	{
		string sUsername = "admin";
		string sPassword = "admin";
	}stAdminLogin;

public:

	//member functions
	int AdminMenuList();
	bool AdminLogin();

	virtual void CreateAccountHolder();
	virtual void DisplayAccountHolder();
	virtual void ModifyAccountHolder();
	virtual void Deposit(int nAmount);
	virtual void WithdrawAmount(int nAmount);
	virtual void Report();
	virtual int ReturnAccountNumber();
	virtual int ReturnDeposit();
	virtual int AccountHolderMenuList();
	virtual string ReturnUsername();
	virtual string ReturnPassword();

	virtual void AddEmployee();
	virtual void ViewEmployeeDetails();
	virtual void EditEmployeeDetails();
};

