// Self-Test Exercise 15.7
// Pointers, Base Class, Derived Class, and Virtual Functions 


#include <iostream>
using namespace std;


// Case 1
// Without Virtual Function 
class Pet1
{
public:
  string name;
 void print() const;
};

void Pet1 :: print() const
{ cout << "Pet name: " << name << endl; }


class Dog1 : public Pet1
{
public:
  string breed;
  void print() const;
};

void Dog1 :: print() const 
{ 
  cout << "Dog name: " << name  << endl; 
  cout << breed << endl; 
}



// Case 2
// With Virtual Function 
class Pet2
{
public:
  string name;
 virtual void print() const;
};

void Pet2 :: print() const
{ cout << "Pet name: " << name << endl; }


class Dog2 : public Pet2
{
public:
  string breed;
  virtual void print() const;
};

void Dog2 :: print() const 
{ 
  cout << "Dog name: " << name  << endl; 
  cout << breed << endl; 
}





int main()
{

  // Base and Derived Classes without Virtual Function
  cout << "Classes without virtual function " << endl; 
  cout << "Pet *ppet = new Dog;" << endl << endl;
  Pet1 *ppet1 = new Dog1;

  ppet1->name  = "Tiny";
  ppet1->print();  

  delete ppet1; ppet1 = 0;
  cout << endl;


  // Base and Derived Classes with Virtual Function
  cout << "Classes with virtual function ..." << endl; 
  cout << "Pet *ppet = new Dog;" << endl << endl;
  Pet2 *ppet2 = new Dog2;

  ppet2->name  = "Tiny";
  ppet2->print();  

  delete ppet2; ppet2 = 0;

  return 0;
}
