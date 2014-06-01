// Example: 12.1, 12.2, 12.3, 12.4, 12.5
// Inheritance, Nested Class  
// Base Class    : Person 
// Derived Class : Student 


#include "Date.hpp"
#include <cstring>
#include <iostream>
using namespace std;


class Person
{
public :
  Person();
  Person(string theName, string theNatn, string theSex); 
  Person(const Person& Object);
 ~Person();

  void setDOB(int m, int d, int y) { dob.setDate(m,d,y); }
  void setDOD(int m, int d, int y) { dod.setDate(m,d,y); }
  
  void        printName() { cout << name; }
  void printNationality() { cout << natn; }

protected:
  string name, natn, sex;
  Date dob, dod;
};

Person :: Person()
{ name = " ";  natn = " "; sex = " "; }

Person :: Person(string theName, string theNatn, string theSex)
{ name = theName;  natn = theNatn; sex = theSex; }

Person :: Person(const Person& Object) 
{ 
  name = Object.name; 
  natn = Object.natn; 
  sex  = Object.sex; 
}

Person :: ~Person() { }




class Student : public Person 
{
public:
  Student(); 
  Student(string theName, string theNatn, 
	  string theSex, string theId);
  
  void   setDOM(int m, int d, int y) { doM.setDate(m,d,y); }
  void printDOM() { cout << doM; }
  void printSex() { cout << sex; }

protected:
  string id;   // id number
  int credits;
  float gpa;

  Date  doM;   // date of Matriculation 
};

Student :: Student() : Person()
{ id = " ";  credits = 0; }

Student :: Student(string theName, string theNatn, 
		   string theSex, string theId) 
  : Person(theName, theNatn, theSex)
{ id = theId;  credits = 0; }




int main()
{ 
  Student x("Nurur Rahman", "USA", "M", "201243028");
  x.setDOB(8, 24, 1973);
  x.setDOM(1, 10, 1990);

  cout<< "name         : "; x.printName();        cout << endl;
  cout<< "nationality  : "; x.printNationality(); cout << endl;
  cout<< "sex          : "; x.printSex();         cout << endl;
  cout<< "matriculation: "; x.printDOM();         cout << endl;

  return 0; 
}
