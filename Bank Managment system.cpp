// Bank Managment system.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<iomanip>
#include<vector>
#include"Bank.h"
#include"AccountHolder.h"
#include"Employee.h"
vector<CAccountHolder> vAccountHolderCollection;
vector<CEmployee> vEmployeeCollection;

int nNumberOfEmployee = 0;
int nNumberOfCustomer = 0;

//Enum for mainmenu
enum eMainMenu
{
	Admin = 1,
	Employee,
	Customer,
	Exit
};

//Enum for SubMenuChoice of Admin
enum eAdminSubMenuChoice
{
	AccountHolder = 1,
	Employees
};

enum eAdminAccountHolderMenuChoice
{
	AdminAddAccountHolder=1,
	AdminViewAccountHolder,
	AdminSearchAccountHolder,
	AdminEditAccountHolder,
	AdminDeleteAccountHolder,
	AdminAddEmployee,
	AdminViewEmployee,
	AdminSearchEmployee,
	AdminEditEmployee,
	AdminDeleteEmployee,
	AdminLogout
};

void AddAccountHolder(vector<CAccountHolder> &vAccountHolderCollection);
void ViewAccountHolder(vector<CAccountHolder> &vAccountHolderCollection);
void SearchAccountHolder(vector<CAccountHolder> &vAccountHolderCollection);
void ModifyAccountHolder(vector<CAccountHolder> &vAccountHolderCollection);
void CloseAccountHolder(vector<CAccountHolder> &vAccountHolderCollection);
void AddCEmployee(vector<CEmployee> &vEmployeeCollection);
void ViewEmployee(vector<CEmployee> &vEmployeeCollection);
void EditEmployeeDetails(vector<CEmployee> &vEmployeeCollection);
void DeleteEmployeeDetails(vector<CEmployee> &vEmployeeCollection);
void SearchEmployeeDetails(vector<CEmployee> &vEmployeeCollection);

CBank* pBank = NULL;
CBank oBank;
CAccountHolder oAccountHolder;
CEmployee oEmployee;

