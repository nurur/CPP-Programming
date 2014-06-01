// Example : 14.1, 14.2
// Inheritance : Base Class 


#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP


#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;



// Class Employee : Interface      ********************************
class Employee
{
public:
  Employee();
  Employee(string theName, string theSsn);

  string   getName() const;
  string    getSsn() const;
  double getNetPay() const;

  void     setName(string newName);
  void       setSsn(string newSsn);
  void setNetPay(double newNetPay);

  void printCheck() const;

protected:
  string name;
  string ssn;
  double netPay;
};



// Class Employee : Implementation ********************************
// Constructors 
Employee :: Employee() 
  : name("No name yet"), ssn("No ssn yet"), netPay(0) { }

Employee :: Employee(string theName, string theSsn) 
  : name(theName), ssn(theSsn) { }


// Getty member functions 
string Employee ::  getName() const
{ return name; }

string Employee ::   getSsn() const
{ return ssn; }

double Employee :: getNetPay() const
{ return netPay; }

// Setty member functions
void Employee :: setName(string newName)
{ name = newName; }

void Employee :: setSsn(string newSsn)
{ ssn = newSsn; }

void Employee ::  setNetPay(double newNetPay)
{ netPay = newNetPay; }


void Employee ::  printCheck() const
{ 
  cout << "Error: printCheck function called for an \n"
       << "unidentified employee. Aborting the program.\n" ;

  exit(1);
}


#endif 
