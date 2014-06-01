// Problem 6.6,  chaper 6 (C++, J Hubbard)
// Linear Search Algorithm
// Note:
// Example 6.12 Modified 
// Return the highest index of multiple occurance of an element


#include <iostream>
using namespace std;



int index(int a[], int n, int x)
{
  for (int i=n-1; i>=0; i--)
    if (x == a[i]) 
      { 	
	cout << "The object is found.\n";              
	return i;
      }
  
  for (int i=n-1; i>=0; i--)
    if (x != a[i])                        
      { 
	cout << "The object is not found.\n"; 
	return n;             
      }
}



int main()
{
  const int SIZE = 10;
  int a[10] = {22, 44, 66, 88, 44, 11, 33, 55, 11, 99};

  cout << "Array index(a,SIZE,44) is : " << index(a,SIZE,11) << endl;
  cout << "Array index(a,SIZE,50) is : " << index(a,SIZE,50) << endl;

  return 0;
}