using namespace std;
int main()
{
	bool bCheck = false;
	char cChoice = 0;
	int nChoice = 0;
	int nSubMenuChoice = 0;
	int nCount = 0;
	int nIterator = 0;
	int nCheck = 0;
	int nAmount = 0;
	int nFlag = 0;
	string sTempUser, sTempPassword;
	string sUsername = " ";
	string sPassword = " ";

	//loop for display the main menu
	do
	{
		//display the Main Menu
		cout << "\n\n\t\t\t" << setw(50) << setfill('*') << "* BANK MANAGEMENT SYSTEM *" << setw(28) << setfill('*') << "*" << endl << endl << endl;
		cout << setw(65) << setfill(' ') << "1. Admin \n";
		cout << setw(67) << setfill(' ') << "2. Employee\n";
		cout << setw(67) << setfill(' ') << "3. Customer\n";
		cout << setw(64) << setfill(' ') << "4. Exit \n";
		cout << "\n\n\t\t\t" << setw(80) << setfill('*') << "*" << "\n";

		//selecting menu list
		cout << "\n\t\t\t" << "Enter Your Choice : ";
		cin >> nChoice;
		switch (nChoice)
		{
		case Admin:
			bCheck = oBank.AdminLogin();
			if (bCheck == true)
			{
				//login sucessfully.

				do
				{
					system("cls");		//clear the screen
					nSubMenuChoice = pBank->AdminMenuList();	//display the admin menulist and return choice value is intialize to nSubMenuChoice

					switch (nSubMenuChoice)
					{
					case AdminAddAccountHolder:
						AddAccountHolder(vAccountHolderCollection);
						break;
					case AdminViewAccountHolder:
						ViewAccountHolder(vAccountHolderCollection);
						break;
					case AdminSearchAccountHolder:
						SearchAccountHolder(vAccountHolderCollection);
						break;
					case AdminEditAccountHolder:
						ModifyAccountHolder(vAccountHolderCollection);
						break;
					case AdminDeleteAccountHolder:
						CloseAccountHolder(vAccountHolderCollection);
						break;
					case AdminAddEmployee:
						AddCEmployee(vEmployeeCollection);
						break;
					case AdminSearchEmployee:
						SearchEmployeeDetails(vEmployeeCollection);
						break;
					case AdminViewEmployee:
						ViewEmployee(vEmployeeCollection);
						break;
					case AdminEditEmployee :
						EditEmployeeDetails(vEmployeeCollection);
						break;
					case AdminDeleteEmployee:
						DeleteEmployeeDetails(vEmployeeCollection);
						break;
					case AdminLogout:
						cout << "Thank You";
						break;
					default:
						cout << "Invalid Choice\n";
						break;
					}

					cout << "\nIf you want continue with this menu press E for exit press Q : ";
					cin >> cChoice;

				} while (cChoice != 'Q' && cChoice != 'q');
			}
			else
			{
				//if password or username is incorrect then this will work and exit from this .
				cout << "Password is incorrect";
			}
			break;

		case Employee:
			do
			{
				system("cls");
				cout << "\n\n\t\t\t" << setw(50) << setfill(' ') << "  BANK MANAGEMENT SYSTEM  "/* << setw(28) << setfill('*') << "*" */ << endl;
				cout << "\n\n\t\t\t" << setw(80) << setfill('*') << "*" << "\n";
				cout << "\t\t\t" << setw(45) << setfill(' ') << "EMPLOYEE PORTAL ";
				cout << "\n\t\t\t" << setw(80) << setfill('*') << "*" << "\n\n";
				cout << setw(61) << setfill(' ') << "1.Manager \n";
				cout << setw(59) << setfill(' ') << "2.Staff \n";
				cout << "\t\t\t" << setw(80) << setfill('_') << "_" << "\n" << endl;

				//selecting menu list
				cout << "\n\t\t\t" << "Enter Your Choice : ";
				cin >> nChoice;

				if (nChoice == 1)//Manager
				{
					cout << "\n\n\t\t\t" << setw(50) << setfill(' ') << "  BANK MANAGEMENT SYSTEM  "/* << setw(28) << setfill('*') << "*" */ << endl;
					cout << "\n\n\t\t\t" << setw(80) << setfill('*') << "*" << "\n";
					cout << "\t\t\t" << setw(45) << setfill(' ') << "EMPLOYEE PORTAL ";
					cout << "\n\t\t\t" << setw(80) << setfill('*') << "*" << "\n\n";
					cout << setw(65) << setfill(' ') << "Manager \n";
					cout << "\t\t\t" << setw(80) << setfill('_') << "_" << "\n\n";
					cout << "\t\t\t\t\tUser Name\t\t:\t\t";
					cin.ignore();
					getline(cin, sUsername);
					cout << "\t\t\t\t\tPassword \t\t:\t\t";
					getline(cin, sPassword);
					cout << "\t\t\t" << setw(80) << setfill('_') << "_" << "\n\n";
					nFlag = 0;
					for (nIterator = 0; nIterator < nNumberOfEmployee; ++nIterator)
					{
						oEmployee = vEmployeeCollection[nIterator];
						sTempUser = oEmployee.ReturnEmployeeUsername();
						sTempPassword = oEmployee.ReturnEmployeePassword();
						if (sUsername == sTempUser && sPassword == sTempPassword)
						{
							nFlag = 1;
							nCheck = nIterator;
						}
					}
					if (nFlag != 0)
					{
						do
						{
							cout << "\n\n\t\t\t" << setw(50) << setfill(' ') << "  BANK MANAGEMENT SYSTEM  "/* << setw(28) << setfill('*') << "*" */ << endl;
							cout << "\n\n\t\t\t" << setw(80) << setfill('*') << "*" << "\n";
							cout << "\t\t\t" << setw(45) << setfill(' ') << "EMPLOYEE PORTAL ";
							cout << "\n\t\t\t" << setw(80) << setfill('*') << "*" << "\n\n";
							cout << setw(65) << setfill(' ') << "Manager \n";
							cout << "\t\t\t" << setw(80) << setfill('_') << "_" << "\n\n";
							cout << setw(74) << setfill(' ') << "1. Account holder view \n";
							cout << setw(68) << setfill(' ') << "2. Edit Account  \n";
							cout << setw(69) << setfill(' ') << "3. Account close  \n";
							cout << setw(62) << setfill(' ') << "4. Logout  \n";

							cout << "\n\t\t\t" << "Enter Your Choice : ";
							cin >> nChoice;
							switch (nChoice)
							{
							case 1:
								ViewAccountHolder(vAccountHolderCollection);
								break;
							case 2:
								ModifyAccountHolder(vAccountHolderCollection);
								break;
							case 3:
								CloseAccountHolder(vAccountHolderCollection);
								break;
			
							case 4:
								cout << "\nThank you for visit our  Bank\n";
								break;
							default: 
								cout << "invalid choice!";
								break;
							}

							cout << "\nIf you want continue with this menu press E for exit press Q : ";
							cin >> cChoice;
							system("cls");
						} while (cChoice != 'Q' && cChoice != 'q');
					}
					else
					{
						cout << "*******************Incorrect**********************";
					}
				}
				else if (nChoice == 2)//staff
				{
					cout << "\n\n\t\t\t" << setw(50) << setfill(' ') << "  BANK MANAGEMENT SYSTEM  "/* << setw(28) << setfill('*') << "*" */ << endl;
					cout << "\n\n\t\t\t" << setw(80) << setfill('*') << "*" << "\n";
					cout << "\t\t\t" << setw(45) << setfill(' ') << "EMPLOYEE PORTAL ";
					cout << "\n\t\t\t" << setw(80) << setfill('*') << "*" << "\n\n";
					cout << setw(65) << setfill(' ') << "Staff \n";
					cout << "\t\t\t" << setw(80) << setfill('_') << "_" << "\n\n";
					cout << "\t\t\t\t\tUser Name\t\t:\t\t";
					cin.ignore();
					getline(cin, sUsername);
					cout << "\t\t\t\t\tPassword \t\t:\t\t";
					getline(cin, sPassword);
					cout << "\t\t\t" << setw(80) << setfill('_') << "_" << "\n\n";

					nFlag = 0;
					for (nIterator = 0; nIterator < nNumberOfEmployee; ++nIterator)
					{
						oEmployee = vEmployeeCollection[nIterator];
						sTempUser = oEmployee.ReturnEmployeeUsername();
						sTempPassword = oEmployee.ReturnEmployeePassword();
						if (sUsername == sTempUser && sPassword == sTempPassword)
						{
							nFlag = 1;
							nCheck = nIterator;
						}
					}
					if (nFlag != 0)
					{
						do
						{
							cout << "\n\n\t\t\t" << setw(50) << setfill(' ') << "  BANK MANAGEMENT SYSTEM  "/* << setw(28) << setfill('*') << "*" */ << endl;
							cout << "\n\n\t\t\t" << setw(80) << setfill('*') << "*" << "\n";
							cout << "\t\t\t" << setw(45) << setfill(' ') << "EMPLOYEE PORTAL ";
							cout << "\n\t\t\t" << setw(80) << setfill('*') << "*" << "\n\n";
							cout << setw(65) << setfill(' ') << "Staff \n";
							cout << "\t\t\t" << setw(80) << setfill('_') << "_" << "\n\n";
							cout << setw(77) << setfill(' ') << "1. Account holder Details  \n";
							cout << setw(77) << setfill(' ') << "2. Add Account holder   \n";
							cout << setw(77) << setfill(' ') << "3. delete Account holder   \n";
							cout << setw(60) << setfill(' ') << "4. Logout \n";
							cout << "\n\n\t\t\t" << setw(80) << setfill('_') << "_" << "\n";
							cout << "\n\t\t\t" << "Enter Your Choice : ";
							cin >> nChoice;
							switch (nChoice)
							{
							case 1:
								ViewAccountHolder(vAccountHolderCollection);
								break;
							case 2:
								AddAccountHolder(vAccountHolderCollection);
								break;
							case 3:
								CloseAccountHolder(vAccountHolderCollection);
								break;
							case 4:
								cout << "\nThank you for visit our  Bank\n";
								break;
							default: cout << "invalid choice";
								break;
							}

							cout << "\nIf you want continue with this menu press E for exit press Q : ";
							cin >> cChoice;
							system("cls");
						} while (cChoice != 'Q' && cChoice != 'q');
					}
					else
					{
						cout << "*******************Incorrect**********************";
					}
				}
				cout << "\nIf you want continue with this menu press E for exit press Q : ";
				cin >> cChoice;
				system("cls");
			} while (cChoice != 'Q');
			break;

		case Customer:

			do
			{
				nChoice = oAccountHolder.AccountHolderMenuList();
				switch (nChoice)
				{
				case 1:
					AddAccountHolder(vAccountHolderCollection);
					break;
				case 2:
					cChoice = 'i';
					system("cls");	//clear the screen


					cout << "\n\n\t\t\t" << setw(50) << setfill(' ') << "  BANK MANAGEMENT SYSTEM  "/* << setw(28) << setfill('*') << "*" */ << endl;
					cout << "\n\n\t\t\t" << setw(80) << setfill('*') << "*" << "\n";
					cout << "\t\t\t" << setw(45) << setfill(' ') << "CUSTOMER PORTAL ";
					cout << "\n\t\t\t" << setw(80) << setfill('*') << "*" << "\n\n";
					cout << setw(65) << setfill(' ') << "LOGIN \n";
					cout << "\t\t\t" << setw(80) << setfill('_') << "_" << "\n\n";
					cout << "\t\t\t\t\tUser Name\t\t:\t\t";
					cin.ignore();
					getline(cin, sUsername);
					cout << "\t\t\t\t\tPassword \t\t:\t\t";
					getline(cin, sPassword);
					cout << "\t\t\t" << setw(80) << setfill('_') << "_" << "\n\n";
					nFlag = 1;
					for (nIterator = 0; nIterator < nNumberOfCustomer; ++nIterator)
					{
						oAccountHolder = vAccountHolderCollection[nIterator];
						sTempUser = oAccountHolder.ReturnUsername();
						sTempPassword = oAccountHolder.ReturnPassword();
						if (sUsername == sTempUser && sPassword == sTempPassword)
						{
							nFlag = 1;
							nCheck = nIterator;
						}

					}

					if (nFlag != 0)
					{
						oAccountHolder = vAccountHolderCollection[nCheck];
						do
						{
							cout << "\n\n\t\t\t" << setw(50) << setfill(' ') << "  BANK MANAGEMENT SYSTEM  "/* << setw(28) << setfill('*') << "*" */ << endl;
							cout << "\n\n\t\t\t" << setw(80) << setfill('*') << "*" << "\n";
							cout << "\t\t\t" << setw(45) << setfill(' ') << "CUSTOMER PORTAL ";
							cout << "\n\t\t\t" << setw(80) << setfill('*') << "*" << "\n\n";
							cout << setw(62) << setfill(' ') << "1. Deposit  \n";
							cout << setw(63) << setfill(' ') << "2. Withdraw  \n";
							cout << setw(70) << setfill(' ') << "3. Balance Enquiry  \n";
							cout << setw(69) << setfill(' ') << "4. Change password \n";
							//cout << setw(68) << setfill(' ') << "5. Change ATM pin \n";
							cout << setw(60) << setfill(' ') << "5. Logout \n";
							cout << "\n\n\t\t\t" << setw(80) << setfill('_') << "_" << "\n";
							//selecting menu list
							cout << "\n\t\t\t" << "Enter Your Choice : ";
							cin >> nChoice;
							switch (nChoice)
							{
							case 1:
								nAmount = oAccountHolder.Deposit();
								vAccountHolderCollection[nCheck].m_nDeposit = nAmount;
								break;
							case 2:
								nAmount = oAccountHolder.WithdrawAmount();
								vAccountHolderCollection[nCheck].m_nDeposit = nAmount;
								break;
							case 3:
								oAccountHolder.DisplayAccountHolder();
								break;
							case 4:
								cout << "Enter New Account Holder Password : ";
								cin >> vAccountHolderCollection[nIterator].m_sAccountHolderPassword;
								cout << "\nSucessfully Password Changed ";
								break;
							case 5:
								cout << "\nThank you for visit our  Bank\n";
								break;
							default:
								break;
							}
							cout << "\nIf you want continue with this menu press E for exit press Q : ";
							cin >> cChoice;
							system("cls");
						} while (cChoice != 'Q');
					}
					else
					{
						//if password or username is incorrect then this will work and exit from this .
						cout << "Wrong ";
						break;
					}

				}
				cout << "\nIf you want continue with this menu press E for exit press Q : ";
				cin >> cChoice;
				system("cls");
			} while (cChoice != 'Q');
			break;

		case Exit:
			system("cls");
			cout << "\n\n\tThanks for using bank managemnt system";
			exit(0);
			break;

		}


		cout << "\nIf you want  to view Home Page press H and for  Exit  press  Q : ";
		cin >> cChoice;
		system("cls");
	} while (cChoice != 'Q' && cChoice != 'q');
	
}

