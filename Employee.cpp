#include "Employee.h"
#include <iostream>
#include<iomanip>
#include<string>
using namespace std;
void CEmployee::AddEmployee()
{
	int nChoice;
	//system("CLS");
	cout << "\n\t\t\tEnter the Employee Id\t\t\t: ";
	cin >> m_nEmployeeId;
	cout << "\t\t\tEnter the Name of Employee\t\t: ";
	cin.ignore();
	getline(cin, m_sEmployeeName);
	cout << "\t\t\tEnter Employee Age: ";
	cin >> m_nEmployeeAge;

	cout << "\t\t\tChoose the  Employee Designation  1. MANAGER 2.STAFF : ";
	cin >> nChoice;
	switch (nChoice)
	{
	case 1:
		m_sEmployeeDesignation = "MANAGER";
		break;
	case 2:
		m_sEmployeeDesignation = "STAFF";
		break;
	}
	cout << "\n\t\t\tEnter Employee Address : ";
	cin.ignore();
	cin >> m_sEmployeeAddress;
	cout << "\n\t\t\tEnter the Employee Username: ";
	cin.ignore();
	getline(cin, m_sEmployeeUsername);
	cout << "\t\t\tEnter the Password \t\t: ";
	cin.ignore();
	getline(cin, m_sEmployeePassword);
	cout << "\n\t\t\t Account Created..";
}

void CEmployee::ViewEmployeeDetails()
{
	cout << "\n\t\t\tEmployee Id		  : " << m_nEmployeeId;
	cout << "\n\t\t\tName of the Employee : " << m_sEmployeeName;
	cout << "\n\t\t\tEmployee Designation : " << m_sEmployeeDesignation;
	cout << "\n\t\t\tEmployee Address	  : " << m_sEmployeeAddress;
}


string CEmployee::ReturnEmployeeUsername()
{
	return m_sEmployeeUsername;
}

string CEmployee::ReturnEmployeePassword()
{
	return m_sEmployeePassword;
}
