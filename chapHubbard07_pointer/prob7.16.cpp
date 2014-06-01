// Problem 7.16, chap 7 (C++, J R Hubbard)
// Indirect Selection Sort using Array of Pointers 


#include <iostream>
using namespace std;


void swap(float& x, float& y)
{
  float tmp;
  tmp = x;
  x   = y;
  y   = tmp;
}


void selectionSort(float* p[], int n)
{
  for (int i=1; i<n; i++)
    {
      for (int j=0; j<n-i; j++) 
	
	if (*p[j] > *p[j+1])
	  swap(*p[j], *p[j+1]);
    }
}


void printA(float a[], int n)
{
  for(int i = 0; i<n; i++)
    cout << a[i] << " ";  
  cout << endl;  
}

void printP(float* a[], int n)
{
  for(int i=0; i<n; i++)
    cout << *a[i] << " ";  
  cout << endl;  
}






int main()
{
   const int SIZE = 8;
   float a[SIZE] = {55.5, 22.5, 99.9, 66.6, 44.4, 88.8, 33.3, 77.7};

  cout << "elements of the array are: " << endl;
  printA(a,SIZE);


  float* p[SIZE];
  for(int i=0; i<SIZE; i++)
    p[i] = &a[i]; 


  selectionSort(p,SIZE);
  printP(p,SIZE);

  return 0;
}