void AddAccountHolder(vector<CAccountHolder> &vAccountHolderCollection)
{
	system("cls"); //clear the screen

	int nCount = 0;
	int nIterator = 0;

	CAccountHolder oAccountHolder; //create object for AccountHolder Class

	//input Number of AccountHolder to add
	cout << "\nHow many Account Holder do you want to add ? : ";
	cin >> nCount;

	for (nIterator = 0; nIterator < nCount; ++nIterator)
	{
		//calling Acount hoder class member function CreateAccountHolder() using class object
		oAccountHolder.CreateAccountHolder();

		//input each object values to vector
		vAccountHolderCollection.push_back(oAccountHolder);
	}

	//update the count of customer after entering values
	nNumberOfCustomer += nCount;

	//return vAccountHolderCollection;
}

void ViewAccountHolder(vector<CAccountHolder> &vAccountHolderCollection)
{
	system("cls"); //clear the screen

	int nIterator = 0;

	CAccountHolder oAccountHolder; //create object for AccountHolder Class
	//cout << "\nNumberOfCustomer : " << nNumberOfCustomer;
	//cout<<"size : "<<vAccountHolderCollection.size();
	if (vAccountHolderCollection.size() != 0)
	{
		for (nIterator = 0; nIterator < vAccountHolderCollection.size(); nIterator++)
		{
			//each index value of vector is Store to object
			oAccountHolder = vAccountHolderCollection.at(nIterator);
			//calling Acount hoder class member function CreateAccountHolder() using class object
			oAccountHolder.DisplayAccountHolder();
		}
	}
	else
	{
		cout << "Customer DataBase is Empty";
	}
	
}

