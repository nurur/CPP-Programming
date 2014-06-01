// Example : 14.12,  Method 1
// Driver Program 
// Use Base Class PFArrayD & Derived Class PFArrayDBak
// Base Class PFArrayD data members are 'protected'


#include "PFArrayD.1.hpp"
#include "PFArrayDBak.1.hpp"
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;



void testPFArrayDBak();


int main()
{
  cout << "This program tests the class PFArrayDBak.\n";

  char ans;
  do 
    {
      testPFArrayDBak();
      cout << "Test again? (y/n) ";
      cin >> ans;
    } while( (ans == 'y') || (ans == 'Y') );

  return 0;
}



void testPFArrayDBak()
// Conducts one test for the class PFArrayDBak
{
  int cap, used;
  cout << "Enter capacity of the supar array: ";
  cin >> cap;
  PFArrayDBak tmp(cap);

  cout << "Enter up to " << cap << " non-negative numbers.\n";
  cout << "Place a negative number at the end.\n";

  double next;

  cin >> next;
  while ( (next >= 0) && (!tmp.full()) )
    {
      tmp.addElements(next);
      cin >> next;
    }

  if (next >= 0) 
    {
      cout << "Could not read all numbers.\n";
      while(next >= 0)
	cin >> next;
    }

  //  cout << "You entered the following "
  //     << tmp.getNumbUsed() << " numbers: \n";
  
  //  cout << "You entered the following " << tmp << " numbers: \n";

  int count = tmp.getNumbUsed();
  cout << "The following " << count << " numbers "
       << "are read and stored:\n"; 
  for (int index=0; index < count; index++)
    cout << tmp[index] << " ";
  cout << endl;

  cout << "Now backing up the array ...\n";
  tmp.backup();
  cout << "Now emptying the array   ...\n";
  tmp.emptyArray();
  cout << tmp.getNumbUsed()
       << " numbers are now stored in the array.\n";

  cout<< "Now restoring the array  ...\n";
  tmp.restore();
  count = tmp.getNumbUsed();
  cout << "The following " << count << " numbers"
       << "are now stored:\n"; 
  for (int index=0; index < count; index++)
    cout << tmp[index] << " ";


  cout << endl;
}
