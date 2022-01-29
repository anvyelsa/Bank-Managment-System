#pragma once
#include"Bank.h"
class CAccountHolder: public CBank
{
public:
    int m_nAccountNumber;
    string m_sAccountHolderName;
    int m_nDeposit; //current amount in account
    string m_sAccountType;
    string m_sAccountHolderUsername;
    string m_sAccountHolderPassword;

    //constructor
    CAccountHolder()
    {
        m_nAccountNumber = 0;
        m_sAccountHolderName = "";
        m_nDeposit = 0;
        m_sAccountType = "";
        m_sAccountHolderUsername = "";
        m_sAccountHolderPassword = "";
    }

    void CreateAccountHolder();
    void DisplayAccountHolder();
    void ModifyAccountHolder();
    int Deposit();
    int WithdrawAmount();
    void Report();
    int ReturnAccountNumber();
    int ReturnDeposit();
    string ReturnUsername();
    string ReturnPassword();
    int AccountHolderMenuList();
};

