#pragma once
#include "Bank.h"
class CEmployee :
    public CBank
{
private:
    
    
    int m_nEmployeeAge; 
    string m_sEmployeeDesignation;
    string m_sEmployeeAddress;
    int m_nEmployeeSalary;
    
public:
    int m_nEmployeeId;
    string m_sEmployeeUsername;
    string m_sEmployeePassword;
    string m_sEmployeeName;
    //constructor
    CEmployee()
    {
        m_nEmployeeId = 0;
        m_sEmployeeName = "";
        m_nEmployeeAge = 0;
        m_sEmployeeDesignation = "";
        m_sEmployeeAddress = "";
        m_sEmployeeUsername = "";
        m_sEmployeePassword = "";
    }

    void AddEmployee();
    void ViewEmployeeDetails();
    string ReturnEmployeeUsername();
    string ReturnEmployeePassword();
};