void SearchAccountHolder(vector<CAccountHolder> &vAccountHolderCollection)
{
	int nSearchAccountNumber = 0;
	int flag = 0;
	int nIterator = 0;
	system("cls");
	CAccountHolder oAccountHolder; //create object for AccountHolder Class
	cout << "Enter The Account number do you want Search : ";
	cin >> nSearchAccountNumber;
	for (nIterator = 0; nIterator < vAccountHolderCollection.size(); ++nIterator)
	{
		if (nSearchAccountNumber == vAccountHolderCollection.at(nIterator).m_nAccountNumber )
		{
			oAccountHolder = vAccountHolderCollection[nIterator];
			oAccountHolder.DisplayAccountHolder();
			flag = 1;
			break;
		}

	}
	if (flag == 0)
	{
		cout << "Account Number Not Found\n";
	}

}

void ModifyAccountHolder(vector<CAccountHolder> &vAccountHolderCollection)
{
	int nSearchAccountNumber = 0;
	int nChoice = 0;
	int flag = 0;
	int nIterator = 0;
	system("cls");
	cout << "Enter The Account number do you want to Modify : ";
	cin >> nSearchAccountNumber;

	for (nIterator = 0; nIterator < nNumberOfCustomer; ++nIterator)
	{
		if (nSearchAccountNumber == vAccountHolderCollection.at(nIterator).m_nAccountNumber)
		{
			
			cout << "What do you want to edit ? \nEnter your option\n";
			cout << "1.Name\n2.Username\n3.Password\n";
			cout << "Enter your choice:" << endl << endl;
			cin >> nChoice;
			switch (nChoice)
			{
			case 1:
				cout << "Enter Account Holder Name : ";
				cin >> vAccountHolderCollection.at(nIterator).m_sAccountHolderName;
				break;
			case 2:
				cout << "Enter Account Holder Username : ";
				cin >> vAccountHolderCollection.at(nIterator).m_sAccountHolderUsername;
				break;
			case 3:
				cout << "Enter Account Holder Password : ";
				cin >> vAccountHolderCollection.at(nIterator).m_sAccountHolderPassword;
				break;
			default:cout << "Invalid choice";
				break;
			}
			flag = 1;
			break;
		}

	}
	if (flag == 0)
	{
		cout << "Account Number Not Found\n";
	}
}

