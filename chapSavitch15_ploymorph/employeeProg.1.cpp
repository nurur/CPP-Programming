// Example: 15.6
// Driver program  
// Note:
/*
 * Abstract base class can not be instantiated
 */


#include "Employee.hpp"
#include "HourlyEmployee.hpp"
#include "SalariedEmployee.hpp"
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;



int main()
{
  // Employee is an abstract base class
  // Therefore, the following instances of the class are wrong!
  Employee x;
  Employee y("John", "351951015");
  cout << y.getName() << " " << y.getSsn() << endl;

  return 0;
}
