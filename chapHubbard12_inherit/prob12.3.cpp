// Problem 12.3, chap 12 (C++, C Hubbard)
// Inheritance 


#include "Date.hpp"
#include "Name.hpp"
#include <cstring>
#include <iostream>
using namespace std;


class Person
{
public :
  Person();                                     // default constructor 
  Person(const Person&);                        // copy constructor
  Person(char* n="", char* nat="", char* s="")  // constructor 
  : name(n), nationality(nat), sex(s) { }
  ~Person();                                    // destructor

  void setDOB(int m, int d, int y) { dob.setDate(m,d,y); }
  void setDOD(int m, int d, int y) { dod.setDate(m,d,y); }
  
  void        printName() { cout << name; }
  void printNationality() { cout << nationality; }
  void         printDOB() { cout << dob;  }
  void         printDOD() { cout << dod;  }

protected:
  string nationality, sex;
  Name name;
  Date dob, dod;
};




int main ()
{
  Name x("Bach", "Johann", "Sebastian");
  cout << x << endl;
  cout << endl;

  //using member functions
  x.last("Rahman");
  x.first("Nurur");
  x.middle("xxxx");
  x.title("SKA Fellow");
  x.nick("The Cool");
  cout << x << endl;

  // using member functions 
  cout << x.last();


  cout << endl;
  return 0;
}