void CloseAccountHolder(vector<CAccountHolder> &vAccountHolderCollection)
{
	int nSearchAccountNumber = 0;
	int flag = 0;
	int nIterator = 0;
	CAccountHolder oAccountHolder; //create object for AccountHolder Class
	system("cls");
	cout << "Enter The Account number do you want to Delete : ";
	cin >> nSearchAccountNumber;
	flag = 0;
	int nIndex = 0;
	for (nIterator = 0; nIterator < nNumberOfCustomer; ++nIterator)
	{
		if (nSearchAccountNumber == vAccountHolderCollection.at(nIterator).m_nAccountNumber)
		{

			nIndex = nIterator - 1;
			vAccountHolderCollection.erase(vAccountHolderCollection.begin()+nIterator);
			--nNumberOfCustomer;
			flag = 1;
		}
	}
	if (flag == 0)
	{
		cout << "Account Number Not Found\n";
	}
}

void AddCEmployee(vector<CEmployee> &vEmployeeCollection)
{
	system("cls"); //clear the screen

	int nCount = 0;
	int nIterator = 0;

	CEmployee oEmployee; //create object for Employee Class

	//input Number of Employee to add
	cout << "\nHow many Employee do you want to add ? : ";
	cin >> nCount;

	for (nIterator = 0; nIterator < nCount; ++nIterator)
	{
		//calling Acount hoder class member function CreateEmployee() using class object
		oEmployee.AddEmployee();

		//input each object values to vector
		vEmployeeCollection.push_back(oEmployee);
	}

	//update the count of customer after entering values
	nNumberOfEmployee += nCount;

	
}

