// Example : 15.6
// Concerte Derived Class


#ifndef SALARIEDEMPLOYEE_HPP
#define SALARIEDEMPLOYEE_HPP

#include "Employee.hpp"
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;



// Class SalariedEmployee : Interface      ********************************
//
class SalariedEmployee : public Employee
{
public:
  SalariedEmployee();
  SalariedEmployee(string theName, string theSsn, double theSalary);

  double getSalary() const;
  void setSalary(double newSalary);

  virtual void printCheck();

protected:
  double salary; // weekly
};



// Class SalariedEmployee : Implementation ********************************
// Constructors 
SalariedEmployee ::  SalariedEmployee() 
  : Employee(), salary(0) { }

SalariedEmployee ::  SalariedEmployee(string theName, string theSsn, 
				      double theSalary) 
  : Employee(theName, theSsn), salary(theSalary) { }

double SalariedEmployee :: getSalary() const
{ return salary; }

void SalariedEmployee :: setSalary(double newSalary)
{ salary = newSalary; }


void SalariedEmployee :: printCheck() 
{
  setNetPay(salary);

  cout <<"\n---------------------------------------\n";
  cout << "Pay to the order of " << getName() << endl;
  cout << "The sum of $" << getNetPay() << endl;
  cout <<"\n---------------------------------------\n";
  cout << "Check Stub: Not Negotiable.\n";
  cout << "Employee Number: " <<  getSsn() << endl;
  cout << "Employee Name  : " << getName() << endl;
  cout <<"\n---------------------------------------\n";
}


#endif
