// Self Test Exercise 14.5
// Inheritance : Derived Class
// Special Note :  Re-define base class member function 


#ifndef TITLEDEMPLOYEE_HPP
#define TITLEDEMPLOYEE_HPP

#include "Employee.hpp"
#include "SalariedEmployee.hpp"
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;


class TitledEmployee : public SalariedEmployee
{
public:
  TitledEmployee();
  TitledEmployee(string theName, string theSsn, double theSalary, 
		 string theTitle);
  
  string getTitle() const;
  void   setTitle(string newTitle);
  void   setName(string newName);    // Redefined base member function  

  void printEmployeeData() const;
  
private:
  string title;
};



TitledEmployee :: TitledEmployee()
  : SalariedEmployee(), title("no title yet") { }

TitledEmployee :: TitledEmployee(string theName, 
				 string theSsn, 
				 double theSalary, 
				 string theTitle) 
  : SalariedEmployee(theName, theSsn, theSalary), 
    title(theTitle) { }



string TitledEmployee :: getTitle() const
{ return title; }

void   TitledEmployee :: setTitle(string newTitle)
{ title = newTitle; } 


void TitledEmployee :: setName(string newName)
// Re-define base member function 
{ 
  Employee::setName(title + " " + newName); 
}

void TitledEmployee :: printEmployeeData() const
{
  cout <<"\n---------------------------------------\n";
  cout << "Derive Class: TitledEmployee          \n\n";
  cout << "Titled Employee's Name   : " <<  getName()  << endl;
  cout << "Titled Employee's SSN    : " <<  getSsn()   << endl;
  //cout << "Titled Employee's Title  : " <<  getTitle() << endl;
}


#endif   //TITLEDEMPLOYEE_HPP
