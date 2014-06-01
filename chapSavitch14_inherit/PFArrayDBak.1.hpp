// Example : 14.10, 14.11
// Partially Filled Array using Dynamic Array 
// Derived Class PFArrayDBak  : data members are made 'protected'
// Base Class PFArrayD 


#ifndef PFARRAYDBAK_HPP
#define PFARRAYDBAK_HPP


#include "PFArrayD.1.hpp"
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;


// Class Interface   ************************************************
//
class PFArrayDBak : public  PFArrayD
{
public:
  PFArrayDBak();
  // Initialize with a capacity of 50;
  PFArrayDBak(int capacityValue);
  // User defined capacity

  PFArrayDBak(const PFArrayDBak& Object);
  PFArrayDBak& operator=(const PFArrayDBak& rightSide);
 ~PFArrayDBak();

  void backup();
  // Makes a backup copy of the partially filled array
  void restore();
  // Restore the partially filled array to the last saved version  


private:
  double* b;    // for a backup pf main array  
  int usedB;    // backup for inherited member variable used 
};




// Class Implementation ********************************************
PFArrayDBak :: PFArrayDBak() : PFArrayD(), usedB(0)
{  b  = new double[capacity]; }

PFArrayDBak :: PFArrayDBak(int capacityValue) 
  : PFArrayD(capacityValue), usedB(0) 
{  b  = new double[capacity]; }

PFArrayDBak :: PFArrayDBak(const PFArrayDBak& Object) 
: PFArrayD(Object), usedB(0) 
{
  usedB = Object.usedB;  
  b     = new double[capacity];
  for (int i=0; i < usedB; i++)
    b[i] = Object.b[i];
}

PFArrayDBak& PFArrayDBak :: operator=(const PFArrayDBak& rightSide)
{
  int oldCapacity = capacity;
  PFArrayD :: operator=(rightSide);

  if (oldCapacity != rightSide.capacity)
    {
      delete[] b;
      b = new double[rightSide.capacity];
    }
  
  usedB  = rightSide.usedB;
  for (int i=0; i< usedB; i++)
    b[i] = rightSide.b[i];
  
  return *this;
}


PFArrayDBak :: ~PFArrayDBak()
{
  delete [] b;
}
  

void PFArrayDBak ::  backup()
// Makes a backup copy of the partially filled array
{ 
  usedB = used;
  for (int i=0; i<usedB; i++)
    b[i] = a[i];    // This is a copy, NOT an assignment
}

void  PFArrayDBak :: restore()
// Restore the partially filled array to the last saved version  
{
  used = usedB;
  for (int i=0; i<used; i++)
    a[i] = b[i];    
}


#endif  // PFARRAYBAK_HPP
