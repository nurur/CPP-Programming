// Example : 10.10, 10.11, 10.12
// Class PFArrayD
// Partially Filled Array using Dynamic Array 



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




// Driver Program    **************************************************** 
void testPFArrayD();
// Conducts one test for the class PFArrayD 


int main()
{
  cout << "This program tests the class PFArrayD.\n";

  char ans;
  do 
    {
      testPFArrayD();
      cout << "Test again? (y/n) ";
      cin >> ans;
    } while( (ans == 'y') || (ans == 'Y') );

  return 0;
}



void testPFArrayD()
{
  int cap, used;
  cout << "Enter capacity of the supar array: ";
  cin >> cap;
  PFArrayD tmp(cap);

  cout << "Enter up to " << cap << " non-negative numbers.\n";
  cout << "Place a negative number at the end.\n";

  double next;

  cin >> next;
  while ( (next >= 0) && (!tmp.full()) )
    {
      tmp.addElements(next);
      cin >> next;
    }


  cout << "You entered the following "
       << tmp.getNumbUsed() << " numbers: \n";
  
  //  cout << "You entered the following " << tmp << " numbers: \n";

  int count = tmp.getNumbUsed();
  for (int index=0; index < count; index++)
    cout << tmp[index] << " ";
  
  cout << endl;
}
