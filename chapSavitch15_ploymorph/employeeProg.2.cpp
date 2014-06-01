// Self-Test Exercise : 15.4
// Driver program  


#include "Employee.hpp"
#include "HourlyEmployee.hpp"
#include "SalariedEmployee.hpp"
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;



int main()
{
  HourlyEmployee Joe("Mighty Joe", "123-45-6789", 20.50, 40);
  Joe.printCheck(); 


  HourlyEmployee Mike;
  Mike.setName("Mighty Mike");
  Mike.setSsn("123-45-6789");
  Mike.setWageRate(20.50);
  Mike.setHour(40);
  Mike.printCheck();


  SalariedEmployee Noor;
  Noor.setName("Nurur Rahman");
  Noor.setSsn("123-45-6789");
  Noor.setSalary(325000.00);
  Noor.printCheck();

  return 0;
}
