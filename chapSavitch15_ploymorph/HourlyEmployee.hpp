// Example : 15.6
// Concerte Derived Class


#ifndef HOURLYEMPLOYEE_HPP
#define HOURLYEMPLOYEE_HPP


#include "Employee.hpp"
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;



// Class HourlyEmployee : Interface      ********************************
//
class HourlyEmployee : public Employee
{
public:
  HourlyEmployee();
  HourlyEmployee(string theName, string theSsn, 
		 double theWageRate, double theHours);

  double getWageRate() const;
  double getHour() const;

  void setWageRate(double newWageRate);
  void setHour(double hoursWorked);

  virtual void printCheck();

private:
  double wageRate;
  double hours;
};



// Class HourlyEmployee : Implementation ********************************
// Constructors 
HourlyEmployee :: HourlyEmployee() 
  : Employee(), wageRate(0), hours(0) { } 

HourlyEmployee :: HourlyEmployee(string theName, string theSsn,
				 double theWageRate, double theHours)
  : Employee(theName, theSsn), wageRate(theWageRate), hours(theHours) { } 

double HourlyEmployee :: getWageRate() const
{ return wageRate; }

double HourlyEmployee :: getHour() const
{ return hours; }

void HourlyEmployee :: setWageRate(double newWageRate)
{ wageRate = newWageRate; }

void HourlyEmployee :: setHour(double hoursWorked)
{ hours = hoursWorked; }


void HourlyEmployee :: printCheck() 
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


#endif 
