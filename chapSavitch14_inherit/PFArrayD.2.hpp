// Example : 14.8, 14.9
// Partially Filled Array using Dynamic Array 
// Base Class PFArrayD : data members 'private'


#ifndef PFARRAYD_HPP
#define PFARRAYD_HPP


#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;


// Class Interface   ************************************************
class PFArrayD
{
  friend ostream& operator<<(ostream& ostr, const PFArrayD& pfarr);

public:
  PFArrayD();
  // Initialize with a capacity of 50;
  PFArrayD(int capacityValue);
  // User defined capacity

  PFArrayD(const PFArrayD& pfaObject);
  PFArrayD& operator=(const PFArrayD& rightSide);
  double& operator[](int index);
 ~PFArrayD();

  void addElements(double element);
  bool full()       const { return (capacity == used); }
  int getCapacity() const { return capacity; }
  int getNumbUsed() const { return used; }
  void emptyArray() { used = 0; } 


private:
  double* a;      // For an array of doubles
  int capacity;   // For the size of the array
  int used;       // For the number of array positions currently being used

};




// Class Implementation ********************************************
PFArrayD :: PFArrayD()
{ 
  capacity = 50; 
  used     = 0; 
  a        = new double[capacity];
}

PFArrayD :: PFArrayD(int capacityValue)
{ 
  capacity = capacityValue; 
  used     = 0;
  a        = new double[capacity];
}

PFArrayD :: PFArrayD(const PFArrayD& pfaObject)
{
  capacity = pfaObject.getCapacity();
  used     = pfaObject.getNumbUsed();
  
  a = new double[capacity];
  for (int i=0; i < used; i++)
    a[i] = pfaObject.a[i];
}

PFArrayD& PFArrayD :: operator=(const PFArrayD& rightSide)
{
  if (capacity != rightSide.capacity)
    {
      delete[] a;
      a = new double[rightSide.capacity];
    }
  
  capacity = rightSide.capacity;
  used     = rightSide.used;
  for (int i=0; i< used; i++)
    a[i] = rightSide.a[i];
  
  return *this;
}

double& PFArrayD :: operator[](int index)
{
  if (index >= used)
    {
      cout << "Illigal index in PFArrayD.\n";
      exit(1);
    }

  return a[index];
}

PFArrayD :: ~PFArrayD()
{
  delete [] a;
}
  
void PFArrayD :: addElements(double element)
{
  if (used >= capacity)
    {
      cout << "Attempts to exceed capacity in PFArrayD.\n";
      exit(1);
    }

  a[used] = element;
  used++;
}


ostream& operator<<(ostream& ostr, const PFArrayD& pfarr)
{
  ostr << pfarr.used;
  return ostr;
}

#endif // PFARRAYD_HPP
