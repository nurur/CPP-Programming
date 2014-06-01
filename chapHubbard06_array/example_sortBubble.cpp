// Example: chaper 6 (C++, J Hubbard)
// Sorting an array in ascending order using Bubble Sort algorithm 
//
// Algorithm:
/*
 * On the first iteration it compares each pair of consecutive elements
 * from all elemnts and move the larger element up, to the last (a[n-1]) 
 * position
 * On the second iteration it repeats the same process but with the 
 * remaining a[n-2] elements and move the larger element to the next to 
 * the last (i.e. a[n-2]) position
 * It repeats until it compares the first two elemnts of the original array 
 */


#include <iostream>
using namespace std;


void swap(float& x, float& y)
{
  float t;
  t = x;
  x = y;
  y = t;
}


void bubbleSort(float a[], int n)
{
  for (int i=1; i<n; i++)
    for (int j=0; j<n-i; j++) 
      { 
	if (a[j] > a[j+1])
	  swap(a[j], a[j+1]);
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

  cout << "elements of the array are: " << endl;
  printA(a,SIZE);


  // Use bubble sort
  bubbleSort(a,SIZE);
  printA(a,SIZE);


  return 0;
}
