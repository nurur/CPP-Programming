// Problem: 6.11  chaper 6 (C++, J Hubbard)
// Find the largest and second largest elements in an array  


#include <cstdlib>
#include <iostream>
using namespace std;


void largestElements(float a[], int n, float& max1, float& max2)
{
  float maxVal;
    
  maxVal = a[0];
  for (int i=0; i<n; i++) 	
    { if ( a[i] >= maxVal ) 
	maxVal = a[i];
    }
  max1 = maxVal;
  
  maxVal = a[0];
  for (int i=0; i<n; i++) 	
    { if ( a[i] >= maxVal && a[i] != max1) 
	maxVal = a[i]; 
    }
  max2 = maxVal;
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


  float x, y;
  largestElements(a,SIZE,x,y); 
  cout << "The largest and the second largest elements are : " << endl;
  cout << x << " " << y << endl;
    


  return 0;
}
