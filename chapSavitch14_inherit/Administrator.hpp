// Problem 14.1
// Inheritance : 
// Base Class SalariedEmployee 
// Derived Class Administrator 



#ifndef ADMINISTRATOR_HPP
#define ADMINISTRATOR_HPP


#include "Employee.hpp"
#include "SalariedEmployee.hpp"
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;


class Administrator : public SalariedEmployee 
{
public:
  Administrator();
  Administrator(string theName, string theSsn, double theSalary, 
		string theTitle, 
		string theResponsibility, 
		string theSupervisor);

  double getEmployeeData();

  void setTitle(string newTitle);
  void setResponsibility(string newResponsibility);
  void setSupervisor(string newSupervisor);

  void printEmployeeData() const;
  void printCheck();

protected:
  double adminSalary;

private:
  string adminTitle;
  string adminResponsibility;
  string adminSupervisor;
};



Administrator :: Administrator() 
  : SalariedEmployee(), 
    adminTitle("no title yet"), 
    adminResponsibility("no repsonsibility yet"),
    adminSupervisor("no name of the supervisor yet") 
{ }

Administrator :: Administrator(string theName, 
			       string theSsn, 
			       double theSalary, 
			       string theTitle, 
			       string theResponsibility, 
			       string theSupervisor) 
  : SalariedEmployee(theName, theSsn, theSalary), 
    adminTitle(theTitle), 
    adminResponsibility(theResponsibility),
    adminSupervisor(theSupervisor) 
{ } 


double Administrator :: getEmployeeData()
{
  return adminSalary;
}

void Administrator :: setTitle(string newTitle)
{ 
  adminTitle = newTitle; 
} 

void Administrator :: setResponsibility(string newResponsibility)
{
  adminResponsibility = newResponsibility;
}

void Administrator :: setSupervisor(string newSupervisor)
{ 
  adminSupervisor = newSupervisor; 
}

void Administrator :: printEmployeeData() const
{
  cout <<"\n---------------------------------------\n";
  cout << "Derive Class: Administrator           \n\n";
  cout << "Adminitrator's Name          : " << getName()           << endl;
  cout << "Adminitrator's SSN           : " << getSsn()            << endl;
  cout << "Adminitrator's title         : " << adminTitle          << endl;
  cout << "Adminitrator's responsibility: " << adminResponsibility << endl;
  cout << "Adminitrator's salary        : " << getSalary()         << endl;
  cout << "Adminitrator's supervisor    : " << adminSupervisor     << endl;
}

void Administrator :: printCheck()
{
  setNetPay(salary);

  cout << "\n\n";
  cout << "Pay to the order of " << getName() << endl;
  cout << "The sum of $" << getNetPay() << " per week." << endl;
  cout << "\n---------------------------------------\n";
  cout << "Check Stub: Not Negotiable.\n";
  cout << "Employee Number: " <<  getSsn() << endl;
  cout << "Employee Name  : " << getName() << endl;
  cout << "\n---------------------------------------\n";
}

#endif  //ADMINISTRATOR_HPP
