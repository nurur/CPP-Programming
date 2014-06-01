// Problem     : 14.2
// Inheritance 
// Base Class Employee 
// Derived Class TemporaryEmployee


#ifndef TEMPORARYEMPLOYEE_HPP
#define TEMPORARYEMPLOYEE_HPP


#include "Employee.hpp"
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;



// Class TemporaryEmployee : Interface      ********************************
//
class TemporaryEmployee : public Employee
{
public:
  TemporaryEmployee();
  TemporaryEmployee(string theName, string theSsn, 
		    double theWageRate, double theHours,
		    int theContractLength);
  
  double getWageRate() const;
  double getHour()     const;
  int    getContract() const;

  void setWageRate(double newWageRate);
  void setHour(double newHours);
  void setContract(double newContract);

  void printCheck();

private:
  double wageRate;
  double hours;
  int contractLength;
};



// Class HourlyEmployee : Implementation ********************************
// Constructors 
TemporaryEmployee :: TemporaryEmployee() 
  : Employee(), wageRate(0), hours(0), contractLength(0) 
{ } 

TemporaryEmployee :: TemporaryEmployee(string theName, 
				       string theSsn,
				       double theWageRate, 
				       double theHours,
				       int theContractLength)
  : Employee(theName, theSsn), 
    wageRate(theWageRate), 
    hours(theHours), 
    contractLength(theContractLength) 
{ } 


double TemporaryEmployee :: getWageRate() const
{ return wageRate; }

double TemporaryEmployee :: getHour() const
{ return hours; }

int TemporaryEmployee :: getContract() const
{ return contractLength; }


void TemporaryEmployee :: setWageRate(double newWageRate)
{ wageRate = newWageRate; }

void TemporaryEmployee :: setHour(double hoursWorked)
{ hours = hoursWorked; }

void TemporaryEmployee :: setContract(double newContract)
{ contractLength =  newContract; }


void TemporaryEmployee :: printCheck()
{
  /* Sepcial Note:
   * The following call is illegal because base class private data members 
   * can not be called from a derived class member function unless the 
   * data memebrs in the base class is made public 
   
   double netPay = hours * wageRate;   //Illegal 
   setNetPay(netPay);
  */

  setNetPay(hours * wageRate);

  cout <<"\n---------------------------------------\n";
  cout << "Pay to the order of " << getName() << endl;
  cout << "The sum of " << getNetPay() << endl;
  cout <<"\n---------------------------------------\n";
  cout << "Check Stub: Not Negotiable.\n";
  cout << "Employee Number: " <<  getSsn() << endl;
  cout <<"\n---------------------------------------\n";
}


#endif  //TEMPORARYEMPLOYEE_HPP