void ViewEmployee(vector<CEmployee> &vEmployeeCollection)
{
	system("cls"); //clear the screen

	int nIterator = 0;

	CEmployee oEmployee; //create object for Employee Class

	if (vEmployeeCollection.size() != 0)
	{
		for (nIterator = 0; nIterator < vEmployeeCollection.size(); ++nIterator)
		{
			//each index value of vector is Store to object
			oEmployee = vEmployeeCollection.at(nIterator);
			//calling Acount hoder class member function ViewEmployee() using class object
			oEmployee.ViewEmployeeDetails();
		}
	}
	else
	{
		cout << "Employee DataBase is Empty";
	}
}

void EditEmployeeDetails(vector<CEmployee> &vEmployeeCollection)
{
	int nSearchEmployeeId = 0;
	int nChoice = 0;
	int flag = 0;
	int nIterator = 0;

	system("cls");
	cout << "Enter The EmployeeId do you want to Modify : ";
	cin >> nSearchEmployeeId;

	

	for (nIterator = 0; nIterator < vEmployeeCollection.size(); ++nIterator)
	{
		if (nSearchEmployeeId == vEmployeeCollection[nIterator].m_nEmployeeId)
		{

			cout << "What do you want to edit ? \nEnter your option\n";
			cout << "1.Name\n2.Username\n3.Password\n";
			cout << "Enter your choice:" << endl << endl;
			cin >> nChoice;
			switch (nChoice)
			{
			case 1:
				cout << "Enter Employee Name : ";
				cin >> vEmployeeCollection[nIterator].m_sEmployeeName;
				break;
			case 2:
				cout << "Enter Employee Username : ";
				cin >> vEmployeeCollection[nIterator].m_sEmployeeUsername;
				break;
			case 3:
				cout << "Enter Employee Password : ";
				cin >> vEmployeeCollection[nIterator].m_sEmployeePassword;
				break;
			default:cout << "Invalid choice";
				break;
			}
			flag = 1;
			break;
		}

	}
	if (flag == 0)
	{
		cout << "Employee ID Not Found\n";
	}
}

void DeleteEmployeeDetails(vector<CEmployee> &vEmployeeCollection)
{
	int nSearchEmployeeId = 0;
	int nIterator = 0;
	int nFlag = 0;
	int nIndex = 0;

	system("cls");

	CEmployee OEmployee;
	cout << "Enter The EmployeeId do you want to delete : ";
	cin >> nSearchEmployeeId;
	for (nIterator = 0; nIterator < vEmployeeCollection.size(); ++nIterator)
	{
		if (nSearchEmployeeId == vEmployeeCollection[nIterator].m_nEmployeeId)
		{
			
			nIterator==0? nIterator=2: nIndex = nIterator - 1;
			vEmployeeCollection.erase(vEmployeeCollection.begin()+nIndex);
			
			nFlag = 1;
			nNumberOfEmployee--;
			//break;
		}
	}
	if (nFlag == 0)
	{
		cout << "EmployeeId Not Found\n";
	}
}

void SearchEmployeeDetails(vector<CEmployee> &vEmployeeCollection)
{
	int nSearchEmployeeId = 0;
	int nIterator = 0;
	int nFlag = 0;
	CEmployee OEmployee;

	system("cls");

	cout << "Enter The EmployeeId do you want to Search : ";
	cin >> nSearchEmployeeId;
	for (nIterator = 0; nIterator < nNumberOfEmployee; ++nIterator)
	{
		if (nSearchEmployeeId == vEmployeeCollection[nIterator].m_nEmployeeId)
		{
			oEmployee = vEmployeeCollection[nIterator];
			oEmployee.ViewEmployeeDetails();
			nFlag = 1;
			break;
		}
	}
	if (nFlag == 0)
	{
		cout << "EmployeeId Not Found\n";
	}
}



