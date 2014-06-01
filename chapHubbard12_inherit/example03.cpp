// Example: 12.7, 12.8
// Inheritance  
// Execuation of Base Constructors and Base Destructors 
// Execuation of Derived Constructors and Derived Destructors 



#include <cstring> 
#include <iostream>
using namespace std;


// *************************************************************************
// Example 12.7
class X
{
  public:
  X()  { cout << " X::X() Constructor Executing\n"; }
  ~X() { cout << "~X::X() Destructor Executing \n"; }
};

class Y : public X
{
  public:
  Y()  { cout << " Y::Y() Constructor Executing\n"; }
  ~Y() { cout << "~Y::Y() Destructor Executing \n"; }
};

class Z : public Y
{
  public:
  Z(int) { cout << " Z::Z() Constructor Executing\n"; }
  ~Z()   { cout << "~Z::Z() Destructor Executing \n"; }
};




// *************************************************************************
// Example 12.8 
class Person
{
public :
  Person();
  Person(const char* s)
  { 
    cout << "Base Class Constructor Executing  " << endl;
    name = new char[strlen(s)+1];  strcpy(name,s); 
  }

 ~Person() 
{ 
  cout << "Base Class Destructor Executing  " << endl;
  delete [] name; 
}

protected:
  char* name;
};


class Student : public Person 
{
public:  
  Student();
  Student(const char* s, const char* m) 
  : Person (s) 
  { 
    cout << "Derived Class Constructor Executing  " << endl;
    major = new char[strlen(m)+1]; strcpy(major,m); 
  }	

  ~Student() 
  { 
    cout << "Derived Class Destructor Executing" << endl;
    delete [] major; 
  }

protected:
  char* major;
};



int main()
{
  // Check 
  Z z(44);


  // Check
  Student s("Sarah", "Biology");  
  cout << endl;


  return  0;
}
