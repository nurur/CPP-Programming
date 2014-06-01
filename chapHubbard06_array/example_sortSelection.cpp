// Problem: 6.19  chaper 6 (C++, J Hubbard)
// Sorting an array in ascending order using Selection Sort algorithm 
//
// Algorithm:
/*
 * On the first iteration it selects the largest of all elements (a[n])
 * and swaps it with the last (a[n-1]) element
 * On the second iteration it selects the largest from the remaining 
 * a[n-2] elements and swaps it with the second to last (a[n-2]) element
 * It repeats until it compares the first two elemnts of the original array
 */


#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;


void swap(float a[], int m, int n)
{
  float t;
  t    = a[m];
  a[m] = a[n];
  a[n] = t;
}


void selectionSort(float a[], int n)
{
  float maxVal;
  int indx; 

  for (int i=1; i<n; i++)
    { 
      maxVal = a[0];
      for (int j=0; j<n-i; j++) 	
	{ if ( a[j] >= maxVal ) 
	    { maxVal = a[j];
	      indx   = j;
	    }
	}
      swap(a,indx,(n-i));
    }
}


void printA(float a[], int n)
{
  for(int i = 0; i<n; i++)
    cout << a[i] << " ";  
  cout << endl;  
}




int main()
{
   const int SIZE = 8;
   float a[SIZE] = {55.5, 22.5, 99.9, 66.6, 44.4, 88.8, 33.3, 77.7};

  cout << "The elements of the array are: " << endl;
  printA(a,SIZE);


  // Use selection sort
  selectionSort(a,SIZE);
  printA(a,SIZE);


  return 0;
}
