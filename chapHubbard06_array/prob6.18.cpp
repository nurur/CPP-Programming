// Problem: 6.18  chaper 6 (C++, J Hubbard)
// Sorting an array in ascending order using Insertion Sort algorithm 


#include <iostream>
using namespace std;


void insertionSort(float a[], int n)
{
  int i, j;

  for (i=1; i<n;i++)
    {
      float x = a[i];
      j = i;
      //cout << "i =" <<i << ", j =" << j << "   " << x << endl; 
      while (j>0 && a[j-1]>x)
	{
	  a[j] = a[j-1]; 
	  j--;
	}
      a[j] = x; 
      
      //for (int k=j; k<n; k++)
      //cout << "a[" << k <<"] = " << a[k] << endl;
      //cout << " --- " << endl;
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


  // Use Insertionsort
  insertionSort(a,SIZE);
  printA(a,SIZE);


  return 0;
}
