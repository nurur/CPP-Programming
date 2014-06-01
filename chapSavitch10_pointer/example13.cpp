// Example:  Smart Pointer
// Part 2 : Examining the scope of pointers 
 

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



class RC
{
public:
  RC() : mcount(0) { } 

  void AddRef()
  { // Increment the reference count
    mcount++;
    cout << mcount << " ";
  }
  
  int Release()
  { // Decrement the reference count and
    // return the reference count.
    return --mcount;
  }
  
private:
  int mcount; // Reference count
};


template <class T> 
class SP
{
public:
  SP()          : m_data(0), m_refe(0) 
  { 
    // Default constructor 
    // Create a new reference 
    m_refe = new RC;
    // Increment the reference count
    m_refe->AddRef();
    cout << "From Default constructor" << endl;
  }
  
  SP(T* pValue) : m_data(pValue), m_refe(0) 
  { 
    // Auxiliary constructor
    // Create a new reference 
    m_refe = new RC;
    // Increment the reference count
    m_refe->AddRef();   
    cout << "From Auxiliary constructor" << endl;
  }

  SP(const SP<T>& sp) : m_data(sp.m_data), m_refe(sp.m_refe)
  {
    // Copy constructor
    // Copy the data and reference pointer
    // and increment the reference count
    m_refe->AddRef();
    cout << "From Copy constructor" << endl;
  }

  ~SP() 
  { 
    // Destructor
    // Decrement the reference count
    // if reference become zero delete the data
    if(m_refe->Release() == 0)
      {
	delete m_data;
	delete m_refe;
      }
  }
  

  SP<T>& operator =(const SP<T>& rhs)
  {
    // Assignment operator
    if (this != &rhs) // Avoid self assignment
      {
	// Decrement the old reference count
	// if reference become zero delete the old data
	if(m_refe->Release() == 0)
	  {
	    delete m_data;
	    delete m_refe;
	  }
	
	// Copy both data and reference pointer
	// and increment the reference count
	m_data = rhs.m_data;
	m_refe = rhs.m_refe;

	m_refe->AddRef();
	cout << "From Copy Assignment operator" << endl;
     }
    return *this;
  }

  

  T& operator*()
  { return *m_data; }
  
  T* operator->()
  { return m_data; }
  
private:
  T*  m_data; // Generic pointer to generic Class T
  RC* m_refe; // Pointer to RC class
};



int main()
{
  SP<Person> p( new Person("Scott", 25) ); // Auxiliary constructor 
  p->Display();
  //
  {
    SP<Person> q = p;                     // Copy constructor 
    q->Display();
    // Destructor of q will be called here..
    
    SP<Person> r;                         // Default constructor 
    r = p;                                // Copy assignment operator  
    r->Display();
    // Destructor of r will be called here..
  }
  //
  p->Display();
  // Destructor of p will be called here 
  // and person pointer will be deleted
  
  return 0;
}
