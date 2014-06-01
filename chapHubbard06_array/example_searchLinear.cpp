// Example 6.12
// Linear Search Algorithm
// Note:
// Return the smallest index of multiple occurance of an element


#include <iostream>
using namespace std;


int index1(int a[], int n, int x)
// Returns the first occurance among multiple occurances
{
  for (int i=0; i<n; i++)
    if (x == a[i]) 
      { 	
	cout << "The object is found.\n";              
	return i;
      }
  
  for (int i=0; i<n; i++)
    if (x != a[i])                        
      { 
	cout << "The object is not found.\n"; 
	return -1;             
      }
}



int index2(int a[], int n, int x)
// Returns the last occurance among multiple occurances
{
  int indx   = 0;
  bool found = false;
  
  for (int i=0; i<n; i++)
    if (x == a[i]) 
      { 	
	cout << "The object is found.\n";              
	indx  = i;
	found = true;
      }
  
  if (found) return indx;
  else 
    { 
      cout << "The object is not found.\n"; 
      return -1;             
    }
}



int main()
{
  const int SIZE = 10;
  int a[10] = {22, 44, 66, 88, 44, 11, 33, 55, 11, 99};

  cout << "Array index(a,SIZE,44) is : " << index1(a,SIZE,11) << endl;
  cout << "Array index(a,SIZE,50) is : " << index1(a,SIZE,50) << endl;

  cout << endl;
  cout << "Array index(a,SIZE,44) is : " << index2(a,SIZE,11) << endl;
  cout << "Array index(a,SIZE,50) is : " << index2(a,SIZE,50) << endl;

  return 0;
}
