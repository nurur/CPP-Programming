// Problem 6.15, chaper 6 (C++, J Hubbard)
// Rotate first k elements of an array 


#include <cstdlib>
#include <iostream>
using namespace std;


void rotateArray(float a[], int n, int k)
{
  float b[abs(k)];

  if (k > 0)     // Rotate last k elements to the first k elements 
    { 
      float b[abs(k)];

      int j=0;
      for (int i=n-k; i<n; i++)
	{
	  b[j] = a[i];
	  ++j;
	}
      
      j = n-1;
      for (int i=n-k; i>0; i--)
	{    
	  a[j] = a[i-1];
	  --j;
	}
      
      for (int i=0; i<k; i++)
	a[i] = b[i];  
    }   // endif
  
  
  if (k < 0)     // Rotate first k elements to the last k elements 
    { 
      int kk = abs(k);
      int j = 0;
      for (int i=0; i<kk; i++)
	{
	  b[j] = a[i];
	  ++j;
	}
      
      j = 0;
      for (int i=kk; i<n; i++)
	{    
	  a[j] = a[i];
	  ++j;
	}
     
      j = 0;
      for (int i=n-kk; i<n; i++)
	{	
	  a[i] = b[j];  
	  ++j;
	}
    } // endif 
}


void printA(float a[], int n)
{
  for(int i=0; i<n; i++)
    cout << a[i] << " ";  
  cout << endl;  
}



int main()
{
   const int SIZE = 9;
   float a[SIZE] = {55.5, 22.5, 99.9, 11.1, 66.6, 44.4, 88.8, 33.3, 77.7};
   float b[SIZE] = {55.5, 22.5, 99.9, 11.1, 66.6, 44.4, 88.8, 33.3, 77.7};
    
  cout << "The array elements are: " << endl;
  printA(a,SIZE);

  int m = +1;
  rotateArray(a,SIZE,m);
  printA(a,SIZE);

  int n = -1;
  rotateArray(b,SIZE,n);
  printA(b,SIZE);



  return 0;
}
