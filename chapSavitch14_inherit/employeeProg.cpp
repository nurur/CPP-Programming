// Example: 14.1, 14.2, 14.3, 14.4, 14.5, & 14.6
// Driver program  


#include "Employee.hpp"
#include "HourlyEmployee.hpp"
#include "SalariedEmployee.hpp"
#include "TitledEmployee.hpp"
#include "Administrator.hpp"
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;



int main()
{
  Employee x;
  Employee y("John", "351951015");
  cout << y.getName() << " " << y.getSsn() << endl;

  HourlyEmployee Joe("Mighty Joe", "123-45-6789", 20.50, 40);
  Joe.printCheck(); 

  HourlyEmployee Mike;
  Mike.setName("Mighty Mike");
  Mike.setSsn("123-45-6789");
  Mike.setWageRate(20.50);
  Mike.setHour(40);
  Mike.printCheck();


  TitledEmployee Noor;
  Noor.setTitle("Dr.");
  Noor.setName("Nurur Rahman");
  Noor.setSsn("123-45-6789");
  Noor.printEmployeeData();
  
  TitledEmployee NR("Nurur Rahman", "123-45-6789", 325000, "Dr.");

  
  Administrator Nurur;
  Nurur.setName("Nurur Rahman");   //Inherited from Employee
  Nurur.setSsn("123-45-6789");     //Inherited from Employee
  Nurur.setSalary(5000);           //Inherited from SalariedEmployee
  Nurur.setTitle("Director");
  Nurur.setResponsibility("Computing");
  Nurur.setSupervisor("Robert Brandenburger");
  Nurur.printEmployeeData();
  Nurur.printCheck();
  

  return 0;
}
