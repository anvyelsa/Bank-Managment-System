# Bank-Managment-System
 Requirements:   
   * A bank has the Account Holder and the Employees,  
   * Bank can manage all records of employees. 
   * An employee should have a login portal for managing bank customers. 
   * Customers should have a login portal for managing their bank account.

Based on these requirements, We choose the functionalities:


Functionalities are:
______________________________________________________________________________________________________________________________________________




* CreateAccoundHolder()
    Create a new Account Holder by entering the details like Name, Age, Address,Initial Amount etc.


* SearchAccountHolder()
     By using the Account Number, admin can search for an Account Holder.


* ModifyAccountHolder()
          Using Account Number, admin can edit/modify the details(Name, Age etc.) of an Account Holder.
* CloseAccount()
          The admin can permanently delete the Account of an Account Holder

* RegisterEmployer()
          A new Employer can be added. Employee Id. will also be added at this time. Employee details like Name, Age will be added.
          It will also ask to choose the Designation-Staff,Manager. 
          Further details like Address etc should be entered
          Create a new username and password for Employer.


* SearchEmployer()
          Based on Employee Id, the admin can search for an employee.


* ViewEmployer()
          Based on Employee Id, the admin can view the employee details.


* ModifyEmployerDetails()
          Based on Employee Id, admin can modify the details of the employee (i.e. Name, Age, Address etc)


_____________________________________________________________________________________________________________________________________________


Employee:


In the Employee portal, there are two options like. We can chose either Manager or staff.But the staff can only view the Account Holder details-They cannot edit or close the account.
And the functions that comes under the employee are:


ViewAccountHolder()
          Based on the Account Number, the manager can view the details of an Account Holder.


ModifyAccountHolder()
          Based on the Account Number, the manager can modify the details of an Account Holder.


CloseAccountHolder()
          Manager can also delete an account holder data.


_________________________________________________________________________________________________________________________________________________


Account Holder:


Account Holder can either make a new registration or can also login to the existing account.The functions are:


CreateAccountHolder()
         A new Account can be created by entering the details like Name, Age, Address, Initial amount etc. Also create a username and password for further login.


ViewAccountHolder()
         Account Holder can view his details by using the username and password.


ModifyAccountHolder()
         He can login and choose the option to be edited.
