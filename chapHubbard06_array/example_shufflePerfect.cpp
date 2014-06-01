// Problem 6.29, chaper 6 (C++, J Hubbard)
// Shuffling elemnents of an array with even number of elements 



#include <cstdlib>
#include <iostream>
using namespace std;



void shufflePerfect(int a[], int n)
{
  int j;
  int mid = n/2;
  int b[mid];

  j=0;  
  for (int i=mid; i<n-1; i++)
    {
      b[j] = a[i];
	++j;
     } 

  for (int i=mid-1; i>=1; i--)
    a[2*i] = a[i];

  j=1;
  for (int i=0; i<mid-1; i++)
    {
      a[j] = b[i];
      j += 2;
    }
}


void printA(int a[], int n)
{
  for(int i = 0; i<n; i++)
    cout << a[i] << " ";  
  cout << endl;  
}




int main()
{
  const int SIZE = 10;
  int a[SIZE] = {34, 12, 89, 22, 21, 45, 55, 93, 27, 76};
 
  cout << "The original array elements are ...  " << endl;
  printA(a,SIZE);
  cout << endl;


  // Perfect shuffle of array elements
  shufflePerfect(a,SIZE);
  cout << "The shuffled array elements are ...  " << endl;
  printA(a,SIZE);

  return 0;
}
