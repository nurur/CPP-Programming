// Example:  Smart Pointer
// Part 1 : Defining new pointers at a time
 

#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;



class Person
{
public:
  Person(): m_name(0),m_age(0) { }
  Person(const char* pName, int pAge): m_name(pName), m_age(pAge) { }
  ~Person() { }
  
  void Display()
  {
    cout << "Name: " << m_name << ", age: " << m_age << endl;
  }
  void Shout()
  {
    cout << "Oyi ... !!" << endl;
  } 
  
private:
  int    m_age;
  const char* m_name;
};



template <class T> 
class SP
{
public:
  SP()          : m_data(0) { }
  SP(T* pValue) : m_data(pValue) { }
 ~SP() { delete m_data; }
  
  T& operator*()
  { return *m_data; }
  
  T* operator->()
  { return m_data; }

private:
  T* m_data; // Generic pointer to generic Class T
  
};



int main()
{
  SP<Person> p( new Person("David", 24) );
  p->Display();
  p->Shout();

  SP<Person> q( new Person("Scott", 25) );
  q->Display();
  q->Shout();

  SP<Person> r = new Person("Steve", 26);
  r->Display();
  r->Shout();


  /* why it does not work!? 
  SP<Person> s;
  s = new Person("Doug", 27);
  s->Display();
  s->Shout();
  */


  return 0;
}
